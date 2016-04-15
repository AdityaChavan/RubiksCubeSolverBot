/*
 *
 * GccApplication6.cpp
 *
 * Created: 3/11/2016 1:40:51 PM
 * Author : Aditya
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/uart/uart.h>
#include<string.h>


int main(void)
{//all initializations
	int i,j,z,n;
	z=1;
i=0;
j=0;
DDRB|=0xFF;
DDRD|=0xFF;
DDRC|=0xFF;
TCCR1A|=(1<<WGM11)|(1<<COM1B1)|(1<<COM1A1)|(1<<COM1A0)|(1<<COM1B0);
TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11);
ICR1=19999;
	
	
	uart_init();
	while(1){
		
		
			while(1){i=0;
int grabbed=0;
			char input9[100]=" ";
		while(1) {input9[i] = uart_read();
			if (input9[i]=='.') 
			break;
			i++;}
		
		if(strcmp(input9,"Grab.")==0||strcmp(input9,"\nGrab.")==0)
		{//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		//code to hold cube in 2 brackets, add delay and then hold with other 2 brackets if you want
PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(5000);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(5000);
	
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		grabbed=1;
		uart_string("Grabbed.\n");
			}
		else if(strcmp(input9,"Ungrab.")==0||strcmp(input9,"\nUngrab.")==0)
			{//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		//all brackets go back,leaving cube
PORTC=0b00000000;//select linear RL and FB
			OCR1A=17200;
			OCR1B=17200;
			_delay_ms(5000);
	
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		grabbed=0;
		uart_string("Ungrabbed.\n");
		
			}
		else if(strcmp(input9,"Start.")==0||strcmp(input9,"\nStart.")==0)
			{
				
//if (grabbed==1)
//{
uart_string("Ready.\n");
goto right;
	//}
			}


else {uart_string("Invalid.\n");
	uart_num(strcmp(input9,"Start."));
	uart_string(input9);
}
		}

	
		//*******************************************************************************************//Right	
		right:
		i=0;
		char input6[100]=" ";
		
		while(1) {
			input6[i] = uart_read();//read char
			if (input6[i]=='.')
			break;
			i++;
			
		}
		
		
		
		if(strcmp(input6,"\nRight.")==0)
		{
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		//code to bring R to the top face

PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=17200;
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=18250;
		OCR1B=18250;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1B=17200;
		OCR1A=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1B=18250;
		OCR1A=18250;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);

		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		uart_string("Right.\n");
		}
		else {
		uart_num(strcmp(input6,"\nRight."));
			goto right;
		}
		//*******************************************************************************************//front
		front:
		i=0;
		char input1[100]=" ";
		
		
		while(1) {
			input1[i] = uart_read();//read char
			if (input1[i]=='.')
			break;
			i++;
			
		}
		
		
		if(strcmp(input1,"\nFront.")==0)
		{//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//code to bring F to the top face
		PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1A=17200;
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1B=18250;
		OCR1A=18250;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		uart_string("Front.\n");
		}	
		else goto front;
		//*******************************************************************************************//down
		down:
		i=0;
		char input2[100]=" ";
		
		
		while(1) {
			input2[i] = uart_read();//read char
			if (input2[i]=='.')
			break;
			i++;
			
		}
		
		if(strcmp(input2,"\nDown.")==0)
		{//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//code to bring D to the top face
			
PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=17200;
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=18250;
		OCR1B=18250;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
			
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		uart_string("Down.\n");
		}
		else goto down;
		//*******************************************************************************************//left
		left:
		i=0;
		char input3[100]=" ";
		
		
		while(1) {
			input3[i] = uart_read();//read char
			if (input3[i]=='.')
			break;
			i++;
			
		}
		
		
		if(strcmp(input3,"\nLeft.")==0)
		{//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//code to bring L to the top face


PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=19150;
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=18250;
		OCR1B=18250;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1A=17200;
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1B=18250;
		OCR1A=18250;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);


		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		uart_string("Left.\n");
		}
		else goto left;
		//*******************************************************************************************//back
		back:
		i=0;
		char input4[100]=" ";
		
		
		while(1) {
			input4[i] = uart_read();//read char
			if (input4[i]=='.')
			break;
			i++;
			
		}
		
		
		if(strcmp(input4,"\nBack.")==0)
		{//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//code to bring B to the top face
PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1A=17200;
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1B=18250;
		OCR1A=18250;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);

		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		uart_string("Back.\n");
		}
		else goto back;
		//*******************************************************************************************//
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//write code to bring U on top again


PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1A=17200;
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1A=19150;
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00010010;//select B and F
		OCR1A=18250;
		OCR1B=18250;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=19150;
		OCR1B=17200;
		_delay_ms(100);
		PORTC=0b00000001;//select linear FB
		OCR1B=19150;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=17200;
		_delay_ms(100);
		PORTC=0b00100100;//select R and L
		OCR1A=18250;
		OCR1B=18250;
		_delay_ms(100);
		PORTC=0b00001000;//select linear RL
		OCR1A=19150;
		_delay_ms(100);
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//*******************************************************************************************//
		i=0;
		char input[100]=" ";
		
		
		while(1) {
			input[i] = uart_read();//read char
			if (input[i]=='.')
			break;
			i++;
			
		}
//*******************************************************************************************//solve cube
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//now code for solving the cube //solution is char input [100]
		
while(input[z]!='.')
{

while(input[j]!=' ')
{
n=n+1;
j++;
}
if(n==1)
{
if(input[z]=='R')
{
PORTC=0b00001100;//select R
OCR1A=17200;//rotR-0
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00001100;//select R
OCR1A=18250;//rotR-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='L')
{
PORTC=0b00100001;//select L
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100001;//select L
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='F')
{
PORTC=0b00001010;//select F
OCR1A=17200;//rotF-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1B=18250;//rotF-90
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
}
else if(input[z]=='B')
{
PORTC=0b00010001;//select B
OCR1B=17200;//rotB-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=18250;//rotB-90
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
}
else if(input[z]=='U')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=19150;//rotR-180
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00000000;
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=17200;//rotF-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=18250;//rotF-90
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=17200;//rotR-0
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='D')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=19150;//rotR-180
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=17200;//rotB-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=18250;//rotB-90
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=17200;//rotR-0
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
z++;
}
if(n==2)
{
if(input[z+1]=='2')
{
if(input[z]=='R')
{
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00001100;//select R
OCR1A=19150;//rotR-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00001100;//select R
OCR1A=17200;//rotR-0
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00001100;//select R
OCR1A=18250;//rotR-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='L')
{
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100001;//select L
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00100001;//select L
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100001;//select L
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='F')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=19150;//rotF-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=17200;//rotF-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=18250;//rotF-90
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
}
else if(input[z]=='B')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=19150;//rotB-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=17200;//rotB-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=18250;//rotB-90
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
}
else if(input[z]=='U')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=19150;//rotR-180
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=19150;//rotF-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=17200;//rotF-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=18250;//rotF-90
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=17200;//rotR-0
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='D')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=19150;//rotR-180
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=19150;//rotB-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=17200;//rotB-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=18250;//rotB-90
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=17200;//rotR-0
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
z+=2;}
else 
if(input[z]=='R')
{
PORTC=0b00001100;//select R
OCR1A=19150;//rotR-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00001100;//select R
OCR1A=18250;//rotR-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='L')
{
PORTC=0b00100001;//select L
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100001;//select L
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='F')
{
PORTC=0b00001010;//select F
OCR1A=19150;//rotF-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=18250;//rotF-90
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
}
else if(input[z]=='B')
{
PORTC=0b00010001;//select B
OCR1B=19150;//rotB-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=18250;//rotB-90
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
}
else if(input[z]=='U')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=19150;//rotR-180
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=19150;//rotF-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00001010;//select F
OCR1A=18250;//rotF-90
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=17200;//rotR-0
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}
else if(input[z]=='D')
{
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=19150;//rotR-180
OCR1B=17200;//rotL-0
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=19150;//rotB-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=17200;//linFB-0
_delay_ms(100);
PORTC=0b00010001;//select B
OCR1B=18250;//rotB-90
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=17200;//rotR-0
OCR1B=19150;//rotL-180
_delay_ms(100);
PORTC=0b00000001;//select linear FB
OCR1B=19150;//linFB-180
_delay_ms(100);
PORTC=0b00001100;//select linear RL
OCR1A=17200;//linRL-0
_delay_ms(100);
PORTC=0b00100100;//select R and L
OCR1A=18250;//rotR-90
OCR1B=18250;//rotL-90
_delay_ms(100);
PORTC=0b00001000;//select linear RL
OCR1A=19150;//linRL-180
_delay_ms(100);
}

z+=2;
}
z++;

}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++		
//*******************************************************************************************//done
	uart_string("Done\n");
	}


	}



