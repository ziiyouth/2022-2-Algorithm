#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// Check string matches from the back
// Repeat as a recursive function and add 1 if there is a string
int subseq(char* strX, char* strZ, int m, int n) {

	if (n > m) {
		return 0;
	}

	if (m == 0 || n == 0) {
		return 1;
	}
	else if (strX[m - 1] == strZ[n - 1]) {
		return subseq(strX, strZ, m - 1, n) + subseq(strX, strZ, m - 1, n - 1);
	}
	else
		return subseq(strX, strZ, m - 1, n);
}


void main() {
	
	char stringX[10000];
	char stringZ[100];
	int num = 0;

	printf("Enter the number of test cases : ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {

		printf("Enter string X : ");
		scanf("%s", stringX);

		printf("Enter string Z : ");
		scanf("%s", stringZ);

		printf("The number of distinct occurrences of Z in X : %d\n", subseq(stringX, stringZ, strlen(stringX), strlen(stringZ)));
	}

}