#include <bits/stdc++.h>
#include <ctime>
using namespace std;

#include "Passenger.h"

Passenger::Passenger(const string& name, const Date& dob, const Gender& gg, const string& aadhaar, 
	const string& mobileno, const Divyaang& d, const string& divyaangID): name_(name), dob(dob), gender(gg),
	aadhaar(aadhaar), mobileno(mobileno), disabilityType(d), divyaangID(divyaangID) {
		computeAge();
		isValidPassenger();		
	}

Passenger::~Passenger() {}

const Divyaang& Passenger::getDisabilityType() const {
	return disabilityType;
}

Date Passenger::getDateofBirth() const {
	return dob; 
}

int Passenger::getAge() const {
	return age;
}

const Gender& Passenger::getGender() const {
	return gender;
}

void Passenger::computeAge() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	Date nn(ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year);
	if(nn<dob) {
		Bad_Passenger z; throw z;
		return;
	}
	vector <int> v = nn-dob;
	if(v[1]>=6) age = v[2]+1;
	else age = v[2];
}

bool Passenger::isValidPassenger() const {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	Date nn(ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year);

	if(name_=="") {
		Bad_Passenger z; throw z;
		return false;
	}

	if(nn<dob) {
		Bad_Passenger z; throw z;
		return false;
	}	
	if(aadhaar.length()!=12) {
		Bad_Passenger z; throw z;
		return false;
	}
	for(int i=0;i<12;i++) {
		if(!(('0'<=aadhaar[i])&&(aadhaar[i]<='9'))) {
			Bad_Passenger z; throw z;
			return false;
		}
	}

	if((mobileno.length()!=10)&&(mobileno.length()!=0)) {
		Bad_Passenger z; throw z;
		return false;
	}
	if(mobileno.length()!=0) {
		for(int i=0;i<10;i++) {
			if(!(('0'<=mobileno[i])&&(mobileno[i]<='9'))) {
				Bad_Passenger z; throw z;
				return false;
			}
		}
	}
	if(disabilityType.isDisabled()==true) {
		if(divyaangID.compare("")==0) {
			Bad_Passenger z; throw z;
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const Passenger& p) {
	os << "Passenger Details: " << endl;
	os << "Name: " << p.name_ << endl;
	os << "Date of Birth: " << p.dob << "Age: " << p.age << endl;
	os << "Gender: " << p.gender.GetName() << endl;
	os << "Aadhaar Number: " << p.aadhaar << endl;
	if(p.mobileno.compare("")==0) os << "Mobile Number was not provided." << endl;
	else os << "Mobile Number: " << p.mobileno << endl;
	if(p.disabilityType.isDisabled()==false) os << "No Disability." << endl;
	else {
		os << "Disability Type: " << p.disabilityType.GetName() << endl;
		os << "Disability ID: " << p.divyaangID << endl;
	}
	return os;
}