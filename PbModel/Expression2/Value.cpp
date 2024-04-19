#include "Value.h"

Value::Value(int value)
{
	this->val = value;
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