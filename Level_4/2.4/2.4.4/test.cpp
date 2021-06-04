// Test Program
// To make the output concise, I hide the information for Point constructor and destructor
// The code is basically the same as test.cpp in 2.4.1, just change all ".ToString()" to directly "<<"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
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

    cout<<"p1:"<<p1<<endl;

    // Input the x and y coordinates for point2
    cout<<"Input the x- and y- coordinate for point 2:"<<endl;
    cin>>x;
    cin>>y;
    Point p2(x,y);

    Point p3=-p1;                   //test negating the coordinates
    cout<<"Negate of p1 is:"<<p3<<endl;

    Point p4=p1*3;  //test scaling the coordinates
    cout<<p1<<" multiplied by 3 = "<<p4<<endl;

    Point p5=p1+p2; //test adding coordinates
    cout<<p1<<"+"<<p2<<"="<<p5<<endl;

    cout<<"p1==p2?" << ((p1==p2)?"Yes":"No") <<endl; //test equality

    p1=p1;    //test Point assignment operator
    cout<<"self assignment:p1=p1 is "<<p1<<endl;

    p5*=4;
    cout<<(p1+p2)<<"*=4 equals "<<p5<<endl;

    Line l1(p1,p2), l2;     //test Line assignment operator
    cout<<"l1(p1,p2) is:"<<l1<<endl;
    l2=l1;
    cout<<"using Assignment operator l2=l1, l2 is: "<<l2<<endl;

    Circle c1(5.0,p1),c2;   //test Circle assignment operator
    cout<<"c1(5.0,p1) is: "<<c1<<endl;
    c2=c1;
    cout<<"Using Assignment operator c2=c1, c2 is: "<<c2<<endl;
    

    return 0;

}
