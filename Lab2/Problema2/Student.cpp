#include "Student.h"

void Student::setName(string nameToSet)
{
	name = nameToSet;
}

string Student::getName()
{
	return name;
}

void Student::setGradeMatematics(float gradeToSet)
{
	gradeMatematics = gradeToSet;
}

float Student::getGradeMatematics() const
{
	return gradeMatematics;
}

void Student::setGradeEnglish(float gradeToSet)
{
	gradeEnglish = gradeToSet;
}

float Student::getGradeEnglish() const
{
	return gradeEnglish;
}

void Student::setGradeHistory(float gradeToSet)
{
	gradeHistory = gradeToSet;
}

float Student::getGradeHistory() const
{
	return gradeHistory;
}

float Student::getAverageGrade() const
{
	return (gradeEnglish + gradeHistory + gradeMatematics) / 3.0f;
}







