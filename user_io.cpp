#include <iostream>
#include <string>
#include <sstream>

#include "functions.h"

// returns a string, no error checking yet
string getString(ActionData& action_data, const string& prompt) {
	string result;

	action_data.getOutStream() << prompt;
	action_data.getInStream() >> result;

	return result;
}

//	ensures output is a valid integer and won't accept floats to truncate
int getInteger(ActionData& action_data, const string& prompt) {
	string input;
	int result, count = 0;
	bool converted = false, correctChars;

	while (!converted) {
		correctChars = true;
		if (count % 10 == 0) {
			action_data.getOutStream() << prompt;
		}

		action_data.getInStream() >> input;

		if (input.empty()) {
			cerr << "Error: Input is empty. Try again" << endl;
			continue;
		}

		for (size_t i = 0; i < input.size(); i++) {
			if (!isdigit(input[i]) && !(i == 0 && (input[i] == '-' || input[i] == '+'))) {
				correctChars = false;
				break;
			}
		}

		if (correctChars) {
			try {
				result = stoi(input);
				converted = true;
			} catch (const invalid_argument& e) {
				cerr << "Error: Number not detected. Try again." << endl;
			} catch (const out_of_range& e) {
				cerr << "Error: Number out of range. Try again." << endl;
			}
		} else {
			action_data.getOutStream() << "Input contains incorrect characters. Try again." << endl;
		}

		count++;
	}
	return result;
}

// ensures output is a valid float with no extra characters a decimal and as many digits as a double holds... oh and a + or - to start.
double getDouble(ActionData& action_data, const string& prompt) {
	string input;
	double result;
	int decimalCount;
	bool converted = false, correctChars;

	while (!converted) {
		correctChars = true;
		decimalCount = 0;

		action_data.getOutStream() << prompt;

		action_data.getInStream() >> input;

		for (size_t i = 0; i < input.size(); i++) {
			if (input[i] == '.') {
				decimalCount++;
			} else if (!isdigit(input[i]) && !(i == 0 && (input[0] == '-' || input[0] == '+'))) {
				correctChars = false;
				cerr << "Input contains incorrect characters. Try again." << endl;
				break;
			}
		}

		if (decimalCount > 1) {
			correctChars = false;
			cerr << "Numbers don't have more than one decimal. Try again." << endl;
		}

		if (correctChars) {
			try {
				result = stod(input);
				converted = true;
			} catch (const invalid_argument& e) {
				cerr << "Error: Number not detected. Try again." << endl;
			} catch (const out_of_range& e) {
				cerr << "Error: Number out of range. Try again." << endl;
			}
		}
	}
	return result;
}

// Presents descriptions of commands loaded into menu_data along with numbers assigned to each action
void presentOptions(MenuData& menu_data, ActionData& action_data) {
	ostream& os = action_data.getOutStream();

	os << "\nHere are your options:\n";

	for (int i = 0; i < menu_data.getSize(); i++) {
		os << "[" << i << "] " << menu_data.getDescription(i) << "\n";
	}

	os << "Which option would you like?";
}

// Throws out options from menu data and gets a response. Will not accept, or crash with, invalid choices.
int getChoice(MenuData& menu_data, ActionData& action_data) {
	string input;
	int choice, count = 1;

	do {
		if (count % 10 == 0) {
			presentOptions(menu_data, action_data);
		}

		choice = getInteger(action_data, "\n");

		if (menu_data.isValid(choice)) {
			action_data.Choose(choice);
		} else {
			cerr << "That is not an option. Please try again." << endl;
		}

		count++;
		//cout << menu_data.isValid(choice) << " is the result of isValid" << endl;
	} while (!menu_data.isValid(choice));
	return choice;
}

Matrix getMatrix(ActionData& action_data, string& prompt) {
	string entry_prompt;
	double number;

	action_data.getOutStream() << prompt;

	int rows = getInteger(action_data, "Row count: ");
	int columns = getInteger(action_data, "Column count: ");

	Matrix matrix(rows, columns);

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			entry_prompt = "Entry [" + to_string(row+1) + "," + to_string(column+1) + "]=";
			number = getDouble(action_data, entry_prompt);
			matrix.enterElement(row, column, number);
		}
	}
	return matrix;
}
