#ifndef _LCD_H
#define _LCD_H

#include <reg52.h> //��ʵ���п���ȥ�����ϸ��˵���ظ�������

#define LCD1602_DATAPINS P2 //������Ļ��д��������
sbit LCD1602_E=P1^0; //en�����ǿ���ʹ���źŵ�����
sbit LCD1602_RW=P1^1;//��/дģʽ��������
sbit LCD1602_RS=P1^2;//����/����ѡ������

void delay (unsigned int c);
void wcmd (unsigned char cmd);
void wdat (unsigned char dat);
void lcd_init();

#endif