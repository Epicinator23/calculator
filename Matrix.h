#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;

class Matrix {
private:
	int mRows;
	int mColumns;
	int mSize;
	vector<double> mMatrix;

public:
	Matrix();
	Matrix(const int& rows, const int& columns);
	Matrix(const int& rows, const int& columns, const vector<double> matrix);
	~Matrix();

	const bool isValid(const int& row, const int& column) const;
	void enterElement(const int& row, const int& column, const double& entry);
	void enterRow(const int& row, const vector<double>& entries);
	void enterColumn(const int& column, const vector<double>& entries);

	const int& getRows() const;
	const int& getColumns() const;
	const double getElement(const int& row, const int& column) const;
	const vector<double> getRow(const int& row) const;
	const vector<double> getColumn(const int& column) const;
	const vector<double> getMatrix() const;

	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator/(const Matrix& other) const;
};

ostream& operator<<(std::ostream& os, const Matrix& matrix);

#endif
