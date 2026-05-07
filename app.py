import json
import queue
from collections import deque
from datetime import datetime

import pandas as pd
import paho.mqtt.client as mqtt
import streamlit as st

# --- CONFIGURATION ---
MQTT_BROKER = "broker.hivemq.com"
DATA_TOPIC = "sia/compost/data"
COMMAND_TOPIC = "sia/compost/commands"
MAX_MESSAGES_PER_CYCLE = 100

# --- STATE MANAGEMENT ---
if "history" not in st.session_state:
    st.session_state.history = deque(maxlen=20)

if "message_queue" not in st.session_state:
    st.session_state.message_queue = queue.Queue(maxsize=200)

# --- MQTT CALLBACKS ---
def on_message(client, userdata, message):
    try:
        payload = json.loads(message.payload.decode())
        new_entry = {
            "Time": datetime.now().strftime("%H:%M:%S"),
            "Temp": payload.get("temp"),
            "Hum": payload.get("hum"),
            "Methane": payload.get("methane"),
            "Status": payload.get("status", "Unknown"),
        }
        try:
            userdata.put_nowait(new_entry)
        except queue.Full:
            pass
    except (json.JSONDecodeError, UnicodeDecodeError):
        pass


if "mqtt_client" not in st.session_state:
    client = mqtt.Client()
    client.user_data_set(st.session_state.message_queue)
    client.on_message = on_message
    client.connect(MQTT_BROKER)
    client.subscribe(DATA_TOPIC)
    client.loop_start()
    st.session_state.mqtt_client = client
else:
    client = st.session_state.mqtt_client

processed = 0
while processed < MAX_MESSAGES_PER_CYCLE:
    try:
        item = st.session_state.message_queue.get_nowait()
    except queue.Empty:
        break
    st.session_state.history.append(item)
    processed += 1

# --- STREAMLIT UI ---
st.set_page_config(page_title="Sia-Compost-Sync", layout="wide")
st.title("🌿 Sia-Compost-Sync Dashboard")
st.subheader("Divine Insight & Real-time Synchronization")

# Sidebar for Controls
with st.sidebar:
    st.header("System Controls")
    if st.button("🚨 System Reset"):
        client.publish(COMMAND_TOPIC, "RESET")
        st.warning("Reset command sent to ESP32")
    
    if st.button("📊 Force Refresh"):
        client.publish(COMMAND_TOPIC, "REFRESH")
        st.info("Refresh command sent")

# Top Metrics
history_df = pd.DataFrame(list(st.session_state.history))

if not history_df.empty:
    latest = history_df.iloc[-1]
    col1, col2, col3, col4 = st.columns(4)
    col1.metric("Temperature", f"{latest['Temp']}°C")
    col2.metric("Humidity", f"{latest['Hum']}%")
    col3.metric("Methane (Raw)", latest['Methane'])
    col4.success(f"AI Status: {latest['Status']}")

    # Live Chart
    st.line_chart(history_df.set_index("Time")[["Temp", "Hum"]])
else:
    st.info("Waiting for data from Sia-Compost-Sync probe...")

# Browser-driven refresh to keep UI live without server-side sleep loops
st.markdown("<meta http-equiv='refresh' content='2'>", unsafe_allow_html=True)
