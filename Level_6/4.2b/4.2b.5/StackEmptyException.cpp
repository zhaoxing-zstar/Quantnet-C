
/*
StackEmptyException.cpp
Implementation for class StackEmptyException
*/
#include "StackException.hpp"
#include<iostream>
#include<sstream>
using namespace std;

namespace zstar{
    namespace Containers{
        StackEmptyException::StackEmptyException() {}
        StackEmptyException::~StackEmptyException() {}

        string StackEmptyException::GetMessage() const
        {
            stringstream ss;
            ss<<"Stack is empty! ! ";
            return ss.str();
        }
    }
}