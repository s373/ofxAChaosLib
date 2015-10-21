/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosNavierStokesEuler : public AChaosBase {
public:

	REAL a, b, c, d, e, r, dt;
	
	AChaosNavierStokesEuler(){}
	~AChaosNavierStokesEuler(){}	

	void setup(){
		AChaosBase::setup();		

		//classic navierstokes
		a = 1.0;
		b = 1.0;
		c = 1.0;
		d = 1.0;
		e = 1.0;
		r = 28.0;
		dt = 0.01;

		iv.push_back(a);
		iv.push_back(b);
		iv.push_back(c);
		iv.push_back(d);
		iv.push_back(e);
		iv.push_back(r);
		iv.push_back(dt);

		ov.push_back(a);
		ov.push_back(b);
		ov.push_back(c);
		ov.push_back(d);
		ov.push_back(e);
	}

	void reset(){
		a = iv[0];
		b = iv[1];
		c = iv[2];
		d = iv[3];
		e = iv[4];
		r = iv[5];
		dt = iv[6];
	}
	

	void calc(){ 	

		REAL da, db, dc, dd, de;
	
		da=((a * -2) + (4 * b * c) + (4 * d * e))*dt;
		db=((b * -9) + (3 * a * c))*dt;
		dc=((c * -5) + (-7 * a * b) + r)*dt;
		dd=((d * -5) - (a * e))*dt;
		de=((a * d * -3) - e)*dt;

		a += da;
		b += db;
		c += dc;
		d += dd;
		e += de;

		ov[0] = a;
		ov[1] = b;
		ov[2] = c;
		ov[3] = d;
		ov[4] = e;

 	}
};