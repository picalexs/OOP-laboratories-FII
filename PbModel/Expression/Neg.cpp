#include "Neg.h"
Neg::Neg(Expression* expr)
{
	this->expr = expr;
}

Neg::~Neg()
{
	delete expr;
}


void Neg::print()
{
	printf("-(");
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
	if (idx == 0)
		return this->expr;
	return nullptr;
}