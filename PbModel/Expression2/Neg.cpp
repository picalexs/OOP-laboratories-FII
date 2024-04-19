#include "Neg.h"

Neg::Neg(Expression* expression)
{
	this->expr = expression;
}

void Neg::print()
{
	printf("( - ");
	this->expr->print();
	printf(")");
}

int Neg::compute()
{
	return -this->expr->compute();
}

int Neg::get_children_count()
{
	return 1;
}

Expression* Neg::get_child(int idx)
{
	return this->expr;
}