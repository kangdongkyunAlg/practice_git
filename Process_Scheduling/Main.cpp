#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "CircularQueue.h"
#include "eachTime.h"
#include "Interface.h"
#include "Scheduling.h"
#include "GantTable.h"

Time nt[PROCESSNUMBERMAX];
Time tempT;

Gant dopyo[100];//비선점 알고리즘 도표 출력 위함 어느정도 큰 배열

void InitImformation();

int main() {
	Menu();
}
void Menu() {
	int select = 0;
	int NumberOfProcess=5;
	int TimeQuantum;
	while (1) {
		printf("1.FCFS \n2.RR\n3. SPN\n4. SRTN\n5.HRRN\n6. exit()\n");
		scanf("%d", &select);
		if (select == 2) {
			printf("사용제한시간 : ");
			scanf("%d", &TimeQuantum);
		}
		if (select == 6) {
			system("cls");
			printf("프로그램을 종료합니다...\n");
			break;
		}

		//printf("프로세스 갯수 입력 : ");
		//scanf("%d", &NumberOfProcess);
		//Input_Time(NumberOfProcess);
		Input_Debug();
		switch (select)
		{
			//FCFS
		case 1:
			system("cls");
			FCFS(NumberOfProcess);
			break;
			//RR
		case 2:
			system("cls");
			RR(NumberOfProcess, TimeQuantum);
			break;
			//SPN
		case 3:
			system("cls");
			SPN(NumberOfProcess);
			break;
			//SRTN
		case 4:
			SRTN(NumberOfProcess);
			break;
			//HRRN
		case 5:
			HRRN(NumberOfProcess);
			break;

		default:

			break;
		}
		system("cls");
		printTable(NumberOfProcess, select);
	}
}
void Input_Debug() {
	nt[0].arrivalTime = 0;

	nt[0].burstTime = 3;

	nt[1].arrivalTime = 1;

	nt[1].burstTime = 7;

	nt[2].arrivalTime = 3;

	nt[2].burstTime = 2;

	nt[3].arrivalTime = 5;

	nt[3].burstTime = 5;

	nt[4].arrivalTime = 6;

	nt[4].burstTime = 3;

}
void Input_Time(int n) {

	/*
	*/for (int i = 0; i < n; i++) {

		system("cls");

		printf("P[%d]Enter Process Arrival Time\n", i + 1);

		scanf("%d", &nt[i].arrivalTime);

		printf("P[%d]Enter Process Burst Time\n", i + 1);

		scanf("%d", &nt[i].burstTime);

	}


printf("ArrivalTime\tBurstTime\n");

for (int i = 0; i < n; i++) {

	printf("%d\t\t%d\n", nt[i].arrivalTime, nt[i].burstTime);

}


}
void makeGante(int preemptive) {

	int color = 10;
	int start, end;
	int k = 0;
	int count = 0;
	//FCFS
	if (preemptive == 0) {
		for (int i = 0; i < PROCESSNUMBERMAX; i++) {
			start = nt[i].arrivalTime + nt[i].waitingTime;
			end = nt[i].arrivalTime + nt[i].trunaroundTime;
			for (int j = start; j < end; j++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				printf("■");
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(100);
			}
			color++;
		}
	}
	//RR
	else if (preemptive == 1) {
		while (dopyo[k].id != 0 && dopyo[k].lengh != 0) {
			if (dopyo[k].id == 1) color = 10;//p1
			else if (dopyo[k].id == 2) color = 11;//p2
			else if (dopyo[k].id == 3) color = 12;//p3
			else if (dopyo[k].id == 4) color = 13;//p4
			else if (dopyo[k].id == 5) color = 14;//p5
			for (int i = 0; i < dopyo[k].lengh; i++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				printf("■");
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(100);
			}
			k++;
		}
	}
	//SPN
	else if (preemptive == 2) {
		while (dopyo[k].id != 0 && dopyo[k].lengh != 0) {
			if (dopyo[k].id == 1) color = 10;//p1
			else if (dopyo[k].id == 2) color = 11;//p2
			else if (dopyo[k].id == 3) color = 12;//p3
			else if (dopyo[k].id == 4) color = 13;//p4 
			else if (dopyo[k].id == 5) color = 14;//p5
			for (int i = 0; i <dopyo[k].lengh; i++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				printf("■");
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(100);
			}
			k++;
		}
	}

	//HRRN
	else if (preemptive == 4) {
		while (dopyo[k].id != 0 && dopyo[k].lengh != 0) {
			if (dopyo[k].id == 1) color = 10;//p1
			else if (dopyo[k].id == 2) color = 11;//p2
			else if (dopyo[k].id == 3) color = 12;//p3
			else if (dopyo[k].id == 4) color = 13;//p4 
			else if (dopyo[k].id == 5) color = 14;//p5
			for (int i = 0; i <dopyo[k].lengh; i++) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				printf("■");
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Sleep(100);
			}
			k++;
		}
	}

	//단위 출력 부분
	printf("\n");
	for (int i = 0; i <= 20; i++) {
		printf("%d   ", i % 10);
	}
	printf("\n");
	printf("\t\t\t\t\t10\t\t\t\t\t20\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("P1\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("P2\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("P3\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("P4\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("P5\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
void printTable(int n, int sel) {

	int preemptive;
	//system("cls");
	if (sel == 1) {
		printf("----------------------------------------FCFS----------------------------------------\n\n");
		preemptive = 0;
	}
	else if (sel == 2) {
		printf("----------------------------------------RR----------------------------------------\n\n");
		preemptive = 1;
	}
	else if (sel == 3) {
		printf("----------------------------------------SPN----------------------------------------\n\n");
		preemptive = 2;
	}
	else if (sel == 4) {
		printf("----------------------------------------SRTN----------------------------------------\n\n");
		preemptive = 3;
	}
	else if (sel == 5) {
		printf("----------------------------------------HRRN----------------------------------------\n\n");
		preemptive = 4;
	}

	/*간트 도표 출력할 곳*/

	makeGante(preemptive);

	/*표 출력할 곳*/
	printf("\n\n\n");
	printf("process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\t Normalized TT\n");
	for (int i = 0; i < n; i++) {
		printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.3f\n", i + 1, nt[i].arrivalTime, nt[i].burstTime, nt[i].waitingTime, nt[i].trunaroundTime, nt[i].NormalizedTT);
	}
}

//구조체 배열 식별자 등록, 남는시간, 전체시간 초기화
void InitImformation() {
	for (int i = 0; i < PROCESSNUMBERMAX; i++) {
		nt[i].id = i;
		nt[i].leavebTime = nt[i].burstTime;
		nt[i].totalTime = 0;

	}
}
void FCFS(int n) {
	int p_num = 0;//종료된 process 개수
	int p_id = 0;//실행중인 process
	int starttime = 0;//해당 process 시작 시간
	//int count = 0;//대기중인 process 갯수 Debug용
	QueueType ready;
	Time temp1;
	init(&ready);
	InitImformation();
	while (1) {
		//printf("%d", starttime);
		//진행중 도착한 프로세스 enqueue
		for (int i = 0; i < n; i++) {
			if ((i != p_num) && (starttime < nt[i].arrivalTime) && (starttime + nt[p_id].burstTime >= nt[i].arrivalTime)){
				enqueue(&ready, nt[i]);
				//count++ Debug용
			}
		}
		//현재 프로세스 WT,TAT,NTT 계산
		nt[p_id].endTime = starttime + nt[p_id].burstTime;
		nt[p_id].waitingTime = starttime-nt[p_id].arrivalTime;
		nt[p_id].trunaroundTime = nt[p_id].waitingTime + nt[p_id].burstTime;
		nt[p_id].NormalizedTT = (double)nt[p_id].trunaroundTime / nt[p_id].burstTime;

		//FCFS 종료
		p_num++;
		if (p_num == n)break;

		//프로세스 종료후 다음 프로세스 실행
		starttime = nt[p_id].endTime;
		//printf("%d\n", nt[p_id]);
		temp1 = dequeue(&ready);
		p_id = temp1.id;
	}
}
void RR(int n, int TQ) {
	int p_num = 0;//종료된 process 개수
	int p_id = 0;//실행중인 process
	int starttime = 0;//해당 process 시작 시간
	int count = 0;//대기중인 process 갯수 Debug용
	int k = 0;
	QueueType ready;
	Time temp1;
	init(&ready);
	InitImformation();
	while (1) {

		dopyo[k].id = p_id + 1;
		if (nt[p_id].leavebTime > TQ) {
			//정상 실행
			for (int i = 0; i < PROCESSNUMBERMAX; i++) {
				//실행중 도착한 프로세스 enqueue
				if ((p_id != i) && ((nt[i].arrivalTime > starttime) && (nt[i].arrivalTime <= starttime + TQ)))
				{
					enqueue(&ready, nt[i]);
					//printf("id : [%d] , leaveTime : [%d]\n", p_id + 1 ,nt[p_id].leavebTime);
				}
			}

			dopyo[k].lengh = TQ;
			//현재 실행 프로세스 문맥교환
			starttime += TQ;
			nt[p_id].leavebTime -= TQ;
			enqueue(&ready, nt[p_id]);

		}
		else if (nt[p_id].leavebTime <= TQ) {
			//종료를 위한 실행
			for (int i = 0; i < PROCESSNUMBERMAX; i++) {
				//실행중 도착한 프로세스 인큐하기
				if ((p_id != i) && ((nt[i].arrivalTime > starttime) && (nt[i].arrivalTime <= starttime + nt[p_id].leavebTime)))
				{
					enqueue(&ready, nt[i]);
				}
			}
			if (nt[p_id].leavebTime == TQ)    starttime += TQ;
			else    starttime += nt[p_id].leavebTime;

			dopyo[k].lengh = nt[p_id].leavebTime;//도표 만들기위한 변수
			nt[p_id].leavebTime = 0;//해당 프로세스 exit
			nt[p_id].endTime = starttime;//종료시간 저장
			p_num++;
			//현재 프로세스 WT,TAT,NTT 계산
			nt[p_id].totalTime = nt[p_id].endTime - nt[p_id].arrivalTime;
			nt[p_id].waitingTime = nt[p_id].totalTime - nt[p_id].burstTime;
			nt[p_id].trunaroundTime = nt[p_id].waitingTime + nt[p_id].burstTime;
			nt[p_id].NormalizedTT = (double)nt[p_id].trunaroundTime / nt[p_id].burstTime;
			//종료조건
			if (p_num == 5)    break;
		}
		//다음 실행될 프로세스 dequeue
		temp1 = dequeue(&ready);
		p_id = temp1.id;
		k++;//간트도표를 만들기 위한 변수 
	}
}
void SPN(int n) {
	int p_num = 0;//종료된 process 개수
	int p_id = 0;//실행중인 process
	int starttime = 0;//해당 process 시작 시간
	int count = 0;//대기중인 process 갯수 Debug용
	int k = 0;
	QueueType ready;
	Time temp1,temp2;
	Time s_temp[PROCESSNUMBERMAX];//정렬하기 위한 배열
	init(&ready);
	InitImformation();
	while (1) {
		//진행중 도착한 프로세스 enqueue
		dopyo[k].id = p_id + 1;
		for (int i = 0; i < n; i++)
		{
			if ((nt[i].leavebTime != 0) && (i != p_id) && ((starttime < nt[i].arrivalTime) && (starttime + nt[p_id].burstTime >= nt[i].arrivalTime)))
			{
				enqueue(&ready, nt[i]);
				//printf("<%d> \n",i+ 1);
				count++;
			}
		}
		//실행 시간 기준으로 정렬
		for (int i = 0; i < count; i++)
		{
			s_temp[i] = dequeue(&ready);
		}
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - 1; j++)
			{
				if (s_temp[j].burstTime > s_temp[j + 1].burstTime)
				{
					temp2 = s_temp[j + 1];
					s_temp[j + 1] = s_temp[j];
					s_temp[j] = temp2;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			enqueue(&ready, s_temp[i]);
		}
		//현재 프로세스 종료 
		dopyo[k].lengh = nt[p_id].burstTime;
		nt[p_id].leavebTime = 0;
		//현재 프로세스 WT,TAT,NTT 계산
		nt[p_id].waitingTime = starttime - nt[p_id].arrivalTime;
		nt[p_id].trunaroundTime = nt[p_id].burstTime + nt[p_id].waitingTime;
		nt[p_id].NormalizedTT = (double)nt[p_id].trunaroundTime / nt[p_id].burstTime;

		//종료조건 : process가 n개 종료되는 그 순간
		p_num++;
		if (p_num == n)		break;
		//dequeue 다음 프로세서 지정
		starttime += nt[p_id].burstTime;
		temp1 = dequeue(&ready);
		p_id = temp1.id;
		count = 0;
		k++;
	}
}
void SRTN(int n) {
	int p_num = 0;//종료된 process 개수
	int p_id = 0;//실행중인 process
	int starttime = 0;//해당 process 시작 시간
	int starttemp = starttime;
	int count = 0;//대기중인 process 갯수 Debug용
	QueueType ready;
	Time temp1, temp2;
	Time s_temp[PROCESSNUMBERMAX];//정렬하기 위한 배열
	init(&ready);
	InitImformation();
	while (1) {
		break;
	}
}
void HRRN(int n) {
	int p_num = 0;//종료된 process 개수
	int p_id = 0;//실행중인 process
	int starttime = 0;//해당 process 시작 시간
	int count = 0;//대기중인 process 갯수 Debug용
	int k = 0;
	QueueType ready;
	Time temp1, temp2;
	Time s_temp[PROCESSNUMBERMAX];//정렬하기 위한 배열
	init(&ready);
	InitImformation();
	while (1) {

		dopyo[k].id = p_id + 1;//도표

		//printf("%d\n", starttime);
		//진행중 도착한 프로세스 인큐		
		for (int i = 0; i < n; i++)	{
			if ((nt[i].leavebTime != 0) && (i != p_id) && ((starttime < nt[i].arrivalTime) && (starttime + nt[p_id].burstTime >= nt[i].arrivalTime))){
				enqueue(&ready, nt[i]);
				count++;
			}
		}
		//printf("<%d> \n", count);

		//현재 프로세스 종료
		nt[p_id].leavebTime = 0;
		
		//각 시간 구하기
		nt[p_id].waitingTime = starttime - nt[p_id].arrivalTime;
		nt[p_id].trunaroundTime = nt[p_id].burstTime + nt[p_id].waitingTime;
		nt[p_id].NormalizedTT = (double)nt[p_id].trunaroundTime / nt[p_id].burstTime;

		dopyo[k].lengh = nt[p_id].burstTime;//도표
		//종료조건 : process가 n개 종료되는 그 순간
		p_num++;
		if (p_num == n)		break;

		//응답률 기준으로 정렬
		for (int i = 0; i < count; i++)
		{
			s_temp[i] = dequeue(&ready);
		}
		for (int i = 0; i < count; i++)
		{	
			s_temp[i].waitingTime = starttime +nt[p_id].burstTime - s_temp[i].arrivalTime;
			//printf("%d  ", s_temp[i].waitingTime);
			s_temp[i].ResponseRatio = (double)(s_temp[i].waitingTime + s_temp[i].burstTime) / s_temp[i].burstTime;
		}
		//printf("\n");
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - 1; j++)
			{
				if (s_temp[j].ResponseRatio < s_temp[j + 1].ResponseRatio)
				{
					temp2 = s_temp[j + 1];
					s_temp[j + 1] = s_temp[j];
					s_temp[j] = temp2;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			enqueue(&ready, s_temp[i]);
			//s_temp[i].ResponseRatio = 0;
		}
		//=>정렬 끝

		
		//dequeue한 process p_id 저장
		starttime += nt[p_id].burstTime;
		//printf("%d  ", p_id);
		temp1 = dequeue(&ready);
		count--;
		p_id = temp1.id;
		k++;
	}
}