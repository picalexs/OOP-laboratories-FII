#pragma once
#include "Expression.h"
class Add : public Expression
{
	Expression* expr1, * expr2;
public:
	Add(Expression* expression1, Expression* expression2);
	void print() override;
	int compute() override;
	int get_children_count() override;
	Expression* get_child(int idx) override;
};

