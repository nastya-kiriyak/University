#include "Human.h"

Human::Human(const string& full_name_, const unsigned int& age_, const unsigned int& height_)
{
    full_name = full_name_;
    age = age_;
    height = height_;
}
Human::Human(const string& full_name_, const unsigned int& age_)
{
    full_name = full_name_;
    age = age_;
}
Human::Human()
{

}

void Human::Info() const
{
    cout << "Name: " << full_name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << '\n';
}
void Human::IsValid() const
{
    if (age > 100)
    {
        throw invalid_argument("Invalid age");
    }

}

