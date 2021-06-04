// Test Program
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Exception.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;  
using namespace zstar::Containers;    
using namespace std;
int main()
{
	
	Array<Point> points(10);
	int index;
	for(int i=0;i<points.Size();i++)
	{points[i]=Point(i*i,0);}//modify each element with Point
	cout<<"Input the index of the element"<<endl;
	cin>>index;
	try
	{
		cout<<points[index]<<endl;
		points.SetElement(4,Point(1,1));		
		cout<<points.GetElement(4);			
		points[3]=Point(2,2);		
		cout<<points[3]<<endl;			
		//print array on screen
		for(int i=0;i!=points.Size();i++)
		{
			cout<<"Element "<<i+1<<" of the points array is: "<<points[i]<<endl;
		}
	}
	catch (ArrayException& err)
	{
			cout<<err.GetMessage()<<endl;
	}
	catch(...)
	{
		cout<<"An unknown error has occured!"<<endl;
	}
}
	
