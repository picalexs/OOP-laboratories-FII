#include "CharSet.h"
#include <stdio.h>
#define ASCII_SIZE 256

CharSet::CharSet()
{
	for (int i = 0; i < ASCII_SIZE; i++)
		this->chars[i] = false;
}

CharSet::CharSet(const CharSet& other)
{
	for (int i = 0; i < ASCII_SIZE; i++)
		this->chars[i] = other.chars[i];
}

int getLength(const char* string)
{
	int length = 0;
	for (int i = 0; string[i] != '\0'; i++) length++;
	return length;
}

CharSet::CharSet(const char* string)
{
	for (int i = 0; i < ASCII_SIZE; i++)
		this->chars[i] = false;
	int length = getLength(string);
	for (int i = 0; i < length; i++)
		this->chars[string[i]] = true;
}

CharSet& CharSet::operator+=(char ch)
{
	this->chars[ch] = true;
	return *this;
}

CharSet::operator int()
{
	int count = 0;
	for (int i = 0; i < ASCII_SIZE; i++)
		if (this->chars[i] == true)
			count++;
	return count;
}

CharSet& CharSet::operator|(const CharSet& other)
{
	CharSet U = *this;
	for (int i = 0; i < ASCII_SIZE; i++)
		if (other.chars[i])
			U.chars[i] = true;
	return U;
}

CharSet& CharSet::operator&(const CharSet& other)
{
	CharSet I = *this;
	for (int i = 0; i < ASCII_SIZE; i++) {
		if (other.chars[i] && I.chars[i])
			I.chars[i] = true;
		else
			I.chars[i] = false;
	}
	return I;
}

void CharSet::print()
{
	for (int i = 0; i < ASCII_SIZE; i++)
		if (this->chars[i])
			printf("%c,", i);
	printf("\n");
}

bool CharSet::operator[](int idx)
{
	return this->chars[idx];
}

int CharSet::operator()(const char* string)
{
	int count = 0;
	int length = getLength(string);
	for (int i = 0; i < length; i++)
		if (this->chars[string[i]])
			count++;
	return count;
}
