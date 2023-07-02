#pragma once
#include "Human.h"
#include "vector"
#include "Grade.h"

class Student : public Human
{
public:
    Student(const string& full_name_, const unsigned int& age_, const string& fac_, const unsigned int& course_, const unsigned int& group_, const vector<Grade>& gradesVector_);
    Student();
    ~Student()
    {

    }
    unsigned int getGroup()
    {
        return group;
    }
    string getFaculty()
    {
        return faculty;
    }
    unsigned int getCourse()
    {
        return course;
    }

    void setGroup(const unsigned int& group_)
    {
        group = group_;
    }
    void setFaculty(const string& fac_)
    {
        faculty = fac_;
    }
    void setCourse(const unsigned int& course_)
    {
        course = course_;
    }

    void IsValid() const override;
    void Info() const override;
    int CalculateAverageGrade() const;
    int CalculateScholarship() const;
    bool hasFailingGrade() const;
private:
    unsigned int group;
    string faculty;
    unsigned int course;
    vector<Grade> gradesVector;

};
