#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Dress {
	int idx;
	int time;
	int pen;
	float efficiency;
};

void main() {

	int test_num = 0;
	int job_num = 0;

	struct Dress dress[1000] = { 0 };
	struct Dress temp = { 0 };

	scanf("%d", &test_num);
	// Handling Non-Conditional Value Exceptions
	if (test_num < 1 || test_num>1000) {
		printf("Error. Please enter a value that fits the range. \n");
		exit(0);
	}

	scanf("%d", &job_num);
	for (int i = 0; i < job_num; i++) {
		scanf("%d %d", &dress[i].time, &dress[i].pen);
		dress[i].idx = i;

		// Handling Non-Conditional Value Exceptions
		if (dress[i].pen < 1 && dress[i].pen>10000) {
			printf("Error. Please enter a value that fits the range. \n");
			exit(0);
		}
	}
	
	// Enter idx, the completion time
	// and daily penalty into the structure and obtain efficiency.
	for (int i = 0; i < job_num; i++) {
		dress[i].efficiency = (float)(dress[i].pen / dress[i].time);
	}

	// Prioritize work by comparing efficiencies.
	for (int i = 0; i < job_num - 1; i++) {
		for (int j = 0; j < job_num - 1 - i; j++) {
			if (dress[j].efficiency < dress[j + 1].efficiency) {
				temp = dress[j];
				dress[j] = dress[j + 1];
				dress[j + 1] = temp;
			}
		}
	}

	printf("\n\n");
	for (int i = 0; i < job_num; i++) {
		printf("%d ", dress[i].idx + 1);
	}

}