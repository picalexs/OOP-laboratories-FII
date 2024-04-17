#include "Add.h"
Add::Add(Expression* expr1, Expression* expr2)
{
	this->expr1 = expr1;
	this->expr2 = expr2;
}

Add::~Add()
{
	delete expr1;
	delete expr2;
}

void Add::print() {
	printf("(");
	this->expr1->print();
	printf(" + ");
	this->expr2->print();
	printf(")");
}

int Add::compute()
{
	return this->expr1->compute() + this->expr2->compute();
}

int Add::get_children_count()
{
	return 2;
}

Expression* Add::get_child(int idx)
{
	if (idx == 0)
		return this->expr1;
	if (idx == 1)
		return this->expr2;
	return nullptr;
}