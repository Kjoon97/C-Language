/*#include <stdio.h>
#include<string.h>
int calculate(void);
int main(void)
{
	int total_time = 0,             //��ü �ð�
	    h1=0, m1=0, h2=0, m2=0,              //���� ���۽� ��,�� /���� ����� ��,��
		add_time = 0,               //�߰��� �ð� 
		add_fare = 0,               //�߰� ���
		total_fare = 0,             //��ü ���
		n = 0;                      //�ڵ��� �� �� ��Ÿ���� ����
	char str1[5] = "�ܱ�";          //str1�迭�� �ܱ� ����
	char str2[5] = "���";          //str2�迭�� ��� ����
	char str3[5]=  "\0";                  //���,�ܱ� �� �ϳ� �Է� �� ������ str1,2�� ���� �迭 �ʱ�ȭ
	char str4[3] = "��";            //str4�迭�� �� ����
	char str5[7] = "�ƴϿ�";          //str5�迭�� �ƴϿ� ����
	char str6[7] = "\0";              //�� �ƴϿ� �� �ϳ��� �Է��� ������ str4,5�� ���� �迭 �ʱ�ȭ
	char str7[5] = "����";        //str7�迭�� ���� ����
	char str8[5] = "����";         //str8�迭�� ���� ����
	char str9[5] = "\0";                  //���� ���� �� �ϳ��� �Է��� ������ str7,8�� ���� �迭 �ʱ�ȭ
	printf("����������̸� ���, �ܱ� �������̸� �ܱ��� �Է��ϼ���; ");
	scanf_s("%s", str3, sizeof(str3));             //�迭str3�� ���, �ܱ� �� �ϳ� �Է�
	if (strcmp(str1, str3) == 0)                   //���� str1=str3�̸�(�Ѵ� �ܱ�) �� ->if�� ����
	{
		 total_time = calculate();       //�� ���� �ð��� ������ ����ϴ� �Լ� ȣ��
		                                                  
		if (total_time <= 30)                        //��ü �̿�ð�(total_time)�� 30������ ->1200��
		{
			total_fare = 1200;                      
		}
		else if (total_time > 30 && total_time < 600)   //��ü �̿� �ð��� 30�� �ʰ� 10�ð� �̸�
		{
			add_time = total_time - 30;                 //�߰��� �ð� = ��ü�ð� - �⺻�ð�
		    add_fare = (add_time / 15) * 600;                 // 1�д� ��� *600��
			if (add_time % 15 != 0)                    //�߰��� �ð��� 15�� ����� �ƴҶ�
			{
				add_fare = add_fare + 600;       //15�к��� �۾Ƶ� 1�и� �ö󰡵� ����� �ö󰡰� 
			}                                     //add_timeD�� �� ����ǹǷ� 1�д� ��ݿ� 600���� ������
			total_fare = 1200 + add_fare;         //��ü ��� = �⺻��� + �߰����
		}
		else if (total_time >= 600)             //��ü �ð��� 10�ð� �̻��� ���
		{
			total_fare = 24000;                 //10�ð� ���� 24�ð����� �Ϸ� �ִ� ��� ->24000��
		}
		printf("������ �ڵ����Դϱ�?(��/�ƴϿ�): "); //����ϱ� �ռ� ���ǵ��� �ɾ���
		scanf_s("%s", str6, sizeof(str6));             //�� �Ǵ� �ƴϿ並 str6�� ����
		if (strcmp(str4, str6) == 0)                  // str4(��)�� ���ؼ� �����ϸ�(�� �� '��')-> if�� ���
		{
		    printf("�� �� �ڵ����Դϱ�?: ");
		    scanf_s("%d", &n);
			if ((n == 1) || (n == 2)) {
				printf("�� �̿�����:%d���Դϴ�. ", total_fare / 2);
			}
			else if (n == 3) {
				printf("�� �̿�����:%d���Դϴ�. ", total_fare * 80 / 100);
			}
		}
		else if (strcmp(str5, str6) == 0)    // str5(�ƴϿ�)�� ���ؼ� �����ϸ�(�� �� '�ƴϿ�')-> else if�� ���
		{
		printf("������ �����̰ų� ����� ����������,5.18����������,���� ������ȯ��, ����� ��ȸ �Ǵ� ��ü����,���ڳడ�� �� �ش������ �����ʴϱ�?(��/�ƴϿ�): ");               
		scanf_s("%s", str6, sizeof(str6));      //str6�� �ٽ� �� or �ƴϿ並 ����
		if (strcmp(str4, str6) == 0)            //str4(��) == str6 (�� �� '��'�� ����)
			printf("�� �̿�����:%d���Դϴ�. ", total_fare / 2);
		else if (strcmp(str5, str6) == 0)       //str5(�ƴϿ�) == str6 (�� �� '�ƴϿ�' ����)
			printf("�� �̿�����:%d���Դϴ�. ", total_fare);
		}
		
	}
	else if (strcmp(str2, str3) == 0)           //str2 == str3 (�� �� '���' ����) 
	{
		printf("�ڵ����� �����̸� ����, �����̸� �������� �Է����ּ���:"); //�������� �������� ����
		scanf_s("%s", str9, sizeof(str9));                                 //str9�� ���� �Ǵ� ���� ����
		if (strcmp(str7, str9) == 0)                   //str7(����)==str9(�� �� ���� ������ִ� ���)
		{
			total_time = calculate();                 //�� ���� �ð��� ������ ���
            total_fare = (total_time / 60) * 1000;          // �⺻ ��� ���� �ð� �� 1000��.
			if (total_time < 540)                            //9�ð������� 1�ð� �� 1000�� �߰�
			{
				if (total_time % 60 != 0)                  //��ü �ð��� 60�� ������ �ƴѰ��
				{
					total_fare = total_fare + 1000;
				}
				total_fare;
			}
			else if (total_time >= 540 && total_time <= 1440)  //��ü�ð� 9�ð��̻� 24�ð� �̳�->�Ϸ��ִ� ���(9000��)
			{
				total_fare = 9000;
			}
			printf("������ �ڵ����ΰ�?(��/�ƴϿ�): ");      //������ �ڵ������� ���
			scanf_s("%s", str6, sizeof(str6));
			if (strcmp(str4, str6) == 0)
			{
				printf("�� �� �ڵ����ΰ�? :");
				scanf_s("%d��", &n);
				if ((n == 1) || (n == 2))
					printf("�� �̿�����:%d���Դϴ�. ", total_fare / 2);
				else if (n == 3)
					printf("�� �̿�����:%d���Դϴ�. ", total_fare * 80 / 100);
			}
			else if (strcmp(str5, str6) == 0)         //������ �ڵ����� �ƴ� ���
			{
				printf("������ �����̰ų� ����� ����������,5.18����������,���� ������ȯ��, ����� ��ȸ�Ǵ� ��ü����,���ڳడ�� �� �ش������ �����ʴϱ�?(��/�ƴϿ�): ");  //�ٸ� ���� ����ΰ� ���
				scanf_s("%s", str6, sizeof(str6));
				if (strcmp(str4, str6) == 0)
					printf("�� �̿�����:%d���Դϴ�. ", total_fare / 2);
				else if (strcmp(str5, str6) == 0)
					printf("�� �̿�����:%d���Դϴ�. ", total_fare);
			}
		}
		else if (strcmp(str8, str9) == 0)    //str8(����)==str9 (�������� ���)
		{
			total_time = calculate();                           //�� ���� �ð��� ������ ���
            total_fare = (total_time / 30) * 1200;          //�⺻���x ,30�� �� 1200�� �߰�
			if (total_time < 300)                           //5�ð����� ���� ���
			{
				if (total_time % 30 != 0)                    //��ü �ð��� 30�� ������ �ƴ� ���
				{
					total_fare += 1200;
				}
				total_fare;
			}
			else if (total_time >= 300 && total_time <= 1440)  //5�ð� �̻� 24�ð� �̳��� ���->12000��
			{
				total_fare = 12000;                       
			}
			printf("������ �ڵ����ΰ�?(��/�ƴϿ�): ");             
			scanf_s("%s", str6, sizeof(str6));
			if (strcmp(str4, str6) == 0)                        //������ �ڵ����ϰ�� (��)
			{
				printf("�� �� �ڵ����ΰ�?: ");                    
				scanf_s("%d��", &n);
				if ((n == 1) || (n == 2))
					printf("�� �̿�����:%d���Դϴ�. ", total_fare / 2);
				else if (n == 3)
					printf("�� �̿�����:%d���Դϴ�. ", total_fare * 80 /100);
			}
			else if (strcmp(str5, str6) == 0)               // ������ �ڵ����� �ƴҰ�� (�ƴϿ�)
			{
				printf("������ �����̰ų� ����� ����������,5.18����������,���� ������ȯ��, ����� ��ȸ �Ǵ� ��ü����,���ڳడ�� �� �ش������ �����ʴϱ�?(��/�ƴϿ�):");
				scanf_s("%s", str6, sizeof(str6));
				if (strcmp(str4, str6) == 0)
					printf("�� �̿�����:%d���Դϴ�. ", total_fare / 2);
				else if (strcmp(str5, str6) == 0)
					printf("�� �̿�����:%d���Դϴ�. ", total_fare);
			}
		}
	}
    return 0;
}
int calculate(void)                     //�� ���� �ð��� ������ ����ϴ� �Լ�
{
	int total_time2;
	int h1, m1, h2, m2;
	printf("���� ���� �ð��� �Է��ϼ���(��ø������ �Է�): ");   //�� ���� �ð� ���ϱ�
	scanf_s("%d�� %d��", &h1, &m1);
	printf("���� ���� �ð��� �Է��ϼ���(��ø������ �Է�):");
	scanf_s("%d�� %d��", &h2, &m2);
	total_time2= (60 * h2 + m2) - (60 * h1 + m1);
	
	return total_time2;
}*/