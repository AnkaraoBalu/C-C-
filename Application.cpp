#include <bits/stdc++.h>
using namespace std;

#include "Date.cpp"
#include "Gender.cpp"
#include "Divyaang.cpp"
#include "BookingClass.cpp"
#include "Exceptions.cpp"
#include "Passenger.cpp"
#include "Concessions.cpp"
#include "Booking.cpp"
#include "BookingCategory.cpp"

int main() {
	GeneralCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACThreeTier::Type(),p1);	

	GeneralCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACFirstClass::Type(),p1);	

	SeniorCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACThreeTier::Type(),p4);

	SeniorCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACFirstClass::Type(),p5);		

	DivyaangCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACThreeTier::Type(),p6);

	DivyaangCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACFirstClass::Type(),p8);		

	TatkalCategory::Type().createBooking(Station("Delhi"),Station("Mumbai"),
		Date(30,4,2021),ACThreeTier::Type(),p1);	

	TatkalCategory::Type().createBooking(Station("Chennai"),Station("Bangalore"),
		Date(30,4,2021),ACFirstClass::Type(),p1);	

	vector <Booking*> :: iterator it;
	for(it = Booking::sBookings.begin();it!=Booking::sBookings.end();++it) {
		if((*it)!=NULL) cout << (*(*(it))) << endl;
	}		
	return 0;
}