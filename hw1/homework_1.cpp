#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

double average(vector<double> v)
{
// code for calculating average of members of v
// and returning the average
    double sum  = 0;
    for(double i : v){
        sum = sum + i ;
    }
    return sum/(v.size());
}

double find_rate(vector<double> rate_vec, vector<string> date_vec, string date)
{
// code for finding the Baa rate for the
// given date (in yyyy-mm format)
// and returning the rate for that month
    int index = 0;
    for (vector<string>::iterator i = date_vec.begin(); i != date_vec.end(); i++ ) {
        if (date.compare(*i) == 0){
            return rate_vec[index];
        }
        index ++;
    }
    return -1.;
}

int main()
{
    vector<double> rate;
    vector<string> date;
    ifstream infile("./hw1_H.15_Baa_Data.csv");

// code for loading rate and date vectors from the file hw1_H.15_Baa_Data.csv
// the headers should be handled properly. do not delete them manually

	if(infile){
		string data;
	    while (getline(infile, data)){
	    	 if(!isalpha(data[0])){
				int index = data.find_first_of(",");
	    		string dateString = data.substr (0,index);
	    		string rateValue = data.substr (index+1,data.length());
	    		rate.push_back(  std::stod (rateValue) );
    			date.push_back( dateString );
			}
		}
	}

   	infile.close();
   	double avgRate = average(rate);
// code for prompting user for a date and returning the rate
// and the difference between the rate for that date and the
// average rate
//
// This code should allow the user to continue to input dates
// until the user inputs the EOF (End-of-file), namely control-d (in linux/mac) or control-z (in windows)
// This should not crash if a bad date is entered.


    std::string userInput;
    std::cout << "Enter the Date (YYYY-MM):" << endl;
    while (std::getline(std::cin, userInput))
    {
        if (userInput.length()!=7 || userInput.at(4)!='-'){
        	std::cout<<"The format of the date entered is invalid, please input YYYY-MM"<<endl;
		}
   		else{
   			if(find_rate(rate, date, userInput) == -1.0)
			   std::cout<<"The date entered is not in range"<<endl;
   			else{
                std::cout << "The rate for your entered date is:" << find_rate(rate, date, userInput) << endl;
                std::cout << "The rate difference for your entered date is:" << find_rate(rate, date, userInput) - avgRate << endl;
   			}

		}

        std::cout << "Enter the Date:" << endl;
    }

    return 0.0; // program end
}

