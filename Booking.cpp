#include <bits/stdc++.h>
using namespace std;

#include "Booking.h"

//Static members of Booking Class
int Booking::nextPNR_ = 1; //Initialize to 1. Keeps track of next available PNR
double Booking::sBaseFarePerKM = 0.50; //Base Charge per KM

//Public static member
vector <Booking*> Booking::sBookings{}; //Keeps track of all bookings done in this scope.

//Booking Constructor
Booking::Booking(const Station& a, const Station& b,const Date& c, 
	const BookingClass& d,const Passenger& p,const string& name): //All the parameters. Passenger is defaulted to null
	fromStation(a),toStation(b), dateofReservation(c), bC(d),
	p(p), PNR_(Booking::nextPNR_), dateofBooking_(Date::Today()), category(name) {
		// fare = this->ComputeFare();
	}

//Destructor for Booking Class
Booking::~Booking() {}

Date Booking::getTodaysDate() const {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	Date nn(ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year);
	return nn;
}

// //Function to compute fare
// int Booking::ComputeFare() const {
// 	double tf=0; 
// 	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
// 	tf*=(bC.GetLoadFactor()); //Multiply by the load factor
// 	if(bC.IsAC()) tf+=(Booking::sACSurcharge); //Add the ac surcharge if any
// 	if(bC.IsLuxury()) tf*=((Booking::sLuxuryTaxPercent)/100+1); //Luxury tax for luxury suites
// 	int fF = (int)round(tf); //Round to the closest integer
// 	return fF; //Return the integer
// }

//to get fare
int Booking::GetFare() const {
	return fare; //Return fare
}

//Gives a complete summary of a given booking
ostream& operator<<(ostream& os,const Booking& b) {
	os << b.bookingMessage << endl;
	os << "PNR Number = " << b.PNR_ << endl;
	os << "From Station = " << b.fromStation.GetName() << endl;
	os << "To Station = " << b.toStation.GetName() << endl;
	os << "Booking Date = " << b.dateofBooking_;
	os << "Reservation Date = " << b.dateofReservation;
	os << "Travel Class = " << b.bC.GetName() << endl;
	os << "Travel Category = " << b.category << endl;
	os << " : Mode: ";
	if(b.bC.IsSitting()) os << "Sitting" << endl;
	else os << "Sleeping" << endl;
	os << " : Comfort: ";
	if(b.bC.IsAC()) os << "AC" << endl;
	else cout << "Non-AC" << endl;
	os << " : Bunks: " << b.bC.GetNumberOfTiers() << endl;
	os << " : Luxury: ";
	if(b.bC.IsLuxury()) os << "Yes" << endl;
	else os << "No" << endl;
	os << "Fare = " << b.fare << endl;
	// os << "Info of Passenger: " << endl;
	os << b.p << endl;
	return os;
}

GeneralBooking::GeneralBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p) : Booking(a,b,dareofReservation,d,p,"General") {

	isValidBooking(); fare = ComputeFare();
	Booking::sBookings.push_back(this); //Push the present booking into sBookings
	Booking::nextPNR_++; //Increase the next available PNR by 1.
}
GeneralBooking::~GeneralBooking() {}

int GeneralBooking::ComputeFare() const {
	double tf=0; 
	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
	tf*=(bC.GetLoadFactor()); //Multiply by the load factor
	//General Booking Category, no concession
	tf+=(bC.GetReservationCharge()); //Add reservation charge
	int fF = (int)round(tf); //Round to the closest integer
	return fF; //Return the integer
}

bool GeneralBooking::isValidBooking() const {
	if((dateofReservation<Date::Today()) || ((dateofReservation-Date::Today())[2]>=1)) {
		Bad_Booking z; throw z;
		return false;
	}
	if(dateofReservation<p.getDateofBirth()) {
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}


TatkalBooking::TatkalBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p) : Booking(a,b,dareofReservation,d,p,"Tatkal") {

	isValidBooking(); fare = ComputeFare();
	Booking::sBookings.push_back(this); //Push the present booking into sBookings
	Booking::nextPNR_++; //Increase the next available PNR by 1.
}
TatkalBooking::~TatkalBooking() {}

int TatkalBooking::ComputeFare() const {
	double tf = 0; int dist = (Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation);
	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
	tf*=(bC.GetLoadFactor());
	if(dist>=(bC.getTatkalDetails().second)) {
		double tatkalfare;
		if(bC.isSecondSitting()) tatkalfare = 0.1*tf;
		else tatkalfare = 0.3*tf;
		if(tatkalfare<(bC.getTatkalDetails().first.first)) tatkalfare = bC.getTatkalDetails().first.first;
		else if(tatkalfare>(bC.getTatkalDetails().first.second)) tatkalfare = bC.getTatkalDetails().first.second;
		// cout << tatkalfare << endl;
		tf+=(tatkalfare);
	} 
	tf+=(bC.GetReservationCharge());
	int fF = (int)round(tf); //Round to the closest integer
	return fF;
}

bool TatkalBooking::isValidBooking() const {
	if((dateofReservation<Date::Today()) || ((dateofReservation-Date::Today())[2]>=1)) {
		Bad_Booking z; throw z;
		return false;
	}
	if(dateofReservation<p.getDateofBirth()) {
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}


PremiumTatkalBooking::PremiumTatkalBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p) : Booking(a,b,dareofReservation,d,p,"Premium Tatkal") {

	isValidBooking(); fare = ComputeFare();
	Booking::sBookings.push_back(this); //Push the present booking into sBookings
	Booking::nextPNR_++; //Increase the next available PNR by 1.
}
PremiumTatkalBooking::~PremiumTatkalBooking() {}

int PremiumTatkalBooking::ComputeFare() const {
	double tf = 0; int dist = (Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation);
	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
	tf*=(bC.GetLoadFactor());
	if(dist>=(bC.getTatkalDetails().second)) {
		double tatkalfare;
		if(bC.isSecondSitting()) tatkalfare = 0.1*tf;
		else tatkalfare = 0.3*tf;
		if(tatkalfare<(bC.getTatkalDetails().first.first)) tatkalfare = bC.getTatkalDetails().first.first;
		else if(tatkalfare>(bC.getTatkalDetails().first.second)) tatkalfare = bC.getTatkalDetails().first.second;
		tf+=(2*tatkalfare); //double because of premium tatkal
	} 
	tf+=(bC.GetReservationCharge());
	int fF = (int)round(tf); //Round to the closest integer
	return fF;
}

bool PremiumTatkalBooking::isValidBooking() const {
	if((dateofReservation<Date::Today()) || ((dateofReservation-Date::Today())[2]>=1)) {
		Bad_Booking z; throw z;
		return false;
	}
	if(dateofReservation<p.getDateofBirth()) {
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}


ConcessionalBooking::ConcessionalBooking(const Station&a, const Station& b,
	const Date& dareofReservation, const BookingClass& d, 
	const Passenger& p,const string& name) : Booking(a,b,dareofReservation,d,p,name) {}
ConcessionalBooking::~ConcessionalBooking() {}

LadiesBooking::LadiesBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p) : ConcessionalBooking(a,b,dareofReservation,d,p,"Ladies") {

	isValidBooking(); fare = ComputeFare();
	Booking::sBookings.push_back(this); //Push the present booking into sBookings
	Booking::nextPNR_++; //Increase the next available PNR by 1.
}
LadiesBooking::~LadiesBooking() {}

int LadiesBooking::ComputeFare() const {
	double tf=0; 
	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
	tf*=(bC.GetLoadFactor()); //Multiply by the load factor
	//Check for concessions
	const LadiesConcession lc(p);
	tf = tf*(1.00-lc.getConcessionFactor());
	tf+=(bC.GetReservationCharge()); //Add reservation charge
	int fF = (int)round(tf); //Round to the closest integer
	return fF; //Return the integer
}

bool LadiesBooking::isValidBooking() const {
	if((dateofReservation<Date::Today()) || ((dateofReservation-Date::Today())[2]>=1)) {
		Bad_Booking z; throw z;
		return false;
	}
	if(p.getGender().isMale()) {
		if(p.getAge()<=12) return true;
		Bad_Booking z; throw z;
		return false;
	}
	if(dateofReservation<p.getDateofBirth()) {
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}


SeniorBooking::SeniorBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p) : ConcessionalBooking(a,b,dareofReservation,d,p,"Senior") {

	isValidBooking(); fare = ComputeFare();
	Booking::sBookings.push_back(this); //Push the present booking into sBookings
	Booking::nextPNR_++; //Increase the next available PNR by 1.
}
SeniorBooking::~SeniorBooking() {}

int SeniorBooking::ComputeFare() const {
	double tf=0; 
	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
	tf*=(bC.GetLoadFactor()); //Multiply by the load factor
	//Check for concessions
	const SCConcession sc(p);
	tf = tf*(1.00-sc.getConcessionFactor());
	tf+=(bC.GetReservationCharge()); //Add reservation charge
	int fF = (int)round(tf); //Round to the closest integer
	return fF; //Return the integer
}

bool SeniorBooking::isValidBooking() const {
	if((dateofReservation<Date::Today()) || ((dateofReservation-Date::Today())[2]>=1)) {
		Bad_Booking z; throw z;
		return false;
	}
	if(dateofReservation<p.getDateofBirth()) {
		Bad_Booking z; throw z;
		return false;
	}
	if(p.getGender().isMale()) {
		if(p.getAge()>=60) return true;
	}
	else {
		if(p.getAge()>=58) return true;
	}
	Bad_Booking z; throw z;
	return false;
}


DivyaangBooking::DivyaangBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p) : ConcessionalBooking(a,b,dareofReservation,d,p,"Divyaang") {

	isValidBooking(); fare = ComputeFare();
	Booking::sBookings.push_back(this); //Push the present booking into sBookings
	Booking::nextPNR_++; //Increase the next available PNR by 1.
}
DivyaangBooking::~DivyaangBooking() {}

int DivyaangBooking::ComputeFare() const {
	double tf=0; 
	tf+=((Booking::sBaseFarePerKM)*fromStation.GetDistance(toStation)); //Add the basic distance
	tf*=(bC.GetLoadFactor()); //Multiply by the load factor
	//Check for concessions
	const DivyaangConcession dc(p,bC);
	tf = tf*(1.00-dc.getConcessionFactor());
	tf+=(bC.GetReservationCharge()); //Add reservation charge
	int fF = (int)round(tf); //Round to the closest integer
	return fF; //Return the integer
}

bool DivyaangBooking::isValidBooking() const {
	if((dateofReservation<Date::Today()) || ((dateofReservation-Date::Today())[2]>=1)) {
		Bad_Booking z; throw z;
		return false;
	}
	if(dateofReservation<p.getDateofBirth()) {
		Bad_Booking z; throw z;
		return false;
	}
	if(p.getDisabilityType().isDisabled()==false) {
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}