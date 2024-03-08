#include "Student.h"

void Student::SetName(const string& nameToSet)
{
	name = nameToSet;
}

string Student::GetName()
{
	return name;
}

void Student::SetGradeMatematics(float gradeToSet)
{
	gradeMatematics = gradeToSet;
}

float Student::GetGradeMatematics() const
{
	return gradeMatematics;
}

void Student::SetGradeEnglish(float gradeToSet)
{
	gradeEnglish = gradeToSet;
}

float Student::GetGradeEnglish() const
{
	return gradeEnglish;
}

void Student::SetGradeHistory(float gradeToSet)
{
	gradeHistory = gradeToSet;
}

float Student::GetGradeHistory() const
{
	return gradeHistory;
}

float Student::GetAverageGrade() const
{
	return (gradeEnglish + gradeHistory + gradeMatematics) / 3.0f;
}







