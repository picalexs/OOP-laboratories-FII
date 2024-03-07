#pragma once
#include <string>
using namespace std;
class Movies
{
	string movieName;
	int releaseYear;
	double IMDBScore;
	int movieLength;

public:
	void set_name(const string& name);
	string get_name() const;
	void set_year(int year);
	int get_year() const;
	void set_score(double score);
	double get_score() const;
	void set_length(int length);
	int get_length() const;
	int get_passed_years() const;
};

