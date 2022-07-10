#ifndef __DATE_H
#define __DATE_H

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

#include "Exceptions.h"

class Date{ 

	int date_,year_,month_; string day_;
	static const vector <string> monthNames;
	static const vector <string> dayNames; 

	//to set day
	void set_day();

public:
	//Constructor. Following DD/MM/YYYY format.
	Date(int d,int m,int y);
	~Date(); 

	//Check if the given date is valid. 
	//Useful for assignment 4
	bool isvalid();

	//Copy Constructor
	Date& operator=(const Date& d);
	static Date Today();

	string getDay() const;

	//ostream friend function
	friend ostream& operator<<(ostream& os,const Date& a);
	//friend difference function
	friend vector <int>  operator-(const Date& a, const Date& b);
	// friend comparator function
	friend bool operator<(const Date& a,const Date& b);
};

#endif