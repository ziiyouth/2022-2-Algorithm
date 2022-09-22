#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

// A structure that stores information about elephants
typedef struct elephants {
	int index;
	int kg;
	int iq;
} ele;

// Sort by return value in ascending order
int compare(const void* first, const void* second) {
	int com = ((ele*)first)->kg - ((ele*)second)->kg;
	if (com == 0) {
		return ((ele*)second)->iq - ((ele*)first)->iq;
	}
	else return com;
}

// maxArr: To find the maximum number
// idxArr: For connecting the selected idx
ele elephant[1002];
int maxArr[1002], idxArr[1002], result[1002];


int main() {
	int n = 0, i = 0, j = 0;
	int idx = 0;

	// Get input only before eof
	// Determine the number of elephants by n in the array
	while (scanf("%d %d", &elephant[n].kg, &elephant[n].iq) == 2) {
		elephant[n].index = n + 1;
		n++;
	}

	// Sort with qsort
	qsort(elephant, n, sizeof(ele), compare);

	// Since it is sorted by kg, look at the IQ and find possible options
	maxArr[0] = 1;
	for (i = 0; i < n; i++) {
		int max = 0;
		int maxIdx = -1;
		for (j = 0; j < i; j++)
		{
			if (elephant[i].iq < elephant[j].iq && elephant[i].kg != elephant[j].kg && max < maxArr[j]) {
				max = maxArr[j];
				maxIdx = j;
			}
		}
		maxArr[i] = max + 1;
		idxArr[i] = maxIdx;
	}

	// Find the biggest lenght
	int count = -1, maxIdx = 0;
	for (i = 0; i < n; i++) {
		if (maxArr[i] > count) {
			count = maxArr[i];
			maxIdx = i;
		}
	}
	printf("%d\n", count);

	// Obtaining an Array of Results
	while (1)
	{
		result[idx] = elephant[maxIdx].index;
		idx++;
		maxIdx = idxArr[maxIdx];
		if (maxIdx == -1) {
			break;
		}
	}

	// Print an Array of Results
	for (i = idx; i > 0; i--) {
		printf("%d\n", result[i - 1]);
	}
	return 0;
}