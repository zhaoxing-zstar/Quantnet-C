// Test Program
// To make the output concise, I hide the information for constructor and destructor
#include "Point.hpp"
#include "Array.hpp"
#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    int array_len;
    cout<<"Input the length of the Array: "<<endl;
    cin>>array_len;

    //test constructors
    Array arr1;
    Array arr2(array_len);
    Array arr3(arr2);
    cout<<"Array 1:"<<endl;
	for (int i=0;i<10;i++)
	{cout<<arr1[i]<<endl;}
	cout<<"Array 2:"<<endl;
	for (int i=0;i<arr2.Size();i++)
	{cout<<arr2[i]<<endl;}
	cout<<"Array 3:"<<endl;
	for (int i=0;i<arr3.Size();i++)
	{cout<<arr3[i]<<endl;}

    //test for setters
    Point p1(2,3), p2(7.8,9.1), p3(4.5,2.1);
    arr1.SetElement(1,p1);
    arr2.SetElement(5,p2);
    arr3.SetElement(8,p3); 

    //test for getters
    cout<<arr1.GetElement(1)<<endl;
    cout<<arr2.GetElement(5)<<endl;
    cout<<arr3.GetElement(8)<<endl;

    //test operator =
    Array arr4=arr1;
    cout<<"After arr4 = arr1, arr4 is:"<<endl;
    for (int i=0;i<arr4.Size();i++)
	{cout<<arr4[i]<<endl;}

    //test for const version of [], this is used for const objects
	const Array arr5(array_len);
	cout<<"Array 5:"<<endl;
	for (int i=0;i<arr5.Size();i++)
	{cout<<arr5[i]<<endl;}

    return 0;

}
