#include "Matrix.h"


Matrix::Matrix(int nrC, int nrL)
{
	this->nrColumns = nrC;
	this->nrLines = nrL;
	this->matrix = new int* [nrL];
	for (int i = 0; i < nrL; i++)
	{
		this->matrix[i] = new int[nrC];
		for (int j = 0; j < nrC; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}

void Matrix::fill(int val)
{
	for (int i = 0; i < nrLines; i++)
		for (int j = 0; j < nrColumns; j++)
			this->matrix[i][j] = val;
}

void Matrix::print()
{
	for (int i = 0; i < nrLines; i++) {
		for (int j = 0; j < nrColumns; j++)
			std::cout << this->matrix[i][j] << ' ';
		std::cout << '\n';
	}
}

bool Matrix::is_square_matrix()
{
	return (this->nrColumns == this->nrLines);
}

bool Matrix::is_identity_matrix()
{
	if (!is_square_matrix())
		return false;
	for (int i = 0; i < nrColumns; i++)
		if (this->matrix[i][i] != 1)
			return false;
	return true;
}

int& Matrix::operator()(int coordC, int coordL)
{
	return this->matrix[coordL][coordC];
}

int Matrix::operator[](const char* string)
{
	if (string[0] == 'w')
		return nrColumns;
	if (string[0] == 'h')
		return nrLines;
	if (string[0] == 's')
		return sizeof(this->matrix);

	std::cout << "Parametru gresit";
	return -1;
}

bool Matrix::operator==(const Matrix& other)
{
	if (this->nrColumns != other.nrColumns || this->nrLines != other.nrLines)
		return false;
	for (int i = 0; i < this->nrLines; i++)
		for (int j = 0; j < this->nrColumns; j++)
			if (this->matrix[i][j] != other.matrix[i][j])
				return false;
	return true;
}



