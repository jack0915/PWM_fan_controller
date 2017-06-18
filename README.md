# PWM_fan_controller
[![software version](https://img.shields.io/badge/software%20-v0.6-green.svg)](https://github.com/jack0915/PWM_fan_controller)
[![hardware version](https://img.shields.io/badge/hardware-v0.0-yellow.svg)](https://github.com/jack0915/PWM_fan_controller)
[![Author](https://img.shields.io/badge/POWER%20BY-Jack%20Liang-blue.svg?)](https://github.com/jack0915/PWM_fan_controller)

****
## Project description
A smart fan controller use a STM32 MCU to cooling a LED light . The controller have 3 main function.   
1.A GPIO generate a 25KHz PWM signal to control the fan speed.   
2.The fan speed increase with temperature increasing.   
3.When the temperature over 80 degress celsius, a buzzer sound. When the tmeperature over 100 degress celsius, the LED light power will be cut off  

update on 16th May,2017
****
The NTC temperature has been read correctly. the DS18B20 digital sensor use to calibrate the NTC temperature. Due to the lookup table only have 1 degree accuracy, the NTC temperature lower than DS18B20 2 degrees. 
****
In this application, the temperature does not need a high accuracy.
****
Further job would update the lookup table and expand the array. The interpolation algorithm can also increase the accuracy.
****

****
reference
http://www.petervis.com/electronics%20guides/cpu%20fan%20tacho/cpu%20fan%20tacho.html   
