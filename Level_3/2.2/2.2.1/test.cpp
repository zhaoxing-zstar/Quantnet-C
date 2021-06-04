// Test Program
#include "Point.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    Point pt;
    double x,y;
    cout<<"Input the x- and y- coordinate:"<<endl;
    cin>>x;
    cin>>y;

    pt.SetX(x);
    pt.SetY(y);

    cout<<pt.ToString()<<endl;
    
    cout<<"The x-coordinate of the point is:"<<pt.GetX()<<endl;
    cout<<"The y-coordinate of the point is:"<<pt.GetY()<<endl;
    
    return 0;

}