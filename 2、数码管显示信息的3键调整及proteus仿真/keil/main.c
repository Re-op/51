#include "reg52.h"

#define uchar unsigned char
#define uint unsigned int



sbit AN2=P3^3;
sbit AN3=P3^4;
sbit AN1=P1^5;

#define AN1PIN 0x20
#define AN2PIN 0x10
#define AN3PIN 0x08
#define NONPIN 0xff
#define KEYMASK (AN1PIN+AN2PIN+AN3PIN)




uchar code SegCode[]={0xaf,0xa0,0xc7,0xe5,0xe8,0x6d,0x6f,0xa1,0xef,0xe9,0xeb,0x6e,0x0f,0xe6,0x4f,0x4b,0xc8,0x10,0x00,0x40};
uchar code PlaceCode[]={0x04,0x20,0x10,0x08};
uchar DispBuf[]={4,3,2,1};
uchar Key_Value=0;
uchar Key_Count=0;
uchar Key_Down=0;
uchar StateNum;
char code reserve[3]_at_ 0x3b;




void DelayMs(uint n){
	uchar j;
	while(n--){
		for(j=0;j<113;j++);
	}
}

void BufToSeg(){
	uchar i;
	for(i=0;i<4;i++){
		if(i==StateNum)
			P0=SegCode[DispBuf[i]]|0x10;
		else P0=SegCode[DispBuf[i]];
		P2=PlaceCode[i];
		DelayMs(2);
		P2&=0xc3;
	}
}


uchar ReadKey(){
	if(AN1==0)
		return ~AN1PIN;
	else if(AN2==0)
		return ~AN2PIN;
	else if(AN3==0)
		return ~AN3PIN;
	else
		return NONPIN;
}


uchar Key_Scan(){
	uchar temp,Key_Num=0;
	temp=KEYMASK & ReadKey();

	if(temp!=KEYMASK){
		Key_Count++;
		if(Key_Count==10)	{
			Key_Down=1;
			Key_Value=temp;
		}
	}
	else{
		Key_Count=0;
		if(Key_Down==1){
			Key_Down=0;
			switch(Key_Value){
				case 0x18:Key_Num=1;break;
				case 0x28:Key_Num=2;break;
				case 0x30:Key_Num=3;break;
				default:break;
			}
		}
	}
	return(Key_Num);
}


void main(void)
{
	uchar temp;
	while(1)
	{
		temp=Key_Scan();
		switch(temp)
		{
			case 1:
			if(++StateNum>3)
			StateNum=0;
		break;
			case 2:
		  if(++DispBuf[StateNum]>15)
		    DispBuf[StateNum]=0;
		break;
			case 3:
		if(--DispBuf[StateNum]>15)
		  DispBuf[StateNum]=15;
		  break;
			default:
		  break;
		}
		BufToSeg();
		DelayMs(5);
	}
}

