#ifndef ghAutomation_H
#define ghAutomation_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "ghRTOS.h"

#define ApplianceSwitchGPIOPort		GPIOB
// 14 Pins Available
#define TotalSwitchPins	14
extern uint16_t ApplSwitchPins[14];


#define ApplianceRelayGPIOPort		GPIOA
// 13 Pins Available
#define TotalRelayPins	13
extern uint16_t ApplRelayPins[13];

void vSetup_Automation(void);


#ifdef __cplusplus
	extern "C" {
#endif

#endif
