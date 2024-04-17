#pragma once
#include "Expression.h"
class Sub : public Expression
{
	Expression* expr1, * expr2;
public:
	Sub(Expression* expr1, Expression* expr2);
	~Sub();

	void print() override;
	int compute() override;
	int get_children_count() override;
	Expression* get_child(int idx) override;
};

