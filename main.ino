#include <Wire.h>
#include "MAX30102.h" // Include library for MAX30102
#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_SENSOR_PIN 2  // Pin for temperature sensor
MAX30102 pulseSensor;     // MAX30102 object

// Temperature sensor setup
OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature tempSensor(&oneWire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize sensors
  if (!pulseSensor.begin()) {
    Serial.println("Pulse oximeter not found!");
    while (1);
  }
  tempSensor.begin();
  
  Serial.println("Sensors initialized!");
}

void loop() {
  float heartRate, SpO2;
  float bodyTemp;

  // Read data from the pulse oximeter
  if (pulseSensor.check() == true) {
    heartRate = pulseSensor.getHeartRate();
    SpO2 = pulseSensor.getSpO2();
  } else {
    heartRate = -1; // Error
    SpO2 = -1;      // Error
  }

  // Read data from the temperature sensor
  tempSensor.requestTemperatures();
  bodyTemp = tempSensor.getTempCByIndex(0);

  // Send data via Serial or MQTT
  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.print(", SpO2: ");
  Serial.print(SpO2);
  Serial.print(", Body Temp: ");
  Serial.println(bodyTemp);

  // Delay to prevent spamming
  delay(1000);
}
