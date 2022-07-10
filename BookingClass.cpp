#include <bits/stdc++.h>
using namespace std;

#include "BookingClass.h"

//declaring all the names as static constants
const string ACFirstClass::sName = "AC First Class";
const string ACTwoTier::sName = "AC Two Tier";
const string FirstClass::sName = "First Class";
const string ACThreeTier::sName = "AC Three Tier";
const string ACChairCar::sName = "AC Chair Car";
const string Sleeper::sName = "Sleeper";
const string SecondSitting::sName = "Second Sitting";
const string ExecutiveChairCar::sName = "Executive Chair Car";

//Defining loadFactors for various classes
const double ACFirstClass::loadFactor = 6.50;
const double ACTwoTier::loadFactor = 4.00;
const double FirstClass::loadFactor = 3.00;
const double ACThreeTier::loadFactor = 2.50;
const double ACChairCar::loadFactor = 2.00;
const double Sleeper::loadFactor = 1.00;
const double SecondSitting::loadFactor = 0.60;
const double ExecutiveChairCar::loadFactor = 5.00;

//reservationCharge for various classes
const int ACFirstClass::reservationCharge = 60;
const int ExecutiveChairCar::reservationCharge = 60;
const int ACTwoTier::reservationCharge = 50;
const int FirstClass::reservationCharge = 50;
const int ACThreeTier::reservationCharge = 40;
const int ACChairCar::reservationCharge = 40;
const int Sleeper::reservationCharge = 20;
const int SecondSitting::reservationCharge = 15;

//Constructor for the base Booking Class
BookingClass::BookingClass(const double& loadFactor, const string& name,
	const int& reservationCharge) : loadFactor(loadFactor), name_(name), reservationCharge(reservationCharge) {}

//Virtual Destructor for Booking Class(Virtual is mentioned in .h of the same)
BookingClass::~BookingClass() {}

//Copy Constructor. All classes are singleton, so its declared a private member function
BookingClass& BookingClass::operator=(const BookingClass& b) {}

//Const method for getting loadfactor
double BookingClass::GetLoadFactor() const {return loadFactor;}

//Const Method for getting name
string BookingClass::GetName() const {return name_;}

//const Method for getting reservation factor
int BookingClass::GetReservationCharge() const {return reservationCharge;}

bool BookingClass::isSecondSitting() const {return false;}

//Gives a brief description of the class
ostream& operator<<(ostream& os,const BookingClass& b) {
	os << "Summary of the Booking Class." << endl;
	os << "Name: " << b.GetName() << endl;
	os << "Load Factor: " << b.GetLoadFactor() << endl;
	if(b.IsSitting()) os << "Seated class" << endl;
	else os << "Berth/Sleeping Class" << endl;
	if(b.IsAC()) os << "AC Class" << endl;
	else os << "Non AC Class" << endl;
	os << "Numer of Tiers: " << b.GetNumberOfTiers() << endl;
	if(b.IsLuxury()) os << "Luxury suite" << endl;
	else os << "Non Luxury Class" << endl;
	os << "Tatkal Details: " << endl;
	os << "  Minimum Fare: " << b.getTatkalDetails().first.first << endl;
	os << "  Maximum Fare: " << b.getTatkalDetails().first.second << endl;
	os << "  Minimum Distance for Charge: " << b.getTatkalDetails().second << endl;
	os << "Reservation Charge: " << b.GetReservationCharge() << endl;
	return os;
}

//Constructor
ACFirstClass::ACFirstClass():BookingClass(ACFirstClass::loadFactor,
	ACFirstClass::sName, ACFirstClass::reservationCharge) {}

//Destructor
ACFirstClass::~ACFirstClass() {}

//Returns the singleton instance of the class
const BookingClass& ACFirstClass::Type() {
	static const ACFirstClass theObj;
	return theObj;
}
//Define the remaining member functions 
bool ACFirstClass::IsAC() const {return true;} //It is an AC suite
bool ACFirstClass::IsLuxury() const {return true;} //It is a luxury class
bool ACFirstClass::IsSitting() const {return false;}
int ACFirstClass::GetNumberOfTiers() const {return 2;}
pair<pair<int,int>,int> ACFirstClass::getTatkalDetails() const {return make_pair(make_pair(400,500),500);}
double ACFirstClass::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.50;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.50;
	else if(s.compare("Cancer Patient")==0) return 0.50;
	else if(s.compare("Tuberculosis Patient")==0) return 0.00;
	else return 0;
}

//AC Two Tier class. Constructor
ACTwoTier::ACTwoTier():BookingClass(ACTwoTier::loadFactor,
	ACTwoTier::sName, ACTwoTier::reservationCharge) {}

//Destructor
ACTwoTier::~ACTwoTier() {}

//Return the singleton instance
const BookingClass& ACTwoTier::Type() {
	static const ACTwoTier theObj;
	return theObj;
}
//Define the remaining functions
bool ACTwoTier::IsAC() const {return true;} //AC Class
bool ACTwoTier::IsLuxury() const {return false;} //Non Luxury class
bool ACTwoTier::IsSitting() const {return false;}
int ACTwoTier::GetNumberOfTiers() const {return 2;}
pair<pair<int,int>,int> ACTwoTier::getTatkalDetails() const {return make_pair(make_pair(400,500),500);}
double ACTwoTier::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.50;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.50;
	else if(s.compare("Cancer Patient")==0) return 0.50;
	else if(s.compare("Tuberculosis Patient")==0) return 0.00;
	else return 0;
}

//First Class. Constructor
FirstClass::FirstClass():BookingClass(FirstClass::loadFactor,
	FirstClass::sName, FirstClass::reservationCharge) {}

//Destructor
FirstClass::~FirstClass() {}

//Return the singleton instance
const BookingClass& FirstClass::Type() {
	static const FirstClass theObj;
	return theObj;
}
bool FirstClass::IsAC() const {return false;} //Non-AC Suite
bool FirstClass::IsLuxury() const {return true;} //Luxury class
bool FirstClass::IsSitting() const {return false;}
int FirstClass::GetNumberOfTiers() const {return 2;}
pair<pair<int,int>,int> FirstClass::getTatkalDetails() const {return make_pair(make_pair(400,500),500);}
double FirstClass::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.75;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.75;
	else if(s.compare("Cancer Patient")==0) return 0.75;
	else if(s.compare("Tuberculosis Patient")==0) return 0.75;
	else return 0;
}

//All classes from here on are defined the same way.

//AC Three tier. 
ACThreeTier::ACThreeTier():BookingClass(ACThreeTier::loadFactor,
	ACThreeTier::sName,ACThreeTier::reservationCharge) {}
ACThreeTier::~ACThreeTier() {}
const BookingClass& ACThreeTier::Type() {
	static const ACThreeTier theObj;
	return theObj;
}
bool ACThreeTier::IsAC() const {return true;} //AC Class
bool ACThreeTier::IsLuxury() const {return false;} //Non Luxury class
bool ACThreeTier::IsSitting() const {return false;}
int ACThreeTier::GetNumberOfTiers() const {return 3;}
pair<pair<int,int>,int> ACThreeTier::getTatkalDetails() const {return make_pair(make_pair(300,400),500);}
double ACThreeTier::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.75;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.75;
	else if(s.compare("Cancer Patient")==0) return 1.00;
	else if(s.compare("Tuberculosis Patient")==0) return 0.00;
	else return 0;
}


ACChairCar::ACChairCar():BookingClass(ACChairCar::loadFactor,
	ACChairCar::sName, ACChairCar::reservationCharge) {}
ACChairCar::~ACChairCar() {}
const BookingClass& ACChairCar::Type() {
	static const ACChairCar theObj;
	return theObj;
}
bool ACChairCar::IsAC() const {return true;} //AC Class
bool ACChairCar::IsLuxury() const {return false;} //Non Luxury class
bool ACChairCar::IsSitting() const {return true;}
int ACChairCar::GetNumberOfTiers() const {return 0;}
pair<pair<int,int>,int> ACChairCar::getTatkalDetails() const {return make_pair(make_pair(125,225),250);}
double ACChairCar::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.75;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.75;
	else if(s.compare("Cancer Patient")==0) return 1.00;
	else if(s.compare("Tuberculosis Patient")==0) return 0.00;
	else return 0;
}


Sleeper::Sleeper():BookingClass(Sleeper::loadFactor,
	Sleeper::sName, Sleeper::reservationCharge) {}
Sleeper::~Sleeper() {}
const BookingClass& Sleeper::Type() {
	static const Sleeper theObj;
	return theObj;
}
bool Sleeper::IsAC() const {return false;} //Non AC Class
bool Sleeper::IsLuxury() const {return false;} //Non Luxury class
bool Sleeper::IsSitting() const {return false;}
int Sleeper::GetNumberOfTiers() const {return 3;}
pair<pair<int,int>,int> Sleeper::getTatkalDetails() const {return make_pair(make_pair(100,200),500);}
double Sleeper::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.75;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.75;
	else if(s.compare("Cancer Patient")==0) return 1.00;
	else if(s.compare("Tuberculosis Patient")==0) return 0.75;
	else return 0;
}


SecondSitting::SecondSitting():BookingClass(SecondSitting::loadFactor,
	SecondSitting::sName,SecondSitting::reservationCharge) {}
SecondSitting::~SecondSitting() {}
const BookingClass& SecondSitting::Type() {
	static const SecondSitting theObj;
	return theObj;
}
bool SecondSitting::isSecondSitting() const {return true;}
bool SecondSitting::IsAC() const {return false;} //Non AC Class
bool SecondSitting::IsLuxury() const {return false;} //Non Luxury Class
bool SecondSitting::IsSitting() const {return true;}
int SecondSitting::GetNumberOfTiers() const {return 0;}
pair<pair<int,int>,int> SecondSitting::getTatkalDetails() const {return make_pair(make_pair(10,15),100);}
double SecondSitting::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.75;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.75;
	else if(s.compare("Cancer Patient")==0) return 1.00;
	else if(s.compare("Tuberculosis Patient")==0) return 0.75;
	else return 0;
}

ExecutiveChairCar::ExecutiveChairCar() : BookingClass(ExecutiveChairCar::loadFactor,
	ExecutiveChairCar::sName, ExecutiveChairCar::reservationCharge) {}
ExecutiveChairCar::~ExecutiveChairCar() {}
const BookingClass& ExecutiveChairCar::Type() {
	static const ExecutiveChairCar theObj;
	return theObj;
}
bool ExecutiveChairCar::IsAC() const {return true;}
bool ExecutiveChairCar::IsLuxury() const {return true;}
bool ExecutiveChairCar::IsSitting() const {return true;}
int ExecutiveChairCar::GetNumberOfTiers() const {return 0;};
pair<pair<int,int>,int> ExecutiveChairCar::getTatkalDetails() const {return make_pair(make_pair(400,500),250);}
double ExecutiveChairCar::getDisabilityDetails(string s) const {
	if (s.compare("Blind")==0) return 0.75;
	else if(s.compare("Orthopaedically Handicapped")==0) return 0.75;
	else if(s.compare("Cancer Patient")==0) return 0.75;
	else if(s.compare("Tuberculosis Patient")==0) return 0.00;
	else return 0;
}