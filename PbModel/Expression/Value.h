#pragma once
#include "Expression.h"
class Value : public Expression
{
	int val;
public:
	Value(int val);
	~Value();

	void print() override;
	int compute() override;
	int get_children_count() override;
	Expression* get_child(int idx) override;
};

