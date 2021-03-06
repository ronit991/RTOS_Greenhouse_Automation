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
| int                       | l          | 'l' denotes "long"                             |
| short                     | s          | 's' denotes "short"                            |
| char                      | c          | 'c' denotes "char"                             |
| float                     | f          | 'f' denotes "float"                            |
| void                      | v          | 'v' denotes "void"                             |
| user_defined_data_type    | x          | .                                              |
| third_party_data_type     | x          | .                                              |
|---------------------------|------------|------------------------------------------------|


All of the variables follow **Snake_Case** afterwards.  
Pointer types are prefixed with a _'p'_ followed by the _data-type-prefix_ followed by the _variable-name_.  


**Array(s)**
* a\<_data-type-prefix_\>\<_variable-name_\> for normal arrays.
* ap\<_data-type-prefix_\>\<_variable-name_\> for array of pointers.

Few examples are given below:
```C
uint32_t ulToken_Count;
float fTemperature = 0;
char cUART_Tx_buffer;
void* pvBuffer;
SensorDataType axSensorData[100];     // "SensorDataType" is a user-defined structure
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

Task functions & Task handles of each category are named as \<_task-type-prefix_\>\<_task-name_\> in Snake_Case.

| Task Type        | Task Handle Prefix | TaskFunction Prefix |
|------------------|:------------------:|:-------------------:|
| Continuous Task  | xCT_              | vCT_               |
| Occassional Task | xOT_              | vOT_               |
| Rare Task        | xRT_              | vRT_               |

* 'x' is prefixed for task handles because it is a third-party data type (defined in FreeRTOS kernel).
* 'v' is prefixed for task functions as FreeRTOS tasks never end, hence return void.
* All task functions have _" void* param "_ as the parameter.

Examples:
```C
TaskHandle_t xCT_Sync_With_Server;
TaskHandle_t xOT_Update_Sensor_Data;

void vCT_SyncWithServer(void* param);
void vOT_UpdateSensorData(void* param);
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

**Conditional Statements:** Conditional statements use the following style
```C
// if-statement
if(condition)
{
    // some code
}
else if(condition)
{
    // some code
}
else
{
    // some code
}
// Tip: Compilers may or may not throw an error on dangling else. To avoid problems, always use braces to specify the blocks.

// switch-statement
switch(var)
{
    // single-line statements'  style
    case c1:    some_code;         break;
    case c2:    some_other_code;   break;  // all break(s) should be aligned properly for single-line statements
    // multi-line statements' style
    case c3:    some_code;
                some_other_code;
                yet_another_code;
                break;

    case c4:    some_code;                  // break is omitted here for so & so reason.
                                            // Always place a comment for fall-through like this.
    case c5:    some_other_code;    break;

    default:    the_default_code;
                the_default_code;
                break;
}

// ternary/conditional operator
// A General Rule:  Use ternary operator only while setting a value, or execute single-line commands
//                  Use if-statments for everything else.

// Use case 1
int startPoint = (num%2 == 0) ? 0 : 1;
// Use case 2
(temperature > threshold) ? vRing_Alarm() : sleep();
```

**Structures:** All structure types should be defined in the following style
```C
typedef struct
{
    // data members
}struct_name;
```
