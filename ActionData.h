#ifndef ACTION_DATA_H
#define ACTION_DATA_H

#include <iostream>

using namespace std;

class ActionData {
private:
	istream& in_stream;
	ostream& out_stream;
	double operand1;
	double operand2;
	double result;

public:
	ActionData(std::istream& is, std::ostream& os);
	~ActionData();

	istream& getInStream();
	ostream& getOutStream();

	const double& getOperand1() const;
	const double& getOperand2() const;
	const double& getResult() const;

	void setOperand1(const double& value);
	void setOperand2(const double& value);
	void setResult(const double& value);
};

#endif