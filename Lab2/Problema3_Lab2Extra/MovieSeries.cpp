#include "MovieSeries.h"

void MovieSeries::init()
{
	this->count = 0;
}

void MovieSeries::add(Movies* M)
{
	if (this->count < 16)
	{
		this->moviesSeries[this->count++] = *M;
	}
}

void MovieSeries::print() const
{
	for (int i = 0; i < this->count; i++)
	{
		printf("name: %s\n", this->moviesSeries[i].get_name().c_str());
		printf("year: %d\n", this->moviesSeries[i].get_year());
		printf("score: %.2f\n", this->moviesSeries[i].get_score());
		printf("length: %d\n", this->moviesSeries[i].get_length());
	}
}

void MovieSeries::sort()
{
	for (int i = 0; i < this->count - 1; i++)
	{
		for (int j = 0; j < this->count - i - 1; j++)
		{
			if (movie_compare_name(this->moviesSeries[j], this->moviesSeries[j + 1]) > 0)
			{
				const Movies temp = this->moviesSeries[j];
				this->moviesSeries[j] = this->moviesSeries[j + 1];
				this->moviesSeries[j + 1] = temp;
			}
		}
	}
}

