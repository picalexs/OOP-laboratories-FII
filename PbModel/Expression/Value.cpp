#include "Value.h"
Value::Value(int val)
{
	this->val = val;
}

Value::~Value()
{
	this->val = 0;
}

void Value::print()
{
	printf("%d", this->val);
}

int Value::compute()
{
	return this->val;
}

int Value::get_children_count()
{
	return 0;
}

Expression* Value::get_child(int idx)
{
	return nullptr;
}

