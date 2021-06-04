// Test Program
// To make the output concise, I hide the information for Point constructor and destructor
#include "Point.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    double x,y;

    // Input the x and y coordinates for point2
    cout<<"Input the x- and y- coordinate for point :"<<endl;
    cin>>x;
    cin>>y;

    // Dynamically creating objects
    Point* pt=new Point;        //default constructor
    Point* pt_1=new Point(x,y);         //overload constructor
    Point* pt_2=new Point(*pt_1);       //copy constructor

    //calling distance function
    cout<<"The distance between "<<(*pt)<<" and "<<(*pt_1)<<" is "<<(*pt).Distance(*pt_1)<<endl;
    cout<<"The distance between "<<(*pt_1)<<" and "<<(*pt_2)<<" is "<<(*pt_1).Distance(*pt_2)<<endl;

    //delete the object 
    delete pt;
    delete pt_1;
    delete pt_2;

    int len_array=0;
    cout<<"Input the size of the array :"<<endl;
    cin>>len_array;

    //Point* pp[len_array];     This code works fine for me because the C++ compilers (e.g. GCC) 
    //support variable length arrays (VLA) where the size can be determined at run-time
    
    Point* array_p=new Point[len_array]; //can only use default constructor when creating an array of points on the heap using keyword new

    for(int i=0;i<len_array;i++)
    {
        cout<< array_p[i] << endl;
    }
    delete [] array_p;
    return 0;

}
