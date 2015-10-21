/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosLogistic : public AChaosBase {
public:

	REAL seed, lambda;
	
	AChaosLogistic(){}
	~AChaosLogistic(){}	

	void setup(){
		AChaosBase::setup();		
		//init	
		seed = 0.777f;
		lambda = 3.9f;

		iv.push_back(seed);
		iv.push_back(lambda);

		ov.push_back(seed);
	}

	void reset(){
		seed = iv[0];
		lambda = iv[1];
	}
	
 	void calc(){ 	
 		seed = lambda * seed * (1.0-seed);

		ov[0] = seed;		
 	}
};