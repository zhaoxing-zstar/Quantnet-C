// Test Program
#include "Point.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    double x,y;

    // Input the x and y coordinates for point1
    cout<<"Input the x- and y- coordinate for point 1:"<<endl;
    cin>>x;
    cin>>y;
    Point p1(x,y);

    cout<<"p1:"<<p1.ToString()<<endl;

    // Input the x and y coordinates for point2
    cout<<"Input the x- and y- coordinate for point 2:"<<endl;
    cin>>x;
    cin>>y;
    Point p2(x,y);

    cout<<"p2:"<<p2.ToString()<<endl;

    /*
    const Point cp(1.5,3.9);
    cp.X(0.3);      // This causes a compile error because const object is unchangeable;

    cout<<cp.X()<<endl;  // This also causes a compile erroe because the compiler 
                         //  does not know that the function does not change anything;
    */ 

   //create a const Object
    const Point cp(1.5,3.9);
    cout<<"The x-coordinate of cp(const Point) is:"<<cp.X()<<endl;

    // output their distances from the origin and distances between them
    cout<<"The distance from p1 to the origin (0,0) is:"<<p1.Distance()<<"\n"<<endl;
    cout<<"The distance from p2 to the origin (0,0) is:"<<p2.Distance()<<"\n"<<endl;
    cout<<"The distance from cp to the origin (0,0) is:"<<cp.Distance()<<"\n"<<endl;
    cout<<"The distance between p1 and cp is:"<<p1.Distance(cp)<<endl;
    return 0;

}
