#include "stm32f4xx.h"
void delay();
void showdigit(int digit);
void setout();
int Ispalindrom(int number);
int Isprime(int num);
void delay2();
void shownumber(int number);
int main(void)
{
	RCC->AHB1ENR = ((1U<<0)  | (1U<<1));
	// SET B GROUP AS INPUT
	GPIOB->MODER = 0X00000000;
	GPIOB->PUPDR = 0X00000000;
	GPIOB->PUPDR |= (2UL << 2*0);
	GPIOB->PUPDR |= (2UL << 2*1);
	setout();

	int number=101;
	int react;
	while(1){
		react = 0x3 & GPIOB->IDR;
		if(react == 1 | react == 2){
			if(react==1){
				number+=1;
				while(1){
				if(Ispalindrom(number) && Isprime(number))
					break;
				number+=1;
			}
		}
			else if(react==2){
				if(number>2){
			   number-=1;
				while(1){
				if(Ispalindrom(number) && Isprime(number))
					break;
				number-=1;
			}
			}
		}
		}
		
	 shownumber(number);
	 delay2();		
  }
	
  return 0;
 }
void delay()
{
   for(unsigned int d=200000; d!=0; d--)
    {}
}	
void delay2(){
   
 for(unsigned int d=2000000; d!=0; d--)
    {}

}
void showdigit(int digit){
	if(digit==0)
		GPIOA->ODR |=(3<<5);//0
	else if(digit==1)
		GPIOA->ODR |=(159<<5); //1
	else if(digit==2)
		GPIOA->ODR |=(37<<5); //2
	else if(digit==3)
		GPIOA->ODR |=(13<<5); //3
	else if(digit==4)
		GPIOA->ODR |=(153<<5);// 4
	else if(digit==5)
		GPIOA->ODR |=(73<<5); //5
	else if(digit==6)
		GPIOA->ODR |=(65<<5); //6
	else if(digit==7)
		GPIOA->ODR |=(31<<5);// 7
	else if(digit==8)
		GPIOA->ODR |=(1<<5); //8
	else
		GPIOA->ODR |=(9<<5); //9
	return;
}
void setout(){
	GPIOA->MODER |= (1<<10);
	GPIOA->MODER |= (1<<12);
	GPIOA->MODER |= (1<<14);
	GPIOA->MODER |= (1<<16);
	GPIOA->MODER |= (1<<18);
	GPIOA->MODER |= (1<<20);
	GPIOA->MODER |= (1<<22);
	GPIOA->MODER |= (1<<24);
}
int Ispalindrom(int number){
int copyofnumber=number;
int reverse=0;
while (number != 0) {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
if(copyofnumber==reverse)
	return 1;
else
	return 0;	
}
int Isprime(int num){
if(num==1)
return 0;
else if(num==2)
	return 1;
else if(num%2==0)
	return 0;
else
{
for(int i=3;i<num;i=i+2)
 if(num%i==0)
   return 0;	 
}
return 1;	
}	
void shownumber(int number){
while (number != 0) {
    int remain=number % 10;
    number /= 10;
		showdigit(remain);
		delay();
		GPIOA->ODR &= ~(0x3FF << 5);
		delay();

}
return ;
}
