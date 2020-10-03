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

// Continuous
TaskHandle_t xCT1_H_SyncWithServer;

// Occasional
TaskHandle_t xOT1_H_UpdateSensorData;
TaskHandle_t xOT2_H_MonitorTankLevel;


// Rare -> Event Triggered
/*TaskHandle_t xRT1_H_Doorbell;
TaskHandle_t xRT2_H_StaircaseLights;
TaskHandle_t xRT3_H_NightLight;
TaskHandle_t xRT4_H_Curtains;
*/

/* ********************************************* Interrupt Functions *********************************************** */


/* ************************************************ Task Functions ************************************************* */

// Continuous
void vCT1_SyncWithServer(void* param);

// Occasional
void vOT1_UpdateSensorData(void* param);
void vOT2_MonitorTankLevel(void* param);

// Rare / Event_Triggered
void vRT1_ControlTemperature(void* param);
void vRT2_ControlHumidity(void* param);
void vRT3_ControlLight(void* param);
void vRT4_FillWaterTank(void* param);



/* ************************************************ User Functions ************************************************* */
void blinkLED(void);


/* ************************************************** User Types *************************************************** */
typedef struct{
	float temperature;
	float humidity;
	float soilMoisture;
}SensorDataType;
// Variable of this structure is declared in the global space.

/* ************************************************* Global Space ************************************************** */
char message[250];

SensorDataType SensorData;

/* ***************************************************** main ****************************************************** */
int main(void)
{
	SetupHardware();
	SetupAutomation();

	blinkLED();

	// Create Tasks
	xTaskCreate(vCT1_SyncWithServer,	"CT1: Sync Data with Server",  500, NULL, 1, &xCT1_H_SyncWithServer);

	xTaskCreate(vOT1_UpdateSensorData,	"OT1: Update Sensor Data",			500, NULL, 2, &xOT1_H_UpdateSensorData);
	xTaskCreate(vOT2_MonitorTankLevel,	"OT2: Monitor Water Tank Level",	500, NULL, 2, &xOT2_H_MonitorTankLevel);

	//xTaskCreate(vRT1_,			"RT1: ",	500, NULL, 3, &xRT1_H_);


	// Create Queues

	// Start Scheduler
	printMsg("\n\r Starting scheduler... \n\r");
	vTaskStartScheduler();

	while(1);
}



/* ******************************************** Task Function Definition ******************************************* */

// Continuous
void vCT1_SyncWithServer(void* param)
{
	//
}



// Occasional
void vOT1_UpdateSensorData(void* param)
{
	//
}



void vOT2_MonitorTankLevel(void* param)
{
	//
}



// Rare / Event-Triggered Tasks
void vRT1_ControlTemperature(void* param)
{
	//
}



void vRT2_ControlHumidity(void* param)
{
	//
}



void vRT3_ControlLight(void* param)
{
	//
}



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
