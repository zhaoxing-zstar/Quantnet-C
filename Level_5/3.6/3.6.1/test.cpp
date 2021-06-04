// Test Program
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;  
using namespace zstar::Containers;    
using namespace std;
int main()
{
	
	Array arr(5);
	int index;
	for(int i=0;i<arr.Size();i++)
	{arr[i]=Point(i*i,0);}//modify each element with Point
	cout<<"Input the index of the element"<<endl;
	cin>>index;
	try
	{
		cout<<arr[index]<<endl;
		arr.SetElement(4,Point(1,1));		
		cout<<arr.GetElement(4);			
		arr[3]=Point(2,2);		
		cout<<arr[3];
	}
	catch (int err)
	{
		if(err==-1)
		{
			cout<<"Index out of bounds!"<<endl;
		}
	}
	catch(...)
	{
		cout<<"An unknown error has occured!"<<endl;
	}
}
	
