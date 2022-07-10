#ifndef __STATION_HXX
#define __STATION_HXX

#include <bits/stdc++.h>
using namespace std;

#include "Exceptions.h"

class Station{ 

	string name_; //Name of the station
	//To store all the relevant distances
	static const vector<pair<pair<string,string>,int>> distances;

	bool isValidStation() const;

public:
	//Constructor using name
	Station(string name);
	~Station();

	//Copy Constructor
	Station& operator=(const Station& s);

	//getting the name of station
	string GetName() const;

	//Getting the distance from a station
	int GetDistance(const Station& u) const;

	//Getting the distance from string
	int GetDistance(const string& a) const;

	//ostream friend function
	friend ostream& operator<<(ostream& os,const Station& a);
};

#endif