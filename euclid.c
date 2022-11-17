#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int euclid(int a, int b, int* x, int* y) {

	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}

	else {
		int n = 0, m = 0;
		int d = euclid(b, a % b, &n, &m);
		*x = m;
		*y = n - (a / b) * (m);
		return d;
	}
}

int main() {

	int a, b, x, y;

	scanf("%d %d", &a, &b);

	printf("%d %d %d", x, y, euclid(a, b, &x, &y));

}