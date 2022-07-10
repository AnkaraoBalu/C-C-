#ifndef __CONCESSIONS_H
#define __CONCESSIONS_H

#include <bits/stdc++.h>
using namespace std;

#include "Passenger.h"
#include "BookingClass.h"
#include "Gender.h"

class Concessions {
protected:
	Concessions();
	virtual ~Concessions();

public:
	virtual double getConcessionFactor() const = 0;
};

class GeneralConcessions: public Concessions {
	const Passenger& p;

public:
	GeneralConcessions(const Passenger& p);
	~GeneralConcessions();

	double getConcessionFactor() const;
};

class SCConcession: public Concessions {
	const Passenger& p;

public:
	SCConcession(const Passenger& p);
	~SCConcession();

	double getConcessionFactor() const;
};

class LadiesConcession: public Concessions {
	const Passenger& p;

public:
	LadiesConcession(const Passenger& p);
	~LadiesConcession();

	double getConcessionFactor() const;
};

class DivyaangConcession: public Concessions {
	const Passenger& p;
	const BookingClass& b;

public:
	DivyaangConcession(const Passenger& p, const BookingClass& b);
	~DivyaangConcession();

	double getConcessionFactor() const;
};

#endif