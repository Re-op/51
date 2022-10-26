#ifndef _LCD_H
#define _LCD_H

#include <reg52.h>
#define LCD1602_DATAPINS P2
sbit LCD1602_E=P1^0;
sbit LCD1602_RW=P1^1;
sbit LCD1602_RS=P1^2;

void delay (unsigned int c);
void wcmd (unsigned char cmd);
void wdat (unsigned char dat);
void lcd_init();

#endif