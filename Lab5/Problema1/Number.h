#pragma once
class Number
{
	char* number;
	int base;
public:
	Number(const char* inputNumber, int inputBase); // where base is between 2 and 16
	Number(int nr);
	Number(const char* charNr);
	~Number();
	Number(const Number& other);
	Number(Number&& other);

	Number& operator=(const Number& other);
	Number& operator=(int nr);
	Number& operator=(char* charNr);

	Number Add(const Number& other) const;
	friend Number operator+(const Number& other, int nr);
	friend Number operator+(int nr, const Number& other);
	Number operator+(const Number& other);
	Number& operator+=(const Number& other);

	Number Subtract(const Number& other) const;
	friend Number operator-(const Number& other, int nr);
	friend Number operator-(int nr, const Number& other);
	Number operator-(const Number& other);
	Number& operator-=(const Number& other);

	char operator[](int index);
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);
	Number& operator--();
	Number operator--(int nr);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

