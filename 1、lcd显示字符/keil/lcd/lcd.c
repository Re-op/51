#include "lcd.h"
void delay(unsigned int c)   
{
    unsigned char a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
    	
}

void wcmd(unsigned char cmd)
{
	LCD1602_E = 0;     					//ʹ��
	LCD1602_RS = 0;	   					//ѡ��������
	LCD1602_RW = 0;	   					//ѡ��д��
	
	LCD1602_DATAPINS = cmd;     		//��������
	delay(1);							//�ȴ������ȶ�

	LCD1602_E = 1;	          			//д��ʱ��
	delay(5);	  						//����ʱ��
	LCD1602_E = 0;
}

void wdat(unsigned char dat)
{
	LCD1602_E = 0;						//ʹ������
	LCD1602_RS = 1;						//ѡ����������
	LCD1602_RW = 0;						//ѡ��д��

	LCD1602_DATAPINS = dat; 			//д������
	delay(1);

	LCD1602_E = 1;   					//д��ʱ��
	delay(5);   						//����ʱ��
	LCD1602_E = 0;
}
	
void lcd_init()
{
 	wcmd(0x01);  //����ʾ
	wcmd(0x0c);  //����ʾ����ʾ���
	wcmd(0x02);  //дһ��ָ���1
	wcmd(0x06);  //����
	wcmd(0x38);  //��������ָ�����
}










