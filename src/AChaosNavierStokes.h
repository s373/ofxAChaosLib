/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/
#pragma once
#include "AChaosBase.h"

class AChaosNavierStokes : public AChaosBase {
public:

	REAL a, b, c, d, e, r, dt;
	
	AChaosNavierStokes(){}
	~AChaosNavierStokes(){}	

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
	
#define nava(a, b, c, d, e)		((-2*(a)) + (4*(b)*(c)) + (4*(d)*(e)))
#define navb(a, b, c)			((-9*(b)) + (3*(a)*(c)))
#define navc(a, b, c, r)		((-5*(c)) + (-7*(a)*(b)) + (r))
#define navd(a, d, e)			((-5*(d)) - ((a)*(e)))
#define nave(a, d, e)			((-3*(a)*(d)) - (e))

	void calc(){ 	

		REAL dt2=dt/2., afa, bfb, cfc, dfd, efe;
		REAL fa, fb, fc, fd, fe;
		REAL ffa, ffb, ffc, ffd, ffe;

		fa=nava(a, b, c, d, e);
		fb=navb(a, b, c);
		fc=navc(a, b, c, r);
		fd=navd(a, d, e);
		fe=nave(a, d, e);
		
		afa = a +(dt*fa);
		bfb = b +(dt*fb);
		cfc = c +(dt*fc);
		dfd = d +(dt*fd);
		efe = e +(dt*fe);
		
		ffa = nava(afa,bfb,cfc,dfd,efe);
		ffb = navb(afa,bfb,cfc);
		ffc = navc(afa,bfb,cfc,r);
		ffd = navd(afa,dfd,efe);
		ffe = nave(afa,dfd,efe);
		
		a += (dt2*(fa+ffa));
		b += (dt2*(fb+ffb));
		c += (dt2*(fc+ffc));
		d += (dt2*(fd+ffd));
		e += (dt2*(fe+ffe));

		ov[0] = a;
		ov[1] = b;
		ov[2] = c;
		ov[3] = d;
		ov[4] = e;

 	}
};