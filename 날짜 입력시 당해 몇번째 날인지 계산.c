/*#include<stdio.h>
int main(void)
{
	int year=0;
	int month=0;
	int day=0;
	int total_day=0;
	printf("날짜를 입력하세요(몇년몇월몇일):");
	scanf_s("%d년%d월%d일", &year, &month, &day);
	if (month == 1)
		total_day = day;
	else if (month == 2)
		total_day = 31 + day;
	else if (month == 3)
		total_day = 31 + 28 + day;
	else if (month == 4)
		total_day = 31*2 + 28 + day; 
	else if (month == 5) 
		total_day = 31*2 + 28 + 30 + day;
	else if (month == 6)
		total_day = 31 * 3 + 28 + 30 + day;
	else if (month == 7)
		total_day = 31 * 3 + 30*2 + 28 + day;
	else if (month == 8)
		total_day = 31 * 4 + 30 * 2 + 28 + day;
	else if (month == 9)
		total_day = 31 * 5 + 30 * 2 + 28 + day;
	else if (month == 10)
		total_day = 31 * 5 + 30 * 3 + 28 + day;
	else if (month == 11)
		total_day = 31 * 6 + 30 * 3 + 28 + day;
	else if (month == 12)
		total_day = 31 * 6 + 30 * 4 + 28 + day;

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		if (month >=3)
		{
				total_day = total_day + 1;
		}
		else
			total_day;
	}
	else
	{
		total_day;
	}
	printf("그 해의 %d번째 날이다.", total_day);

	return 0;
}*/