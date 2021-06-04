/*
 * @Descripttion: Option.hpp Base class for options
 * @version: 1.0
 * @Author: Zstar
 * @Date: 2021-05-26 23:06:07
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 23:31:09
 */

#ifndef Option_hpp
#define Option_hpp
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;
class Option
{   
private:
	virtual double CallPrice() const = 0; // Price of call
	virtual double PutPrice() const = 0; // Price of put
public:
    Option();       //Constructor
    Option(const Option& op);       //copy constructor
    Option(const string& Optiontype);       //Option type
    virtual ~Option();          //virtual destructor

    Option& operator = (const Option &op);      //assignment operator

    string OptionType;          //Option name (Put,call)
public:

    void Init();	// Initialise all default values
	void Copy(const Option& o2);
    
    // Functions that calculate option price and sensitivities
	double Price() const;
	double Delta() const;
    double Vega() const;
    double Gamma() const;
    double Theta() const;

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)

};


#endif








