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

    // // copy constructor
    // Point p3(p2);

    // cout<<"p3:"<<p3.ToString()<<endl;



    
    // output their distances from the origin and distances between them
    cout<<"The distance from p1 to the origin (0,0) is:"<<p1.DistanceOrigin()<<"\n"<<endl;
    cout<<"The distance from p2 to the origin (0,0) is:"<<p2.DistanceOrigin()<<"\n"<<endl;
    cout<<"The distance between p1 and p2 is:"<<p1.Distance(p2)<<endl;
    return 0;

}

/*
Explanation:

change the Distance function so that it passes the input point “by reference” so that no copy is made

*/