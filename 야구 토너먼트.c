/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define Max 120                                   //Max 120���� ����
int main(void)
{ 
	int score[8] = { 0 };                        //1���忡�� �� ������ ������
	int score2nd[8] = { 0 };                      //2���忡�� �� ������ ������
	int score3rd[8] = { 0 };                         //3���忡�� �� ������ ������
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
	char team_name[8][13] = { "��ȭ�̱���","�λ꺣�","�Ｚ���̿½�","sk���̹���","���������ܽ�", "���Ÿ�̰Ž�","LGƮ����","�Ե����̾���" };
	
	srand((unsigned)time(NULL));                //�׻� ����
	for (i = 0; i <= 7; i++)                //8�� �ݺ�
	{
	again:;
		r = rand() % 8;              //0~7���� �������� �̰� r�� ����
		for (j = 0; j <= i - 1; j++)
			if (r == random[j])                 //�ߺ������� ������ ���� ����
				goto again;
		random[i] = r;
	}

	printf("������ �õ�(seed) ������ �̿��� ���� �Է�:"); //1���� ����
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < 8; i++)                          //8�����̹Ƿ� 8�� �ݺ�
	{
		score[i] = rand() % 15 + 1;                  // ���� 0������ 15������ �������� �̰� ���ʷ� score[0]~score[7]�� ����
	}
	if (score[0] > score[1]) {    
		strcpy_s(winner3_1, sizeof(team_name), team_name[random[0]]); //team_name[random[0]](����)�� winner3_1�� �����
	}
	else if (score[0] < score[1]) {                
		strcpy_s(winner3_1, sizeof(team_name), team_name[random[1]]);//team_name[random[1]](����)�� winner3_1�� �����
	}


	if (score[2] > score[3]) {                  
		strcpy_s(winner3_2, sizeof(team_name), team_name[random[2]]);//team_name[random[2]](����)�� winner3_2�� �����
	}
	else if (score[2] < score[3]) {               //d�� �̱涧
		strcpy_s(winner3_2, sizeof(team_name), team_name[random[3]]);//team_name[random[3]](����)�� winner3_2�� �����
	}


	if (score[4] > score[5]) {
		strcpy_s(winner3_3, sizeof(team_name), team_name[random[4]]); //team_name[random[4]](����)�� winner3_3�� �����
	}
	else if (score[4] < score[5]) {
		strcpy_s(winner3_3, sizeof(team_name), team_name[random[5]]); //team_name[random[5]](����)�� winner3_3�� �����
	}

	if (score[6] > score[7]) {
	    strcpy_s(winner3_4, sizeof(team_name), team_name[random[6]]);  //team_name[random[6]](����)�� winner3_4�� �����
	}
	else if (score[6] < score[7]) {
		strcpy_s(winner3_4, sizeof(team_name) , team_name[random[7]]); //team_name[random[7]](����)�� winner3_4�� �����
	}

	printf("������ �õ�(seed) ������ �̿��� ���� �Է�:");   //2���� ����
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < 4; i++)                          //��ʸ�Ʈ 2���忡�� �ٽ� �����ϰ� ���� ����
	{
		score2nd[i] = rand() % 15 + 1;                //���� 0������ 15������ �����ϰ� ����
	}
	if (score2nd[0] > score2nd[1]) {    
		strcpy_s(winner2_1, sizeof(winner3_1), winner3_1); //2���忡�� winner3_1�� winner2_1�� ����
		strcpy_s(winner3_a, sizeof(winner3_2) ,winner3_2); //2���忡�� winner3_1�� winner3_2�� ����
	}
	else if (score2nd[0] < score2nd[1]){
		strcpy_s(winner2_1, sizeof(winner3_2), winner3_2); //2���忡�� winner3_2�� winner2_1�� ����
		strcpy_s(winner3_a ,sizeof(winner3_1), winner3_1); //2���忡�� winner3_1�� winner3_a�� ����
	}

	if (score2nd[2] > score2nd[3]) {
		strcpy_s(winner2_2, sizeof(winner3_3), winner3_3); //2���忡�� winner3_3�� winner2_2�� ����
		strcpy_s(winner3_b, sizeof(winner3_4), winner3_4); //2���忡�� winner3_4�� winner3_b�� ����
	}
	else if (score2nd[2] < score2nd[3]) {
		strcpy_s(winner2_2, sizeof(winner3_4), winner3_4); //2���忡�� winner3_4�� winner2_2�� ����
		strcpy_s(winner3_b, sizeof(winner3_3), winner3_3); //2���忡�� winner3_3�� winner3_b�� ����
	}
	printf("������ �õ�(seed) ������ �̿��� ���� �Է�:");       //3���� ����
	scanf_s("%d", &seed);
	srand(seed);
	for (i = 0; i < 2; i++)   //3���� ���� 0~15�� �����ϰ� ����
	{
		score3rd[i] = rand() % 15 + 1;
	}
	if (score3rd[0] > score3rd[1])        //score3rd[0] > score3rd[1]�� ��          
	{
		if (strcmp(winner2_1 , team_name[random[0]])==0) {                  //team_name[random[0]]�� winner2_1�� �� ���   
			strcpy_s(winner1, sizeof(winner2_1), winner2_1);    //����� ���� winner2_1�� winner1�� ����
			strcpy_s(winner2, sizeof(winner2_2), winner2_2);    //����� ���� winner2_2�� winner2�� ����
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[1]], score[0], score[1], winner3_a, score2nd[0], score2nd[1], winner2, score3rd[0], score3rd[1]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[4]], score[4], score[5], winner3_b, score2nd[2], score2nd[3], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[2]]) == 0) && (strcmp(winner3_b, team_name[random[6]]) == 0)) { //winner3_2�� team_name[random[2]]�� �������� winner3_4�� team_name[random[6]]�� �������
				printf("3��:%s (1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner1, score2nd[1], score2nd[0]); 
				printf("3��:%s (1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner2, score2nd[3], score2nd[2]);
			}
			else if ((strcmp(winner3_a, team_name[random[3]]) == 0) && (strcmp(winner3_b, team_name[random[7]]) == 0)) {  //winner3_2�� team_name[random[3]]�� �������� winner3_4�� team_name[random[7]]�� �������
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner1, score2nd[1], score2nd[0]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner2, score2nd[3], score2nd[2]);
			}
		}
		else if (strcmp(winner2_1 ,team_name[random[1]])==0) {    //team_name[random[1]]�� winner2_1�� �� ���
			strcpy_s(winner1, sizeof(winner2_1), winner2_1);
			strcpy_s(winner2, sizeof(winner2_2), winner2_2);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[0]], score[1], score[0], winner3_a, score2nd[0], score2nd[1], winner2, score3rd[0], score3rd[1]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[5]], score[5], score[4], winner3_b, score2nd[2], score2nd[3], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[2]]) == 0) && (strcmp(winner3_b, team_name[random[6]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner1, score2nd[1], score2nd[0]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner2, score2nd[3], score2nd[2]);
			}
			else if ((strcmp(winner3_a, team_name[random[3]]) == 0) && (strcmp(winner3_b, team_name[random[7]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner1, score2nd[1], score2nd[0]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner2, score2nd[3], score2nd[2]);
			}
	    }
		else if (strcmp(winner2_1, team_name[random[2]])==0) {   //team_name[random[2]]�� winner2_1�� �� ���
			strcpy_s(winner1, sizeof(winner2_1) ,winner2_1);
			strcpy_s(winner2, sizeof(winner2_2) ,winner2_2);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[3]], score[2], score[3], winner3_a, score2nd[1], score2nd[0], winner2, score3rd[0], score3rd[1]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[6]], score[7], score[6], winner3_b, score2nd[3], score2nd[2], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[0]]) == 0) && (strcmp(winner3_b, team_name[random[4]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner1, score2nd[0], score2nd[1]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner2, score2nd[2], score2nd[3]);
			}
			else if ((strcmp(winner3_a, team_name[random[1]]) == 0) && (strcmp(winner3_b, team_name[random[5]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner1, score2nd[0], score2nd[1]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner2, score2nd[2], score2nd[3]);
			}
		}
		else if (strcmp(winner2_1, team_name[random[3]])==0) {   //team_name[random[3]]�� winner2_1�� �� ���
			strcpy_s(winner1, sizeof(winner2_1), winner2_1);
			strcpy_s(winner2, sizeof(winner2_2), winner2_2);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[2]], score[3], score[2], winner3_a, score2nd[1], score2nd[0], winner2, score3rd[0], score3rd[1]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[7]], score[6], score[7], winner3_b, score2nd[2], score2nd[3], winner2_1, score3rd[1], score3rd[0]);
			if ((strcmp(winner3_a, team_name[random[0]]) == 0) && (strcmp(winner3_b, team_name[random[4]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner1, score2nd[0], score2nd[1]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner2, score2nd[2], score2nd[3]);
			}
			else if ((strcmp(winner3_a, team_name[random[1]]) == 0) && (strcmp(winner3_b, team_name[random[5]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner1, score2nd[0], score2nd[1]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner2, score2nd[2], score2nd[3]);
			}
		}
	}
	else if (score3rd[0] < score3rd[1])
	{
		if (strcmp(winner2_2, team_name[random[4]])==0){     //team_name[random[4]]�� winner2_2�� �� ���
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[5]], score[4], score[5], winner3_b, score2nd[2], score2nd[3], winner2, score3rd[1], score3rd[0]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[0]], score[1], score[0], winner3_a, score2nd[0], score2nd[1], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[6]]) == 0) && (strcmp(winner3_a, team_name[random[2]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner1, score2nd[3], score2nd[2]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner2, score2nd[1], score2nd[0]);
			}
			else if ((strcmp(winner3_b, team_name[random[7]]) == 0) && (strcmp(winner3_a, team_name[random[3]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner1, score2nd[3], score2nd[2]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner2, score2nd[1], score2nd[0]);
			}
		}
		else if (strcmp(winner2_2, team_name[random[5]])==0) {   //team_name[random[5]]�� winner2_2�� �� ���
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[4]], score[5], score[4], winner3_b, score2nd[2], score2nd[3], winner2, score3rd[1], score3rd[0]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[1]], score[0], score[1], winner3_a, score2nd[0], score2nd[1], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[6]]) == 0) && (strcmp(winner3_a, team_name[random[2]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[7]], score[6], score[7], winner1, score2nd[3], score2nd[2]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[3]], score[2], score[3], winner2, score2nd[1], score2nd[0]);
			}
			else if ((strcmp(winner3_b, team_name[random[7]]) == 0) && (strcmp(winner3_a, team_name[random[3]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[6]], score[7], score[6], winner1, score2nd[3], score2nd[2]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[2]], score[3], score[2], winner2, score2nd[1], score2nd[0]);
			}
		}
		else if (strcmp(winner2_2, team_name[random[6]])==0) {  //team_name[random[6]]�� winner2_2�� �� ���
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner1, team_name[random[7]], score[6], score[7], winner3_b, score2nd[3], score2nd[2], winner2, score3rd[1], score3rd[0]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d )\n",winner2, team_name[random[3]], score[2], score[3], winner3_a, score2nd[1], score2nd[0], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[4]]) == 0) && (strcmp(winner3_a, team_name[random[0]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner1, score2nd[2], score2nd[3]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner2, score2nd[0], score2nd[1]);
			}
			else if ((strcmp(winner3_b, team_name[random[5]]) == 0) && (strcmp(winner3_a, team_name[random[1]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner1, score2nd[2], score2nd[3]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner2, score2nd[0], score2nd[1]);
			}
		}
		else if (strcmp(winner2_2, team_name[random[7]])==0) {  //team_name[random[7]]�� winner2_2�� �� ���
			strcpy_s(winner1, sizeof(winner2_2), winner2_2);
			strcpy_s(winner2, sizeof(winner2_1), winner2_1);
			printf("1��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d)\n",winner1, team_name[random[6]], score[7], score[6], winner3_b, score2nd[3], score2nd[2], winner2, score3rd[1], score3rd[0]);
			printf("2��:%s \n(1���� %s %d:%d ,2���� %s %d:%d ,3���� %s %d:%d)\n",winner2, team_name[random[2]], score[3], score[2], winner3_a, score2nd[1], score2nd[0], winner2_2, score3rd[0], score3rd[1]);
			if ((strcmp(winner3_b, team_name[random[4]]) == 0) && (strcmp(winner3_a, team_name[random[0]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[5]], score[4], score[5], winner1, score2nd[2], score2nd[3]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[1]], score[0], score[1], winner2, score2nd[0], score2nd[1]);
			}
			else if ((strcmp(winner3_b, team_name[random[5]]) == 0) && (strcmp(winner3_a, team_name[random[1]]) == 0)) {
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_b, team_name[random[4]], score[5], score[4], winner1, score2nd[2], score2nd[3]);
				printf("3��:%s \n(1���� %s %d:%d ,2���� %s %d:%d)\n", winner3_a, team_name[random[0]], score[1], score[0], winner2, score2nd[0], score2nd[1]);
			}
		}
	}
	return 0;
}*/