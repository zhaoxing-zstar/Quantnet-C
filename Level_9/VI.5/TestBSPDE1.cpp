// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FdmDirector.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
using namespace std;

// #include "C:\2021_Spring_Semester\Quantnet_C++\Level_9\UtilitiesDJD\ExcelDriver\ExcelDriverLite.hpp"
enum OptionType
{
	Put,
	Call
};
namespace BS // Black Scholes
{
	// double sig = 0.3;
	// double K = 65.0;
	// double T = 0.25;
	// double r = 0.08;
	// double D = 0.0; // aka q

	enum OptionType Type = Put;
	//double T = 0.25; double K = 65; double sig = 0.30; double r = 0.08; double D = 0.0; // Batch1
	 double T = 0.65; double K = 70; double sig = 0.35; double r = 0.065; double D = 0.0; // Batch2
	//double T = 1.0; double K = 10; double sig = 0.50; double r = 0.12; double D = 0.0; // Batch3
	 //double T = 30.0; double K = 100.0; double sig = 0.30; double r = 0.08; double D = 0.0; // Batch4
	
	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{	if (Type==Put)
		{
			// Put
			return K *exp(-r * t);
		}
		else
		{
			return 0.0;
		}
	}

	double myBCR (double t)
	{
		if(Type==Put)
		{
			// Put
			return 0.0; // P
		}
		else
		{
			return 5.0*BS::K;
		}
	}

	double myIC (double x)
	{ // Payoff 
		if(Type==Put)
		{
				// Put
			return max(K - x, 0.0);
		}
		else
		{
			return max(x-K, 0.0);
		}
	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	/* change here : Put / Call    */
	BS::Type=Put;

	int J = static_cast<int>(5*BS::K); int N = 100000-1; // k = O(h^2) !!!!!!!!!

	double Smax = 5*BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();
	
	cout << "Finished\n";

	// Have you Excel installed (ExcelImports.cpp)
	ofstream os;
	os.open("output.csv");
	os<<"X,Y\n";

	cout <<string("Value")<<endl;
	vector<double> tmp;
	vector<double> curr=fdir.current();
	for(int i=0;i<fdir.xarr.size();i++)
	{	
		os<<fdir.xarr[i]<<","<<curr[i]<<endl;
		cout<<fdir.xarr[i]<<","<<curr[i]<<endl;
	}
	// printOneExcel(fdir.xarr, fdir.current(), string("Value"));

	return 0;
}
