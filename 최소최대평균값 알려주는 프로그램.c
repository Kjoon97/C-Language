/*#include <stdio.h>
void main()
{
	int n, a = 0, i, sum = 0, agv, max, min;

	printf("숫자를 입력하세요: ");
	scanf_s("%d", &n);

	printf("%d개의 숫자를 입력하세요(만약 %d개보다 더 입력하실 시,%d번째 입력된 숫자부터는 무시됩니다.): ", n,n,n+1);
    scanf_s("%d", &a); //마지막 숫자 a에 저장됨

	max = a;  // a에 저장된 마지막 숫자가 max에도 저장됨 
	min = a;  // a에 저장된 마지막 숫자가 min에도 저장됨
	sum = sum + a; // a에 저장된 마지막 숫자가 0값인 sum에 더해져서 sum에 저장된다.

	for (i = 1; i < n; i++) // n-1번 반복된다
	{
		scanf_s("%d", &a); //a에 다시 처음부터 차례로 숫자가 저장됨 1번 반복될때마다 1번씩
		
		sum = sum + a;   // for문 이전 저장된 sum값에 a를 반복해서 더해간다

		if (a > max) max = a; //for문 이전에 저장된 max값보다 a값이 크면 max에 a를 저장
		if (a < min) min = a;  //for문 이전에 저장된 min값보다 a값이 작으면 min에 a를 저장
	}

	agv = sum / n; //평균값

	printf("최대값 = %d \n", max);
	printf("최소값 = %d \n", min);
	printf("평  균 = %d \n", agv);
}*/
