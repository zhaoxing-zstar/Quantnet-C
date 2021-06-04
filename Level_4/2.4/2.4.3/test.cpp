// Test Program for exercise 2.4.3
#include "Point.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    Point p(1.0, 1.0);
    if (p==(Point)1.0) cout<<"Equal!"<<endl;
    else cout<<"Not equal"<<endl;
    return 0;

}
/*
# The output is "Equal!" if we don't add "explicit " before the constructor,
because the Point constructor with the single double argument is implicitly used to 
convert the number in the if statement to a Point object. Thus constructors are used 
as implicit conversion operators.

# after adding "explicit", it gives a compile error as "Point == double", which means 
we have to use the constructor as conversion operator explicitly this time.

*/