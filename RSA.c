#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


/*
* function: Euclid algorithm
* input: nonnegative integer a, positive integer b
* return: the result of gcd(a, b)
* Use gcd(a, b) = gcd(a, a mod b)
*/

int euclid_fun(int a, int b) {

	if (b == 0) {
		return a;
	}
		
	else {
		euclid_fun(b, a % b);
	}
		
}


/*
* function: Repeated squaring algorithm
* input: cyphertext message m, private key d, public key n
* return: the result of reminder
*/

int mod_fun(int m, int d, int n) {

	int mod = 1;

	while (d > 0) {
		if (d % 2 == 1) {
			mod = (mod * m) % n;
		}
		m = (m * m) % n;
		d = d / 2;
	}

	return mod;
}


int main() {

	int e, n, msg;
	int gcd = 0, a, b, t;
	int d = 0, co = 0, org;

	// Enter the public key (e and n)
	printf("Enter the public key (e, n): ");
	scanf("%d %d", &e, &n);

	// Enter the cyphertext message
	printf("Enter the ciphertext message: ");
	scanf("%d", &msg);

	a = n - 1;

	// Find prime numbers a and b
	while (gcd != 1) {
		b = n / a;
		if (a * b == n) {
			gcd = euclid_fun(a, b);
		}
		a--;
	}
	a++;

	// Calculate t : Euler totient
	t = (a - 1) * (b - 1);

	// Find d : private key
	while (1) {
		d = (co * t + 1) / e;
		// Find d that e * d mod 1
		if (d * e == (co * t + 1)) {  
			break;
		}
		co++;
	}

	// Decryption : Using Repeated squaring algorithm
	org = mod_fun(msg, d, n);

	// Print the original message
	printf("Original message: %d", org);

}