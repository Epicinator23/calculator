#include <stdio.h>
#include <math.h>

void add() {
	double a, b, c;
	printf("First addend: ");
	scanf("%lf", &a);
	printf("Second addend: ");
	scanf("%lf", &b);
	c = a + b;
	printf("Sum: %lf\n", c);
}

void subtract() {
	double a, b, c;
	printf("Minuend: ");
	scanf("%lf", &a);
	printf("Subtrahend: ");
	scanf("%lf", &b);
	c = a - b;
	printf("Difference: %lf\n", c);
}

void multiply() {
	double a, b, c;
	printf("First factor: ");
	scanf("%lf", &a);
	printf("Second factor: ");
	scanf("%lf", &b);
	c = a * b;
	printf("Product: %lf\n", c);
}

void divide() {
	double a, b, c;
	printf("Dividend: ");
	scanf("%lf", &a);
	printf("Divisor: ");
	scanf("%lf", &b);
	if (b != 0) {
		c = a / b;
		printf("Quotient: %lf\n", c);
	} else {
		printf("You cannot divide by 0. Nice try.\n");
	}
}

void exponent() {
	double a, b, c;
	printf("Base: ");
	scanf("%lf", &a);
	printf("Exponent: ");
	scanf("%lf", &b);
	c = exp(b * log(a));
	printf("Power: %lf\n", c);
}

void logarithm() {
	double a, b, c;
	printf("Argument: ");
	scanf("%lf", &a);
	printf("Base: ");
	scanf("%lf", &b);
	if (a > 0 && b > 0 && b != 1) {
		c = log(a) / log(b);
	} else if (a <= 0) {
		printf("You cannot find the log of a number less than or equal to 0.\n");
		return;
	} else if (b <= 0) {
		c = 0;
	} else if (b == 1) {
		c = a;
	}
	printf("Logarithm: %lf\n", c);
}