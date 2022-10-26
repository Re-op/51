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
	LCD1602_E = 0;     					//使能
	LCD1602_RS = 0;	   					//选择发送命令
	LCD1602_RW = 0;	   					//选择写入
	
	LCD1602_DATAPINS = cmd;     		//放入命令
	delay(1);							//等待数据稳定

	LCD1602_E = 1;	          			//写入时序
	delay(5);	  						//保持时间
	LCD1602_E = 0;
}

void wdat(unsigned char dat)
{
	LCD1602_E = 0;						//使能清零
	LCD1602_RS = 1;						//选择输入数据
	LCD1602_RW = 0;						//选择写入

	LCD1602_DATAPINS = dat; 			//写入数据
	delay(1);

	LCD1602_E = 1;   					//写入时序
	delay(5);   						//保持时间
	LCD1602_E = 0;
}
	
void lcd_init()
{
 	wcmd(0x01);  //开显示
	wcmd(0x0c);  //开显示不显示光标
	wcmd(0x02);  //写一个指针加1
	wcmd(0x06);  //清屏
	wcmd(0x38);  //设置数据指针起点
}










