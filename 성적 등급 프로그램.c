#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int grade; // grade ����

	printf("������ �Է��Ͻÿ�:"); //���� �Է��϶�� �ȳ��� ���
	scanf_s("%d", &grade); 

	if (grade > 100)
	{
		printf("������ 100������ �Դϴ� \n");  //100�� �ʰ� �� ������ 100��������� �ȳ��� ���
	}
	else if (grade >= 90) //grade�� 90�̻��� ���ڰ� ����Ǿ� ���� ���
	{
		printf("Excellence \n"); 
	}
	else if (grade >= 80)//grade�� 90�̸������� 80�̻��� ���ڰ� ����Ǿ� ���� ���
	{
		printf("good \n");
	}
	else if (grade >= 70)//grade�� 80�̸������� 70�̻��� ���ڰ� ����Ǿ� ���� ���
	{
		printf("Not Bad \n");
	}
	else             //grade�� 70�̸��� ���ڰ� ����Ǿ� ���� ���
	{
		printf("Bad \n");
	}
	system("pause"); 
	return 0;
}