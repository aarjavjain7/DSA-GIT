// we have to find area of rectangle by taking inputs
//from the user using structure.

#include <iostream>
#include <stdio.h>

using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

int main()
{
    int x,y;
    cout << "Enter the length of rectangle: ";
    cin >> x;
    cout << "Enter the breadth of rectangle: ";
    cin >> y;
    rectangle r = {x,y};

    printf("the area of rectangle is %d\n",r.length*r.breadth);
    cout << "area of rectangle is " ;
    cout << r.length*r.breadth;

    return 0;

}