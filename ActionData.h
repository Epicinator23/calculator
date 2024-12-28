#ifndef ACTION_DATA_H
#define ACTION_DATA_H

#include <iostream>

#include "Matrix.h"		// using namespace std;

class ActionData {
private:
	istream& in_stream;
	ostream& out_stream;

	double operand1;
	double operand2;
	double result;

	Matrix matrix1;
	Matrix matrix2;
	Matrix matrix_result;

	int choice;
	bool quitter;

public:
	ActionData(std::istream& is, std::ostream& os);
	~ActionData();

	istream& getInStream();
	ostream& getOutStream();

	const double& getOperand1() const;
	const double& getOperand2() const;
	const double& getResult() const;

	const Matrix& getMatrix1() const;
	const Matrix& getMatrix2() const;
	const Matrix& getMatrixResult() const;

	const int& getChoice() const;
	const bool& getQuitter() const;



	void setOperand1(const double& value);
	void setOperand2(const double& value);
	void setResult(const double& value);

	void setMatrix1(const Matrix& matrix);
	void setMatrix2(const Matrix& matrix);
	void setMatrixResult(const Matrix& matrix);

	void Choose(const int& value);
	void quit();
};

#endif
