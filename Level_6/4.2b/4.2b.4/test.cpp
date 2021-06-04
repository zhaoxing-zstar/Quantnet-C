// Test Program for Stack
#include "Stack.hpp"
#include "Point.hpp"
#include "PointArray.hpp"
#include "Exception.hpp"
#include<iostream>
#include<sstream>

using namespace zstar::CAD;  
using namespace zstar::Containers;    
using zstar::Containers::Stack;
using namespace std;

int main()
{	Stack<Point> st(5);
	try
	{
		//initialize pointarrays with some values
		PointArray pa1(5);
		for(int i=0; i!=pa1.Size();i++)
		{
			pa1.SetElement(i,Point(i,i+1));
		}
		//push some points in the stack
		for(int i=0; i!=3;i++)
		{
			st.Push(pa1[i]);
		}
		cout<<st.Pop()<<endl;
		cout<<st.Pop()<<endl;
		cout<<st.Pop()<<endl;
		cout<<st.Pop()<<endl; //this will throw an exception because of too many pop(s)
	}
	catch(ArrayException& excep)
	{
		cout<<excep.GetMessage()<<endl;
	}
	catch(...) //default catch
	{
		cout<<"An unexcepted error has happened"<<endl;
	}
	return 0;
	
}
	
