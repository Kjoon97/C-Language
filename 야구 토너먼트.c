/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define Max 120                                   //Max 120으로 정의
int main(void)
{ 
	int score[8] = { 0 };                        //1라운드에서 각 구단의 점수들
	int score2nd[8] = { 0 };                      //2라운드에서 각 구단의 점수들
	int score3rd[8] = { 0 };                         //3라운드에서 각 구단의 점수들
	int i, r, j, random[8];
	int seed;
	char winner3_1[Max] = { 0 };
	char winner3_2[Max] = { 0 };
	char winner3_3[Max] = { 0 };
	char winner3_4[Max] = { 0 };
	char winner3_a[Max] = { 0 };
	char winner3_b[Max] = { 0 };
	char winner2_1[Max] = { 0 };
	char winner2_2[Max] = { 0 };
	char winner2[Max] = { 0 };
	char winner1[Max] = { 0 };
	char team_name[8][13] = { "한화이글즈","두산베어스","삼성라이온스","sk와이번스","현대유니콘스", "기아타이거스","LG트윈스","롯데자이언츠" };
	
	srand((unsigned)time(NULL));                //항상 랜덤
	for (i = 0; i <= 7; i++)                //8번 반복
	{
	again:;
		r = rand() % 8;              //0~7까지 랜덤으로 뽑고 r에 저장
		for (j = 0; j <= i - 1; j++)
			if (r == random[j])                 //중복적으로 뽑히는 것을 방지
				goto again;
		random[i] = r;
	}

	printf("난수의 시드(seed) 값으로 이용할 정수 입력:"); //1라운드 시작
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < 8; i++)                          //8구단이므로 8번 반복
	{
		score[i] = rand() % 15 + 1;                  // 점수 0점에서 15점까지 무작위로 뽑고 차례로 score[0]~score[7]에 저장
	}
	if (score[0] > score[1]) {    
		strcpy_s(winner3_1, sizeof(team_name), team_name[random[0]]); //team_name[random[0]](구단)이 winner3_1에 복사됨
	}
	else if (score[0] < score[1]) {                
		strcpy_s(winner3_1, sizeof(team_name), team_name[random[1]]);//team_name[random[1]](구단)이 winner3_1에 복사됨
	}


	if (score[2] > score[3]) {                  
		strcpy_s(winner3_2, sizeof(team_name), team_name[random[2]]);//team_name[random[2]](구단)이 winner3_2에 복사됨
	}
	else if (score[2] < score[3]) {               //d가 이길때
		strcpy_s(winner3_2, sizeof(team_name), team_name[random[3]]);//team_name[random[3]](구단)이 winner3_2에 복사됨
	}


	if (score[4] > score[5]) {
		strcpy_s(winner3_3, sizeof(team_name), team_name[random[4]]); //team_name[random[4]](구단)이 winner3_3에 복사됨
	}
	else if (score[4] < score[5]) {
		strcpy_s(winner3_3, sizeof(team_name), team_name[random[5]]); //team_name[random[5]](구단)이 winner3_3에 복사됨
	}

	if (score[6] > score[7]) {
	    strcpy_s(winner3_4, sizeof(team_name), team_name[random[6]]);  //team_name[random[6]](구단)이 winner3_4에 복사됨
	}
	else if (score[6] < score[7]) {
		strcpy_s(winner3_4, sizeof(team_name) , team_name[random[7]]); //team_name[random[7]](구단)이 winner3_4에 복사됨
	}

	printf("난수의 시드(seed) 값으로 이용할 정수 입력:");   //2라운드 시작
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < 4; i++)                          //토너먼트 2라운드에서 다시 랜덤하게 점수 배정
	{
		score2nd[i] = rand() % 15 + 1;                //점수 0점에서 15점까지 랜덤하게 배정
	}
	if (score2nd[0] > score2nd[1]) {    
		strcpy_s(winner2_1, sizeof(winner3_1), winner3_1); //2라운드에서 winner3_1은 winner2_1에 복사
		strcpy_s(winner3_a, sizeof(winner3_2) ,winner3_2); //2라운드에서 winner3_1은 winner3_2에 복사
	}
	else if (score2nd[0] < score2nd[1]){
		strcpy_s(winner2_1, sizeof(winner3_2), winner3_2); //2라운드에서 winner3_2은 winner2_1에 복사
		strcpy_s(winner3_a ,sizeof(winner3_1), winner3_1); //2라운드에서 winner3_1은 winner3_a에 복사
	}

	if (score2nd[2] > score2nd[3]) {
		strcpy_s(winner2_2, sizeof(winner3_3), winner3_3); //2라운드에서 winner3_3은 winner2_2에 복사
		strcpy_s(winner3_b, sizeof(winner3_4), winner3_4); //2라운드에서 winner3_4은 winner3_b에 복사
	}
	else if (score2nd[2] < score2nd[3]) {
		strcpy_s(winner2_2, sizeof(winner3_4), winner3_4); //2라운드에서 winner3_4은 winner2_2에 복사
		strcpy_s(winner3_b, sizeof(winner3_3), winner3_3); //2라운드에서 winner3_3은 winner3_b에 복사
	}
	printf("난수의 시드(seed) 값으로 이용할 정수 입력:");       //3라운드 시작
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < 2; i++)   //3라운드 점수 0~15점 랜덤하게 배정
	{
		score3rd[i] = rand() % 15 + 1;
	}
	if (score3rd[0] > score3rd[1])        //score3rd[0] > score3rd[1]일 때          
	{
		if (strcmp(winner2_1 , team_name[random[0]])==0) {                  //team_name[random[0]]이 winner2_1이 될 경우   
			strcpy_s(winner1, sizeof(winner2_1), winner2_1);    //결승전 에서 winner2_1은 winner1에 복사
			strcpy_s(winner2, sizeof(winner2_2), winner2_2);    //결승전 에서 winner2_2은 winner2에 복사
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[1]], score[0], score[1], winner3_a, score2nd[0], score2nd[1], winner2, score3rd[0], score3rd[1]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[4]], score[4], score[5], winner3_b, score2nd[2], score2nd[3], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[2]]) == 0) && (strcmp(winner3_b, team_name[random[6]]) == 0)) { //winner3_2와 team_name[random[2]]가 같을경우와 winner3_4와 team_name[random[6]]가 같을경우
				printf("3위:%s (1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner1, score2nd[1], score2nd[0]); 
				printf("3위:%s (1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner2, score2nd[3], score2nd[2]);
			}
			else if ((strcmp(winner3_a, team_name[random[3]]) == 0) && (strcmp(winner3_b, team_name[random[7]]) == 0)) {  //winner3_2와 team_name[random[3]]가 같을경우와 winner3_4와 team_name[random[7]]가 같을경우
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner1, score2nd[1], score2nd[0]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner2, score2nd[3], score2nd[2]);
			}
		}
		else if (strcmp(winner2_1 ,team_name[random[1]])==0) {    //team_name[random[1]]이 winner2_1이 될 경우
			strcpy_s(winner1, sizeof(winner2_1), winner2_1);
			strcpy_s(winner2, sizeof(winner2_2), winner2_2);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[0]], score[1], score[0], winner3_a, score2nd[0], score2nd[1], winner2, score3rd[0], score3rd[1]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[5]], score[5], score[4], winner3_b, score2nd[2], score2nd[3], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[2]]) == 0) && (strcmp(winner3_b, team_name[random[6]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner1, score2nd[1], score2nd[0]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner2, score2nd[3], score2nd[2]);
			}
			else if ((strcmp(winner3_a, team_name[random[3]]) == 0) && (strcmp(winner3_b, team_name[random[7]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner1, score2nd[1], score2nd[0]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner2, score2nd[3], score2nd[2]);
			}
	    }
		else if (strcmp(winner2_1, team_name[random[2]])==0) {   //team_name[random[2]]이 winner2_1이 될 경우
			strcpy_s(winner1, sizeof(winner2_1) ,winner2_1);
			strcpy_s(winner2, sizeof(winner2_2) ,winner2_2);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[3]], score[2], score[3], winner3_a, score2nd[1], score2nd[0], winner2, score3rd[0], score3rd[1]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[6]], score[7], score[6], winner3_b, score2nd[3], score2nd[2], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[0]]) == 0) && (strcmp(winner3_b, team_name[random[4]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner1, score2nd[0], score2nd[1]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner2, score2nd[2], score2nd[3]);
			}
			else if ((strcmp(winner3_a, team_name[random[1]]) == 0) && (strcmp(winner3_b, team_name[random[5]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner1, score2nd[0], score2nd[1]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner2, score2nd[2], score2nd[3]);
			}
		}
		else if (strcmp(winner2_1, team_name[random[3]])==0) {   //team_name[random[3]]이 winner2_1이 될 경우
			strcpy_s(winner1, sizeof(winner2_1), winner2_1);
			strcpy_s(winner2, sizeof(winner2_2), winner2_2);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[2]], score[3], score[2], winner3_a, score2nd[1], score2nd[0], winner2, score3rd[0], score3rd[1]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[7]], score[6], score[7], winner3_b, score2nd[2], score2nd[3], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[0]]) == 0) && (strcmp(winner3_b, team_name[random[4]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner1, score2nd[0], score2nd[1]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner2, score2nd[2], score2nd[3]);
			}
			else if ((strcmp(winner3_a, team_name[random[1]]) == 0) && (strcmp(winner3_b, team_name[random[5]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner1, score2nd[0], score2nd[1]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner2, score2nd[2], score2nd[3]);
			}
		}
	}
	else if (score3rd[0] < score3rd[1])
	{
		if (strcmp(winner2_2, team_name[random[4]])==0){     //team_name[random[4]]이 winner2_2이 될 경우
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[5]], score[4], score[5], winner3_b, score2nd[2], score2nd[3], winner2, score3rd[1], score3rd[0]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[0]], score[1], score[0], winner3_a, score2nd[0], score2nd[1], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[6]]) == 0) && (strcmp(winner3_a, team_name[random[2]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner1, score2nd[3], score2nd[2]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner2, score2nd[1], score2nd[0]);
			}
			else if ((strcmp(winner3_b, team_name[random[7]]) == 0) && (strcmp(winner3_a, team_name[random[3]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner1, score2nd[3], score2nd[2]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner2, score2nd[1], score2nd[0]);
			}
		}
		else if (strcmp(winner2_2, team_name[random[5]])==0) {   //team_name[random[5]]이 winner2_2이 될 경우
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[4]], score[5], score[4], winner3_b, score2nd[2], score2nd[3], winner2, score3rd[1], score3rd[0]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[1]], score[0], score[1], winner3_a, score2nd[0], score2nd[1], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[6]]) == 0) && (strcmp(winner3_a, team_name[random[2]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner1, score2nd[3], score2nd[2]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner2, score2nd[1], score2nd[0]);
			}
			else if ((strcmp(winner3_b, team_name[random[7]]) == 0) && (strcmp(winner3_a, team_name[random[3]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner1, score2nd[3], score2nd[2]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner2, score2nd[1], score2nd[0]);
			}
		}
		else if (strcmp(winner2_2, team_name[random[6]])==0) {  //team_name[random[6]]이 winner2_2이 될 경우
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner1, team_name[random[7]], score[6], score[7], winner3_b, score2nd[3], score2nd[2], winner2, score3rd[1], score3rd[0]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d )\n",winner2, team_name[random[3]], score[2], score[3], winner3_a, score2nd[1], score2nd[0], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[4]]) == 0) && (strcmp(winner3_a, team_name[random[0]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner1, score2nd[2], score2nd[3]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner2, score2nd[0], score2nd[1]);
			}
			else if ((strcmp(winner3_b, team_name[random[5]]) == 0) && (strcmp(winner3_a, team_name[random[1]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner1, score2nd[2], score2nd[3]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner2, score2nd[0], score2nd[1]);
			}
		}
		else if (strcmp(winner2_2, team_name[random[7]])==0) {  //team_name[random[7]]이 winner2_2이 될 경우
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d)\n",winner1, team_name[random[6]], score[7], score[6], winner3_b, score2nd[3], score2nd[2], winner2, score3rd[1], score3rd[0]);
			printf("2위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d ,3차전 %s %d:%d)\n",winner2, team_name[random[2]], score[3], score[2], winner3_a, score2nd[1], score2nd[0], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[4]]) == 0) && (strcmp(winner3_a, team_name[random[0]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner1, score2nd[2], score2nd[3]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner2, score2nd[0], score2nd[1]);
			}
			else if ((strcmp(winner3_b, team_name[random[5]]) == 0) && (strcmp(winner3_a, team_name[random[1]]) == 0)) {
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner1, score2nd[2], score2nd[3]);
				printf("3위:%s \n(1차전 %s %d:%d ,2차전 %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner2, score2nd[0], score2nd[1]);
			}
		}
	}
	return 0;
}*/