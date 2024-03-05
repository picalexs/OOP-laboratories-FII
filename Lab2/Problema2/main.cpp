#include <iostream>
#include "Functions.h"
#include "Student.h"
using namespace std;

int main()
{
	Student Popescu, Ioan;
	Ioan.setName("Ioan");
	Ioan.setGradeMatematics(10);
	Ioan.setGradeEnglish(5);
	Ioan.setGradeHistory(9);

	Popescu.setName("Popescu");
	Popescu.setGradeMatematics(6);
	Popescu.setGradeEnglish(8);
	Popescu.setGradeHistory(10);

	printf("Compare name (Ioan, Popescu) = %d\n", compareName(Ioan, Popescu));
	printf("Compare grade matematics (Ioan, Popescu) = %d\n", compareGradeMatematics(Ioan, Popescu));
	printf("Compare grade english (Ioan, Popescu) = %d\n", compareGradeEnglish(Ioan, Popescu));
	printf("Compare grade history (Ioan, Popescu) = %d\n", compareGradeHistory(Ioan, Popescu));
	printf("Compare average grade (Ioan, Popescu) = %d\n", compareAverageGrade(Ioan, Popescu));

	return 0;
}