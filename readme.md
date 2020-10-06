# GreenHouse Automation Project

This Project aims to automate the functions/operations/tasks in a greenhouse.

## **Hardware**
### **MCU**
ST Nucleo-64 Board ([available here](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)) is used which has an STM32F446RE microcontroller. It is a 32-bit ARM Cortex-M4 based MCU from ST Microelectronics.

### **Switches & Relays**
Two-way microswitches and SPDT Relays are used for manual control of various things.

## **Software**

**IDE used:** System Workbench for STM32 ([available here](https://www.st.com/en/development-tools/sw4stm32.html))

![software_stack](https://drive.google.com/file/d/1kygPza72iMTBUeCbkeIeD2bGRs0y-__Z/view?usp=sharing)

| Software Stack |
| :--: |
| <br/> **Firmware Layer** <br/> ( ST Standard Peripheral Library ) |
| <br/> **Operating System Layer** <br/> ( FreeRTOS ) |
| <br/> **Networking Layer** <br/> _Networking abilities will be added later_ |
| <br/> **Application Layer** |


All of the application layer code is structured within the following files:-
| File | Contents |
|------|---------|
| ghRTOS.h | Std Library Files, Architecture-specific files, and prototypes of generic & MCU-specific hardware configuration functions |
| ghRTOS.c | Definitions of functions declared in ghRTOS.h |
| ghAutomation.h | Configuration APIs for the hardware used in automation |
| ghAutomation.c | Definition of functions declared in ghAutomation.h |
| ghNetwork.h | Configuration APIs for the hardware used for communication & networking purposes |
| ghNetwork.c | Definition of functions declared in ghNetwork.h|
| main.c | Program execution flow |

### Naming Convention
**Variables**
| Data Type | Prefix | Comments |
|:-----------|:--------:|----------|
| uint32_t | ul | 'u' denotes "unsigned" and 'l' denotes "long" |
| uint16_t | us | 'u' denotes "unsigned" and 's' denotes "short" |
| uint8_t | uc | 'u' denotes "unsigned" and 'c' denotes "char" |
| int | i | 'i' denotes "int" |
| char | c | 'c' denotes "char" |
| float | f | 'f' denotes "float" |
| void | v | 'v' denotes "void" |
| user_defined_data_type | x | . |
| | ----------


All of the variables follow **Snake_Case** afterwards.  
Pointer types are prefixed with a 'p' followed by the data-type-prefix followed by the variable name.  

Few examples are given below:
```C
uint32_t ulToken_Count;
float fTemperature = 0;
char cUART_Tx_buffer;
void* pvBuffer;
```

**Functions**

Function names are prefixed with the data type of their respective return values.  
All prefix(s) are same as described in the previous section.  

Example:
```C
int iFun1(...)
{
    int x;
    .
    .
    return x;
}

char* pcFun2(...)
{
    .
    .
    .
    return &message;  // message is a character array defined globally
}
```

**Macros**

### Formatting Styles

**Indentation**: Code is indented with a tab size of 4.  
**Braces**:  

```C
int foo(...)
{
    // Opening and Closing braces follow this style.
    // Code within the block appears one "tab" succeeding the column of the braces
}
```