#pragma once
#include <iostream>

class Matrix
{
	int** matrix;
	int nrLines;
	int nrColumns;
public:
	Matrix(int nrC, int nrL);
	void fill(int val);
	void print();
	bool is_square_matrix();
	bool is_identity_matrix();
	int& operator()(int coordC, int coordL);
	int operator[](const char* string);
	bool operator==(const Matrix& other);
};

