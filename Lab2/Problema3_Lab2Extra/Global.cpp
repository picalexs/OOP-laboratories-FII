#include "Global.h"
int movie_compare_name(const Movies& M1, const Movies& M2)
{
	if (M1.get_name() > M2.get_name())
		return 1;
	if (M1.get_name() < M2.get_name())
		return -1;
	return 0;
}

int movie_compare_year(const Movies& M1, const Movies& M2)
{
	if (M1.get_year() > M2.get_year())
		return 1;
	if (M1.get_year() < M2.get_year())
		return -1;
	return 0;
}

int movie_compare_score(const Movies& M1, const Movies& M2)
{
	if (M1.get_score() > M2.get_score())
		return 1;
	if (M1.get_score() < M2.get_score())
		return -1;
	return 0;
}

int movie_compare_length(const Movies& M1, const Movies& M2)
{
	if (M1.get_length() > M2.get_length())
		return 1;
	if (M1.get_length() < M2.get_length())
		return -1;
	return 0;
}

int movie_compare_passed_years(const Movies& M1, const Movies& M2)
{
	if (M1.get_passed_years() > M2.get_passed_years())
		return 1;
	if (M1.get_passed_years() < M2.get_passed_years())
		return -1;
	return 0;
}
