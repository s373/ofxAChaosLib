/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"
#define	pi  3.14159265358979323846264338327950288419716939937510f
#define twopi 2.*pi
class AChaosTorus : public AChaosBase {
public:

	REAL x0, y0, cr;
	
	AChaosTorus(){}
	~AChaosTorus(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		x0 = 0.777f;
		y0 = 1.2f;
		cr = 1.26f;

		iv.push_back(x0);
		iv.push_back(y0);
		iv.push_back(cr);

		ov.push_back(x0);
		ov.push_back(y0);
	}

	void reset(){
		x0 = iv[0];
		y0 = iv[1];
		cr = iv[2];
	}
	
 	void calc(){ 	
 		x0 = fmodf((x0+cr*SIN(y0)), twopi);
		y0 = fmodf((x0+y0), twopi);

		ov[0] = x0;
		ov[1] = y0;
 	}
};