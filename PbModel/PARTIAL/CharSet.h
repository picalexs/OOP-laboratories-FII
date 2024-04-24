#pragma once
class CharSet
{
	bool chars[256];
public:
	CharSet();
	CharSet(const char* string);
	CharSet(const CharSet& other);
	CharSet& operator+= (char ch);
	operator int();
	operator float();
	CharSet& operator| (const CharSet& other);
	CharSet& operator& (const CharSet& other);
	void print();
	bool operator[](int idx);
	CharSet& operator+(int nr);

	int operator()(const char* string);
};

