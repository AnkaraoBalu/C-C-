#ifndef __RAILWAYS_HXX
#define __RAILWAYS_HXX

#include <bits/stdc++.h>
using namespace std;

#include "Station.h"
#include "Station.cpp"

//We will be implementing meyer's singleton
class Railways {

	//private constructor
	Railways();
	~Railways();

public:

	//Returns the singleton instance of Railways
	static const Railways& railways(); 
	static vector<vector<int>> sDistStations; //List of distance between stations
	static vector<Station> sStations; //List of stations

	//Updating the distances in stations
	// void UpdateDistances();

	//Getting distance between two stations
	int GetDistance(Station a,Station b) const; //Station input
	int GetDistance(string a,string b) const; //String input
};

#endif