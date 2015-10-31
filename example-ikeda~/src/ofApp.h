#pragma once

#include "ofMain.h"

#include "ofxAChaosLib.h"
#include "AChaosViz.h"

class ofApp : public ofBaseApp{

	public:

		void setup(){
			chaos.setup();
			viz.setup(&chaos);
			volume = 0.57f;
			sound.listDevices();
			sound.setup(this, 2, 0, 44100, 64, 4);
			ofSetFrameRate(60);
		}

		void update(){
			if(output==NULL) return;
			REAL p[6] = {output[0], output[1],ofMap(ofGetMouseX(),0,ofGetWidth(),0.75, 1.1), ofMap(ofGetMouseY(),0,ofGetHeight(),0.75, 1.1),0.4,7.7};
			chaos.set(p);
		}

		void draw(){ viz. draw(); }
		
		void audioOut(float * outpt, int bufferSize, int nChannels){
			for (int i = 0; i < bufferSize; i++){
				output = chaos.update();
				viz.update(output);
				 outpt[i*nChannels    ] = ofMap(output[0], viz.channels[0].min, viz.channels[0].max, -1, 1) * volume;
				 outpt[i*nChannels + 1] =  ofMap(output[1], viz.channels[1].min, viz.channels[1].max, -1, 1) * volume;
			}
		}

	AChaosIkeda		chaos;
	AChaosViz		viz;
	REAL			*output,volume;
	ofSoundStream	sound;
		
};
