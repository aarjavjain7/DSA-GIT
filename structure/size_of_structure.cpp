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
    // here character should be given size of 1 but it will give size 4 because 
    // length and breadth will give values of 4 so char will also take value of 4
    // istead of getting a seperate block of 1
};

int main()
{
    //here we are creating a variable that is having a structure of rectangle
    rectangle r1;
    cout << "size of structure is: " << sizeof(r1);

    return 0;
}