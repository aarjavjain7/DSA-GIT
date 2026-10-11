#include<iostream>
#include<stdio.h>

using namespace std;

struct student
{
    char name[30];
    int age;
    float marks;
};

int main()
{
    student s[3];

    for (int i = 0; i<3 ; i++)
    {
        cout << "Enter name of student: ";
        cin >> s[i].name  ;

        cout << "Enter age of student: ";
        cin >> s[i].age  ;

        cout << "Enter marks of student: ";
        cin >> s[i].marks  ;
    }

    cout << "\nDetails of students are:";

    for (int i = 0; i < 3 ; i++)
    {
        cout << "\nname: " << s[i].name << endl;
        cout << "age: " << s[i].age << endl;
        cout << "marks:" << s[i].marks << endl;
    }

    return 0;
}