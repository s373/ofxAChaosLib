/*
	A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: WTFPL 0.0
*/

#pragma once
#include "AChaosBase.h"
#define lorx(x, y, a) 		(a) * ((y) - (x));		
#define lory(x, y, z, a) 	((x) * ((r) - (z))) - (y);
#define lorz(x, y, z, c) 	((x) * (y)) - ((z) * (c));

class AChaosLorenz : public AChaosBase {
public:

	REAL	a, r, c, nx, ny, nz,dt; //eq variables
	
	AChaosLorenz(){}
	~AChaosLorenz(){}	

	void setup(){
		AChaosBase::setup();
		//classic lorenz
		 a=10.0;
		 r=28.0; 
		 c= 2.67; 
		 nx=0.1; 
		 ny=0.1; 
		 nz=0.1;
		 dt=0.01;

		iv.push_back(nx);
		iv.push_back(ny);
		iv.push_back(nz);
		iv.push_back(a);
		iv.push_back(r);
		iv.push_back(c);
		iv.push_back(dt);

		ov.push_back(nx);
		ov.push_back(ny);
		ov.push_back(nz);
	}

	void reset(){
		nx = iv[0];
		ny = iv[1];
		nz = iv[2];
		a = iv[3];
		r = iv[4];
		c = iv[5];
		dt = iv[6];
	}
	
 	void calc(){
 		
		REAL dt2, 
				fx, fy, fz, 
				ffx, ffy, ffz, 
				dtfx, dtfy, dtfz;
		
		dt2 = dt/2.;

		fx = lorx   (nx,ny,a);
		fz = lorz(nx,ny,nz,c);
		fy = lory(nx,ny,nz,r);

		dtfx = nx + (dt*fx);
		dtfy = ny + (dt*fy);
		dtfz = nz + (dt*fz);

		ffx = lorx	   (dtfx,dtfy,a);
		ffz = lorz(dtfx,dtfy,dtfz,c);
		ffy = lory(dtfx,dtfy,dtfz,r);

		nx += (dt2*(fx+ffx));
		ny += (dt2*(fy+ffy));
		nz += (dt2*(fz+ffz));

		ov[0] = nx;
		ov[1] = ny;
		ov[2] = nz;
 	}
};