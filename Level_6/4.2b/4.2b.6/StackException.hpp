/*
StackException.hpp
header files for StackException, StackEmptyException and StackFullException classes
*/
#include<iostream>
#include<sstream>
using namespace std;

#ifndef StackException_HPP
#define StackException_HPP
namespace zstar{
    namespace Containers{
        class StackException{
        public:
            StackException();       //constructor
            virtual ~StackException();      //destructor
            virtual string GetMessage() const = 0;      //abstract funtion
        };
    }
}
#endif

#ifndef StackEmptyException_HPP
#define StackEmptyException_HPP
namespace zstar{
    namespace Containers{
        class StackEmptyException : public StackException
        {
        public:
            StackEmptyException();       //constructor
            virtual ~StackEmptyException();      //destructor
            virtual string GetMessage() const;      //return a message string
        };
    }
}
#endif

#ifndef StackFullException_HPP
#define StackFullException_HPP
namespace zstar{
    namespace Containers{
        class StackFullException : public StackException
        {
        public:
            StackFullException();       //constructor
            virtual ~StackFullException();      //destructor
            virtual string GetMessage() const;      //return a message string

        };
    }
}
#endif