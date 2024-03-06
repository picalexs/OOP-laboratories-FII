#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string name;
	float gradeMatematics;
	float gradeEnglish;
	float gradeHistory;
public:
	void SetName(string nameToSet);
	string GetName();

	void SetGradeMatematics(float gradeToSet);
	float GetGradeMatematics() const;
	void SetGradeEnglish(float gradeToSet);
	float GetGradeEnglish() const;
	void SetGradeHistory(float gradeToSet);
	float GetGradeHistory() const;

	float GetAverageGrade() const;
};