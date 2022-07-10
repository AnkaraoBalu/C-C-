#ifndef __BOOKINGCLASS_HXX
#define __BOOKINGCLASS_HXX

#include <bits/stdc++.h>
using namespace std;

#include "Railways.h"

class BookingClass { 
	//LoadFactor of the class
	const double loadFactor;
	//Name of the class
	const string name_;
	//Reservation cost
	const int reservationCharge;

protected:
	// protected constructor so that subclasses can access
	BookingClass(const double& loadFactor,
		const string& name, const int& reservationCharge);

	//Virtual destructor
	virtual ~BookingClass();

	//Copy constructor so that we cannot copy
	virtual BookingClass& operator=(const BookingClass& b);

public:
	//Various member functions
	double GetLoadFactor() const;
	string GetName() const;
	int GetReservationCharge() const;
	virtual bool isSecondSitting() const;
	virtual bool IsSitting() const = 0;
	virtual bool IsAC() const = 0;
	virtual int GetNumberOfTiers() const = 0;
	virtual bool IsLuxury() const = 0;
	virtual pair<pair<int,int>,int> getTatkalDetails() const = 0;
	virtual double getDisabilityDetails(string s) const = 0;

	//Gives a summary of the class
	friend ostream& operator<<(ostream& os,
		const BookingClass& b);
};

//Actual booking class, which is not an abstract class
class ACFirstClass: public BookingClass {
	ACFirstClass(); //private constructor
	~ACFirstClass(); //private destructor
	static const string sName; //static name
	static const double loadFactor; //static loadFactor
	static const int reservationCharge; //static reservation charge for this class

public:
	//Returns the singleton instance
	static const BookingClass& Type();
	//Overriding the remaining member functions
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

class ACTwoTier: public BookingClass {
	ACTwoTier(); //Private constructor
	~ACTwoTier(); //Private Destructor
	static const string sName; //name of the class
	static const double loadFactor; //Load Factor
	static const int reservationCharge;

public:
	//To get the singleton instance
	static const BookingClass& Type();
	//Override the remaining member functions
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

//From here on out, all the Booking classes are 
//similar to the ones mentioned above
class FirstClass: public BookingClass {
	FirstClass();
	~FirstClass();
	static const string sName;
	static const double loadFactor;
	static const int reservationCharge;

public:
	static const BookingClass& Type();
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

class ACThreeTier: public BookingClass {
	ACThreeTier();
	~ACThreeTier();
	static const string sName;
	static const double loadFactor;
	static const int reservationCharge;

public:
	static const BookingClass& Type();
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

class ACChairCar: public BookingClass {
	ACChairCar();
	~ACChairCar();
	static const string sName;
	static const double loadFactor;
	static const int reservationCharge;

public:
	static const BookingClass& Type();
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

class Sleeper: public BookingClass {
	Sleeper();
	~Sleeper();
	static const string sName;
	static const double loadFactor;
	static const int reservationCharge;

public:
	static const BookingClass& Type();
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

class SecondSitting: public BookingClass {
	SecondSitting();
	~SecondSitting();
	static const string sName;
	static const double loadFactor;
	static const int reservationCharge;

public:
	static const BookingClass& Type();
	bool isSecondSitting() const;
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

class ExecutiveChairCar: public BookingClass {
	ExecutiveChairCar();
	~ExecutiveChairCar();
	static const string sName;
	static const double loadFactor;
	static const int reservationCharge;

public:
	static const BookingClass& Type();
	bool IsSitting() const;
	int GetNumberOfTiers() const;
	bool IsAC() const;
	bool IsLuxury() const;
	pair<pair<int,int>,int> getTatkalDetails() const;
	double getDisabilityDetails(string s) const;
};

#endif