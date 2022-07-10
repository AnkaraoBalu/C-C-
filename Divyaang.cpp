#include <bits/stdc++.h>
using namespace std;

#include "Divyaang.h"

Divyaang::Divyaang(const string& name) : name_(name) {}
Divyaang::~Divyaang() {}

bool Divyaang::isDisabled() const {return true;}
const string& Divyaang::GetName() const {return name_;}

const string Blind::sName = "Blind";
const string OH::sName = "Orthopaedically Handicapped";
const string CancerPatient::sName = "Cancer Patient";
const string TBPatient::sName = "Tuberculosis Patient";
const string NoDisability::sName = "No Disability";

Blind::Blind() : Divyaang(Blind::sName) {}
Blind::~Blind() {}
const Divyaang& Blind::Type() {
	static const Blind theObj;
	return theObj;
}

OH::OH() : Divyaang(OH::sName) {}
OH::~OH() {}
const Divyaang& OH::Type() {
	static const OH theObj;
	return theObj;
}

CancerPatient::CancerPatient() : Divyaang(CancerPatient::sName) {}
CancerPatient::~CancerPatient() {}
const Divyaang& CancerPatient::Type() {
	static const CancerPatient theObj;
	return theObj;
}

TBPatient::TBPatient() : Divyaang(TBPatient::sName) {}
TBPatient::~TBPatient() {}
const Divyaang& TBPatient::Type() {
	static const TBPatient theObj;
	return theObj;
}

NoDisability::NoDisability() : Divyaang(NoDisability::sName) {}
NoDisability::~NoDisability() {}
const Divyaang& NoDisability::Type() {
	static const NoDisability theObj;
	return theObj;
}

bool NoDisability::isDisabled() const {return false;}