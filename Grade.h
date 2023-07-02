#pragma once
#include<string>
#include<stdexcept>
#include<iostream>
using namespace std;

class Grade 
{
public:
    Grade(const string& subject_, const int& grade_);
    Grade(const int& grade_);
    ~Grade()
    {

    }
    int getGrade()
    {
        return grade;
    }
    string getSubject()
    {
        return subject;
    }
    void setGrade(const int& grade_)
    {
        grade = grade_;
    }
    void setSubject(const string& subject_)
    {
        subject = subject_;
    }

    char FormECTS(int grade);
    string FormWordGrade(int grade);

private:
    string subject;
    bool passed;
    unsigned int grade;
    char ects;
    string word_grade;
};

