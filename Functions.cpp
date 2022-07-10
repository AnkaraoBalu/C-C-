#include <bits/stdc++.h>
using namespace std;

#include "Passenger.h"
#include "BookingClass.h"
#include "BookingCategory.h"

Passenger* CreatePassenger() {
	while(true) {
		string firstname,middlename,lastname,aadhaar,mobileno,divyaangID="";
		while(true) {
			cout << "Enter First Name: "; cin >> firstname;
			cout << "Enter Middle Name: "; cin >> middlename;
			cout << "Enter Last Name: "; cin >> lastname;
			if((firstname=="")&&(lastname=="")) {
				cout << "Both firstname and lastname cannot be empty." << endl;
				cout << "Please Try again." << endl;
				continue;
			}
			break;
		}
		string name = firstname+middlename+lastname;
		Date dob(1,1,2001);
		while(true) {
			int day,month,year;
			cout << "Enter the year you were born(between 1899-2021): "; cin >> year;
			cout << "Enter your month of birth(between 1-12): "; cin >> month;
			cout << "Enter your day of birth(1-31): "; cin >> day;
			try {
				Date d(day,month,year);
			}
			catch(Bad_Date& ex) {
				cout << ex.what(); 
				cout << "Please Try again." << endl;
				continue;
			}
			Date d(day,month,year);
			dob=d;
			break;
		}
		int temp1,temp2,temp;
		cout << "Enter your gender(0 for male, 1 for female): "; cin >> temp1;
		cout << "Enter your aadhaar number: "; cin >> aadhaar;
		cout << "Do you want to enter your mobile Number?(its optional. Input 0 if you don't want to, otherwise 1): "; cin >> temp;
		if(temp==1) cout << "Enter your mobile number(leaving it empty is allowed): "; cin >> mobileno;
		cout << "Enter your disability type(1:Blind, 2:Orthopaedically Handicapped, 3:Cancer, 4:TB, 5:None): ";
		cin >> temp2;
		if((temp2>=1)&&(temp2<=4)) {
			cout << "Enter Disability ID: "; cin >> divyaangID;
		}
		try {
			if(temp1==0 && temp2 == 1) return new Passenger(name,dob,Male::Type(),aadhaar,mobileno,Blind::Type(),divyaangID);
			if(temp1==0 && temp2 == 2) return new Passenger(name,dob,Male::Type(),aadhaar,mobileno,OH::Type(),divyaangID);
			if(temp1==0 && temp2 == 3) return new Passenger(name,dob,Male::Type(),aadhaar,mobileno,CancerPatient::Type(),divyaangID);
			if(temp1==0 && temp2 == 4) return new Passenger(name,dob,Male::Type(),aadhaar,mobileno,TBPatient::Type(),divyaangID);
			if(temp1==0 && temp2 == 5) return new Passenger(name,dob,Male::Type(),aadhaar,mobileno,NoDisability::Type(),divyaangID);
			if(temp1==1 && temp2 == 1) return new Passenger(name,dob,Female::Type(),aadhaar,mobileno,Blind::Type(),divyaangID);
			if(temp1==1 && temp2 == 2) return new Passenger(name,dob,Female::Type(),aadhaar,mobileno,OH::Type(),divyaangID);
			if(temp1==1 && temp2 == 3) return new Passenger(name,dob,Female::Type(),aadhaar,mobileno,CancerPatient::Type(),divyaangID);
			if(temp1==1 && temp2 == 4) return new Passenger(name,dob,Female::Type(),aadhaar,mobileno,TBPatient::Type(),divyaangID);
			if(temp1==1 && temp2 == 5) return new Passenger(name,dob,Female::Type(),aadhaar,mobileno,NoDisability::Type(),divyaangID);
		}
		catch(Bad_Passenger& ex) {
			cout << "Invalid Details. Please try again." << endl;
		}
	}
}

Booking* CreateBooking() {
	string fromsta,tosta;
	cout << "Enter from station: "; cin >> fromsta;
	cout << "Enter to station: "; cin >> tosta;
	int day,month,year;
	cout << "Enter year of reservation Date(can be between 1899-2099 but should be after today): "; cin >> year;
	cout << "Enter month of travel(1-12): "; cin >> month;
	cout << "Enter day of travel(1-31): "; cin >> day;
	int temp1,temp2;
	cout << "Choose a booking class. Enter the index of the class from the list below: " << endl;
	cout << "1. AC First Class" << endl;
	cout << "2. Executive Chair Car" << endl;
	cout << "3. AC Two Tier" << endl;
	cout << "4. First Class" << endl;
	cout << "5. AC Three Tier" << endl;
	cout << "6. AC Chair Car" << endl;
	cout << "7. Sleeper" << endl;
	cout << "8. Second Sitting" << endl;
	cin >> temp1; 
	if(temp1 == 1) {

	}
}