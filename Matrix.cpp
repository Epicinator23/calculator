#include <iostream>

#include "Matrix.h"		// using namespace std;

Matrix::Matrix()
: mRows(1), mColumns(1), mSize(1) {
	mMatrix.resize(mSize);
	mMatrix[0] = 0;
}

Matrix::Matrix(const int& rows, const int& columns)
: mRows(rows), mColumns(columns), mSize(rows*columns) {
	mMatrix.resize(mSize);
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			enterElement(row, column, 0);
		}
	}
}

Matrix::Matrix(const int& rows, const int& columns, const vector<double> matrix)
: mRows(rows), mColumns(columns), mSize(rows*columns) {
	mMatrix.resize(mSize);
	for (int row = 0; row < rows; row ++) {
		for (int column = 0; column < columns; column ++) {
			enterElement(row, column, matrix[row * columns + row]);
		}
	}
}

Matrix::~Matrix() {
}

const bool Matrix::isValid(const int& row, const int& column) const {
	return ((row < mRows) && (column < mColumns));
}

void Matrix::enterElement(const int& row, const int& column, const double& entry) {
	if (isValid(row, column)) {
		mMatrix[row * mColumns + column] = entry;
	} else {
		cerr << "Entry " << entry << " could not be entered." << endl;
	}
}

void Matrix::enterRow(const int& row, const vector<double>& entries) {
	if (isValid(row, (int)entries.size()-1)) {
		for (int column = 0; column < mColumns; column++) {
			enterElement(row, column, entries[column]);
		}
	} else {
		cerr << "Row " << row << " could not be entered." << endl;
	}
}

void Matrix::enterColumn(const int& column, const vector<double>& entries) {
	if (isValid((int)entries.size()-1, column)) {
		for (int row = 0; row < mRows; row++) {
			enterElement(row, column, entries[row]);
		}
	} else {
		cerr << "Column " << column << " could not be entered." << endl;
	}
}


const int& Matrix::getRows() const {
	return mRows;
}

const int& Matrix::getColumns() const {
	return mColumns;
}

const double Matrix::getElement(const int& row, const int& column) const {
	double entry = 0.0;
	if (isValid(row, column)) {
		entry = mMatrix[row * mColumns + column];
	} else {
		cerr << "Entry at " << row << "," << column << " could not be retrieved. Returning 0.0." << endl;
	}
	return entry;
}

const vector<double> Matrix::getRow(const int& row) const {
	vector<double> entries;
	if (isValid(row, 0)) {
		for (int column = 0; column < mColumns; column++) {
			entries.push_back(getElement(row, column));
		}
	} else {
		cerr << "Row " << row << " could not be retrieved. Returning 0 vector." << endl;
		for (int column = 0; column < mColumns; column++) {
			entries.push_back(0.0);
		}
	}
	return entries;
}

const vector<double> Matrix::getColumn(const int& column) const {
	vector<double> entries;
	if (isValid(0, column)) {
		for (int row = 0; row < mRows; row++) {
			entries.push_back(getElement(row, column));
		}
	} else {
		cerr << "Column " << column << " could not be retrieved. Returning 0 vector." << endl;
	}
	return entries;
}

const vector<double> Matrix::getMatrix() const {
	return mMatrix;
}

Matrix Matrix::operator+(const Matrix& other) const {
	if (getRows() == other.getRows() && getColumns() == other.getColumns()) {
		double a, b, c;
		Matrix m(getRows(), getColumns());
		for (int row = 0; row < getRows(); row++) {
			for (int column = 0; column < getColumns(); column++) {
				a = getElement(row, column);
				b = other.getElement(row, column);
				c = a + b;
				m.enterElement(row, column, c);
			}
		}
		return m;
	} else {
		cerr << "Matrices not the same size. They cannot be added together. Returning [0]" << endl;
		return Matrix();
	}
}

Matrix Matrix::operator-(const Matrix& other) const {
	if (getRows() == other.getRows() && getColumns() == other.getColumns()) {
		double a, b, c;
		Matrix m(getRows(), getColumns());
		for (int row = 0; row < getRows(); row++) {
			for (int column = 0; column < getColumns(); column++) {
				a = getElement(row, column);
				b = other.getElement(row, column);
				c = a - b;
				m.enterElement(row, column, c);
			}
		}
		return m;
	} else {
		cerr << "Matrices not the same size. They cannot be subtracted. Returning [0]." << endl;
		return Matrix();
	}
}

Matrix Matrix::operator*(const Matrix& other) const {
	if (getColumns() == other.getRows()) {
		double a, b, c;
		Matrix m(getRows(), other.getColumns());
		for (int row = 0; row < getRows(); row++) {
			for (int column = 0; column < other.getColumns(); column++) {
				c = 0;
				for (int i = 0; i < getColumns(); i++) {
					a = getElement(row, i);
					b = other.getElement(i, column);
					cout << "row: " << row << " column: " << column << " a=" << a << " b=" << b << " c=" << c << endl;
					c += a * b;
					cout << "c+=" << a*b <<  " c=" << c << endl;
				}
				m.enterElement(row, column, c);
			}
		}
		return m;
	} else {
		cerr << "Matrices are not compatible sizes. They cannot be multiplied. Returning [0]." << endl;
		return Matrix();
	}
}

Matrix Matrix::operator/(const Matrix& other) const {
	cerr << "Could not compute inverse of other matrix and multiply because dingus did not implement it yet." << endl;
	return Matrix();
}


ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	for(int row = 0; row < matrix.getRows(); row++) {
		for (int column = 0; column < matrix.getColumns(); column++) {
			os << matrix.getElement(row, column);
			if (column == matrix.getColumns()-1 && row < matrix.getRows()-1) {
				os << "\n";
			} else if (column < matrix.getColumns()-1) {
				os << ", ";
			}
		}
	}
	return os;
}
