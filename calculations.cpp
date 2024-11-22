#include <cmath>
#include "calculations.h"


void add(ActionData& action_data) {
	double a, b, c;

	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();

	os << "First addend: ";
	is >> a;
	action_data.setOperand1(a);

	os << "Second addend: ";
	is >> b;
	action_data.setOperand2(b);

	c = a + b;
	action_data.setResult(c);
	os << "\nSum: " << action_data.getResult();
}

void subtract(ActionData& action_data) {
	double a, b, c;

	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();

	os << "Minuend: ";
	is >> a;
	action_data.setOperand1(a);

	os << "Subtrahend: ";
	is >> b;
	action_data.setOperand2(b);

	c = a - b;
	action_data.setResult(c);
	os << "\nDifference: " << action_data.getResult();
}

void multiply(ActionData& action_data) {
	double a, b, c;

	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();

	os << "First factor: ";
	is >> a;
	action_data.setOperand1(a);

	os << "Second factor: ";
	is >> b;
	action_data.setOperand2(b);

	c = a * b;
	action_data.setResult(c);
	os << "\nProduct: " << action_data.getResult();
}

void divide(ActionData& action_data) {
	double a, b, c;

	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();

	os << "Dividend: ";
	is >> a;
	action_data.setOperand1(a);

	os << "Divisor: ";
	is >> b;
	action_data.setOperand2(b);

	if (b != 0) {
		c = a / b;
		action_data.setResult(c);
		os << "\nQuotient: " << action_data.getResult();
	} else {
		os << "You cannot divie by 0. Nice try.\n";
	}
}

void exponent(ActionData& action_data) {
	double a, b, c;

	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();

	os << "Base: ";
	is >> a;
	action_data.setOperand1(a);

	os << "Exponent: ";
	is >> b;
	action_data.setOperand2(b);

	c = exp(b * log(a));
	action_data.setResult(c);
	os << "\nResult: " << action_data.getResult();
}

void logarithm(ActionData& action_data) {
	double a, b, c;

	ostream& os = action_data.getOutStream();
	istream& is = action_data.getInStream();

	os << "Argument: ";
	is >> a;
	action_data.setOperand1(a);

	os << "Base: ";
	is >> b;
	action_data.setOperand2(b);

	if (a > 0 && b > 0) {
		c = log(a) / log(b);
		action_data.setResult(c);
		os << "\nLogarithm: " << action_data.getResult();
	} else if (a <= 0) {
		os << "You cannot find the log of a number less than or equal to 0.\n";
		return;
	} else if (b <= 0) {
		os << "Logarithms are undefined for bases that are negative";
	} else if (b == 1) {
		c = a;
		action_data.setResult(c);
		os << "\nLogarithm: " << action_data.getResult();
	}
}