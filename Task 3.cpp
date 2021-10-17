#include <iostream>
#include <string>

using namespace std;

class University;

class Student
{
    string name;

public:
    friend class University;
    Student(string name_)
        :name(name_)
        {

        }

    string get_name() const
    {
        return name;
    }
};

class University
{
    string uni_name;
public:
    University(string uni_name_)
        :uni_name(uni_name_)
        {

        }

    void display(const Student& s)
    {
        cout << s.name;
    }
};

int main()
{
    Student first("DAVE");
    University second("BRUH");

    second.display(first);

    return 0;
}
