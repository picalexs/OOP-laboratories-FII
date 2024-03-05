#pragma once
#include <string>
#include "Student.h"
using namespace std;

int compareName(Student firstStudent, Student secondStudent);

int compareGradeMatematics(const Student& firstStudent, const Student& secondStudent);

int compareGradeEnglish(const Student& firstStudent, const Student& secondStudent);

int compareGradeHistory(const Student& firstStudent, const Student& secondStudent);

int compareAverageGrade(const Student& firstStudent, const Student& secondStudent);