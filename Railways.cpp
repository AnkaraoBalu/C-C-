#include <bits/stdc++.h>
using namespace std;

#include "Railways.h"

//Private Railways constructor
Railways::Railways() {}
//Destructor
Railways::~Railways() {}

//Returns the only instance of Railways
const Railways& Railways::railways() {
	static Railways newone; //Create the instance
	return newone;
}

//Define all the stations, in the Indian Railways
Station Mumbai("Mumbai");
Station Delhi("Delhi");
Station Bangalore("Bangalore");
Station Kolkata("Kolkata");
Station Chennai("Chennai");

//Define sStations in Railways class
vector <Station> Railways::sStations = {Mumbai,Delhi,
	Bangalore,Kolkata,Chennai};

vector<vector<int>> Railways::sDistStations = {
	{0,1447,981,2014,1338},
	{1447,0,2150,1472,2180},
	{981,2150,0,1871,350},
	{2014,1472,1871,0,1659},
	{1338,2180,350,1659,0}
};


//GetDistance with Station as inputs
int Railways::GetDistance(Station a, Station b) const {
	return a.GetDistance(b); //Use the string overload of the same function
}

//Get Distance with string as input
int Railways::GetDistance(string a, string b) const {
	vector <Station> :: iterator it; //Iterator for sStations.
	for(it=sStations.begin();it!=sStations.end();it++) {
		if(!(it->GetName().compare(a))){
			return it->GetDistance(b);
		}
	}
	return -1; //Returns -1 when input is not valid
}