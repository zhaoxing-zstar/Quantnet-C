/*
DimensionException.cpp
Implement functions for DimensionException class
*/

#include<iostream>
#include<sstream>
using namespace std;
#include "Exception.hpp"

namespace zstar{
    namespace Containers{

        DimensionException::DimensionException() : ArrayException(){}
        DimensionException::~DimensionException(){}
        string DimensionException::GetMessage()
        {   stringstream ss;
            ss<<"Two arrays are of different dize!";
            return ss.str();
        }

    }
}