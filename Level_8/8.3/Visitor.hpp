/*
Vistor.hpp
header files for class Vistor
*/
#ifndef Visitor_HPP
#define Visitor_HPP

#include<iostream>
#include<boost/variant.hpp>
#include"Circle.hpp"
using namespace std;

namespace zstar{
    namespace CAD{
        class Visitor: boost::static_visitor<int>
        {
        private:
            double m_dx;
            double m_dy;
        public:
            Visitor();      // Default constructor
			Visitor(double dx_value, double dy_value);      // Overload constructor
			Visitor(const Visitor& source);	        // Copy constructor
			Visitor& operator = (const Visitor& source);        // Assignment operator
			virtual ~Visitor();	        // Destructor

            //visit a point
            void operator () (Point& p) const;

            //visit a line
            void operator () (Line& l) const;

            //visit a circle
            void operator () (Circle& c) const;
        };
    }

}


#endif