#include <iostream>
#include "Fractie.h"
using namespace std;

int main()
{
	Fractie f1(1, 4);
	Fractie f2(8, 16);
	Fractie f3 = f1 + f2;
	f1.print(); printf(" + "); f2.print(); printf(" = "); f3.print(); printf("\n");
	Fractie f4 = f2 - f1;
	f2.print(); printf(" - "); f1.print(); printf(" = "); f4.print(); printf("\n");
	Fractie f5 = f3 * f4;
	f3.print(); printf(" x "); f4.print(); printf(" = "); f5.print(); printf(" [");
	Fractie f6 = f5.simplify();
	f6.simplify(); f6.print(); printf("]\n");
	Fractie f7 = { 2,4 };
	Fractie f8 = "10/20";
	if (f7 == f8) { printf("Egale\n"); }
	Fractie f9 = "123";
	f9.print();
	Fractie f10 = { 123,321 };
	printf("\n[%d/%d]", f10["numerator"], f10["denominator"]);
}
