#include "ActionData.h"		// using namespace std;

ActionData::ActionData(istream& is, ostream& os)
: in_stream(is), out_stream(os), operand1(0.0), operand2(0.0), result(0.0) {
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

void ActionData::setOperand1(const double& value) {
	operand1 = value;
}

void ActionData::setOperand2(const double& value) {
	operand2 = value;
}

void ActionData::setResult(const double& value) {
	result = value;
}