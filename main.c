#include <stdio.h>

#include "calculations.h"

void printWelcome() {
	printf("Welcome.\n\tThis is a calculator.\n\t\tA very boring calculator.\n");
	return;
}

int presentOptions() {
	printf("Here are the calculations you may perform:\n");
	printf("[1] Add two numbers\n");
	printf("[2] Subtract two numbers\n");
	printf("[3] Multiply two numbers\n");
	printf("[4] Divide two numbers\n");
	printf("[5] Raise a number to some exponent\n");
	printf("[6] Take the log a number with some base\n");
	printf("Which option would you like?\n");
	int input;
	scanf("%d", &input);
	return input;
}


int main() {
	printWelcome();
	
	int choice;
	choice = presentOptions();

	switch (choice) {
	case 1:
		add();
		break;
	case 2:
		subtract();
		break;
	case 3:
		multiply();
		break;
	case 4:
		divide();
		break;
	case 5:
		exponent();
		break;
	case 6:
		logarithm();
		break;
	default:
		printf("Your choice did not match one of the options.\nThe program will now close.\n");
		return 1;
		break;
	}
	return 0;
}