#include "functions.h"		// using namespace std;

// sets up menu_data. Add raw literals here for new functions.
void configureMenu(MenuData& menu_data) {
	menu_data.addFunction(&add, "+", "Add two numbers", "First addend", "Second addend", "Sum");
	menu_data.addFunction(&subtract, "-", "Subtract two numbers", "Minuend", "Subtrahend", "Difference");
	menu_data.addFunction(&multiply, "*", "Multiply two numbers", "First Factor", "Second Factor", "Product");
	menu_data.addFunction(&divide, "/", "Divide two numbers", "Dividend", "Divisor", "Quotient");
	menu_data.addFunction(&addMatrices, "+", "Add two matrices", "First matrix", "Second matrix", "Sum matrix");
	menu_data.addFunction(&subtractMatrices, "-", "Subtract two matrices", "Minuend matrix", "Subtrahend matrix", "Difference Matrix");
	menu_data.addFunction(&multiplyMatrices, "*", "Multiply two matrices", "First matrix", "Second matrix", "Product matrix");
	menu_data.addFunction(&divideMatrices, "/", "Multiply a matrix by the inverse of another matrix", "Dividend matrix", "Divisor matrix", "Quotient matrix");
}

// Simple welcome printer function
void printWelcome(ActionData& action_data) {
	action_data.getOutStream() << "\n  Welcome!\n\tThis is a calculator.\n\t\tA mildly boring calculator.\n";
}

// The heart of the program. Everything ends up running through here that needs to
int main() {
	ActionData action_data(cin, cout);
	MenuData menu_data;

	printWelcome(action_data);
	configureMenu(menu_data);

	int choice;

	while (action_data.getQuitter() == false) {	// running program engine
		presentOptions(menu_data, action_data);
		choice = getChoice(menu_data, action_data);	// ensures choice is a valid option
		if (choice == 0) {
			menu_data.getFunction(choice)(action_data);
		} else {
			doMath(menu_data, action_data);
		}
	}
	return 0;
	// Please print all three matrices at once :)
}
