#pragma once
#include<string>
#include<stdexcept>
#include<iostream>

using namespace std;

class Human
{
public:
    Human(const string& full_name_, const unsigned int& age_, const unsigned int& height_);
    Human(const string& full_name_, const unsigned int& age_);
    Human();
    virtual ~Human()
    {
    }
    virtual string getFull_name() const
    {
        return full_name;
    }
    void setFull_name(const string& full_name_)
    {
        full_name = full_name_;
    }
    virtual int getAge() const
    {
        return age;
    }
    void setAge(const int& age_)
    {
        age = age_;
    }
    virtual int getHeight() const
    {
        return height;
    }
    void setHeight(const int& height_)
    {
        height = height_;
    }

    virtual void Info() const;
    virtual void IsValid() const;
private:
    string full_name = "";
    unsigned int age = 0;
    unsigned int height = 0;

};

