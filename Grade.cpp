#include "Grade.h"

Grade::Grade(const string& subject_, const int& grade_) 
{
	if (grade >= 60) passed = true;
	else passed = false;
	grade = grade_;
	subject = subject_;
}
Grade::Grade(const int& grade_) 
{
	if (grade >= 60) passed = true;
	else passed = false;
	grade = grade_;
}
char Grade::FormECTS(int grade)
{
	if (grade > 90) ects = 'A';
	else if (grade >= 81 && grade < 90) ects = 'B';
	else if (grade >= 75 && grade < 81) ects = 'C';
	else if (grade >= 65 && grade < 75) ects = 'D';
	else if (grade >= 60 && grade < 65) ects = 'E';
	else if (grade < 60) ects = 'F';
	return ects;
}
string Grade::FormWordGrade(int grade)
{
	if (grade > 90) word_grade = "Exellent";
	else if (grade >= 75 && grade < 90) word_grade = "Good";
	else if (grade >= 60 && grade < 75) word_grade = "Satisfactorily";
	else if (grade < 60) word_grade = "Unsatisfactorily";
	return word_grade;
}
