#include "Sub.h"

#include <cmath>

Sub::Sub(Expression* expr1, Expression* expr2)
{
	this->expr1 = expr1;
	this->expr2 = expr2;
}

Sub::~Sub()
{
	delete expr1;
	delete expr2;
}

void Sub::print() {
	printf("(");
	this->expr1->print();
	printf(" - ");
	this->expr2->print();
	printf(")");
}

int Sub::compute()
{
	return this->expr1->compute() - this->expr2->compute();
}

int Sub::get_children_count()
{
	return 2;
}

Expression* Sub::get_child(int idx)
{
	if (idx == 0)
		return this->expr1;
	if (idx == 1)
		return this->expr2;
	return nullptr;
}