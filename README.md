# Real-Time-Health-Monitoring-System
The Real-Time Health Monitoring System is a wearable IoT device that monitors key health metrics such as heart rate, body temperature, and blood oxygen levels. The system streams the data in real time to a user-friendly dashboard for visualization and analysis, making it ideal for remote health monitoring and wellness tracking.

---

## Features
- **Real-Time Monitoring**: Heart Rate, Body Temperature, Blood Oxygen Levels (SpO2)
- **User-Friendly Dashboard**: Displays health Metrics 
- **Alerts for Abnormal Health Perameters**
- **Historical Data Logging**
- **Wireless Data Logging using WiFi/Bluetooth** 
- **Cross Platform Support**: Accessible through desktop or mobile browser

---

## Hardware Requirements 
- **Microcontroller** (ESP32, Raspberry Pi or Arduino)
- **Pulse Oximeter** (MAX30102 or MAX30100)
- **Temperature Sensors** (DS18B20 or LM35)
- **Breadboard**
- **Power Source** (battery pack or USB)
- **Resistors, Wires, Connectors**

---

## Software Requirements
- Python 3.x
- Arduino IDE
- **Programming Languages**: Pyhton, Arduino (C/C++), HTML, JavaScript
- **Libraries**
  -Python: `flask`, `matplotlib`, `pandas`
  -Arduino: `Wire.h`, `Adafruit_Sensor.h`, `DallasTemperature.h`, `MAX30102.h`
- **MQTT (Message Queuing Telemetry Transport)**: for Wireless Communication

---

## Project Workflow
1. **Hardware Configuration**
   - Connect the sensors to the microcontroller as per their respective pin configurations.
   - Power the microcontroller using a USB or battery pack.

2. **Write Firmware**
   - Program the microcontroller to read sensor data.
   - Use MQTT or serial communication to send the data to the server.
  
3. **Develop Backend**
   - Create a Flask application to receive data from the microcontroller.
   - Process and store the data in a local database or CSV file.

4. **Build Frontend Dashboard**
   - Use Flask templates or JavaScript (e.g., Chart.js) to display real-time health metrics.
   - Add historical data visualization and alerts.

5. **Test System**
   - Test hardware connections, data transmission, and dashboard functionality.
   - Adjust thresholds for alerts based on test data.
  
---

## How To Run
1. **Clone Repository**
   ```bash
   git clone https://github.com/yourusername/real-time-health-monitoring.git
   cd real-time-health-monitoring
   ```

2. **Set Up Hardware**

3. **Install Dependencies**
   ```bash
   pip install -r requirements.txt
   ```

4. **Run Backend Server**
   ```bash
   python app.py
   ```

5. **Upload Microcontroller Code**
   - Open `firmware.ino` in the Arduino IDE, configure the Wi-Fi credentials, and upload the code to your microcontroller.
  
6. **Access Dashboard**
   - Open your browser and go to `http://localhost:5000`.
  
---

## Outputs
- **Real-Time Dashboard**: Displays live data for heart rate, body temperature, and SpO2.
- **Alerts**: Notifies users if any health metric exceeds predefined thresholds.
- **Historical Data** : Visualizations of trends over time (line graphs, bar charts, etc.).

---

## Acknowledgments 
This project was inspired by the increasing need for remote health monitoring solutions. 
Special thanks to:
 - **Open-Source Libraries**: `Flask`, `matplotlib`, `Adafruit Sensor Libraries`.
 - The IoT and maker community for guidance and support.




