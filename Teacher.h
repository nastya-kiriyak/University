#pragma once
#include "Human.h"

class Teacher : public Human
{
public:
	Teacher(const string& full_name_, const unsigned int& age_, const string& degree_, const string& sub_);
	~Teacher()
	{
	}
	string getAcDegree() const
	{
		return academic_degree;
	}
	string getSubject() const
	{
		return subject;
	}
	void setAcDegree(const string& degree_)
	{
		academic_degree = degree_;
	}
	void setSubject(const string& sub_)
	{
		subject = sub_;
	}
	void IsValid() const override;
	void Info() const override;
private:
	string academic_degree;
	string subject;
};

