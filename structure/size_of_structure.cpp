#include <iostream>
#include <stdio.h>

using namespace std;

//we are making a structure of rectangle
struct rectangle
{
    //here we are simply defining characteristics of a triangle
    int length;
    int breadth;
    char x;
};

int main()
{
    //here we are creating a variable that is having a structure of rectangle
    rectangle r1;
    cout << "size of structure is: " << sizeof(r1);

    return 0;
}