/*
a Person tuple that contains a name, age and height
function: print the Person tuple & change the age of person

*/
#include<iostream>
#include<boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace std;

typedef boost::tuple<string, int, double> Person;
//print the Person Tuple
void PrintPerson(const Person& p)
{
    cout<<"Name: "<<p.get<0>()<<" Age: "<<p.get<1>()<<" Height: "<<p.get<2>()<<endl;
}
//change the age of person
template <typename T>
void IncreamentAge(T &t,T new_age)
{
    t=new_age;
}
int main()
{   
    //create Person tuples
    Person p1=boost::make_tuple(string("A"),10,1.70);
    Person p2=boost::make_tuple(string("B"),20,1.80);
    Person p3=boost::make_tuple(string("C"),30,1.90);

    //print the Person tuple
    PrintPerson(p1);
    PrintPerson(p2);
    PrintPerson(p3);

    //change the age of person
    IncreamentAge(p1.get<1>(),21);
    IncreamentAge(p2.get<1>(),31);
    IncreamentAge(p3.get<1>(),41);

    //print the Person tuple
    PrintPerson(p1);
    PrintPerson(p2);
    PrintPerson(p3);
    return 0;
}