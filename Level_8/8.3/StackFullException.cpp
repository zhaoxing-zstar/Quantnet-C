
/*
StackFullException.cpp
Implementation for class StackFullException
*/
#include "StackException.hpp"
#include<iostream>
#include<sstream>
using namespace std;

namespace zstar{
    namespace Containers{
        StackFullException::StackFullException() {}
        StackFullException::~StackFullException() {}

        string StackFullException::GetMessage() const
        {
            stringstream ss;
            ss<<"Stack is full! ! ";
            return ss.str();
        }
    }
}