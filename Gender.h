#ifndef __GENDER_H
#define __GENDER_H

#include <bits/stdc++.h>
using namespace std;

class Gender {
	const string& name_;

protected:
	Gender(const string& name);
	virtual ~Gender();

public:
	const string& GetName() const;
	virtual bool isMale() const = 0;
};

class Male: public Gender {
	Male();
	~Male();
	static const string sName;

public:
	static const Gender& Type(); 
	bool isMale() const;
};

class Female: public Gender {
	Female();
	~Female();
	static const string sName;

public:
	static const Gender& Type(); 
	bool isMale() const;
};

#endif