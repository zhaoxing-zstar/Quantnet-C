// Test Program
#include "Circle.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    double x,y,radius;

    // Input the x and y coordinates for point1
    cout<<"Input the x- and y- coordinate for centerpoint :"<<endl;
    cin>>x;
    cin>>y;
    Point p1(x,y);

    cout<<"p1:"<<p1.ToString()<<endl;

    //Input the radius
    cout<<"Input the radius:"<<endl;
    cin>>radius;

    //create a circle class 
    Circle c1(radius, p1);
    cout<<c1.ToString()<<endl;

    //output the Diamter, area, circumference of circle c1
    cout<<"The Diamter of Circle c1 is:"<<c1.Diameter()<<endl;
    cout<<"The Area of Circle c1 is:"<<c1.Area()<<endl;
    cout<<"The Circumference of Circle c1 is:"<<c1.Circumference()<<endl;

    //change the radius & centerpoint
    cout<<"Input the new x- and y- coordinate for centerpoint :"<<endl;
    cin>>x;
    cin>>y;
    Point p2(x,y);
    c1.CenterPoint(p2);
    cout<<"Input the new radius:"<<endl;
    cin>>radius;
    c1.Radius(radius);
    cout<<c1.ToString()<<endl;

    return 0;
}
