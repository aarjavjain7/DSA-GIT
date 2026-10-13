#include<iostream>
#include<stdio.h>

using namespace std;

void change(int x){
    x = 50;
}

void change02(int *p){
    *p = 50;
}

int main(){
    int a = 10;
    int b = 20;
    change(a);
    change02(&b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}

