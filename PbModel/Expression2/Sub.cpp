#include "Sub.h"

Sub::Sub(Expression* expression1, Expression* expression2)
{
	this->expr1 = expression1;
	this->expr2 = expression2;
}

void Sub::print()
{
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