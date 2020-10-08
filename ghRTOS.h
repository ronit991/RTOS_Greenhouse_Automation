#ifndef ghRTOS_H
#define ghRTOS_H

#ifdef __cplusplus
 extern "C" {
#endif

 // Standard Library files
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>


 // Architecture/System Specific Stuff
 #include "stm32f4xx.h"
 #define __DWT_CYCCNT *((uint32_t*)0xE0001004)
 extern uint32_t CYCCNT_OVERFLOW_COUNTS[2];

 #define ghSystemClock 16000000U

 // FreeRTOS Library files
 #include "FreeRTOS.h"
 #include "task.h"
 #include "timers.h"
 #include "queue.h"
 #include "semphr.h"


 // Flags
 #define False		0
 #define True		1

 #define Set		True
 #define Clear		False

 #define Yes		True
 #define No			False


 // Setup MCU and Board Specific Peripherals
 /* Setup MCU and Board Specific Peripherals
  * These functions are defined in the ghRTOS.c file and are written here just for reference.
  * DO NOT un-comment the following lines:

     static void prvSetupHW(void);
     static void prvSetupNucleoButtonAndLED(void);
     static void prvSetupUART(void);
 */

 // Print a message over UART
 void printMsg(char *msg);


 // Get system up-time in milliseconds
 #define SysUpTime_ms ( (__DWT_CYCCNT/ghSystemClock)*1000 )
 /* Care should be taken while using the above macro. The DWT_CYCCNT register overflows every 4.5 minutes (approx) when
  * using a 16 MHz system clock.
  * While calculating time difference using this macro, in case the DWT_CYCCNT register overflows between the two time
  * instants, the difference will become negative, and can cause unwanted problems.
  * It is also possible that due to sufficient delay in the time_logging, the register overflows and the value becomes
  * greater than the previous time_stamp again. This will not make the difference to be negative but still create bugs
  * as the results will be highly inaccurate.
  *
  * In order to avoid problems:
  *  > Always check for negative time-difference
  *  > Use a variable for storing overflows when high time delay needs to be measured.
  * */



 // Configure Hardware used in the project
 void SetupHardware(void);


#ifdef __cplusplus
 }
#endif

#endif		// include guard ends here.
