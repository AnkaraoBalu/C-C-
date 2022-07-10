#include <bits/stdc++.h>
using namespace std;

#include "Exceptions.h"

const char* Bad_Date::what() const throw() {
	return "Invalid Date.\n";
}

const char* Bad_Railways::what() const throw() {
	return "Invalid Master Data in Railways.\n";
}

const char* Bad_Booking::what() const throw() {
	return "Invalid Booking. Please try again.\n";
}

const char* Bad_Passenger::what() const throw() {
	return "Invalid Passenger details.\n";
}

const char* Bad_Station::what() const throw() {
	return "Invalid Station.\n";
}

const char* Bad_BookingCategory::what() const throw() {
	return "Invalid Station.\n";
}