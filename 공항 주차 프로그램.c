/*#include <stdio.h>
#include<string.h>
int calculate(void);
int main(void)
{
	int total_time = 0,             //전체 시간
	    h1=0, m1=0, h2=0, m2=0,              //주차 시작시 시,분 /주차 종료시 시,분
		add_time = 0,               //추가된 시간 
		add_fare = 0,               //추가 요금
		total_fare = 0,             //전체 요금
		n = 0;                      //자동차 몇 종 나타내는 변수
	char str1[5] = "단기";          //str1배열에 단기 저장
	char str2[5] = "장기";          //str2배열에 장기 저장
	char str3[5]=  "\0";                  //장기,단기 중 하나 입력 후 저장해 str1,2와 비교할 배열 초기화
	char str4[3] = "네";            //str4배열에 네 저장
	char str5[7] = "아니요";          //str5배열에 아니요 저장
	char str6[7] = "\0";              //네 아니요 중 하나를 입력후 저장해 str4,5와 비교할 배열 초기화
	char str7[5] = "소형";        //str7배열에 소형 저장
	char str8[5] = "대형";         //str8배열에 대형 저장
	char str9[5] = "\0";                  //소형 대형 중 하나를 입력후 저장해 str7,8과 비교할 배열 초기화
	printf("장기주차장이면 장기, 단기 주차장이면 단기라고 입력하세요; ");
	scanf_s("%s", str3, sizeof(str3));             //배열str3에 장기, 단기 중 하나 입력
	if (strcmp(str1, str3) == 0)                   //만약 str1=str3이면(둘다 단기) 참 ->if문 실행
	{
		 total_time = calculate();       //총 주차 시간을 분으로 계산하는 함수 호출
		                                                  
		if (total_time <= 30)                        //전체 이용시간(total_time)이 30분이하 ->1200원
		{
			total_fare = 1200;                      
		}
		else if (total_time > 30 && total_time < 600)   //전체 이용 시간이 30분 초과 10시간 미만
		{
			add_time = total_time - 30;                 //추가된 시간 = 전체시간 - 기본시간
		    add_fare = (add_time / 15) * 600;                 // 1분당 요금 *600원
			if (add_time % 15 != 0)                    //추가된 시간이 15분 배수가 아닐때
			{
				add_fare = add_fare + 600;       //15분보다 작아도 1분만 올라가도 요금이 올라가고 
			}                                     //add_timeD에 몫만 저장되므로 1분당 요금에 600원을 더해줌
			total_fare = 1200 + add_fare;         //전체 요금 = 기본요금 + 추가요금
		}
		else if (total_time >= 600)             //전체 시간이 10시간 이상일 경우
		{
			total_fare = 24000;                 //10시간 부터 24시간까지 하루 최대 요금 ->24000원
		}
		printf("저공해 자동차입니까?(네/아니요): "); //출력하기 앞서 조건들을 걸어줌
		scanf_s("%s", str6, sizeof(str6));             //네 또는 아니요를 str6에 저장
		if (strcmp(str4, str6) == 0)                  // str4(네)와 비교해서 동일하면(둘 다 '네')-> if문 출력
		{
		    printf("몇 종 자동차입니까?: ");
		    scanf_s("%d", &n);
			if ((n == 1) || (n == 2)) {
				printf("총 이용요금은:%d원입니다. ", total_fare / 2);
			}
			else if (n == 3) {
				printf("총 이용요금은:%d원입니다. ", total_fare * 80 / 100);
			}
		}
		else if (strcmp(str5, str6) == 0)    // str5(아니요)와 비교해서 동일하면(둘 다 '아니요')-> else if문 출력
		{
		printf("차량이 경차이거나 장애인 국가유공자,5.18민주유공자,고엽제 후유증환자, 장애인 협회 또는 단체차량,다자녀가구 중 해당사항이 있으십니까?(네/아니요): ");               
		scanf_s("%s", str6, sizeof(str6));      //str6에 다시 네 or 아니요를 저장
		if (strcmp(str4, str6) == 0)            //str4(네) == str6 (둘 다 '네'가 저장)
			printf("총 이용요금은:%d원입니다. ", total_fare / 2);
		else if (strcmp(str5, str6) == 0)       //str5(아니요) == str6 (둘 다 '아니요' 저장)
			printf("총 이용요금은:%d원입니다. ", total_fare);
		}
		
	}
	else if (strcmp(str2, str3) == 0)           //str2 == str3 (둘 다 '장기' 저장) 
	{
		printf("자동차가 대형이면 대형, 소형이면 소형으로 입력해주세요:"); //소형인지 대형인지 구분
		scanf_s("%s", str9, sizeof(str9));                                 //str9에 소형 또는 대형 저장
		if (strcmp(str7, str9) == 0)                   //str7(소형)==str9(둘 다 소형 저장되있는 경우)
		{
			total_time = calculate();                 //총 주차 시간을 분으로 계산
            total_fare = (total_time / 60) * 1000;          // 기본 요금 없고 시간 당 1000원.
			if (total_time < 540)                            //9시간까지는 1시간 당 1000원 추가
			{
				if (total_time % 60 != 0)                  //전체 시간이 60분 단위가 아닌경우
				{
					total_fare = total_fare + 1000;
				}
				total_fare;
			}
			else if (total_time >= 540 && total_time <= 1440)  //전체시간 9시간이상 24시간 이내->하루최대 요금(9000원)
			{
				total_fare = 9000;
			}
			printf("저공해 자동차인가?(네/아니요): ");      //저공해 자동이차인 경우
			scanf_s("%s", str6, sizeof(str6));
			if (strcmp(str4, str6) == 0)
			{
				printf("몇 종 자동차인가? :");
				scanf_s("%d종", &n);
				if ((n == 1) || (n == 2))
					printf("총 이용요금은:%d원입니다. ", total_fare / 2);
				else if (n == 3)
					printf("총 이용요금은:%d원입니다. ", total_fare * 80 / 100);
			}
			else if (strcmp(str5, str6) == 0)         //저공해 자동차가 아닌 경우
			{
				printf("차량이 경차이거나 장애인 국가유공자,5.18민주유공자,고엽제 후유증환자, 장애인 협회또는 단체차량,다자녀가구 중 해당사항이 있으십니까?(네/아니요): ");  //다른 감면 대상인가 물어봄
				scanf_s("%s", str6, sizeof(str6));
				if (strcmp(str4, str6) == 0)
					printf("총 이용요금은:%d원입니다. ", total_fare / 2);
				else if (strcmp(str5, str6) == 0)
					printf("총 이용요금은:%d원입니다. ", total_fare);
			}
		}
		else if (strcmp(str8, str9) == 0)    //str8(대형)==str9 (대형차인 경우)
		{
			total_time = calculate();                           //총 주차 시간을 분으로 계산
            total_fare = (total_time / 30) * 1200;          //기본요금x ,30분 당 1200원 추가
			if (total_time < 300)                           //5시간보다 적은 경우
			{
				if (total_time % 30 != 0)                    //전체 시간이 30분 단위가 아닐 경우
				{
					total_fare += 1200;
				}
				total_fare;
			}
			else if (total_time >= 300 && total_time <= 1440)  //5시간 이상 24시간 이내일 경우->12000원
			{
				total_fare = 12000;                       
			}
			printf("저공해 자동차인가?(네/아니요): ");             
			scanf_s("%s", str6, sizeof(str6));
			if (strcmp(str4, str6) == 0)                        //저공해 자동차일경우 (네)
			{
				printf("몇 종 자동차인가?: ");                    
				scanf_s("%d종", &n);
				if ((n == 1) || (n == 2))
					printf("총 이용요금은:%d원입니다. ", total_fare / 2);
				else if (n == 3)
					printf("총 이용요금은:%d원입니다. ", total_fare * 80 /100);
			}
			else if (strcmp(str5, str6) == 0)               // 저공해 자동차가 아닐경우 (아니요)
			{
				printf("차량이 경차이거나 장애인 국가유공자,5.18민주유공자,고엽제 후유증환자, 장애인 협회 또는 단체차량,다자녀가구 중 해당사항이 있으십니까?(네/아니요):");
				scanf_s("%s", str6, sizeof(str6));
				if (strcmp(str4, str6) == 0)
					printf("총 이용요금은:%d원입니다. ", total_fare / 2);
				else if (strcmp(str5, str6) == 0)
					printf("총 이용요금은:%d원입니다. ", total_fare);
			}
		}
	}
    return 0;
}
int calculate(void)                     //총 주차 시간을 분으로 계산하는 함수
{
	int total_time2;
	int h1, m1, h2, m2;
	printf("주차 시작 시간을 입력하세요(몇시몇분으로 입력): ");   //총 주차 시간 구하기
	scanf_s("%d시 %d분", &h1, &m1);
	printf("주차 종료 시간을 입력하세요(몇시몇분으로 입력):");
	scanf_s("%d시 %d분", &h2, &m2);
	total_time2= (60 * h2 + m2) - (60 * h1 + m1);
	
	return total_time2;
}*/