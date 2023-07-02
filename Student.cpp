#include "Student.h"

Student::Student(const string& full_name_, const unsigned int& age_, const string& fac_, const unsigned int& course_, const unsigned int& group_, const vector<Grade>& gradesVector_) :Human(full_name_, age_)
{
    group = group_;
    faculty = fac_;
    course = course_;
    gradesVector = gradesVector_;
    IsValid();
}
Student::Student()
{
}
int Student::CalculateAverageGrade() const
{
    int sum = 0;
    int count = gradesVector.size();
    for (Grade grade : gradesVector)
    {
        sum += grade.getGrade();
    }
    double averGrade = sum / count;
    return averGrade;
}
int Student::CalculateScholarship() const
{

    if (!hasFailingGrade() && CalculateAverageGrade() >= 90)
    {
        return 3000;
    }
    if (!hasFailingGrade() && CalculateAverageGrade() >= 75)
    {
        return 1900;
    }
    else return 0;
}
bool Student::hasFailingGrade() const {
    for (Grade grade : gradesVector) {
        if (grade.getGrade() < 60) {
            return true;
        }
    }
    return false;
}

void Student::IsValid() const
{
    Human::IsValid();
    if (getAge() > 100 || group > 3 || course >= 6)
    {
        throw invalid_argument("Invalid data");
    }
}
void Student::Info() const
{
    Grade g(CalculateAverageGrade());
    cout << "Name: " << getFull_name() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Group: " << group << endl;
    cout << "Faculty: " << faculty << endl;
    cout << "Course: " << course << endl;
    cout << "Grants: " << CalculateScholarship() << endl;
    cout << "Average grade: " << CalculateAverageGrade() << endl;
    cout << "Average ECTS grade: " << g.FormECTS(CalculateAverageGrade()) << endl;
    cout << "Average grade in word: " << g.FormWordGrade(CalculateAverageGrade()) << endl;
    cout << '\n';
}
