/*
header files for Line class
*/

#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
#include <sstream>
using namespace std;

namespace zstar{

    namespace CAD{
        class Line : public Shape
        {
        private:
            Point m_startp;
            Point m_endp;
        public:
            Line();                                              //Default Constructor
            Line(const Point &startp, const Point &endp);        //Constructor with a start- and end-point.
            Line(const Line &l);                                 //copy Constructor
            Line& operator = (const Line &source);               //Assignment operator
            ~Line();                                             //Default Destructor

            //Getter functions for start and end point
            Point Start() const;
            Point End() const;

            //Setter functions for start and end point
            void Start(const Point &startp);
            void End(const Point &endp);

            string ToString() const;
            double Length() const;

            friend ostream& operator << (ostream& os, const Line& l);   //declare ostream << operator as friend

            void Draw();								// Simulates drawing by printing some text
        };
    }
}


#endif