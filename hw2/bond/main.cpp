//  bond.cpp
//  Homework2
//
// Hardik Maheshwari

#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include <fstream>
#include "bond.hpp"

using namespace std;
bond :: bond(){
    expiration_date = "0";
    frequency = 0;
    coupon_rate = 0;
}
bond :: bond(string expdate, double freq, double cpr){
    expiration_date = expdate;
    frequency = freq;
    coupon_rate = cpr;
}
bond :: ~bond(){
    std::cout <<" destructing the object" << endl;
}
bond :: bond(const bond& b){
    expiration_date = b.expiration_date;
    frequency = b.frequency;
    coupon_rate = b.coupon_rate;
}
string bond :: ToString(){
    return "Bond(" + this->expiration_date + "," + to_string(frequency) + ", " + to_string(coupon_rate) +")";
}

double bond :: pricing(double maturity, double int_rate ){
    int periods = round(maturity / frequency);
    double price = 0;
    for(int i = 1; i <= periods; i++){
        price = price + 100* coupon_rate * frequency * exp (-1* i * frequency * int_rate);
    }
    price = price + 100 *( 1 + coupon_rate * (maturity - (periods *frequency)) )* exp (-1* maturity * int_rate);
    return price;
}

int main(){
    bond b1 = bond("11/19/2035", 0.5, .07);
    std::cout << b1.ToString() << endl;

    bond b2;
    std::cout << b2.ToString() << endl;

    bond b3("Some Expiration Date", 0.5, .08);
    std::cout << " The price of the bond for q2 is " << b3.pricing(4.2, .07) << endl;

    bond b4("Some Expiration Data", 0.5, .05);
    ifstream infile("./Bond_Ex3.csv");

    int countNum = 0;
    double avgPrice = 0;

    if(infile){
		string data;
	    while (getline(infile, data)){
	        if(!isalpha(data[0])){
                int index = data.find_first_of(",");
                avgPrice = avgPrice + b4.pricing(std::stod(data.substr (0,index)), std::stod(data.substr (index+1,data.length())));
                countNum = countNum + 1;
	        }
	    }
    }
    std::cout << " The arithmetic avg of underlying security is :" << avgPrice/countNum << endl;
    return 0;
}
