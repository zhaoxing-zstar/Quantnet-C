/*
Line.cpp
Implement member functions for Line class
*/

#include "Point.hpp"
#include "Line.hpp"
#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;
namespace zstar{

    namespace CAD{
        //Default Constructor
        Line::Line() : Shape(),m_startp(0,0), m_endp(0,0)
        {   
            // cout<<"Line created"<<endl;
        }
        //Constructor with a start- and end-point.
        Line::Line(const Point &startp, const Point &endp) : Shape(),m_startp(startp), m_endp(endp)
        {
            // cout<<"Line created with given points"<<endl;
        }
        //Copy constructor
        Line::Line(const Line &l) : Shape(l),m_startp(l.m_startp),m_endp(l.m_endp)
        {   
            // cout<<"Line copied!"<<endl;
        }
        //Default Destructor
        Line::~Line()
        {
            // cout<<"Line Destroyed"<<endl;
        }
        //get the start point
        Point Line::Start() const
        {
            return m_startp;
        }
        //get the end point
        Point Line::End() const
        {
            return m_endp;
        }
        //Set the start point
        void Line::Start(const Point &new_startp)
        {
            m_startp=new_startp;
        }
        //Set the end point
        void Line::End(const Point &new_endp)
        {
            m_endp=new_endp;
        }
        //description of the line
        string Line::ToString() const
        {   string s=Shape::ToString();

            stringstream ss;
            ss<<s<< " Line start point:"<<m_startp.ToString()<<"Line end point:"<<m_endp.ToString()<<endl;

            return ss.str();
        }
        //return length of the line
        double Line::Length() const
        {
            return m_startp.Distance(m_endp);
        }
        //Assignment operator
        Line& Line::operator = (const Line &source)
        {   if(this==&source)
            {
                return *this;
            }
            //call the base class assignment
            Shape::operator=(source);

            //copy
            m_startp=source.m_startp;
            m_endp=source.m_endp;
            return *this;
        }
        //overloading Ostream << Operator
        ostream& operator << (ostream& os, const Line& l)
        {
            os << "Line start point:"<<l.m_startp<<"Line end point:"<<l.m_endp<<endl;;
            return os;
        }

    }
}