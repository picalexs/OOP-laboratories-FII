#pragma once

class Student
{
	char nume[256];
	int notamate;
	int notaengleza;
	int notaistorie;
	int media;

public:
	void setname(const char* nume);
	const char* getname() const;
	void setmate(int n);
	int getmate() const;
	void setengleza(int n);
	int getengleza() const;
	void setistorie(int n);
	int getistorie() const;
	int medie() const;
};
