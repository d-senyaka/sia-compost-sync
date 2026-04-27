# 🌿 Sia-Compost-Sync

![C++](https://img.shields.io/badge/C++-Embedded-00599C?logo=c%2B%2B)
![Python](https://img.shields.io/badge/Python-3.10%2B-blue?logo=python)
![TinyML](https://img.shields.io/badge/Framework-TinyML-orange)
![MQTT](https://img.shields.io/badge/Protocol-MQTT-660066)
![Tasks](https://img.shields.io/badge/Tasks-Classification%20%7C%20Telemetry-yellow)
![License](https://img.shields.io/badge/License-MIT-green)
![Platform](https://img.shields.io/badge/Platform-ESP32%20%7C%20Web-lightgrey)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![Project Type](https://img.shields.io/badge/Project-Edge%20AI%20Implementation-brown)


**Sia-Compost-Sync** is an intelligent Edge AI monitoring system that transforms organic waste management into a data-driven process.  
It explores how local intelligence (TinyML) and multi-sensor fusion can be deployed on constrained microcontrollers to autonomously oversee biological decomposition, bridging the gap between raw earth and actionable digital insight.

### 🧠 Meaning of the Name
> *Sia* is derived from the ancient Egyptian personification of Perception, Insight, and Intelligence.  
> *Sync* represents the seamless, bidirectional harmony between the physical edge and the digital cloud.
---

## 🧠 Overview

Sia-Compost-Sync is built to **craft intelligence at the absolute edge**.  
It begins with an ESP32 microcontroller reading raw environmental data, but instead of blindly sending numbers to the cloud, it utilizes an on-device Random Forest model to locally classify the compost's health state (Normal, Wet, Dry, Ready). 

The system then extends to a fully bidirectional cloud architecture, allowing a web-based dashboard not only to visualize these local insights via MQTT but also to send remote commands back to the hardware.

---

## 🏗️ Architecture Highlights

| Component | Description |
|------------|-------------|
| **Edge Hardware** | ESP32 microcontroller fused with DHT11 (Climate) and MQ4 (Methane Gas) sensors. |
| **TinyML Inference Engine** | A Custom Random Forest Classifier trained in Python and ported to C++ (`model.h`) for zero-latency, offline decision-making. |
| **Bidirectional MQTT Sync** | Implements robust telemetry streaming and remote command subscription (e.g., Force Refresh, System Reset) via HiveMQ. |
| **Streamlit Command Center** | A real-time web dashboard for data visualization, state monitoring, and remote hardware intervention. |

---

## 🧩 Project Structure

```text
sia-compost-sync/
│
├── esp32_firmware/              # VS Code / PlatformIO Embedded Project
│   ├── src/
│   │   ├── main.cpp             # Core ESP32 logic (Sensor fusion, TinyML, MQTT)
│   │   └── model.h              # Exported TinyML Random Forest C++ header
│   └── platformio.ini           # Hardware configuration & library dependencies
│
├── python_edge/                 # IntelliJ Python Machine Learning Project
│   ├── data/
│   │   └── compost_data.csv     # Phase 1 empirical dataset (Normal, Wet, Dry, Ready)
│   ├── train_model.py           # Phase 2 ML training, evaluation, & C++ export script
│   ├── app.py                   # Phase 5 Streamlit dashboard & remote command center
│   └── requirements.txt         # Python library dependencies
│
└── README.md
```
---
## ⚙️ Installation

> *Project Structure might change*

```bash
# Clone the repository
git clone [https://github.com/](https://github.com/)<your-username>/sia-compost-sync.git
cd sia-compost-sync
```

### 🔌 1. Hardware & Edge Deployment

1.  **Environment Setup:** Open the `esp32_firmware` directory in **VS Code** with the **PlatformIO** extension installed.
2.  **Wiring:** Connect your sensors to the ESP32 following this pinout:
    - **DHT11 (Data):** GPIO 4
    - **MQ4 (Analog Out):** GPIO 34
3.  **Configuration:** In `src/main.cpp`, update the Wi-Fi credentials (`SSID` and `PASSWORD`).
4.  **Deployment:** Connect the ESP32 to your computer via USB, then **Build** and **Upload** the firmware.

### 💻 2. Dashboard & Cloud Sync Setup

1.  Open the python_edge directory in IntelliJ or your terminal.
2.  Create and activate a virtual Python environment:

```bash
python -m venv venv
source venv/bin/activate     # or .\venv\Scripts\activate on Windows
```
3.  Install the necessary machine learning and UI dependencies:

```bash
pip install -r requirements.txt
```

---

## 🚀 Usage: The 5-Phase Development Path

The project was executed in a modular, 5-phase lifecycle to ensure data integrity and model reliability at the edge.

### 📡 Phase 1 – Data Acquisition
Systematic empirical data collection was performed to build the "Ground Truth" for the classifier.
- **Process:** Sensors were exposed to controlled environments (moisture, gas spikes, dry air).
- **Output:** `compost_data.csv` containing ~1000+ labeled samples.

### 🧠 Phase 2 – Model Training & Conversion
The intelligence layer was forged in a Python environment using a Random Forest architecture.
- **Process:** Data cleaning, feature scaling, and hyperparameter tuning.
- **TinyML Export:** The model was ported to C++ code using `micromlgen` to fit the ESP32’s memory footprint.

### ⚡ Phase 3 – TinyML Deployment
The "Brain" was transplanted into the microcontroller to enable offline inference.
- **Process:** Integration of `model.h` into the Arduino/C++ firmware.
- **Result:** The ESP32 classifies compost states locally without cloud dependency.

### ☁️ Phase 4 – MQTT Connectivity & Sync
Establishing the "Sync" through bidirectional communication.
- **Process:** Implementing `PubSubClient` to stream JSON telemetry and subscribe to command topics.
- **Broker:** HiveMQ Cloud (Public/Free tier).

### 🎨 Phase 5 – Streamlit Dashboard
The final Command Center for remote perception and intervention.
- **Process:** Developing a web-based UI that listens to the MQTT stream.
- **Features:** Real-time metrics, line charts, and remote hardware trigger buttons.

---

## 📊 Results Summary

The system was evaluated on its ability to correctly identify compost states in real-time. The **Random Forest** model provided the best balance between accuracy and memory efficiency.

| Metric | Target | Result (Testing) |
| :--- | :--- | :--- |
| **Model Accuracy** | > 90.0% | **96.4%** |
| **Inference Latency** | < 100ms | **~12ms (Edge)** |
| **State Detection (Ready)** | Precision | **98.0% (Methane Spike)** |
| **Sync Latency** | Real-time | **< 2.5s (MQTT)** |

> **Key Success:** The model demonstrates high resilience to "sensor noise" by prioritizing the interaction between humidity and methane levels rather than simple thresholds.

---


## 🔥 Key Insights

- **Edge Intelligence = Autonomy:** By processing sensor data locally, the system remains operational even during network failures, ensuring the compost process is always supervised.
- **Methane as a Bio-Indicator:** The project proves that methane spikes are the most reliable indicator of "Ready" compost, but only when cross-referenced with stabilized temperature drops.
- **Resource Constraints Breed Efficiency:** Porting a Python-trained model to C++ requires strict memory management, illustrating that powerful AI doesn't always need "big" hardware.
- **Bidirectional Sync:** The "Sync" aspect proves that IoT isn't just about reading data, but about creating a closed-loop system where the user can intervene from anywhere.

---

## 📁 Artifacts

- **Dataset:** `python_edge/data/compost_data.csv` (Raw empirical data).
- **Visualization:** `python_edge/plots/` (Cluster analysis and training curves).
- **The Brain:** `esp32_firmware/src/model.h` (Optimized Random Forest C++ code).
- **Firmware:** `esp32_firmware/src/main.cpp` (Production-ready inference & MQTT engine).

---

## 🪶 Philosophy

> *Sia-Compost-Sync* is built on the belief that nothing in nature is truly "waste" - only misplaced resources.  
> By giving intelligence to a biological process, we transition from being passive observers of nature to active collaborators.  
> To monitor the earth with "Sia" is to respect the transformation of the old into the new.

---

## 🧑‍💻 Author & Maintainer
    d-senyaka
  <img width="100" height="125" alt="image" src="https://github.com/user-attachments/assets/365110f1-44b2-4733-a202-4d1ea5658bf1" />

Data Science Intern · Edge AI Researcher · IoT Enthusiast  

---

## ⚖️ License
This project is released under the **MIT License**.  
Feel free to use, modify, and distribute it for a greener planet.

---

## ⭐ Acknowledgements
- Inspired by the principles of circular economy and sustainable agriculture.
- Developed with a focus on the intersection of Machine Learning and Environmental Science.

> *“To perceive the earth's pulse through data is to understand the language of life.”*
