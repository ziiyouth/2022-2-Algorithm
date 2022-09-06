#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <math.h>


void main() {

	while (1) {

		int studentNum = 0, totalMoney = 0, avgMoney = 0, equalCost = 0;
		scanf("%d", &studentNum);

		if (studentNum == 0) {
			break;
		}

		if (studentNum > 100) {
			printf("\nThe number of students cannot exceed 100.");
			printf("\nPlease enter the number of students again.\n");
			scanf("%d", &studentNum);
		}

		// Dynamic memory allocation for total number of students
		int* money = (int*)malloc(sizeof(studentNum) / sizeof(int));

		for (int i = 0; i < studentNum; i++) {
			scanf("%d", &money[i]);
			totalMoney += money[i];
		}

		// Find the average value excluding the unit of error of \10
		avgMoney = floor((totalMoney / studentNum) / 10) * 10;

		// Find the sum of the money that has to be moved
		for (int i = 0; i < studentNum; i++) {
			if (avgMoney > money[i]) {
				equalCost += avgMoney - money[i];
			}
		}

		printf("$%d", equalCost);
		printf("\n");

	}

}