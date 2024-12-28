#include "ActionData.h"		// using namespace std;

ActionData::ActionData(istream& is, ostream& os)
: in_stream(is), out_stream(os), operand1(0.0), operand2(0.0), result(0.0), choice(-1), quitter(false) {
}

ActionData::~ActionData() {
}

istream& ActionData::getInStream() {
	return in_stream;
}

ostream& ActionData::getOutStream() {
	return out_stream;
}

const double& ActionData::getOperand1() const {
	return operand1;
}

const double& ActionData::getOperand2() const {
	return operand2;
}

const double& ActionData::getResult() const {
	return result;
}

const Matrix& ActionData::getMatrix1() const {
	return matrix1;
}

const Matrix& ActionData::getMatrix2() const {
	return matrix2;
}

const Matrix& ActionData::getMatrixResult() const {
	return matrix_result;
}

const int& ActionData::getChoice() const {
	return choice;
}

const bool& ActionData::getQuitter() const {
	return quitter;
}


void ActionData::setOperand1(const double& value) {
	operand1 = value;
}

void ActionData::setOperand2(const double& value) {
	operand2 = value;
}

void ActionData::setResult(const double& value) {
	result = value;
}

void ActionData::setMatrix1(const Matrix& matrix) {
	matrix1 = matrix;
}

void ActionData::setMatrix2(const Matrix& matrix) {
	matrix2 = matrix;
}

void ActionData::setMatrixResult(const Matrix& matrix) {
	matrix_result = matrix;
}

void ActionData::Choose(const int& value) {
	choice = value;
}

void ActionData::quit() {
	quitter = true;
}
