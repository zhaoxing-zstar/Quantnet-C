// Test Program
// To make the output concise, I hide the information for constructor and destructor
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include<iostream>
#include<sstream>

using zstar::CAD::Line;         //using declaration for using a single class (Line)
using namespace zstar::Containers;          //using declaration for a complete namespace (Containers)
namespace Circ=zstar::CAD;         //using the Circle class by creating a shorter alias
using namespace std;
int main()
{
	//Input the size of the array
	int array_len;
	cout<<"Input the size of the array: "; 
    cin>>array_len;
	
	Array arr1(array_len);
	
	for(int i=0;i<arr1.Size();i++)
	{arr1[i]=zstar::CAD::Point(i*i,0);}//modify each element with Point(full namespace)

	//output the Array 1
	cout<<"Array 1:"<<endl;
	for (int i=0;i<arr1.Size();i++)
	{cout<<arr1[i]<<endl;}
	
	//Initiate coordinates to create points, then line, then circle
	double x1,x2,y1,y2;
	cout<<"x- and y- coordinates for point 1: "<<endl;
	cin>>x1; cin>>y1;
	cout<<"x- and y- coordinates for point 2: "<<endl;
	cin>>x2; cin>>y2;

	//Create the objects
	zstar::CAD::Point p1(x1,y1);
	zstar::CAD::Point p2(x2,y2);
	Line l1(p1,p2);
    int r=5;
	Circ::Circle c1(r,p1);

	//output point, line & circle
	cout<<p1<<" and "<<p2<<endl;
	cout<<l1<<" with a lengh of "<<l1.Length()<<endl;
	cout<<c1<<", the circumference is "<<c1.Circumference()<<", the area is "<<c1.Area()<<endl;
	cout<<endl;


    return 0;

}
