/*
 * ExternalInterrupt.c
 *
 *  Created on: Jan 5, 2020
 *      Author: micheal_onsy
 */

#include "ExternalInterrupt.h"
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static  void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(INT0_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}
ISR(INT1_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}
ISR(INT2_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

void ExternalInterrupt_VidInit(const ExternalInterrupt_ConfigType * ptr)
{
	if(ptr->interrupt==0)
	{
		MCUCR=(MCUCR & 0xFC)|(ptr->Edge);
		GICR|=(1<<INT0);
	}
	if(ptr->interrupt==1)
	{

		MCUCR=(MCUCR & 0xF3 )|((ptr->Edge)<<2);
		GICR|=(1<<INT1);
	}
	if(ptr->interrupt==2)
	{
		if(ptr->Edge)
			MCUCSR=(MCUCSR & 0xBF )|((0)<<6);
		else if(ptr->Edge==3)
			MCUCSR=(MCUCSR & 0xBF )|((1)<<6);

		GICR|=(1<<INT2);
	}
}
void ExternalInterrupt_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}
void ExternalInterrupt_setEdgeDetectionType(const ExternalInterrupt_ChooseInterrupt a_externalInterrupt,const ExternalInterrupt_EdgeType a_edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	if(a_externalInterrupt==0)
	{
		MCUCR=(MCUCR & 0xFC)|(a_edgeType);
	}
	if(a_externalInterrupt==1)
	{
		MCUCR=(MCUCR & 0xF3 )|(a_edgeType<<2);
	}
	if(a_externalInterrupt==2)
	{
		MCUCSR=(MCUCSR & 0xBF )|(a_edgeType<<6);
	}

}




