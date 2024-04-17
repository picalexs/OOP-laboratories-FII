#include "Phrase.h"

int GetLength(const char* string)
{
	int length = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		length++;
	}
	return length;
}

void CopyString(const char* source, char* destination)
{
	int length = GetLength(source);
	for (int i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}
}

bool isLegalChar(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '/' || c == '*';
}

Phrase::Phrase(const char* string)
{
	for (int i = 0; i < wordCount; i++)
		delete[] this->words[i];
	delete[] this->words;

	int length = GetLength(string);
	int wordsCount = 0;
	for (int i = 0; i < length; i++)
	{
		if (isLegalChar(string[i]) && (i == length - 1 || string[i + 1] == ' '))
			wordsCount++;
	}
	this->wordCount = wordsCount;

	this->words = new char* [wordsCount];
	int defaultWordLength = 20, wordIdx = 0, currentWordLength = 0;
	for (int i = 0; i < length; i++)
	{
		if (currentWordLength == 0)
		{
			this->words[wordIdx] = new char[defaultWordLength];
		}
		if (currentWordLength >= defaultWordLength - 1)
		{
			defaultWordLength *= 2;
			char* tmp = new char[defaultWordLength];
			CopyString(this->words[wordIdx], tmp);
			delete[] this->words[wordIdx];
			this->words[wordIdx] = tmp;
		}

		while (!isLegalChar(string[i])) {
			i++;
		}
		this->words[wordIdx][currentWordLength++] = string[i];

		if (isLegalChar(string[i]) && (i == length - 1 || string[i + 1] == ' ')) {
			this->words[wordIdx][currentWordLength] = '\0';
			wordIdx++;
			currentWordLength = 0;
		}
	}
}

int Phrase::CountLetter(int wordIdx, char letter) const
{
	if (wordIdx < 0 || wordIdx >= this->wordCount)
	{
		printf("Illegal word index!\n");
		return 0;
	}

	int length = GetLength(this->words[wordIdx]);
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (this->words[wordIdx][i] == letter)
			count++;
	}
	return count;
}

int Phrase::CountLetter(char letter) const
{
	int count = 0;
	for (int i = 0; i < this->wordCount; i++)
	{
		count += CountLetter(i, letter);
	}
	return count;
}

int Phrase::CountVowels() const
{
	return CountLetter('a') + CountLetter('e') + CountLetter('i') + CountLetter('o') + CountLetter('u') +
		CountLetter('A') + CountLetter('E') + CountLetter('I') + CountLetter('O') + CountLetter('U');
}

char* Phrase::GetLongestWord() const
{
	if (this->wordCount <= 0)
	{
		printf("Word count is <=0!\n");
		return nullptr;
	}

	int longestLength = 0;
	char* longestWord = nullptr;
	for (int i = 0; i < wordCount; i++) {
		int length = GetLength(this->words[i]);
		if (length > longestLength)
		{
			longestLength = length;
			longestWord = new char[length + 1];
			longestWord[length] = '\0';
			CopyString(this->words[i], longestWord);
		}
	}
	return longestWord;
}

char* Phrase::operator[](int wordIdx) const
{
	if (wordIdx < 0 || wordIdx >= this->wordCount)
	{
		printf("Illegal word index!\n");
		return nullptr;
	}
	return this->words[wordIdx];
}

Phrase::operator int() const
{
	return this->wordCount;
}

