#pragma once
#include <stdio.h>
class Expression
{
public:
	virtual void print() = 0;
	virtual int compute() = 0;
	virtual int get_children_count() = 0;
	virtual Expression* get_child(int idx) = 0;
};

