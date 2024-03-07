#include <iostream>
#include "Functions.h"
#include "Student.h"
using namespace std;

int main()
{
	Student Popescu, Ioan;
	Ioan.SetName("Ioan");
	Ioan.SetGradeMatematics(10);
	Ioan.SetGradeEnglish(5);
	Ioan.SetGradeHistory(9);

	Popescu.SetName("Popescu");
	Popescu.SetGradeMatematics(6);
	Popescu.SetGradeEnglish(8);
	Popescu.SetGradeHistory(10);

	printf("Compare name (Ioan, Popescu) = %d\n", CompareName(&Ioan, &Popescu));
	printf("Compare grade matematics (Ioan, Popescu) = %d\n", CompareGradeMatematics(&Ioan, &Popescu));
	printf("Compare grade english (Ioan, Popescu) = %d\n", CompareGradeEnglish(&Ioan, &Popescu));
	printf("Compare grade history (Ioan, Popescu) = %d\n", CompareGradeHistory(&Ioan, &Popescu));
	printf("Compare average grade (Ioan, Popescu) = %d\n", CompareAverageGrade(&Ioan, &Popescu));

	return 0;
}