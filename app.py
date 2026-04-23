import streamlit as st
import paho.mqtt.client as mqtt
import json
import pandas as pd
from datetime import datetime

# --- CONFIGURATION ---
MQTT_BROKER = "broker.hivemq.com"
DATA_TOPIC = "sia/compost/data"
COMMAND_TOPIC = "sia/compost/commands"

# --- STATE MANAGEMENT ---
if 'history' not in st.session_state:
    st.session_state.history = pd.DataFrame(columns=['Time', 'Temp', 'Hum', 'Methane', 'Status'])

# --- MQTT CALLBACKS ---
def on_message(client, userdata, message):
    payload = json.loads(message.payload.decode())
    new_entry = {
        'Time': datetime.now().strftime("%H:%M:%S"),
        'Temp': payload['temp'],
        'Hum': payload['hum'],
        'Methane': payload['methane'],
        'Status': payload['status']
    }
    # Keep only the last 20 readings for the live chart
    st.session_state.history = pd.concat([st.session_state.history, pd.DataFrame([new_entry])]).tail(20)

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
if not st.session_state.history.empty:
    latest = st.session_state.history.iloc[-1]
    col1, col2, col3, col4 = st.columns(4)
    col1.metric("Temperature", f"{latest['Temp']}°C")
    col2.metric("Humidity", f"{latest['Hum']}%")
    col3.metric("Methane (Raw)", latest['Methane'])
    col4.success(f"AI Status: {latest['Status']}")

    # Live Chart
    st.line_chart(st.session_state.history.set_index('Time')[['Temp', 'Hum']])
else:
    st.info("Waiting for data from Sia-Compost-Sync probe...")

# Setup MQTT Client
client = mqtt.Client()
client.on_message = on_message
client.connect(MQTT_BROKER)
client.subscribe(DATA_TOPIC)
client.loop_start()

# Auto-refresh the UI
st.empty()
import time
time.sleep(2)
st.rerun()