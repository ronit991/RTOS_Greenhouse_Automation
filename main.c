/* Write file and brief project description */
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
TaskHandle_t xCT_Sync_With_Server;

// Occasional
TaskHandle_t xOT_Update_Sensor_Data;
TaskHandle_t xOT_Monitor_Tank_Level;

// Rare -> Event Triggered
TaskHandle_t xRT_Control_Temperature;
TaskHandle_t xRT_Control_Humidity;
TaskHandle_t xRT_Irrigation;

/* ********************************************* Interrupt Functions *********************************************** */


/* ************************************************ Task Functions ************************************************* */

// Continuous
void vCT_Sync_With_Server(void* param);

// Occasional
void vOT_Update_Sensor_Data(void* param);
//void vOT_Monitor_Tank_Level(void* param);

// Rare / Event_Triggered
void vRT_Control_Temperature(void* param);
void vRT_Control_Humidity(void* param);
//void vRT_Control_Light(void* param);
//void vRT_FillWaterTank(void* param);
void vRT_Irrigation(void* param);



/* ************************************************ User Functions ************************************************* */
void vBlink_LED(void);



/* ************************************************** User Types *************************************************** */
typedef struct
{
	float fTemperature, fAvg_Temperature;
	float fHumidity, fAvg_Humidity;
	float fSoil_Moisture, fAvg_Soil_Moisture;
}SensorDataType;	// Variable of this structure is declared in the global space.



/* ************************************************* Global Space ************************************************** */

char acMessage[250];				// Message to be sent over UART to PC (for debugging purposes).

SensorDataType xSensor_Data;		// Holds the data from various sensors

// The following variables are used to calculate successive average of the sensor data
float fTemp_Sample_Sum = 0, fHumidity_Sample_Sum = 0, fSoil_Moisture_Sample_Sum = 0;
unsigned int ulNo_Of_Samples_temp = 0, ulNo_Of_Samples_humidity = 0, ulNo_Of_Samples_SoilMoisture = 0;
#define SamplingFreqHz 1
unsigned int ulSample_Timeout = 0;



/* ***************************************************** main ****************************************************** */
int main(void)
{
	vSetup_Hardware();
	vSetup_Automation();

	vBlink_LED();

	// Create Tasks
	xTaskCreate(vCT_Sync_With_Server,       "CT: Sync Data with Server",   500, NULL, 1, &xCT_Sync_With_Server);

	xTaskCreate(vOT_Update_Sensor_Data,     "OT: Update Sensor Data",      500, NULL, 2, &xOT_Update_Sensor_Data);
	//xTaskCreate(vOT_Monitor_Tank_Level, "OT: Monitor Water Tank Level",	500, NULL, 2, &xOT_Monitor_Tank_Level);

	xTaskCreate(vRT_Control_Temperature,    "RT: Control Temperature",     500, NULL, 3, &xRT_Control_Temperature);
	xTaskCreate(vRT_Control_Humidity,       "RT: Control Humidity",        500, NULL, 3, &xRT_Control_Humidity);
	xTaskCreate(vRT_Irrigation,             "RT: Irrigation",              500, NULL, 3, &xRT_Irrigation);

	// Start Scheduler
	vPrint_Msg("\n\r Starting scheduler... \n\r");
	vTaskStartScheduler();

	while(1);
}



/* ******************************************** Task Function Definition ******************************************* */

// Continuous
void vCT_Sync_With_Server(void* param)
{
	//
}



// Occasional
void vOT_Update_Sensor_Data(void* param)
{
	//
}



void vOT_Monitor_Tank_Level(void* param)
{
	//
}



// Rare / Event-Triggered Tasks
void vRT_Control_Temperature(void* param)
{
	//
}



void vRT_Control_Humidity(void* param)
{
	//
}



void vRT_Control_Light(void* param)
{
	//
}



void vRT_Irrigation(void* param)
{
    //
}
/* ******************************************* User Functions' Definition ****************************************** */
void vBlink_LED(void)
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



