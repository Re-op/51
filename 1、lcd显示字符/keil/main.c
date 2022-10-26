#include "reg52.h"
#include "lcd.h" 



unsigned char Disp[]="  2020101710  ";
unsigned char Disp_1[]="  2020101715 ";






int main(){
	unsigned char i;
	lcd_init();
	while(1){
		for(i=0;i<16;i++){
				wdat(Disp[i]);
			}
		wcmd(0x80+0x40);
		for(i=0;i<16;i++){
				wdat(Disp_1[i]);	
			}	
	}	
}