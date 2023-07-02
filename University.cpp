#include "Human.h"
#include "Student.h"
#include "Grade.h"
#include "Teacher.h"
#include <iostream>
#include <stdlib.h>

vector <Teacher> teachers;
vector <Student> students;

void Main_Menu()
{
	system("cls");
	cout << "UNIVERSITY" << endl;
	cout << '\n';
	cout << "1.Teachers" << endl;
	cout << "2.Students" << endl;
	cout << "3.Exit" << endl;
	cout << '\n';
	cout << ">>>";
}
void Menu_Teachers()
{
	cout << "Input 1 if you want to see information about one teacher" << endl;
	cout << "Input 2 if you want to see information about all teachers" << endl;
	cout << "Input 3 if you want to add a teacher" << endl;
	cout << "Input 4 if you want to remove the teacher" << endl;
	cout << "Input 0 if you want to return to the main menu" << endl;
}
void Menu_Students()
{
	cout << "Input 1 if you want see information about one student" << endl;
	cout << "Input 2 if you want see  information about all students" << endl;
	cout << "Input 3 if you want add a new student" << endl;
	cout << "Input 4 if you want delete a student" << endl;
	cout << "Input 0 if you back to main menu" << endl;
}
void CreateTeachers()
{
	Teacher teach1("Stoyanova Olga Volodymyrovna", 64, "Professor", "Mathematical Analysis");
	Teacher teach2("Nedeva Liudmyla Pavlivna", 39, "PhD", "Programming");
	Teacher teach3("Stepanov Yurii Dmytrovych", 31, "Docent", "Physics");
	teachers = { teach1,teach2,teach3 };
}
void CreateStudents()
{
	Student stud_1("Denisov Artem Vitaliyovych", 19, "FMFIT", 2, 1, { Grade(65),Grade(75),Grade(90),Grade(84),Grade(92),Grade(51), Grade(89), Grade(97) });
	Student stud_2("Alekseeva Nataliya Ivanivna", 19, "FMFIT", 2, 2, { Grade(85),Grade(90),Grade(92),Grade(63),Grade(88),Grade(100), Grade(73), Grade(76) });
	Student stud_3("Nesterenko Mariya Yuriivna", 18, "EPF", 1, 1, { Grade(66),Grade(80),Grade(77),Grade(84),Grade(69),Grade(79), Grade(90), Grade(93) });
	Student stud_4("Stoyanov Petr Mykolayovych", 20, "GGF", 3, 1, { Grade(65),Grade(75),Grade(90),Grade(84),Grade(92),Grade(51), Grade(89), Grade(97) });
	Student stud_5("Ivanov Volodymyr Oleksiyovych", 21, "FRGP", 4, 2, { Grade(86),Grade(98),Grade(100),Grade(77),Grade(82),Grade(82), Grade(100), Grade(90) });
	Student stud_6("Petrov Sergiy Borysovych", 18, "FRGP", 1, 1, { Grade(65),Grade(70),Grade(90),Grade(93),Grade(91),Grade(88), Grade(76), Grade(100) });
	Student stud_7("Kiryak Anastasiya Vitaliivna", 18, "FMFIT", 1, 1, { Grade(100),Grade(92),Grade(85),Grade(76),Grade(63),Grade(88), Grade(97), Grade(62) });
	Student stud_8("Tytorov Ignat Volodymyrovych", 19, "FMFIT", 5, 1, { Grade(100),Grade(100),Grade(100),Grade(84),Grade(100),Grade(100), Grade(90), Grade(60) });
	students = { stud_1,stud_2,stud_3,stud_4,stud_5,stud_6,stud_7,stud_8 };
}
void ShowOneStudent(int number)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (i == number - 1)
		{
			students[i].Info();
		}
	}
}
void ShowListOfStudents()
{
	for (int i = 0; i < students.size(); i++)
	{
		cout << i + 1 << ". " << students[i].getFull_name() << " " << students[i].getCourse() << " course" << endl;
	}
	cout << "\n";
}

void ShowListOfTeachers()
{
	for (int i = 0; i < teachers.size(); i++)
	{
		cout << i + 1 << ". " << teachers[i].getFull_name() << " " << teachers[i].getSubject() << " " << teachers[i].getAcDegree() << endl;
	}
	cout << "\n";
}
void ShowOneTeacher(int number)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (i == number - 1)
		{
			teachers[i].Info();
		}
	}
}
void AddTeacher()
{
	system("cls");
	string name, faculty, degree, subject;
	unsigned int age;
	cout << "Enter full name (in one line): " << endl;
	cin.ignore();
	getline(cin, name);
	system("cls");
	cout << "Enter age: " << endl;
	cin >> age;
	system("cls");
	cout << "Enter academic degree: " << endl;
	cin >> degree;
	system("cls");
	cout << "Enter subject: " << endl;
	cin >> subject;
	try
	{
		Teacher t(name, age, degree, subject);
		teachers.push_back(t);
	}
	catch (invalid_argument)
	{
		cout << "You input invalid data. Teacher has not been added" << "\n" << endl;
	}
}
void RemoveTeacher(short& number)
{
	for (Teacher teacher : teachers)
	{
		cout << number << ". " << teacher.getFull_name() << " " << teacher.getSubject() << " " << teacher.getAcDegree() << endl;
		number++;
	}
	cout << "Select teacher to remove: " << endl;
	short l;
	cin >> l;
	system("cls");
	teachers.erase(teachers.begin() + (l - 1));
}
void AddStudent()
{
	system("cls");
	string name, faculty;
	unsigned int age, group, course;
	vector<Grade> gradesVector;
	cout << "Enter full name (in one line): " << endl;
	cin.ignore();
	getline(cin, name);
	system("cls");
	cout << "Enter age: " << endl;
	cin >> age;
	system("cls");
	cout << "Enter faculty: " << endl;
	cin >> faculty;
	system("cls");
	cout << "Enter course (from 1 to 5): " << endl;
	cin >> course;
	cout << "Enter group (from 1 to 3): " << endl;
	cin >> group;
	system("cls");
	cout << "Enter grades (each grade on a new line from 0 to 100 ): " << endl;
	for (int i = 0; i < 8; ++i) {
		int grade;
		cin >> grade;
		Grade newGrade(grade);
		gradesVector.push_back(newGrade);
	}
	try
	{
		Student s(name, age, faculty, course, group, gradesVector);
		students.push_back(s);
	}
	catch (invalid_argument)
	{
		cout << "You input invalid data. Student has not been added" << "\n" << endl;
	}

}
void RemoveStudent(short& number)
{
	for (Student student : students)
	{
		cout << number << ". " << student.getFull_name() << " " << student.getCourse() << " course" << endl;
		number++;
	}
	cout << "Select student to remove: " << endl;
	short k;
	cin >> k;
	system("cls");
	students.erase(students.begin() + (k - 1));
}

int main()
{
	CreateTeachers();
	CreateStudents();
	Main_Menu();
	short number = 1;
	short option = 1;
	short input;
	do {
		cin >> input;
		system("cls");
		switch (input)
		{
		case 1:
			for (Teacher teacher : teachers)
			{
				cout << number << ". " << teacher.getFull_name() << " " << teacher.getSubject() << " " << teacher.getAcDegree() << endl;
				number++;
			}
			cout << '\n';
			do
			{
				Menu_Teachers();
				cin >> option;
				if (option == 1)
				{
					system("cls");
					ShowListOfTeachers();
					int teachNumber;
					cout << "Input number of teacher >> ";
					cin >> teachNumber;
					ShowOneTeacher(teachNumber);
				}
				else  if (option == 2)
				{
					system("cls");
					for (Teacher teacher : teachers)
					{
						teacher.Info();
					}
					number = 1;
				}
				else if (option == 3)
				{
					AddTeacher();
				}
				else if (option == 4)
				{
					number = 1;
					RemoveTeacher(number);
				}
				else if (option == 0)
				{
					system("cls");
					Main_Menu();
					number = 1;
					break;
					cin >> input;
				}
			} while (option != 1 || option != 2 || option != 3 || option != 4 || option != 0);
			break;
		case 2:
			for (Student student : students)
			{
				cout << number << ". " << student.getFull_name() << " " << student.getCourse() << " course" << endl;
				number++;
			}
			cout << '\n';
			do
			{
				Menu_Students();
				cin >> option;
				if (option == 1)
				{
					system("cls");
					ShowListOfStudents();
					int studNumber;
					cout << "Input number of student >> ";
					cin >> studNumber;
					ShowOneStudent(studNumber);
				}
				else if (option == 2)
				{
					system("cls");
					for (auto student : students)
					{
						student.Info();
					}
					number = 1;
				}
				else if (option == 3)
				{
					AddStudent();
				}
				else if (option == 4)
				{
					number = 1;
					RemoveStudent(number);
				}
				else if (option == 0)
				{
					system("cls");
					Main_Menu();
					number = 1;
					break;
					cin >> input;
				}
			} while (option != 1 || option != 2 || option != 3 || option != 0);
			break;
		}
	} while (input != 4);
	return 0;
}
