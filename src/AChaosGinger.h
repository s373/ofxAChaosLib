/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosGinger : public AChaosBase {
public:

	REAL seed, nx, ny;
	
	AChaosGinger(){}
	~AChaosGinger(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		seed = 0.82f;
		nx = 0.7f;
		ny = 1.2f;

		iv.push_back(seed);
		iv.push_back(nx);
		iv.push_back(ny);

		ov.push_back(nx);
		ov.push_back(ny);
	}

	void reset(){
		seed = iv[0];
		nx = iv[1];
		ny = iv[2];
	}
	
 	void calc(){ 		
		// ginger formulae
 		REAL x1,y1;

		y1 = nx;
		if (nx<0.) nx = -nx;
		x1 = 1. - ny - seed*nx;

		nx = x1;
		ny = y1;

		ov[0] = nx;
		ov[1] = ny;
 	}
};