#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
	Canvas c(25, 25);
	c.FillCircle(5, 10, 4, '.');
	c.SetPoint(10, 10, 'X');
	c.DrawLine(0, 0, 8, 8, '\\');
	c.DrawLine(24, 0, 0, 10, '/');
	c.DrawRect(12, 12, 20, 20, '3');
	c.FillRect(14, 14, 18, 18, '4');
	c.DrawCircle(5, 20, 3, 'O');
	c.Print();
	c.Clear();
	c.DrawCircle(10, 10, 10, 'o');
	c.FillCircle(10, 10, 8, '.');
	c.Print();
	return 0;
}