#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"

void Student::setname(const char* nume)
{
	strcpy(this->nume, nume);
}

const char* Student::getname() const
{
	return this->nume;
}

void Student::setmate(int n)
{
	this->notamate = n;
}

int Student::getmate() const
{
	return this->notamate;
}

void Student::setengleza(int n)
{
	this->notaengleza = n;
}

int Student::getengleza() const
{
	return this->notaengleza;
}

void Student::setistorie(int n)
{
	this->notaistorie = n;
}

int Student::getistorie() const
{
	return this->notaistorie;
}

int Student::medie() const
{
	return (this->notaengleza + this->notamate + this->notaistorie) / 3;
}