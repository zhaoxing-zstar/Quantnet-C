/*
Shape.cpp
Implement member functions for Shape class
*/


#include "Shape.hpp"
#include<sstream>
#include<iostream>

#include<stdlib.h>

namespace zstar{
    namespace CAD{
        //Default constructor
        Shape::Shape(){
            m_id=rand();        //initializes the id using a random number.
            // cout<<"Shape created."<<endl;
        }
        //copy constructor
        Shape::Shape(const Shape& s) : m_id(s.m_id)
        {
            // cout<<"Shape copied!"<<endl;
        }
        //Assignment operator
        Shape Shape::operator = (const Shape& s)
        {
            if(this==&s)
            {
                return *this;
            }
            m_id=s.m_id;
            return *this;

        }
        //Destructor
        Shape::~Shape(){}
        //retrive the id of the shape
        int Shape::ID() const
        {
            return m_id;
        }
        //return the id as string
        string Shape::ToString() const
        {
            stringstream ss;
            ss<<"ID:"<<m_id;
            return ss.str();
        }


    }
}