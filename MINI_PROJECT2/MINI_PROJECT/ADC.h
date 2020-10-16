/*
 * ADC.h
 *
 *  Created on: Jan 5, 2020
 *      Author: Micheal Onsy
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Clock;

typedef enum
{
	AREF,AVCC,Reserved,InternalVoltage
}ADC_ChooseVoltage;
typedef enum
{
	POLLING,INTERRUPT
}ADC_POLLORINTER;

typedef struct
{
	ADC_Clock clock;
	ADC_ChooseVoltage volt;
	ADC_POLLORINTER PollingOrInterrupt;

}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_VidInit(const ADC_ConfigType * Cofig_Ptr );

void ADC_setCallBack(void(*a_ptr)(void));

uint16 ADC_GetADCValue(void);

void  ADC_u16ReadChannal(uint8 a_channalNum);


#endif /* ADC_H_ */
