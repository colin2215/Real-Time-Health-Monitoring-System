from flask import Flask, render_template, jsonify
import serial
import threading
import time

app = Flask(__name__)

# Global variables for storing sensor data
data = {"heart_rate": 0, "spO2": 0, "body_temp": 0}

# Serial communication setup (replace with your port)
SERIAL_PORT = "/dev/ttyUSB0"  # Update for your system (e.g., COM3 for Windows)
BAUD_RATE = 9600

def read_serial():
    global data
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    while True:
        try:
            line = ser.readline().decode("utf-8").strip()
            parts = line.split(", ")
            if len(parts) == 3:
                data["heart_rate"] = float(parts[0].split(": ")[1])
                data["spO2"] = float(parts[1].split(": ")[1])
                data["body_temp"] = float(parts[2].split(": ")[1])
        except:
            continue

# Run the serial reader in a separate thread
thread = threading.Thread(target=read_serial)
thread.daemon = True
thread.start()

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/data")
def get_data():
    return jsonify(data)

if __name__ == "__main__":
    app.run(debug=True)
