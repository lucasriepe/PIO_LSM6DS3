/*
  LSM6DS3 - Simple Gyroscope

  This example reads the acceleration values from the LSM6DS3
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  This example code is in the public domain.
*/

#include "PIO_LSM6DS3.hpp"

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  printHeader("Temperature sensor sample rate", IMU.temperatureSampleRate(),
              "Temperature reading in degrees C", "T");

  printHeader("Gyroscope sample rate", IMU.gyroscopeSampleRate(),
              "Gyroscope in degrees/second", "X\tY\tZ");

  printHeader("Accelerometer sample rate", IMU.accelerationSampleRate(),
              "Acceleration in g's", "X\tY\tZ");
}

// Prints a sensor header: sample rate, unit label and column names
void printHeader(const char* rateLabel, float sampleRate,
                 const char* unitLabel, const char* columns) {
  Serial.print(rateLabel);
  Serial.print(" = ");
  Serial.print(sampleRate);
  Serial.println(" Hz");
  Serial.println();
  Serial.println(unitLabel);
  Serial.println(columns);
}

// Prints a 3-axis vector as tab-separated values
void printVector(float x, float y, float z) {
  Serial.print(x);
  Serial.print('\t');
  Serial.print(y);
  Serial.print('\t');
  Serial.println(z);
}

void loop() {
  float t;

  if (IMU.temperatureAvailable()) {
    // after IMU.readTemperature() returns, t will contain the temperature reading
    IMU.readTemperature(t);

    Serial.println(t);
  }

  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);
    printVector(x, y, z);
  }

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    printVector(x, y, z);
  }
}
