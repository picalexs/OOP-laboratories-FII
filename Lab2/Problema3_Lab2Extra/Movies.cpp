#include "Movies.h"

void Movies::set_name(const string& name)
{
	this->movieName = name;
}

string Movies::get_name() const
{
	return this->movieName;
}

void Movies::set_year(int year)
{
	this->releaseYear = year;
}

int Movies::get_year() const
{
	return this->releaseYear;
}

void Movies::set_score(double score)
{
	this->IMDBScore = score;
}

double Movies::get_score() const
{
	return this->IMDBScore;
}

void Movies::set_length(int length)
{
	this->movieLength = length;
}

int Movies::get_length() const
{
	return this->movieLength;
}

int currentYear = 2024;
int Movies::get_passed_years() const
{
	return currentYear - this->releaseYear;
}





