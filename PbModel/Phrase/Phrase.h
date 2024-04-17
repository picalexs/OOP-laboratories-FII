#pragma once
#include <stdio.h>
class Phrase
{
	char** words;
	int wordCount;
public:
	Phrase(const char* string);
	int CountLetter(int wordIdx, char letter) const;
	int CountLetter(char letter) const;
	int CountVowels() const;
	char* GetLongestWord() const;
	char* operator[](int wordIdx) const;
	operator int() const;
};

