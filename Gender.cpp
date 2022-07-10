#include <bits/stdc++.h>
using namespace std;

#include "Gender.h"

Gender::Gender(const string& name) : name_(name) {}
Gender::~Gender() {}

const string& Gender::GetName() const {return name_;}

const string Male::sName = "Male";
const string Female::sName = "Female";

Male::Male() : Gender(Male::sName) {}
Male::~Male() {}
const Gender& Male::Type() {
	static const Male theObj;
	return theObj;
}
bool Male::isMale() const {return true;}

Female::Female() : Gender(Female::sName) {}
Female::~Female() {}
const Gender& Female::Type() {
	static const Female theObj;
	return theObj;
}
bool Female::isMale() const {return false;}