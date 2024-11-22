#include "calculations.h"

void printWelcome(ActionData& action_data) {
	action_data.getOutStream() << "\n  Welcome!\n\tThis is a calculator.\n\t\tA very boring calculator.\n";
}

int presentOptions(ActionData& action_data) {
	action_data.getOutStream() << "\n\nHere are the calculations you may perform:\n"
		<< "[1] Add two numbers\n"
		<< "[2] Subtract two numbers\n"
		<< "[3] Multiply two numbers\n"
		<< "[4] Divide two numbers\n"
		<< "[5] Raise a number to some exponent\n"
		<< "[6] Take the log a number with some base\n"
		<< "Which option would you like?\n";
	int input;
	scanf("%d", &input);
	return input;
}


int main() {
	ActionData action_data(cin, cout);

	printWelcome(action_data);

	int choice;
	do {
		choice = presentOptions(action_data);
		switch (choice) {
		case 1:
			add(action_data);
			break;
		case 2:
			subtract(action_data);
			break;
		case 3:
			multiply(action_data);
			break;
		case 4:
			divide(action_data);
			break;
		case 5:
			exponent(action_data);
			break;
		case 6:
			logarithm(action_data);
			break;
		default:
			action_data.getOutStream () << "Your choice did not match one of the options.\nThe program will now close.\n";
			return 1;
			break;
		}
	} while (choice >=1 && choice <= 6);
	return 0;
}