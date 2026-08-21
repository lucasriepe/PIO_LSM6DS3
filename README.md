# PIO_LSM6DS3 library

A library inspired by the [Arduino_LSM6DS3](https://www.arduino.cc/reference/en/libraries/arduino_lsm6ds3/) library.

## Why revise it?

The goal is to make it easier to change the I2C address and to remove the SPI support, keeping the library clearer and more focused.

## Changing the I2C address

By default, the sensor is accessed at the address `0x6B`. To use a different address, define `LSM6DS3_ADDRESS` **before** including the library:

```cpp
// add this to change the I2C address
#define LSM6DS3_ADDRESS  0x6B

#include "PIO_LSM6DS3.hpp"
```
