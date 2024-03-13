#pragma once
#include "Global.h"
class MovieSeries
{
	Movies moviesSeries[16];
	int count;
public:
	void init();
	void add(Movies* M);
	void print() const;
	void sort();
};