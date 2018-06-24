#pragma once
#define PROCESSNUMBERMAX 5

struct Time {
	int id;
	int arrivalTime;
	int burstTime;
	int leavebTime;
	int waitingTime;
	int trunaroundTime;
	int endTime;
	int totalTime;
	double NormalizedTT;
	double ResponseRatio;
};
