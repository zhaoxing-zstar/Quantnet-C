/*
Algorithms.cpp
Use the count_if algorithm to count the number of elements smaller than a certain number.
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include "IsSmaller.hpp"
using namespace std;

template <typename T>
bool IsSmaller1(const T& t)
{
    T test= 35;
    return ((t<test) ? 1:0);
}

int main () {
    vector<double> vec;
    for (int i=1; i<10; i++) vec.push_back(i*10); // vec: 10-90

    //pass to a global funtion to check if the double input is smaller than a certain value.
    cout << "vec contains " << count_if (vec.begin(), vec.end(), IsSmaller1<double>)  << " numbers smaller than 35.\n";

    double compare_value=35;
    // use a function object
    cout << "vec contains " << count_if (vec.begin(), vec.end(), IsSmaller<double>(compare_value))  << " numbers smaller than 35.\n";

    return 0;
}
