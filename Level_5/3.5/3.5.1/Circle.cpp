/*
Circle.cpp
Implement the memeber functions for Circle class
*/

//define pi
#define _USE_MATH_DEFINES
#include<cmath>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

#include<iostream>
#include<sstream>
using namespace std;

namespace zstar{

    namespace CAD{
        //Default Constructor
        Circle::Circle() : Shape(),m_radius(0.0), m_center_p(0,0)
        {
            // cout<<"Circle created"<<endl;
        }

        //Constructor with given radius and centerpoint
        Circle::Circle(const double &radius, const Point &center_p) : Shape(),m_radius(radius), m_center_p(center_p)
        {
            // cout<<"Circle created with given values"<<endl;
        }

        //copy constructor
        Circle::Circle(const Circle &c):Shape(), m_radius(c.m_radius), m_center_p(c.m_center_p)
        {
            // cout<<"Circle copied!"<<endl;
        }

        //Default destructor
        Circle::~Circle()
        {
            cout<<"Circle destroyed"<<endl;
        }

        //Getter functions for radius & centerpoint
        double Circle::Radius() const
        {
            return m_radius;
        }
        Point Circle::CenterPoint() const
        {
            return m_center_p;
        }

        //Setter functions for radius & centerpoint
        void Circle::Radius(const double &radius)
        {
            m_radius=radius;
        }
        void Circle::CenterPoint(const Point &center_p)
        {
            m_center_p=center_p;
        }

        //string description of the Circle
        string Circle::ToString() const
        {
            stringstream ss;
            ss<<"Circle Radius:"<<m_radius<<",Center Point:"<<m_center_p.ToString();

            return ss.str();
        }

        //calculate the diameter, area and circumference of the circle
        double Circle::Diameter() const
        {
            return 2*m_radius;
        }
        double Circle::Area() const
        {
            return M_PI*pow(m_radius,2);
        }
        double Circle::Circumference() const
        {
            return 2*M_PI*m_radius;
        }
        //Assignment operator
        Circle &Circle::operator = (const Circle &source)
        {   if(this==&source)
            {
                return *this;
            }
            // call the base class assignment
            Shape::operator=(source);

            //copy
            m_radius=source.m_radius;
            m_center_p=source.m_center_p;
            return *this;
        }
        //overloading Ostream << Operator
        ostream& operator << (ostream& os, const Circle& c)
        {
            os << "Circle Radius:"<<c.m_radius<<",Center Point:"<<c.m_center_p<<endl;
            return os;
        }
    }
}
