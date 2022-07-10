#ifndef __BOOKING_HXX
#define __BOOKING_HXX

#include <bits/stdc++.h>
using namespace std;

#include "Date.h"
#include "Passenger.h"
#include "Exceptions.h"
#include "Concessions.h"
#include "BookingClass.h"
#include "Divyaang.h"
#include "Station.h"
#include "Railways.h"
#include "Gender.h"

//Booking
class Booking {
	// Date getTodaysDate() const;

protected:

	//Static variables
	static int nextPNR_; //Maintains the next available PNR
	static double sBaseFarePerKM; //Base fare per km
	const string category;

	//check for validity of booking
	virtual bool isValidBooking() const = 0;

	//Protected for future extensions
	const Station fromStation, toStation; //Stations
	const Date dateofBooking_;  //Date
	const Date dateofReservation;
	const BookingClass& bC;  //Booking Class
	const int PNR_; //PNR of the booking
	const bool bookingStatus = true; //Booking Status
	const string bookingMessage = "BOOKING SUCCEEDED"; //Message
	int fare; //total fare
	const Passenger p;

	Booking(const Station& a, const Station& b,
		const Date& dateofReservation, const BookingClass& d,
		const Passenger& p,const string& category);
	virtual ~Booking();


public:

	virtual int ComputeFare() const = 0; //To compute fare

	//To Get the Fare
	int GetFare() const;

	//Summary of the Booking
	friend ostream& operator<<(ostream& os,const Booking& b);

	//List of all bookings
	static vector<Booking*> sBookings;
	Date getTodaysDate() const;
};

class GeneralBooking: public Booking {
	bool isValidBooking() const;

public:
	GeneralBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p);
	~GeneralBooking();

	int ComputeFare() const;
};

class TatkalBooking: public Booking {
	bool isValidBooking() const;

public :
	TatkalBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p);
	~TatkalBooking();

	int ComputeFare() const;
};

class PremiumTatkalBooking: public Booking {
	bool isValidBooking() const;

public :
	PremiumTatkalBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p);
	~PremiumTatkalBooking();

	int ComputeFare() const;
};

class ConcessionalBooking : public Booking {
public:
	ConcessionalBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p,const string& name);
	virtual ~ConcessionalBooking();
};

class LadiesBooking: public ConcessionalBooking {
	bool isValidBooking() const;

public :
	LadiesBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p);
	~LadiesBooking();

	int ComputeFare() const;
};

class SeniorBooking: public ConcessionalBooking {
	bool isValidBooking() const;

public :
	SeniorBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p);
	~SeniorBooking();

	int ComputeFare() const;
};

class DivyaangBooking: public ConcessionalBooking {
	bool isValidBooking() const;

public :
	DivyaangBooking(const Station& a, const Station& b,
		const Date& dareofReservation, const BookingClass& d,
		const Passenger& p);
	~DivyaangBooking();

	int ComputeFare() const;
};

#endif