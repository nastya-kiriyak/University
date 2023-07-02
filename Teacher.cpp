#include "Teacher.h"

Teacher::Teacher(const string& full_name_, const unsigned int& age_, const string& degree_, const string& sub_) :Human(full_name_, age_)
{
	academic_degree = degree_;
	subject = sub_;
	Human::IsValid();
}

void Teacher::IsValid() const
{
	Human::IsValid();
}
void Teacher::Info() const
{
	cout << "Name: " << getFull_name() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Academic degree: " << academic_degree << endl;
	cout << "Subject: " << subject << endl;
	cout << '\n';
}

