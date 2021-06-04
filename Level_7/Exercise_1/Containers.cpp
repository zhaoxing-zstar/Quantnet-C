/*
Containers.cpp
practice with different STL containers
*/
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main()
{
    //create a list of doubles and add some data
    list<double> lst1;
    for ( int i=0; i<5;i++)
    {
        lst1.push_back(pow(i,2));
    }
    cout<<"Front of list:"<<lst1.front() <<", Back of list:"<< lst1.back()<<endl;

    //create a vector of doubles and add some data
    vector<double> vec(5);
    for(int i=0;i<vec.size();i++)
    {
        vec[i]=i+2;
    }
    vec[0]=10;
    vec.push_back(8);
    vec.push_back(10);
    cout << "The vector elements are: ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout<<endl;
    
    //create a map that maps strings to doubles
    map<string, double> map1;
    map1.insert(pair<string, double>("a",10.0));
    map1.insert(pair<string, double>("b",20.0));
    map1.insert(pair<string, double>("c",30.0));
    map1.insert(pair<string, double>("d",40.0));
    cout<<"The first element is:"<<map1["a"]<<endl;
    
    // printing map1
    map<string, double>::iterator itr;
    cout << "\nThe map1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = map1.begin(); itr != map1.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
    return 0;
}