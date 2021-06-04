/*
Iterators.cpp
create a funtion that calculates the sum of a container with doubles
*/
#include <iterator>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
template <typename T> double Sum(const T& source)
{       //a template Sum function
    double sum=0;
    typename T::const_iterator i;
    // I try not to use the typename before T, however, it will cause errors.
    for (i=source.begin();i!=source.end();i++)
    {
        sum+=(*i);
    }
    return sum;
}

template <typename T1,typename T2>
double Sum(const map<T1,T2>& source)
{       //a Sum function for map containers
    double sum=0;
    typename map<T1,T2>::const_iterator i;
    for (i=source.begin();i!=source.end();++i)
    {
        sum+=i->second;
    }
    return sum;
}

template<typename T>
double Sum(const typename T::const_iterator& start, const typename T::const_iterator&  end)
{   // sum between two iterators 
    double sum=0;
    typename T::const_iterator i;
    for(  i=start; i!=end;i++)
    {
        sum+=*i;
    }
    return sum;

}

 template<typename T1, typename T2>
 double Sum(typename map<T1,T2>::const_iterator start, typename map<T1,T2>::const_iterator end)
{   // sum between two iterators for map
    double sum=0;
    typename map<T1,T2>::const_iterator i;
    for(i=start; i!=end;i++)
    {
        sum+=i->second;
    }
    return sum;
}
int main()
{
    //create a list of doubles and add some data
    list<double> lst1;
    for ( int i=0; i<5;i++)
    {
        lst1.push_back(pow(i,2));
    }
    list<double>::const_iterator start1=lst1.begin();
    list<double>::const_iterator end_list=lst1.end();
    auto start_list=next(start1,2);   //points to 2
    cout<<"Sum of list elements:"<<Sum(lst1)<<endl;
    cout<<"Sum of list elements from 2:4: "<<Sum<list<double>>(start_list,end_list)<<endl;

    //create a vector of doubles and add some data
    vector<double> vec(5);
    for(int i=0;i<vec.size();i++)
    {
        vec[i]=i+2;
    }
    cout<<"Sum of vector elements:"<<Sum(vec)<<endl;
    vector<double>::const_iterator start2=vec.begin();
    vector<double>::const_iterator end_vec=vec.end();
    auto start_vec=next(start2,3);   //points to 3
    cout<<"Sum of list elements from 3:4: "<<Sum<vector<double>>(start_vec,end_vec)<<endl;

    //create a map that maps strings to doubles
    map<string, double> map1;
    map1.insert(pair<string, double>("a",10.0));
    map1.insert(pair<string, double>("b",20.0));
    map1.insert(pair<string, double>("c",30.0));
    map1.insert(pair<string, double>("d",40.0));
    cout<<"Sum of double values in the map:"<<Sum(map1)<<endl;

    map<string,double>::const_iterator start3=map1.begin();
    map<string,double>::const_iterator end_map=map1.end();
    auto start_map=next(start3,2);   //points to 2
    cout<<"Sum of list elements from 2:4: "<<Sum<string,double>(start_map,end_map)<<endl;
    return 0;
    
}
