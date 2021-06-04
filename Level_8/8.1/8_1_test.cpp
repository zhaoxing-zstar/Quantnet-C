/*
A program testing the Smart Pointers
*/

#include<boost/shared_ptr.hpp>
#include "Array.hpp"
#include "Circle.hpp"
#include<iostream>

using namespace std;
using namespace zstar::CAD;
using namespace zstar::Containers;
// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{   
    // initialize smart pointers for different shape
    ShapePtr pt(new Point());
    ShapePtr li(new Line(Point(),Point()));
    ShapePtr cir(new Circle());

    {//create a new scope

        //create an array of shared pointers for shapes
        ShapeArray arr_shape(3);
        cout<<"Inside a new scope"<<endl;
        //fill the array
        arr_shape[0]=pt;
        cout << "Point Reference Count: " << pt.use_count() << endl;
        arr_shape[1]=li;
        cout << "Line Reference Count: " << li.use_count() << endl;
        arr_shape[2]=cir;
        cout << "Point Reference Count: " << cir.use_count() << endl;
        cout<<endl;//print a new line
    }//end of the scope

	//chece if the shapes are deleted automatically
    cout <<"Out of the Scope"<<endl;
	cout << "Point Reference Count: " << pt.use_count() << endl;
	cout << "Line Reference Count: " << li.use_count() << endl;
	cout << "Circle Reference Count: " << cir.use_count() << endl;

    return 0;
}
/* Output:

Inside a new scope
Point Reference Count: 2
Line Reference Count: 2
Point Reference Count: 2

Out of the Scope
Point Reference Count: 1
Line Reference Count: 1
Circle Reference Count: 1

As we can see, the shapes are automatically deleted when nobody is referencing them.
*/