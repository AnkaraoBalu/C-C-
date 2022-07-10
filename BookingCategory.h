#ifndef __BOOKINGCATEGORY_H
#define __BOOKINGCATEGORY_H

#include <bits/stdc++.h>
using namespace std;

#include "Passenger.h"
#include "Booking.h"

class BookingCategory {
	const string name_;

protected:
	BookingCategory(const string& name);
	virtual ~BookingCategory();
	virtual bool isEligible(const Passenger& p) const = 0;

public:
	const string& GetName() const;
	virtual Booking* createBooking(const Station& a, const Station& b, 
		const Date& dateofReservation, const BookingClass& d, 
		const Passenger& p) const = 0;
};

class GeneralCategory : public BookingCategory {
	GeneralCategory();
	~GeneralCategory();
	static const string sName;
	bool isEligible(const Passenger& p) const;

public:
	static const BookingCategory& Type();
	Booking* createBooking(const Station& a, const Station& b, const Date& dateofReservation, const BookingClass& d, const Passenger& p) const;
};

class TatkalCategory : public BookingCategory {
	TatkalCategory();
	~TatkalCategory();
	static const string sName;
	bool isEligible(const Passenger& p) const;

public:
	static const BookingCategory& Type();
	Booking* createBooking(const Station& a, const Station& b, 
		const Date& dateofReservation, const BookingClass& d, const Passenger& p) const;
};

class PremiumTatkalCategory : public BookingCategory {
	PremiumTatkalCategory();
	~PremiumTatkalCategory();
	static const string sName;
	bool isEligible(const Passenger& p) const;

public:
	static const BookingCategory& Type();
	Booking* createBooking(const Station& a, const Station& b, 
		const Date& dateofReservation, const BookingClass& d, const Passenger& p) const;
};

class ConcessionCategory : public BookingCategory {
protected:
	ConcessionCategory(const string& name);
	virtual ~ConcessionCategory();
};

class DivyaangCategory : public ConcessionCategory {
	DivyaangCategory();
	~DivyaangCategory();
	static const string sName;
	bool isEligible(const Passenger& p) const;

public:
	static const BookingCategory& Type();
	Booking* createBooking(const Station& a, const Station& b, 
		const Date& dateofReservation, const BookingClass& d, const Passenger& p) const;
};

class LadiesCategory : public ConcessionCategory {
	LadiesCategory();
	~LadiesCategory();
	static const string sName;
	bool isEligible(const Passenger& p) const;

public:
	static const BookingCategory& Type();
	Booking* createBooking(const Station& a, const Station& b, 
		const Date& dateofReservation, const BookingClass& d, const Passenger& p) const;
};

class SeniorCategory : public ConcessionCategory {
	SeniorCategory();
	~SeniorCategory();
	static const string sName;
	bool isEligible(const Passenger& p) const;

public:
	static const BookingCategory& Type();
	Booking* createBooking(const Station& a, const Station& b, 
		const Date& dateofReservation, const BookingClass& d, const Passenger& p) const;
};

#endif