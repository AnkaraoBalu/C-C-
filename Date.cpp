#include <bits/stdc++.h>
using namespace std;

#include "Date.h"

const vector <string> Date::monthNames{"Jan","Feb","Mar","Apr","May","Jun",
						"Jul","Aug","Sep","Oct","Nov","Dec"};

const vector <string> Date::dayNames{"Sunday","Monday","Tuesday","Wednesday",
						"Thursday","Friday","Saturday"};


Date::Date(int d,int m,int y) : date_(d),month_(m),year_(y){
	set_day();
	isvalid();
}
Date::~Date() {}

void Date::set_day() {
	// array with leading number of days values 
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    
    // if month is less than 3 reduce year by 1 
    if (month_<3) year_-= 1; 
    day_ = Date::dayNames[(year_+year_/4-year_/100+year_/400+t[month_-1]+date_) % 7];

    //changing it back
    if(month_<3) year_++;
}

//Check if the date is valid
bool Date::isvalid() {
	bool isLeap = (((year_%4==0)&&(year_%100!=0))||(year_%400==0));
	if(year_>2099||year_<1900) {
		Bad_Date z; throw z;
		return false;
	}
	if(month_<1 || month_>12) {
		Bad_Date z; throw z;
		return false;
	}
	if(date_<1 || date_>31) {
		Bad_Date z; throw z;
		return false;
	}
	if(month_==2) {
		if(isLeap) {
			if(date_<=29) return true;
			else {
				Bad_Date z; throw z;
				return false;
			}
		}
		else{
			if(date_<=28) return true;
			else {
				Bad_Date z; throw z;
				return false;
			}
		}
	}
	if(month_==4 || month_==6 ||
		month_==9 || month_==11) {
		if(date_<=30) return true;
		else {
			Bad_Date z; throw z;
			return false;
		}
	}
	return true;
}

//Copy constructor
Date& Date::operator=(const Date& d) {
	date_=d.date_;
	month_=d.month_;
	year_=d.year_;
	set_day();
	return *this;
}

//to print the date
ostream& operator<<(ostream& os,const Date& a) {
	os << a.date_ << "/" << Date::monthNames[a.month_-1] << "/" 
		<< a.year_ << " " << a.day_ << endl; //dd mm yyyy day format
	return os;
}

vector <int>  operator-(const Date& a, const Date& b) {
	if(a<b) {
		int month[] = { 31, 28, 31, 30, 31, 30, 31,
	                          31, 30, 31, 30, 31 };
	    int current_date = b.date_, current_month = b.month_, current_year = b.year_;
	    int birth_date = a.date_, birth_month = a.month_, birth_year = a.year_;
	    if (birth_date > current_date) {
	        current_date = current_date + month[birth_month - 1];
	        current_month = current_month - 1;
	    }
	    if (birth_month > current_month) {
	        current_year = current_year - 1;
	        current_month = current_month + 12;
	    }

	    int calculated_date = current_date - birth_date;
	    int calculated_month = current_month - birth_month;
	    int calculated_year = current_year - birth_year;

	    vector <int> ans{calculated_date,calculated_month,calculated_year};
	    return ans;
	}
	int month[] = { 31, 28, 31, 30, 31, 30, 31,
                          31, 30, 31, 30, 31 };
    int current_date = a.date_, current_month = a.month_, current_year = a.year_;
    int birth_date = b.date_, birth_month = b.month_, birth_year = b.year_;
    if (birth_date > current_date) {
        current_date = current_date + month[birth_month - 1];
        current_month = current_month - 1;
    }
    if (birth_month > current_month) {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }

    int calculated_date = current_date - birth_date;
    int calculated_month = current_month - birth_month;
    int calculated_year = current_year - birth_year;

    vector <int> ans{calculated_date,calculated_month,calculated_year};
    return ans;
}

bool operator<(const Date& a,const Date& b) {
	if(a.year_<b.year_) return true;
	else if(a.year_==b.year_) {
		if(a.month_<b.month_) return true;
		else if(a.month_==b.month_) {
			if(a.day_<b.day_) return true;
		}
	}
	return false;
}

Date Date::Today(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	Date nn(ltm->tm_mday,1+ltm->tm_mon,1900+ltm->tm_year);
	return nn;
}

string Date::getDay() const {
	return day_;
}