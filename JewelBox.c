#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int find(int jewel, int* c, int* n) {

	// first : Select if the cost performance is good between the two cases
	int first = n[0] / c[0] >= n[1] / c[1] ? 0 : 1;
	int count[2];
	int rest = 0;

	// rest : Use the first as much as you can and the remaining value
	count[first] = jewel / n[first];
	rest = jewel % n[first];

	// Determine if it is divided against the remaining number
	while (rest % n[1 - first]) {
		count[first]--;
		rest += n[first];

		// End with fail when negative
		if (count[first] < 0) {
			printf("failed\n");
			return 0;
		}
	}

	// Output results if divided
	count[1 - first] = rest / n[1 - first];
	printf("%d   %d\n", count[0], count[1]);
	return 0;
}

void main() {

	int jewel = 0;
	int c[2], n[2];

	while (1) {
		scanf("%d", &jewel);

		// Exit only when 0 is entered
		if (jewel == 0)
			exit(0);

		for (int i = 0; i < 2; i++) {
			scanf("%d %d", &c[i], &n[i]);
		}
		find(jewel, c, n);
	}
}