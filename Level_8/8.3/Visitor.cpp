/*
Visitor.cpp
Implement functions for class Visitor

*/

#include "Visitor.hpp"

namespace zstar{
    namespace CAD{

        Visitor::Visitor() : m_dx(0), m_dy(0) {}        // Default constructor
		
		Visitor::Visitor(double dx, double dy) : m_dx(dx), m_dy(dy) {}  // Overload constructor that initializes with dx and dy value
		
		Visitor::Visitor(const Visitor& source) :  m_dx(source.m_dx), m_dy(source.m_dy) {}  // Copy constructor

		Visitor& Visitor::operator = (const Visitor& source)  // Assignment operator
		{
			// Check to make sure not assigning to myself
			if (this == &source) return *this;

			// Copy state
			m_dx = source.m_dx;
			m_dy = source.m_dy;

			return *this;
		}

		Visitor::~Visitor() {}	// Destructor

        //visit a point
        void Visitor::operator () (Point& p) const
        {
            p.X(p.X()+m_dx);
            p.Y(p.Y()+m_dy);
        }

        //visit a line
        void Visitor::operator() (Line& l) const
        {
            Point pstart=l.Start();
            Point pend=l.End();

            (*this)(pstart);
            (*this)(pend);

            l.Start(pstart);
            l.End(pend);
        }

        //visit a circle
        void Visitor::operator() (Circle &c) const
        {
            Point cen=c.CenterPoint();
            (*this)(cen);
            c.CenterPoint(cen);
        }
    }
}