#include <iostream>
#include "Tree.h"
using namespace std;

int getLength(const char* number)
{
	int length = 0;
	for (int i = 0; number[i] != '\0'; i++)
		length++;
	return length;
}

float stringToFloat(const char* number)
{
	int length = getLength(number);
	float floatNumber = 0;

	int startPoz = 0;
	if (number[0] == '-') {
		startPoz++;
	}

	for (int i = startPoz; i < length; i++) {
		floatNumber = floatNumber * 10 + number[i] - '0';
	}

	if (startPoz == 1) {
		floatNumber *= -1;
	}

	return floatNumber;
}

float operator""_Kelvin(long double number)
{
	return number - 273.15;
}

float operator""_Kelvin(const char* number)
{
	return stringToFloat(number) - 273.15;
}

float operator""_Fahrenheit(long double number)
{
	return (number - 32.0) / 1.8;
}

float operator""_Fahrenheit(const char* number)
{
	return (stringToFloat(number) - 32.0) / 1.8;
}

int main() {
	float a = 300_Kelvin;
	printf("%f\n", a);
	float b = 120_Fahrenheit;
	printf("%f\n", b);
	return 0;
}