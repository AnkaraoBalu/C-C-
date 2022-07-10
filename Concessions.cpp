#include <bits/stdc++.h>
using namespace std;

#include "Concessions.h"

Concessions::Concessions() {}
Concessions::~Concessions() {}

GeneralConcessions::GeneralConcessions(const Passenger& p) : Concessions(),p(p) {}
GeneralConcessions::~GeneralConcessions() {}
double GeneralConcessions::getConcessionFactor() const {return 0.00;}

SCConcession::SCConcession(const Passenger& p) : Concessions(), p(p) {}
SCConcession::~SCConcession() {}
double SCConcession::getConcessionFactor() const {
	if(p.getGender().isMale()) {
		if(p.getAge()>=60) return 0.40;
		return 0.00;
	}
	else {
		if(p.getAge()>=58) return 0.50;
		return 0.00;
	}
}

LadiesConcession::LadiesConcession(const Passenger& p) : Concessions(), p(p) {}
LadiesConcession::~LadiesConcession() {}
double LadiesConcession::getConcessionFactor() const {
	if(p.getGender().isMale()) {
		if(p.getAge()<=12) return 0.00;
		return 0.00;
	}
	else {
		return 0.00;
	}
}

DivyaangConcession::DivyaangConcession(const Passenger& p, 
	const BookingClass& b):Concessions(), p(p), b(b) {}
DivyaangConcession::~DivyaangConcession() {}
double DivyaangConcession::getConcessionFactor() const {
	return b.getDisabilityDetails(p.getDisabilityType().GetName());
}