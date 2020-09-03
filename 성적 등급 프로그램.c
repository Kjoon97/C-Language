#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int grade; // grade 선언

	printf("성적을 입력하시오:"); //성적 입력하라는 안내문 출력
	scanf_s("%d", &grade); 

	if (grade > 100)
	{
		printf("성적은 100점까지 입니다 \n");  //100점 초과 시 성적은 100점까지라는 안내문 출력
	}
	else if (grade >= 90) //grade에 90이상의 숫자가 저장되어 있을 경우
	{
		printf("Excellence \n"); 
	}
	else if (grade >= 80)//grade에 90미만이지만 80이상의 숫자가 저장되어 있을 경우
	{
		printf("good \n");
	}
	else if (grade >= 70)//grade에 80미만이지만 70이상의 숫자가 저장되어 있을 경우
	{
		printf("Not Bad \n");
	}
	else             //grade에 70미만인 숫자가 저장되어 있을 경우
	{
		printf("Bad \n");
	}
	system("pause"); 
	return 0;
}