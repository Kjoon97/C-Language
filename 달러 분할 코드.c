#include<stdio.h>
int main(void)
{
	int num, a1,a2, a3 ,b1,b2,c1,c2; 
	printf("입력:");
	scanf_s("%d" , &num);

	a1 = num / 50; //몫
	a2 = num % 50; //나머지
	a3 = a2 / 10; //몫
	b1 = a2 /20 ; // 몫
	b2 = a2 % 20; //나머지
	c1=  b2 / 10;
	c2 = b2 % 10;

	if (num == 50)
		printf("출력: 50달러 : %d장", a1);
	else if (num ==60)
		printf("출력: 50달러 : %d장 ,10달러 :%d장", a1, a3);
	else if(num==70)
		printf("출력: 50달러 : %d장 ,20달러 :%d장", a1, b1 );
	else
		if((b1==0)&&(c1 != 0))
		printf("출력: 50달러 : %d장,10달러 :%d장", a1,c1);
	    else if ((c1 == 0)&& (b1 != 0))
		printf("출력: 50달러 : %d장 ,20달러 :%d장", a1, b1);
	    else if ((b1 == 0)&&(c1==0))
		printf("출력: 50달러 : %d장", a1);
		else
		printf("출력: 50달러 : %d장 ,20달러 :%d장,10달러 :%d장", a1, b1, c1);

       return 0;
}