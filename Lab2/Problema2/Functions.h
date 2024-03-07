#pragma once
#include <string>
#include "Student.h"
using namespace std;

int CompareName(Student* firstStudent, Student* secondStudent);

int CompareGradeMatematics(const Student* firstStudent, const Student* secondStudent);

int CompareGradeEnglish(const Student* firstStudent, const Student* secondStudent);

int CompareGradeHistory(const Student* firstStudent, const Student* secondStudent);

int CompareAverageGrade(const Student* firstStudent, const Student* secondStudent);