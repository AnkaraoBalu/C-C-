#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <bits/stdc++.h>
#include <exception>
using namespace std;

class Bad_Date: public exception {
public:
	const char* what() const throw();
};

class Bad_Railways: public exception {
public:
	const char* what() const throw();
};

class Bad_Booking: public exception {
public:
	const char* what() const throw();
};

class Bad_Passenger: public exception {
public:
	const char* what() const throw();
};

class Bad_Station: public exception {
public:
	const char* what() const throw();
};

class Bad_BookingCategory: public exception {
public:
	const char* what() const throw();
};

#endif