# GreenHouse Automation Project - Code Structure

This document gives an overview of the project code and the style used for the same.  
Any contribution to the projects' code, should follow the existing style and the guidelines.

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


### Naming Convention

**Variables**

| Data Type                 | Prefix     | Comments                                       |
|:--------------------------|:----------:|------------------------------------------------|
| uint32_t                  | ul         | 'u' denotes "unsigned" and 'l' denotes "long"  |
| uint16_t                  | us         | 'u' denotes "unsigned" and 's' denotes "short" |
| uint8_t                   | uc         | 'u' denotes "unsigned" and 'c' denotes "char"  |
| int                       | i          | 'l' denotes "long"                             |
| short                     | s          | 's' denotes "short"                            |
| char                      | c          | 'c' denotes "char"                             |
| float                     | f          | 'f' denotes "float"                            |
| void                      | v          | 'v' denotes "void"                             |
| user_defined_data_type    | x          | .                                              |
| third_party_data_type     | x          | .                                              |
|---------------------------|------------|------------------------------------------------|


All of the variables follow **Snake_Case** afterwards.  
Pointer types are prefixed with a _'p'_ followed by the _data-type-prefix_ followed by the _variable-name_.  

Convention for arrays **isn't decided yet.** Any suggestions are welcome.

Few examples are given below:
```C
uint32_t ulToken_Count;
float fTemperature = 0;
char cUART_Tx_buffer;
void* pvBuffer;
```

**Functions**

* Function names are prefixed with the _data-type_ of their respective _return-values_.  
* Static functions (excluding those defined in main.c) have a prefix _"prv"_ followed by the function name. These functions do not have a _return-type-prefix_ as they aren't meant to be called from the outside world.

Example:
```C
int lFun1(...)
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
    return message;  // message is a character array defined globally
}
```

**Macros**  
To be decided.

**Task Functions & Task Handles**  
So far, tasks have been categorised into the following:-
1. Continuous Tasks
    * These tasks run continuously and are kept at the lowest priority (1).
2. Occasional Tasks
    * These tasks run periodically, and are blocked otherwise.
    * Priority of such tasks is 2.
3. Rare Tasks
    * These are the tasks that are short & run rarely.
    * Most of these are interrupt triggered and hence kept at the highest priority (3).

Task functions & Task handles of each category are named as \<_task-type-prefix_\>\<index/number\>\<task-name\> in Snake_Case.

| Task Type        | Task Handle Prefix | TaskFunction Prefix |
|------------------|:------------------:|:-------------------:|
| Continuous Task  | xCTn_              | vCTn_               |
| Occassional Task | xOTn_              | vOTn_               |
| Rare Task        | xRTn_              | vRTn_               |

* 'x' is prefixed for task handles because it is a third-party data type (defined in FreeRTOS kernel).
* 'v' is prefixed for task functions as FreeRTOS tasks never end, hence return void.
* All task functions have " void* param " as the parameter.
* 'n' in the above table represents index of the task (category-wise).

Examples:
```C
TaskHandle_t xCT1_Sync_With_Server;

TaskHandle_t xOT1_Update_Sensor_Data;
TaskHandle_t xOT2_Monitor_Tank_Level;

void vCT1_SyncWithServer(void* param);

void vOT1_UpdateSensorData(void* param);
```

### Formatting Styles

**Indentation**: Code is indented with 4 spaces. All occurences of "tab" in this document refer to 4 spaces and **not** the tab ASCII character unless specified otherwise. All indentation should be in multiples of 4 spaces.

**Braces**:  

```C
int foo(...)
{
    // Opening & Closing braces of functions, loops, or any other block of code follow this style.
    // Code within the block appears one "tab" (4 spaces) succeeding the column of the braces
    for(int i = 0; i < 10; i++)
    {
        // some code
    }
}
```

**Structures:** All structure types should be defined in the following style
```C
typedef struct
{
    // data members
}struct_name;
```
