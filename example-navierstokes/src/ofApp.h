#pragma once

#include "ofMain.h"

#include "ofxAChaosLib.h"
#include "AChaosViz.h"

class ofApp : public ofBaseApp{

	public:
		void setup(){
			chaos.setup();
			viz.setup(&chaos);
		}

		void update(){
			REAL * output = chaos.update();
			viz.update(output);
		}
		void draw(){ viz. draw(); }

	
	AChaosNavierStokes 	chaos;
	AChaosViz		viz;
		
};
