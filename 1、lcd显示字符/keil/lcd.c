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

void wcmd(unsigned char cmd)//写指令函数
{
	LCD1602_E = 0;     					
	LCD1602_RS = 0;	   				
	LCD1602_RW = 0;	   					
	
	LCD1602_DATAPINS = cmd;     	//写入具体的指令
	delay(1);							

	LCD1602_E = 1;	          			
	delay(5);	  						//延时，怕屏幕反应不过来
	LCD1602_E = 0;
}

void wdat(unsigned char dat)
{
	LCD1602_E = 0;						//这几条指令是按照1602手册来的
	LCD1602_RS = 1;						
	LCD1602_RW = 0;						

	LCD1602_DATAPINS = dat; 			//写入具体的数据
	delay(1);

	LCD1602_E = 1;   					
	delay(5);   						
	LCD1602_E = 0;
}
	
void lcd_init()
{
 	wcmd(0x01);  //清屏
	wcmd(0x0c);   //显示器开，光标关闭
	wcmd(0x02);  //这句应该是参考1602手册来的，有的厂家1602屏幕不需要这句
	wcmd(0x06);   //文字不动，地址自动+1
	wcmd(0x38);   //16*2显示，5*7点阵，8位数据接口
}










