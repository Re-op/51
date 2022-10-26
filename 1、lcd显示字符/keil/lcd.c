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

void wcmd(unsigned char cmd)//дָ���
{
	LCD1602_E = 0;     					
	LCD1602_RS = 0;	   				
	LCD1602_RW = 0;	   					
	
	LCD1602_DATAPINS = cmd;     	//д������ָ��
	delay(1);							

	LCD1602_E = 1;	          			
	delay(5);	  						//��ʱ������Ļ��Ӧ������
	LCD1602_E = 0;
}

void wdat(unsigned char dat)
{
	LCD1602_E = 0;						//�⼸��ָ���ǰ���1602�ֲ�����
	LCD1602_RS = 1;						
	LCD1602_RW = 0;						

	LCD1602_DATAPINS = dat; 			//д����������
	delay(1);

	LCD1602_E = 1;   					
	delay(5);   						
	LCD1602_E = 0;
}
	
void lcd_init()
{
 	wcmd(0x01);  //����
	wcmd(0x0c);   //��ʾ���������ر�
	wcmd(0x02);  //���Ӧ���ǲο�1602�ֲ����ģ��еĳ���1602��Ļ����Ҫ���
	wcmd(0x06);   //���ֲ�������ַ�Զ�+1
	wcmd(0x38);   //16*2��ʾ��5*7����8λ���ݽӿ�
}










