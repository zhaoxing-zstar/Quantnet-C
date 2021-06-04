/*
 * @Descripttion: header file for OptionExtras 
 * @version: 1.0
 * @Author: Zstar
 * @Date: 2021-05-27 15:33:09
 * @LastEditors: Zstar
 * @LastEditTime: 2021-05-27 23:00:59
 */

#ifndef OptionExtras_hpp
#define OptionExtras_hpp
#include <vector>
using namespace std;

vector<double> GenerateMeshArray(double begin, double end, int n);
double Call_Price(double T, double K, double sig, double r, double U, double b);
double Put_Price(double T, double K, double sig, double r, double U, double b);
double Call_Delta(double T, double K, double sig, double r, double U, double b);
double Put_Delta(double T, double K, double sig, double r, double U, double b);
double Call_Gamma(double T, double K, double sig, double r, double U, double b);
double Put_Gamma(double T, double K, double sig, double r, double U, double b);
double Call_Vega(double T, double K, double sig, double r, double U, double b);
double Put_Vega(double T, double K, double sig, double r, double U, double b);
double Call_Theta(double T, double K, double sig, double r, double U, double b);
double Put_Theta(double T, double K, double sig, double r, double U, double b);
double PerpetualCall(double K, double sig, double r, double U, double b);
double PerpetualPut(double K, double sig, double r, double U, double b);

#endif
