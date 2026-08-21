# PIO_LSM6DS3 library

A library inspired by the [Arduino_LSM6DS3](https://www.arduino.cc/reference/en/libraries/arduino_lsm6ds3/) library.

## Why revise it?

The goal is to make it easier to change the I2C address and to remove the SPI support, keeping the library clearer and more focused.

## Quick start

Add the library to your PlatformIO project and include it in your code:

```cpp
#include "PIO_LSM6DS3.hpp"

void setup() {
  Serial.begin(115200);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}
```

## Installing via Git URL

You can add this library to any PlatformIO project directly from the Git repository.

### Option 1: In `platformio.ini`

Add the repository URL to `lib_deps` in your project's `platformio.ini`:

```ini
[env]
lib_deps =
    https://github.com/lucasriepe/PIO_LSM6DS3.git
```

PlatformIO downloads and installs the library automatically on the next build.

### Option 2: Via the command line

```
pio lib install https://github.com/lucasriepe/PIO_LSM6DS3.git
```

### Option 3: Pin a specific version (optional)

Append a tag or commit hash to use a specific release:

```ini
[env]
lib_deps =
    https://github.com/lucasriepe/PIO_LSM6DS3.git@v0.1.0
```

## Changing the I2C address

By default, the sensor is accessed at the address `0x6B`. To use a different address, define `LSM6DS3_ADDRESS` **before** including the library:

```cpp
// add this to change the I2C address
#define LSM6DS3_ADDRESS  0x6B

#include "PIO_LSM6DS3.hpp"
```
