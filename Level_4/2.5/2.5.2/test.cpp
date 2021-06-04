// Test Program
// To make the output concise, I hide the information for Point constructor and destructor
#include "Point.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    Point** array_point_p=new Point* [3];       //array of Point pointers
    //initialize each pointer in the pointers array.
    for(int i=0;i<3;i++)
    {
        double x,y;
        cout<<"Input the x- and y- coordinates for Point "<<i+1<<endl;
        cin>>x; cin>>y;
        array_point_p[i] = new Point(x,y);
    }
    //print each point in the array
    for(int i=0;i<3;i++)
    {
        cout<<*array_point_p[i]<<endl;
    }
    //delete pointer in the pointers array
    for(int i=0;i<3;i++)
    {
        delete array_point_p[i];
    }
    delete[] array_point_p;     //delete the array


    return 0;

}
