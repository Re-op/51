#ifndef _LCD_H
#define _LCD_H

#include <reg52.h> //其实这行可以去掉，严格的说是重复声明了

#define LCD1602_DATAPINS P2 //设置屏幕的写数据引脚
sbit LCD1602_E=P1^0; //en引脚是控制使能信号的引脚
sbit LCD1602_RW=P1^1;//读/写模式控制引脚
sbit LCD1602_RS=P1^2;//数据/命令选择引脚

void delay (unsigned int c);
void wcmd (unsigned char cmd);
void wdat (unsigned char dat);
void lcd_init();

#endif