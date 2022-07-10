#ifndef __PASSENGER_HXX
#define __PASSENGER_HXX

#include <bits/stdc++.h>
using namespace std;

#include "Date.h"
#include "Gender.h"
#include "Divyaang.h"

class Passenger {
	//All the data members
	string name_;
	Date dob;
	const Gender& gender;
	string aadhaar;
	string mobileno;
	const Divyaang& disabilityType;
	string divyaangID;
	int age;

	void computeAge(); //internal function to compute date
	bool isValidPassenger() const; //internal function to check if the data is valid.

public:
	Passenger(const string& name, const Date& dob, const Gender& gg,
		const string& aadhaar, const string& mobileno, const Divyaang& d, const string& divyaangID);
	~Passenger();

	const Divyaang& getDisabilityType() const; 
	Date getDateofBirth() const;
	int getAge() const;
	const Gender& getGender() const;

	//cout function to display the passenger
	friend ostream& operator<<(ostream& os,const Passenger& p);
};

#endif