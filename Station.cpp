#include <bits/stdc++.h>
using namespace std;

#include "Station.h"

//Distance betweeen every pair of stations
const vector<pair<pair<string,string>,int>> Station::distances{
	{{"Mumbai","Delhi"},1447}, {{"Mumbai","Bangalore"},981},
	{{"Mumbai","Kolkata"},2014}, {{"Mumbai","Chennai"},1338},
	{{"Delhi","Bangalore"},2150}, {{"Delhi","Kolkata"},1472},
	{{"Delhi","Chennai"},2180}, {{"Bangalore","Kolkata"},1871},
	{{"Bangalore","Chennai"},350}, {{"Kolkata","Chennai"},1659}
};

//constructor for station
Station::Station(string name) : name_(name) {
	isValidStation();
}

//Destructor for Station
Station::~Station() {}

//Copy Constructor for station
Station& Station::operator=(const Station& s) {
	name_=s.name_.c_str(); //Does a deep copy
	return *this;
}

//Get Name
string Station::GetName() const {return name_;}

//Get Distance with another station as input
int Station::GetDistance(const Station& u) const{
	return GetDistance(u.GetName()); //Use the string overload of the same function
}

//Get distance with a string as input
int Station::GetDistance(const string& a) const{
	vector<pair<pair<string,string>,int>>::const_iterator it; //Iterator for distances
	//loop through all values
	for(it=Station::distances.begin();it!=Station::distances.end();++it) {
		//Stations can be jumbled, thats why we have two cases
		if((it->first).first==a){
			if((it->first).second==name_)
				return it->second; //it->second holds the distance value
		} 
		else if((it->first).second==a) {
			if((it->first).first==name_)
				return it->second; //it->second holds the distance value
		}
	}
	return -1;
}

//Display station through ostream
ostream& operator<<(ostream& os,const Station& a) {
	os << "Station name: " << a.name_;
	return os;
}

bool Station::isValidStation() const {
	if(name_.compare("Delhi")==0) return true;
	if(name_.compare("Mumbai")==0) return true;
	if(name_.compare("Chennai")==0) return true;
	if(name_.compare("Bangalore")==0) return true;
	if(name_.compare("Kolkata")==0) return true;
	Bad_Station z; throw z;
	return false;
}