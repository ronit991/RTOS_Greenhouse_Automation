# GreenHouse Automation Project

This Project aims to automate the functions/operations/tasks in a greenhouse.
Major tasks:
* Monitor and maintain the desired temperature in the greenhouse.
* Monitor and maintain the desired humidity/moisture in the greenhouse.
* Maintain appropriate level in the water reservoir.
* Automate the irrigation process based on soil moisture.
* Notify the owner in case of fire, excessive wind, and crop damage due to excess IR/UV Light.
* Sync everything with a cloud server.

## **Hardware**
### **MCU**
ST Nucleo-64 Board ([available here](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)) is used which has an STM32F446RE microcontroller. It is a 32-bit ARM Cortex-M4 based MCU from ST Microelectronics.

### **Switches & Relays**
Two-way microswitches and SPDT Relays are used for manual control of various things.

### **Temperature Sensor**
Not yet finalised... will be using DHT11 meanwhile for initial development and testing.

### **Humidity Sensor**
Not yet finalised... will be using DHT11 meanwhile for initial development and testing.

### **Soil Moisture Sensor**
Capacitive Sensor. \< More details need to be added here \>

## **Software**

**IDE used:** System Workbench for STM32 ([available here](https://www.st.com/en/development-tools/sw4stm32.html))

| Software Stack |
| :--: |
| <br/> **Firmware Layer** <br/> ( ST Standard Peripheral Library ) <br/> .|
| <br/> **Operating System Layer** <br/> ( FreeRTOS ) <br/> .|
| <br/> **Networking Layer** <br/> _Networking abilities will be added later_ <br/> .|
| <br/> **Application Layer** <br/> .|


All of the application layer code is structured within the following files:-
| File             | Contents                                                                                                                  |
|------------------|---------------------------------------------------------------------------------------------------------------------------|
| ghRTOS.h         | Std Library Files, Architecture-specific files, and prototypes of generic & MCU-specific hardware configuration functions |
| ghRTOS.c         | Definitions of functions declared in ghRTOS.h                                                                             |
| ghAutomation.h   | Configuration APIs for the hardware used in automation                                                                    |
| ghAutomation.c   | Definition of functions declared in ghAutomation.h                                                                        |
| ghNetwork.h      | Configuration APIs for the hardware used for communication & networking purposes                                          |
| ghNetwork.c      | Definition of functions declared in ghNetwork.h                                                                           |
| main.c           | Program execution flow                                                                                                    |

For more details of code and contribution guidelines, refer to _CodeStructure.md_ file.