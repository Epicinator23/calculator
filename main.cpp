#include "calculations.h"

void quit(ActionData& action_data) {
	action_data.getOutStream() << "Thank you for running this program.\nContributions are encouraged via Venmo @Epicinator23\n";
}

void configureMenu(MenuData& menu_data) {
	menu_data.addFunction(&quit, "Exit the program");
	menu_data.addFunction(&add, "Add two numbers");
	menu_data.addFunction(&subtract, "Subtract two numbers");
	menu_data.addFunction(&multiply, "Multiply two numbers");
	menu_data.addFunction(&divide, "Divide two numbers");
	menu_data.addFunction(&exponent, "Raise a number to some exponent");
	menu_data.addFunction(&logarithm, "Take the log of a number with some base");
}

void printWelcome(ActionData& action_data) {
	action_data.getOutStream() << "\n  Welcome!\n\tThis is a calculator.\n\t\tA very boring calculator.\n";
}

void presentOptions(MenuData& menu_data, ActionData& action_data) {
	ostream& os = action_data.getOutStream();

	os << "\n\nHere are your options:";

	for (int i = 0; i < menu_data.getSize(); i++) {
		os << "\n[" << i << "] " << menu_data.getDescription(i);
	}

	os << "\nWhich option would you like?\n";
}

int main() {
	ActionData action_data(cin, cout);
	MenuData menu_data;

	printWelcome(action_data);
	configureMenu(menu_data);

	int choice;
	do {
		presentOptions(menu_data, action_data);
		action_data.getInStream() >> choice;	// I need to check non-number entries. Program currently exits normally with letters, etc...
		if (menu_data.isValid(choice)) {
			menu_data.getFunction(choice)(action_data);
		} else {
			action_data.getOutStream () << "Your choice did not match one of the options.\nPlease try again.";
		}
	} while (choice != 0);
	return 0;
}