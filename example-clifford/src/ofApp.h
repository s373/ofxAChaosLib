#pragma once

#include <sstream>

#include "ofMain.h"

#include "ofxAChaosLib.h"

class ofApp : public ofBaseApp{

	public:
		void setup(){
			chaos.setup();
		}
		void update(){
			REAL * output = chaos.update();
			//[2] = {0.0f, 0.0f};
			ss.str("");
			ss << ofGetFrameNum() << " " << output[0] << " " << output[1] << endl;
			cout << ss.str();
		}
		void draw(){
			ofDrawBitmapString(ss.str(), 2, 10);
		}

	
	AChaosClifford		chaos;
	std::stringstream 	ss;
		
};
