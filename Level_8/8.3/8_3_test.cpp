/*
A program testing the boost::variant
*/
#include "Visitor.hpp"
#include "Circle.hpp"
#include <iostream>
#include<boost/variant.hpp>
using namespace std;
using namespace zstar::CAD;

typedef boost::variant<Point, Line, Circle> ShapeType;
// a function that ask the user what kind of shape to create and returns that.
ShapeType ReturnShape()
{
    ShapeType u;
    int type;
    cout<<"Input the Shape you want to create(1=Point, 2=Line, 3=Circle): "<<endl;
    cin>>type;
    switch (type)
    {
    case 1:
        u=Point(1,2);
        break;
    case 2:
        u=Line(Point(1,2),Point(3,4));
        break;
    case 3:
        u=Circle(2,Point(1,2));
        break;
    default:
        cout<<"Bad input, set Point as default"<<endl;
        u=Point();
        break;
    }
    return u;
}
int main()
{
    ShapeType shtype;
    shtype=ReturnShape();
    cout<<"User-specified Type: "<<shtype<<endl;
    try
    {
        Line l;
        l=boost::get<Line>(shtype);
        cout<<l<<endl;
    }
    catch(const boost::bad_get& e)
    {
        std::cerr << e.what() << '\n';
    }
    // apply the Visitor to the user-specified type.
    boost::apply_visitor(Visitor(10,20), shtype);
    cout<<"Values after applying Visitor: "<< shtype<<endl;
    return 0;
}