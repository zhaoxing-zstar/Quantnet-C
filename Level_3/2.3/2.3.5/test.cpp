// Test Program
#include "Point.hpp"
#include "Line.hpp"
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

    //create a const Object
    const Point cp(1.5,3.9);

    //create a line class using p1 & p2
    Line l1(p1,p2);
    cout<<l1.Tostring()<<endl;

    //change the start point
    l1.Start(cp);
    cout<<l1.Tostring()<<endl;

    // output their distances from the origin and distances between them
    cout<<"The length of line l1 is:"<<l1.Length()<<endl;
    return 0;

}
