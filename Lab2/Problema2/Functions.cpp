#include "Functions.h"

int CompareName(Student* firstStudent, Student* secondStudent)
{
	const string nameFirstStudent = firstStudent->GetName();
	const string nameSecondStudent = secondStudent->GetName();

	if (nameFirstStudent < nameSecondStudent)
		return -1;
	if (nameFirstStudent > nameSecondStudent)
		return 1;
	return 0;
}

int CompareGradeMatematics(const Student* firstStudent, const Student* secondStudent)
{
	const float gradeFirstStudent = firstStudent->GetGradeMatematics();
	const float gradeSecondStudent = secondStudent->GetGradeMatematics();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}

int CompareGradeHistory(const Student* firstStudent, const Student* secondStudent)
{
	const float gradeFirstStudent = firstStudent->GetGradeHistory();
	const float gradeSecondStudent = secondStudent->GetGradeHistory();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}


int CompareGradeEnglish(const Student* firstStudent, const Student* secondStudent)
{
	const float gradeFirstStudent = firstStudent->GetGradeEnglish();
	const float gradeSecondStudent = secondStudent->GetGradeEnglish();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}

int CompareAverageGrade(const Student* firstStudent, const Student* secondStudent)
{
	const float gradeFirstStudent = firstStudent->GetAverageGrade();
	const float gradeSecondStudent = secondStudent->GetAverageGrade();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}


