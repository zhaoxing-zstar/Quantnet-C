/*
Array.hpp
header files for ArrayException base class and OutOfBoundsException derived class
*/

#ifndef Exception_HPP
#define Exception_HPP

#include<iostream>
#include<sstream>
using namespace std;


namespace zstar{
    namespace Containers{
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