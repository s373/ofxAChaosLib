/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
typedef float REAL;
#define SIN sinf
#define COS cosf

class AChaosBase {
public:
	AChaosBase(){}
	virtual ~AChaosBase(){}	

	vector<REAL> iv;	
	vector<REAL> ov;

	virtual void setup(){
		iv.clear();
		ov.clear();
		cout << "A-Chaos Lib (c) s373.net/x 2004, 2012, 2015 " << __DATE__ << " " __TIME__ << endl;
	}
	virtual void reset(){cout << "reset base" << endl;}
	void set(vector<REAL> &params){
		iv.clear();
		for(int i=0; i<params.size();i++){
			iv.push_back( params[i] );			
		}
		reset();
	}
	REAL * update(){ calc(); return get(); }
	virtual void calc(){cout << "calc base" << endl;}
	REAL * get(){ return &ov[0];}
	vector<REAL> & getVec(){return ov;}	
};