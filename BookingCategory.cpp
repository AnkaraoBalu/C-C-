#include <bits/stdc++.h>
using namespace std;

#include "BookingCategory.h"

const string GeneralCategory::sName = "General Booking Category";
const string TatkalCategory::sName = "Tatkal Booking Category";
const string PremiumTatkalCategory::sName = "Premium Tatkal Booking Category";
const string LadiesCategory::sName = "Ladies Booking Category";
const string SeniorCategory::sName = "Senior Citizen Booking Category";
const string DivyaangCategory::sName = "Divyaang Booking Category";

BookingCategory::BookingCategory(const string& name) : name_(name) {}
BookingCategory::~BookingCategory() {}

const string& BookingCategory::GetName() const {return name_;}

GeneralCategory::GeneralCategory() : BookingCategory(GeneralCategory::sName) {}
GeneralCategory::~GeneralCategory() {}

bool GeneralCategory::isEligible(const Passenger& p) const {return true;}

const BookingCategory& GeneralCategory::Type() {
	static const GeneralCategory theObj;
	return theObj;
}

Booking* GeneralCategory::createBooking(const Station& a,const Station& b, const Date& dateofReservation,
	const BookingClass& d, const Passenger& p) const {
	try {
		return new GeneralBooking(a,b,dateofReservation,d,p);
	}
	catch(Bad_Booking& ex) {
		cout << ex.what();
		return NULL;
	}
	catch(Bad_Station& ex) {
		cout << ex.what();
		cout << "Please enter valid Station Name." << endl;
		return NULL;
	}
	catch(Bad_Date& ex) {
		cout << ex.what();
		cout << "Please Enter valid date." << endl;
	}
	catch(Bad_Passenger& ex) {
		cout << ex.what();
		cout << "Please Enter valid Passenger details." << endl;
	}
	return NULL;
}

TatkalCategory::TatkalCategory() : BookingCategory(TatkalCategory::sName) {}
TatkalCategory::~TatkalCategory() {}

bool TatkalCategory::isEligible(const Passenger& p) const {return true;}

const BookingCategory& TatkalCategory::Type() {
	static const TatkalCategory theObj;
	return theObj;
}

Booking* TatkalCategory::createBooking(const Station& a,const Station& b, const Date& dateofReservation,
	const BookingClass& d, const Passenger& p) const {
	try{
		return new TatkalBooking(a,b,dateofReservation,d,p);
	}
	catch(Bad_Booking& ex) {
		cout << ex.what();
		return NULL;
	}
	catch(Bad_Station& ex) {
		cout << ex.what();
		cout << "Please enter valid Station Name." << endl;
		return NULL;
	}
	catch(Bad_Date& ex) {
		cout << ex.what();
		cout << "Please Enter valid date." << endl;
	}
	catch(Bad_Passenger& ex) {
		cout << ex.what();
		cout << "Please Enter valid Passenger details." << endl;
	}
	return NULL;
}

PremiumTatkalCategory::PremiumTatkalCategory() : BookingCategory(PremiumTatkalCategory::sName) {}
PremiumTatkalCategory::~PremiumTatkalCategory() {}

bool PremiumTatkalCategory::isEligible(const Passenger& p) const {return true;}

const BookingCategory& PremiumTatkalCategory::Type() {
	static const PremiumTatkalCategory theObj;
	return theObj;
}

Booking* PremiumTatkalCategory::createBooking(const Station& a,const Station& b, const Date& dateofReservation,
	const BookingClass& d, const Passenger& p) const {
	try {
		return new PremiumTatkalBooking(a,b,dateofReservation,d,p);
	}
	catch(Bad_Booking& ex) {
		cout << ex.what();
		return NULL;
	}
	catch(Bad_Station& ex) {
		cout << ex.what();
		cout << "Please enter valid Station Name." << endl;
		return NULL;
	}
	catch(Bad_Date& ex) {
		cout << ex.what();
		cout << "Please Enter valid date." << endl;
	}
	catch(Bad_Passenger& ex) {
		cout << ex.what();
		cout << "Please Enter valid Passenger details." << endl;
	}
	return NULL;
}

ConcessionCategory::ConcessionCategory(const string& name):BookingCategory(name) {}
ConcessionCategory::~ConcessionCategory() {}

LadiesCategory::LadiesCategory() : ConcessionCategory(LadiesCategory::sName) {}
LadiesCategory::~LadiesCategory() {}

bool LadiesCategory::isEligible(const Passenger& p) const {
	if(p.getGender().isMale()) {
		if(p.getAge()<=12) return 0.00;
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}

const BookingCategory& LadiesCategory::Type() {
	static const LadiesCategory theObj;
	return theObj;
}

Booking* LadiesCategory::createBooking(const Station& a,const Station& b, const Date& dateofReservation,
	const BookingClass& d, const Passenger& p) const {
	try {
		return new LadiesBooking(a,b,dateofReservation,d,p);
	}
	catch(Bad_Booking& ex) {
		cout << ex.what();
		return NULL;
	}
	catch(Bad_Station& ex) {
		cout << ex.what();
		cout << "Please enter valid Station Name." << endl;
		return NULL;
	}
	catch(Bad_Date& ex) {
		cout << ex.what();
		cout << "Please Enter valid date." << endl;
	}
	catch(Bad_Passenger& ex) {
		cout << ex.what();
		cout << "Please Enter valid Passenger details." << endl;
	}
	return NULL;
}

SeniorCategory::SeniorCategory() : ConcessionCategory(SeniorCategory::sName) {}
SeniorCategory::~SeniorCategory() {}

bool SeniorCategory::isEligible(const Passenger& p) const {
	if(p.getGender().isMale()) {
		if(p.getAge()>=60) return true;
	}
	else {
		if(p.getAge()>=58) return true;
	}
	Bad_Booking z; throw z;
	return false;
}

const BookingCategory& SeniorCategory::Type() {
	static const SeniorCategory theObj;
	return theObj;
}

Booking* SeniorCategory::createBooking(const Station& a,const Station& b, const Date& dateofReservation,
	const BookingClass& d, const Passenger& p) const {
	try {
		return new SeniorBooking(a,b,dateofReservation,d,p);
	}
	catch(Bad_Booking& ex) {
		cout << ex.what();
		return NULL;
	}
	catch(Bad_Station& ex) {
		cout << ex.what();
		cout << "Please enter valid Station Name." << endl;
		return NULL;
	}
	catch(Bad_Date& ex) {
		cout << ex.what();
		cout << "Please Enter valid date." << endl;
	}
	catch(Bad_Passenger& ex) {
		cout << ex.what();
		cout << "Please Enter valid Passenger details." << endl;
	}
	return NULL;
}

DivyaangCategory::DivyaangCategory() : ConcessionCategory(DivyaangCategory::sName) {}
DivyaangCategory::~DivyaangCategory() {}

bool DivyaangCategory::isEligible(const Passenger& p) const {
	if(p.getDisabilityType().isDisabled()==false) {
		Bad_Booking z; throw z;
		return false;
	}
	return true;
}

const BookingCategory& DivyaangCategory::Type() {
	static const DivyaangCategory theObj;
	return theObj;
}

Booking* DivyaangCategory::createBooking(const Station& a,const Station& b, const Date& dateofReservation,
	const BookingClass& d, const Passenger& p) const {
	try{
		return new DivyaangBooking(a,b,dateofReservation,d,p);
	}
	catch(Bad_Booking& ex) {
		cout << ex.what();
		return NULL;
	}
	catch(Bad_Station& ex) {
		cout << ex.what();
		cout << "Please enter valid Station Name." << endl;
		return NULL;
	}
	catch(Bad_Date& ex) {
		cout << ex.what();
		cout << "Please Enter valid date." << endl;
	}
	catch(Bad_Passenger& ex) {
		cout << ex.what();
		cout << "Please Enter valid Passenger details." << endl;
	}
	catch(...) {
		cout << "Unknown Error has occured. Please try again." << endl;
	}
	return NULL;
}