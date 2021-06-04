/*
Array.hpp
header files for Array Class
*/
#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
#include<iostream>
using namespace std;

namespace zstar{

    namespace Containers{
        class Array
        {
        private:
            CAD::Point *m_data;
            int m_size;
        public:
            Array();        //Default constructor
            Array(const int &array_len);        //overload constructor
            Array(const Array &a);          //copy constructor
            ~Array();       //Destructor

            Array& operator = (const Array &source);    //Assignment operator
            CAD::Point& operator [] (int index);         //add a square bracket operator
            const CAD::Point& operator [] (int index) const;         //const version of the square bracket operator

            //Getter functions
            int Size() const;
            CAD::Point& GetElement(int index) const; 

            //Setter function
            void SetElement(int i, const CAD::Point &p);


        };


        // header files for ArrayException class
        class ArrayException
        {
        private:

        public:
            ArrayException();       //constructor
            virtual ~ArrayException();

            virtual string GetMessage()=0;      //abstract function GetMessage()

        };

        //header files for OutOfBoundsException
        class OutOfBoundsException : public ArrayException
        {
        private:
            int m_index;
        public:
            OutOfBoundsException();
            OutOfBoundsException(int index);
            ~OutOfBoundsException();

            string GetMessage();
        };

    }
}

#endif