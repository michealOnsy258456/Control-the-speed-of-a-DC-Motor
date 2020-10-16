/*
 * LCD.h
 *
 *  Created on: Dec 29, 2019
 *      Author: micheal_onsy
 */

#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"
#include "Micro_Config.h"
#include "common_macros.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD HW Pins */
#define RS PD2
#define RW PD1
#define E  PD0
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD
#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

void LCD_VidInit(void);
void LCD_VidWriteCommand(uint8 a_command);
void LCD_VidWriteData(uint8 a_data);
void LCD_clearScreen(void);
void LCD_VidWriteString(const char *Str);
void LCD_VidWriteNumber (uint64 a_Number);
void LCD_VidSetRowColumn(uint8 a_Row,uint8 a_Column);




#endif /* LCD_H_ */
