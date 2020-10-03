/* Write file and brief project description*/
#include "ghRTOS.h"
#include "ghAutomation.h"
			
/* ********************************************** Flags & Misc. Alias ********************************************** */
#define CMD_ON		0x01
#define CMD_OFF		0x00

#define Auto		True
#define Manual		False

#define Active		True
#define NotActive	False

/* ************************************************* Task Handles ************************************************** */
TaskHandle_t xTH_Test;
// Continuous
/*TaskHandle_t xCT1_H_SyncWithServer;
*/

// Occasional
/*TaskHandle_t xOT1_H_FanSpeedControl;
TaskHandle_t xOT2_H_ApplianceControl;
*/

// Rare -> Event Triggered
/*TaskHandle_t xRT1_H_Doorbell;
TaskHandle_t xRT2_H_StaircaseLights;
TaskHandle_t xRT3_H_NightLight;
TaskHandle_t xRT4_H_Curtains;
*/

/* ********************************************* Interrupt Functions *********************************************** */
void FireAndTheftAlarm(void);
void vToggleAppliance( uint8_t ApplianceID, BaseType_t* pxHigherPriorityTaskWoken);


/* ************************************************ Task Functions ************************************************* */
void vT_Test(void* param);/*
// Continuous
void vCT1_SyncWithServer(void* param);

// Occasional
void vOT1_FanSpeedControl(void* param);
void vOT2_ApplianceControl(void* param);

// Rare -> Event Triggered
void vRT1_Doorbell(void* param);
void vRT2_StaircaseLights(void* param);
void vRT3_NightLight(void* param);
void vRT4_Curtains(void* param);
*/

/* ************************************************ User Functions ************************************************* */
void blinkLED(void);


/* ************************************************** User Types *************************************************** */


/* ************************************************* Global Space ************************************************** */
char message[250];



/* ***************************************************** main ****************************************************** */
int main(void)
{
	SetupHardware();
	SetupAutomation();

	blinkLED();

	// Create Tasks

	// Create Queues

	// Start Scheduler
	printMsg("\n\r Starting scheduler... \n\r");
	vTaskStartScheduler();

	while(1);
}



/* ******************************************** Task Function Definition ******************************************* */




/* ******************************************* User Functions' Definition ****************************************** */
void blinkLED(void)
{
	for(int i = 0; i<6; i++)
	{
		GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
		for(int j = 0; j<500000; j++)
		{
			// wait
		}
	}
}



/* ********************************************** Interrupt Handlers *********************************************** */



/* ****************************************** Interrupt Helper Functions ******************************************* */
