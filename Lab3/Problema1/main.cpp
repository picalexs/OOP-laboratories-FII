#include <iostream>

#include "Math.h"
using namespace std;

int main()
{
	printf("10+12 = %d\n", Math::Add(10, 12));
	printf("10+20+30 = %d\n", Math::Add(10, 20, 30));
	printf("10.5+20.7 = %g\n", Math::Add(10.5, 20.7));
	printf("10.5+20.7+30.9 = %g\n", Math::Add(10.5, 20.7, 30.9));
	printf("10*12 = %d\n", Math::Mul(10, 12));
	printf("10*20*30 = %d\n", Math::Mul(10, 20, 30));
	printf("10.5*20.7 = %g\n", Math::Mul(10.5, 20.7));
	printf("10.5*20.7*30.9 = %g\n", Math::Mul(10.5, 20.7, 30.9));
	printf("10+20+30+40+50 = %d\n", Math::Add(5, 10, 20, 30, 40, 50));
	printf("\"127\" + \"45\" = %s\n", Math::Add("127", "45"));

	return 0;
}