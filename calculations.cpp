#include <limits>
#include <string>
#include "functions.h"		// using namespace std;

// General function for binary operations. Only has access to functions in menu_data.
void doMath(MenuData& menu_data, ActionData& action_data) {
	int choice = action_data.getChoice();
	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();
	string prompt;

	if (choice <= 4) {	// Binary math is done here
		double a, b;

		prompt = menu_data.getFirstWord(choice) + ": ";
		a = getDouble(action_data, prompt);
		action_data.setOperand1(a);

		prompt = menu_data.getSecondWord(choice) + ": ";
		b = getDouble(action_data, prompt);
		action_data.setOperand2(b);

		menu_data.getFunction(choice)(action_data);	// Calling appropriate function that actually performs the math operation

		os << menu_data.getFinalWord(choice) << ":\n" << action_data.getOperand1() << " " << menu_data.getOperation(choice) << " " << action_data.getOperand2() << " = " << action_data.getResult() << "\n";
	} else {	// Matrix math is done here
		Matrix a, b;

		prompt = menu_data.getFirstWord(choice) + "...\n";
		a = getMatrix(action_data, prompt);
		action_data.setMatrix1(a);

		prompt = menu_data.getSecondWord(choice) + "...\n";
		b = getMatrix(action_data, prompt);
		action_data.setMatrix2(b);

		menu_data.getFunction(choice)(action_data);	// Calling appropriate function that actually performs the math operation

		os << "\n" << menu_data.getFinalWord(choice) << ":\n" << action_data.getMatrixResult() << "\n";
	}
}


// adds two operands of action_data together
void add(ActionData& action_data) {
	double c;
	c = action_data.getOperand1() + action_data.getOperand2();
	action_data.setResult(c);
}

// finds difference of action_data operands
void subtract(ActionData& action_data) {
	double c;
	c = action_data.getOperand1() - action_data.getOperand2();
	action_data.setResult(c);
}

// multiplies two action_data operands
void multiply(ActionData& action_data) {
	double c;
	c = action_data.getOperand1() * action_data.getOperand2();
	action_data.setResult(c);
}

// divides action_data operands 1 by 2
void divide(ActionData& action_data) {
	double c;
	if (action_data.getOperand2() == 0) {
		action_data.setResult(numeric_limits<double>::infinity());
		cerr << "Dividing by 0 is not allowed. Output is set to infinity anyways. You're welcome.\n";
	} else {
		c = action_data.getOperand1() / action_data.getOperand2();
		action_data.setResult(c);
	}
}

void addMatrices(ActionData& action_data) {
	Matrix m;
	m = action_data.getMatrix1() + action_data.getMatrix2();
	action_data.setMatrixResult(m);
}

void subtractMatrices(ActionData& action_data) {
	Matrix m;
	m = action_data.getMatrix1() - action_data.getMatrix2();
	action_data.setMatrixResult(m);
}

void multiplyMatrices(ActionData& action_data) {
	Matrix m;
	m = action_data.getMatrix1() * action_data.getMatrix2();
	action_data.setMatrixResult(m);
}

void divideMatrices(ActionData& action_data) {
	Matrix m;
	m = action_data.getMatrix1() / action_data.getMatrix2();
	action_data.setMatrixResult(m);
}
