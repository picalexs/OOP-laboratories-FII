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
	void setName(string nameToSet);
	string getName();

	void setGradeMatematics(float gradeToSet);
	float getGradeMatematics() const;
	void setGradeEnglish(float gradeToSet);
	float getGradeEnglish() const;
	void setGradeHistory(float gradeToSet);
	float getGradeHistory() const;

	float getAverageGrade() const;
};