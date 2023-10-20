# The-M.T.H.R
The mthr is a temperature and relative humidity mesurement.
# The SHTC3
The shtc3 is the temperature and relative humidity sensor used in this mini-project.
It is capable of measuring temperatures from -40°C to 125°C and humidities from 0 to 100%.
# Objectives
The main objective of this project is to design a real-time environmental monitoring solution using an SHTC3 and a Raspberry Pi board.
The system must be capable of measure ambient temperature and humidity, and display the measured data on a web page.
# Purpose
The purpose of this project is to create a practical system for monitoring environmental conditions in a given area.
The data collected can be used to make decisions on adjustments to be made in a given environment, such as adding ventilation or air-conditioning, or to monitor ventilation or air-conditioning systems, or to monitor storage conditions for products
sensitive to humidity and temperature.
# Hardware and its role in the system
 * SHTC3 Sensor: This sensor measures temperature and relative humidity and sends data to the Raspberry Pi via the I2C bus.
 * I2C connection cables: The I2C connection cables link the sensor SHTC3 sensor to the Raspberry Pi.
 * The Raspberry Pi: The Raspberry Pi is used to run the software ventilation and heating control software. It receives data from the SHTC3 sensor via the      I2C link and sends commands to the and heating actuators.
 * Ventilation actuator (green LED): The ventilation actuator can be used used to control ventilation speed according to SHTC3 data. The green LED lights       up to indicate that ventilation is on. running.
 * Heating actuator (red LED): The heating actuator can be used to control temperature based on sensor data. The red LED lights up to indicate that             heating is on.
# displaying shtc3 data on the website.
This feature is not ready, that going to be ready in the coming days.(very soon).
