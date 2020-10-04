# GreenHouse Automation Project
using STM32 Microcontroller and FreeRTOS



This Project aims to automate the functions/operations/tasks in a greenhouse.

## **Hardware**
This section describes the hardware used for developing the prototype of this project.
### **MCU**
ST Nucleo-64 Board ([available here](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)) is used which has an STM32F446RE microcontroller. It is a 32-bit ARM Cortex-M based MCU from ST Microelectronics.

### **Switches & Relays**
Two-way microswitches and SPDT Relays are used for manual control of various things.

## **Software**

**IDE used:** System Workbench for STM32 ([available here](https://www.st.com/en/development-tools/sw4stm32.html))

**Firmware Layer:** Standard Peripheral Library from ST  
**Operating System Layer:** FreeRTOS  
**Networking Layer:** _Networking abilities aren't added yet in the project_  
**Application Layer:**

All of the application layer code is structured within the following files:-
| File | Contents |
|------|---------|
| ghRTOS.h | |
| ghRTOS.c | |
| ghAutomation.h | |
| ghAutomation.c | |
| ghNetwork.h | |
| ghNetwork.c | |
| main.c | |

### Naming Convention
**Variables**
| Data Type | Prefix | Comments |
|-----------|--------|----------|
| uint32_t | ul_ | 'u' denotes "unsigned" and 'l' denotes "long" |
| uint16_t | us_ | 'u' denotes "unsigned" and 's' denotes "short" |
| uint8_t | uc_ | 'u' denotes "unsigned" and 'c' denotes "char" |
| int | i_ | 'i' denotes "int" |
| char | c_ | 'c' denotes "char" |
| float | f_ | 'f' denotes "float" |

All of the variables follow **snake_case** afterwards.  
Few examples are given below:
```C
uint32_t ul_Token_Count;
float f_Temperature = 0;
char c_UART_Tx_buffer;
```

**Functions**

**Macros**

