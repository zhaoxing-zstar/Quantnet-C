/*
header files for Shape base class
*/
#ifndef Shape_HPP
#define Shape_HPP
#include<iostream>
using namespace std;

namespace zstar{
    namespace CAD{
        class Shape
        {
        private:
                int m_id;
        public:
                // constructors
                Shape();        //default constructor
                Shape(const Shape& s);         //copy constructor
                Shape& operator = (const Shape& s);          //Assignment operator
                virtual ~Shape();

                //retrive the id of the shape
                int ID() const;

                //return the id as string
                virtual string ToString() const;

                virtual void Draw() = 0; // Abstract Function Draw

        };
    }
}


#endif