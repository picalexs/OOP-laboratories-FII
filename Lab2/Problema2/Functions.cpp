#include "Functions.h"

int compareName(Student firstStudent, Student secondStudent)
{
	const string nameFirstStudent = firstStudent.getName();
	const string nameSecondStudent = secondStudent.getName();

	if (nameFirstStudent < nameSecondStudent)
		return -1;
	if (nameFirstStudent > nameSecondStudent)
		return 1;
	return 0;
}

int compareGradeMatematics(const Student& firstStudent, const Student& secondStudent)
{
	const float gradeFirstStudent = firstStudent.getGradeMatematics();
	const float gradeSecondStudent = secondStudent.getGradeMatematics();

	if(gradeFirstStudent < gradeSecondStudent)
		return -1;
	if(gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}

int compareGradeHistory(const Student& firstStudent, const Student& secondStudent)
{
	const float gradeFirstStudent = firstStudent.getGradeHistory();
	const float gradeSecondStudent = secondStudent.getGradeHistory();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}


int compareGradeEnglish(const Student& firstStudent, const Student& secondStudent)
{
	const float gradeFirstStudent = firstStudent.getGradeEnglish();
	const float gradeSecondStudent = secondStudent.getGradeEnglish();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}

int compareAverageGrade(const Student& firstStudent, const Student& secondStudent)
{
	const float gradeFirstStudent = firstStudent.getAverageGrade();
	const float gradeSecondStudent = secondStudent.getAverageGrade();

	if (gradeFirstStudent < gradeSecondStudent)
		return -1;
	if (gradeFirstStudent > gradeSecondStudent)
		return 1;
	return 0;
}


