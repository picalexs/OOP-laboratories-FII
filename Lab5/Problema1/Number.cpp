#include "Number.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdlib.h>

int CharToValue(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	return c - 'A' + 10;
}

char ValueToChar(int v)
{
	if (v >= 0 && v <= 9)
		return static_cast<char>(v + '0');
	return static_cast<char>(v + 'A' - 10);
}

int SwitchToDecimal(const char* number, int baseA)
{
	int decimal = 0;
	int power = 1;
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		decimal += CharToValue(number[i]) * power;
		power *= baseA;
	}
	return decimal;
}

char* SwitchToBaseB(int number, int baseB)
{
	int newLength = log(number) / log(baseB) + 1;
	char* result = new char[newLength + 1];
	result[newLength] = '\0';

	for (int i = newLength - 1; i >= 0; i--)
	{
		result[i] = ValueToChar(number % baseB);
		number /= baseB;
	}
	return result;
}

void Number::SwitchBase(int newBase)
{
	int numberDecimal = SwitchToDecimal(this->number, this->base);
	char* newNumber = SwitchToBaseB(numberDecimal, newBase);

	delete[] this->number;
	this->number = new char[strlen(newNumber) + 1];
	strcpy_s(this->number, strlen(newNumber) + 1, newNumber);
	delete[] newNumber;

	this->base = newBase;
}

void Number::Print()
{
	printf("%s ,B:%d\n", this->number, this->base);
}

int Number::GetDigitsCount()
{
	return strlen(this->number);
}

int Number::GetBase()
{
	return this->base;
}

Number::Number(const char* inputNumber, int inputBase)
{
	this->number = new char[strlen(inputNumber) + 1];
	strcpy_s(this->number, strlen(inputNumber) + 1, inputNumber);
	this->base = inputBase;
}

Number::Number(int nr) {
	char* intToChar = SwitchToBaseB(nr, 10);
	this->number = new char[strlen(intToChar) + 1];
	strcpy_s(this->number, strlen(intToChar) + 1, intToChar);
	this->base = 10;
	delete[] intToChar;
}

Number::Number(const char* charNr) {
	this->number = new char[strlen(charNr) + 1];
	strcpy_s(this->number, strlen(charNr) + 1, charNr);
	this->base = 10;
}

Number::~Number()
{
	delete[] this->number;
}

Number::Number(const Number& other)
{
	this->number = new char[strlen(other.number) + 1];
	strcpy_s(this->number, strlen(other.number) + 1, other.number);
	this->base = other.base;
}

Number::Number(Number&& other)
{
	this->number = other.number;//we steal the address of the number (╯°□°）╯︵ ┻━┻
	this->base = other.base;

	other.number = nullptr;
	other.base = 0;
}

Number& Number::operator=(const Number& other)
{
	if ((*this) != other)
	{
		delete[] this->number;
		this->number = new char[strlen(other.number) + 1];
		strcpy_s(this->number, strlen(other.number) + 1, other.number);
		this->base = other.base;
	}
	return *this;
}

Number& Number::operator=(int nr)
{
	delete[] this->number;
	char* intToChar = SwitchToBaseB(nr, this->base);//changes int to char*
	this->number = new char[strlen(intToChar) + 1];
	strcpy_s(this->number, strlen(intToChar) + 1, intToChar);
	return *this;
}

Number& Number::operator=(const char* charNr)
{
	delete[] this->number;
	this->number = new char[strlen(charNr) + 1];
	strcpy_s(this->number, strlen(charNr) + 1, charNr);
	return *this;
}

char* AddNumbers(const char* number1, const char* number2, int base) {
	int length1 = strlen(number1);
	int length2 = strlen(number2);
	int maxLength = (length1 > length2) ? length1 : length2;

	char* result = new char[maxLength + 2];
	result[maxLength + 1] = '\0';

	int carry = 0;
	for (int i = 0; i < maxLength; i++) {
		int digit1 = (i < length1) ? CharToValue(number1[length1 - 1 - i]) : 0;
		int digit2 = (i < length2) ? CharToValue(number2[length2 - 1 - i]) : 0;
		int sum = digit1 + digit2 + carry;

		if (sum >= base) {
			carry = 1;
			sum -= base;
		}
		else {
			carry = 0;
		}
		result[maxLength - i] = ValueToChar(sum);
	}

	if (carry > 0) {
		result[0] = '1';
		return result;
	}
	else {
		char* newResult = new char[maxLength + 1];
		strcpy_s(newResult, maxLength + 1, result + 1);
		delete[] result;
		return newResult;
	}
}

Number Number::Add(const Number& other) const
{
	char* sum = nullptr;
	int maxBase = (this->base > other.base) ? this->base : other.base;

	if (this->base == other.base) {
		sum = AddNumbers(this->number, other.number, maxBase);
	}
	else {
		Number copyThis(*this);
		Number copyOther(other);
		copyThis.SwitchBase(maxBase);
		copyOther.SwitchBase(maxBase);
		sum = AddNumbers(copyThis.number, copyOther.number, maxBase);
	}

	Number result(sum, maxBase);
	delete[] sum;
	return result;
}

Number Number::operator+(const Number& other)
{
	return Add(other);
}

Number operator+(const Number& other, int nr)
{
	char* intToChar = SwitchToBaseB(nr, other.base);
	Number intNumber(intToChar, other.base);
	Number result = other.Add(intNumber);
	delete[] intToChar;
	return result;
}

Number operator+(int nr, const Number& other)
{
	char* intToChar = SwitchToBaseB(nr, other.base);
	Number intNumber(intToChar, other.base);
	Number result = other.Add(intNumber);
	delete[] intToChar;
	return result;
}

Number& Number::operator+=(const Number& other)
{
	Number result(*this);
	*this = Add(other);
	return *this;
}

char* SubtractNumbers(const char* number1, const char* number2, int base) {
	int length1 = strlen(number1);
	int length2 = strlen(number2);
	int maxLength = (length1 > length2) ? length1 : length2;

	char* result = new char[maxLength + 2];
	result[maxLength + 1] = '\0';

	int borrow = 0;
	for (int i = 0; i < maxLength; i++) {
		int digit1 = (i < length1) ? CharToValue(number1[length1 - 1 - i]) : 0;
		int digit2 = (i < length2) ? CharToValue(number2[length2 - 1 - i]) : 0;
		int diff = digit1 - digit2 - borrow;

		if (diff < 0) {
			borrow = 1;
			diff += base;
		}
		else {
			borrow = 0;
		}

		result[maxLength - i] = ValueToChar(diff);
	}

	if (borrow > 0) {
		result[0] = '-';
	}
	else {
		int firstDigit = 0;
		while (!(result[firstDigit] > '0' && result[firstDigit] <= '9') && firstDigit < maxLength) {
			firstDigit++;
		}
		if (firstDigit == maxLength + 1) {
			return const_cast<char*>("0");
		}
		char* newResult = new char[maxLength + 2 - firstDigit];
		strcpy_s(newResult, maxLength + 2 - firstDigit, result + firstDigit);
		delete[] result;
		return newResult;
	}

	return result;
}

Number Number::Subtract(const Number& other) const
{
	char* diff;
	int maxBase = (this->base > other.base) ? this->base : other.base;

	if (this->base == other.base) {
		diff = SubtractNumbers(this->number, other.number, maxBase);
	}
	else {
		Number copyThis(*this);
		Number copyOther(other);
		copyThis.SwitchBase(maxBase);
		copyOther.SwitchBase(maxBase);
		diff = SubtractNumbers(copyThis.number, copyOther.number, maxBase);
	}

	Number result(diff, maxBase);
	delete[] diff;
	return result;
}

Number Number::operator-(const Number& other)
{
	return Subtract(other);
}

Number operator-(const Number& other, int nr) {
	char* intToChar = SwitchToBaseB(nr, other.base);
	Number intNumber(intToChar, other.base);
	Number result = other.Subtract(intNumber);//other.number - nr
	delete[] intToChar;
	return result;
}

Number operator-(int nr, const Number& other) {
	char* intToChar = SwitchToBaseB(nr, other.base);
	Number intNumber(intToChar, other.base);
	Number result = intNumber.Subtract(other);//nr - other.number
	delete[] intToChar;
	return result;
}

Number& Number::operator-=(const Number& other)
{
	Number result(*this);
	*this = Subtract(other);
	return *this;
}

bool Number::operator!=(const Number& other)
{
	return strcmp(this->number, other.number) != 0 || this->base != other.base;
}

bool Number::operator==(const Number& other)
{
	return strcmp(this->number, other.number) == 0 && this->base == other.base;
}

bool Number::operator<(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.number < nr2.number;
}

bool Number::operator>(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.number > nr2.number;
}

bool Number::operator<=(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.number <= nr2.number;
}

bool Number::operator>=(const Number& other)
{
	Number nr1(*this), nr2(other);
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	return nr1.number >= nr2.number;
}

char Number::operator[](int index)
{
	return this->number[index];
}

Number& Number::operator--()
{
	int length = strlen(this->number);
	char* newNr = new char[length];
	strcpy_s(newNr, length, this->number + 1);
	delete[] this->number;

	int digitsZero = 0;
	for (int i = 0; newNr[i] == '0'; i++) {
		digitsZero++;
	}

	this->number = new char[length - digitsZero];
	strcpy_s(this->number, length - digitsZero, newNr + digitsZero);
	delete[] newNr;
	return (*this);
}

Number Number::operator--(int nr)
{
	int length = strlen(this->number);
	char* newNr = new char[length];
	strncpy_s(newNr, length, this->number, length - 1);
	delete[] this->number;

	this->number = new char[length];
	strcpy_s(this->number, length, newNr);
	delete[] newNr;
	return (*this);
}