/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosHenon : public AChaosBase {
public:

	REAL a, b, nx, ny;
	
	AChaosHenon(){}
	~AChaosHenon(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		a = 1.4f;
		b = 0.3f;
		nx = 1.0f;
		ny = 1.0f;

		iv.push_back(a);
		iv.push_back(b);
		iv.push_back(nx);
		iv.push_back(ny);

		ov.push_back(nx);
		ov.push_back(ny);
	}

	void reset(){
		a = iv[0];
		b = iv[1];
		nx = iv[2];
		ny = iv[3];
	}
	
 	void calc(){ 		
		// henon 		
		nx = (ny + 1) - (a * (nx*nx));
		ny = b * nx;

		ov[0] = nx;
		ov[1] = ny;
 	}
};