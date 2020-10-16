/*
 * MiniProject2.c
 *
 *  Created on: Jan 5, 2020
 *  Author: Micheal Onsy
 */

#include "ADC.h"
#include "LCD.h"
#include "TIMER.h"
#include "ExternalInterrupt.h"
uint16 g_u16ADCValue=0;
uint8 g_ExternalInterruptFlag =0;


void APP_vidADCProcess(void)
{
	g_u16ADCValue=ADC_GetADCValue();
}
void APP_vidExternalInterruptProcess(void)
{
	if(g_ExternalInterruptFlag==0)
	{
		SET_BIT(PORTB,PB1);
		CLEAR_BIT(PORTB,PB0);
		g_ExternalInterruptFlag=1;
	}
	else if(g_ExternalInterruptFlag==1)
	{
		SET_BIT(PORTB,PB0);
		CLEAR_BIT(PORTB,PB1);
		g_ExternalInterruptFlag=0;
	}
}
int main(void)
{
	/*
	 * Configuration of ADC
	 * */
	ADC_ConfigType ADC_Config={F_CPU_8,AREF,POLLING};
	ADC_VidInit( &ADC_Config );

	/*
	 * Configuration of ExternalInterrupt
	 * */
	ExternalInterrupt_ConfigType ExternalInterrupt={Interrupt1,RISING};
	ExternalInterrupt_VidInit(&ExternalInterrupt);
	ExternalInterrupt_setCallBack(APP_vidExternalInterruptProcess);
	DDRB|=(1<<PB0)|(1<<PB1);
	SET_BIT(PORTB,PB0);
	CLEAR_BIT(PORTB,PB1);


	PWM_VidInit();
	LCD_VidInit();
	LCD_VidWriteString("ADC Value = ");
	sei();
	while(1)
	{
		LCD_VidSetRowColumn(1,12);
		ADC_u16ReadChannal(0);
		if(ADC_Config.PollingOrInterrupt==0)
		{
			while(!(ADCSRA&(1<<ADIF)));
			SET_BIT(ADCSRA,ADIF);
			g_u16ADCValue=ADC_GetADCValue();
		}
		LCD_VidWriteNumber(g_u16ADCValue);
		PWM_VidTakeNumber(g_u16ADCValue);
	}
}
