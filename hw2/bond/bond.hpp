//
//  bond.hpp
//  Homework2
//
// Hardik Maheshwari

#ifndef bond_hpp
#define bond_hpp

#include<stdio.h>
#include<string>

using namespace std;
class bond
{
    string expiration_date;
    double frequency;
    double coupon_rate;

public:
    bond();
    bond(string expiration_date, double frequency, double coupon_rate);
    bond(const bond& b);
    string ToString();
    double pricing( double maturity, double int_rate);
    ~bond();
};
#endif /* bond.hpp */
