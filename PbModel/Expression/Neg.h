#pragma once
#include "Expression.h"
class Neg : public Expression
{
	Expression* expr;
public:
	Neg(Expression* expr);
	~Neg();

	void print() override;
	int compute() override;
	int get_children_count() override;
	Expression* get_child(int idx) override;
};

