/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosDuffing : public AChaosBase {
public:

	REAL a, b, w, t, dt, nx, ny;
	
	AChaosDuffing(){}
	~AChaosDuffing(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		a = 0.25f;
		b = 0.3f;
		w = 1.0f;
		nx = 0.0f;
		ny = 0.0f;
		dt = 0.01f;
		t = 0.0f;

		iv.push_back(a);
		iv.push_back(b);
		iv.push_back(w);
		iv.push_back(nx);
		iv.push_back(ny);
		iv.push_back(dt);
		iv.push_back(t);

		ov.push_back(nx);
		ov.push_back(ny);
	}

	void reset(){
		a = iv[0];
		b = iv[1];
		w = iv[2];
		nx = iv[3];
		ny = iv[4];
		dt = iv[5];
		t = iv[6];
	}
	
 	void calc(){ 		
		t += dt;
		nx = ny;
		ny = nx-(nx*nx*nx)-(a*ny)+(b*COS(w*t));

		ov[0] = nx;
		ov[1] = ny;
 	}
};