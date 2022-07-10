#ifndef __DIVYAANG_H
#define __DIVYAANG_H

#include <bits/stdc++.h>
using namespace std;

class Divyaang {
	const string& name_;

protected:
	Divyaang(const string& name);
	virtual ~Divyaang();

public:
	const string& GetName() const;
	virtual bool isDisabled() const;
};

class Blind: public Divyaang {
	Blind();
	~Blind();
	static const string sName;

public:
	static const Divyaang& Type(); 
};

class OH: public Divyaang {
	OH();
	~OH();
	static const string sName;

public:
	static const Divyaang& Type(); 
};

class CancerPatient: public Divyaang {
	CancerPatient();
	~CancerPatient();
	static const string sName;

public:
	static const Divyaang& Type(); 
};

class TBPatient: public Divyaang {
	TBPatient();
	~TBPatient();
	static const string sName;

public:
	static const Divyaang& Type(); 
};

class NoDisability: public Divyaang{
	NoDisability();
	~NoDisability();
	static const string sName;

public:
	static const Divyaang& Type();
	bool isDisabled() const;
};

#endif