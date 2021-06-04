/*
 * @Descripttion:  source file for OptionExtras, based on OptionExtras in course materials
 * @version: 
 * @Author: Zstar
 * @Date: 2021-05-26 20:58:37
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 23:40:24
 */

#include<string>
#include<vector>
#include <cmath>
#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include "OptionExtras.hpp"

using namespace std;
using namespace boost::math;

vector<double> GenerateMeshArray(double begin, double end, int n)
{
	vector<double> vec;
	double h=(end-begin)/(n-1);
	for(int i=0; i<n; i++)
	{
		vec.push_back(begin+h*i);
	}
	return vec;
}

double Call_Price(double T, double K, double sig, double r, double U, double b) 
{

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	normal_distribution<> normalDist(0,1);

	return (U * exp((b-r)*T) * cdf(normalDist,d1)) - (K * exp(-r * T)* cdf(normalDist,d2));

}

double Put_Price(double T, double K, double sig, double r, double U, double b) 
{

	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;
	
	normal_distribution<> normalDist(0,1);
	return (K * exp(-r * T)* cdf(normalDist,-d2)) - (U * exp((b-r)*T) * cdf(normalDist,-d1));

}

double Call_Delta(double T, double K, double sig, double r, double U, double b) 
{
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
	normal_distribution<> normalDist(0,1);

	return exp((b-r)*T) * cdf(normalDist, d1);
}

double Put_Delta(double T, double K, double sig, double r, double U, double b) 
{
	return Call_Delta(T,K,sig,r,U,b) - exp((b-r)*T);
}

double Call_Gamma(double T, double K, double sig, double r, double U, double b) 
{
	normal_distribution<> normalDist(0,1);
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;

	return ( pdf(normalDist, d1) * exp((b-r)*T) ) / (U * tmp);
}

double Put_Gamma(double T, double K, double sig, double r, double U, double b) 
{
	return Call_Gamma(T,K,sig,r,U,b);
}


double Call_Vega(double T, double K, double sig, double r, double U, double b) 
{
	normal_distribution<> normalDist(0,1);
	double tmp = sig * sqrt(T);
	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;

	return (U * exp((b-r)*T) * pdf(normalDist,d1) * sqrt(T) );
}

double Put_Vega(double T, double K, double sig, double r, double U, double b) 
{
	return Call_Vega(T,K,sig,r,U,b);
}

double Call_Theta(double T, double K, double sig, double r, double U, double b) 
{
	normal_distribution<> normalDist(0,1);
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	double t1 =  (U * exp((b-r)*T ) * pdf(normalDist,d1) * sig * 0.5 )/ sqrt(T);
	double t2 =  (b-r)*(U * exp((b-r)*T) * cdf(normalDist,d1));
	double t3 =  r * K * exp(-r * T) * cdf(normalDist,d2);

	return -(t1 + t2 + t3);
}


double Put_Theta(double T, double K, double sig, double r, double U, double b) 
{
	normal_distribution<> normalDist(0,1);
	double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b + (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;

	double t1 =  (U * exp( (b-r)*T ) * pdf(normalDist,d1) * sig * 0.5 )/ sqrt(T);
	double t2 =  (b-r)*(U * exp((b-r)*T) * cdf(normalDist,-d1));
	double t3 =  r * K * exp(-r * T) * cdf(normalDist, -d2);

	return t2 + t3 - t1;
}
double PerpetualCall (double K, double sig, double r, double U, double b)
{ // Dividend q = r - b

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	

	if (1.0 == y1)
		return U;

	double fac2 = ((y1 - 1.0)*U) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);

	return c;
}

double PerpetualPut (double K, double sig, double r, double U, double b)
{

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return U;

	double fac2 = ((y2 - 1.0)*U) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);

	return p;
}






