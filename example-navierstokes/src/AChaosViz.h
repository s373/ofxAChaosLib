//
//  AChaosViz.h
//  AChaosExample
//
//  Created by andré sier on 20151021.
//
//

#pragma once

#include "AChaosBase.h"
#define PLANETS 255

class AChaosChannel {
public:
	REAL min, max;
	vector<REAL> mystory;
	AChaosChannel(){
		min = 1e10;
		max = -1e10;
		mystory.clear();
	}
	void update(REAL val){
		if(val < min) min = val;
		if(val > max) max = val;
		mystory.push_back(val);
		if(mystory.size()>PLANETS){
			mystory.erase(mystory.begin());
		}
	}
};

class AChaosViz {
public:
	
	AChaosBase *obj;
	vector<AChaosChannel> channels;
	int n;
	
	void setup(AChaosBase *ptr){
		obj = ptr;
		n=obj->ov.size();
		for(int i=0; i<n;i++){
			AChaosChannel ch;
			channels.push_back(ch);
		}
	}
	
	void update(float * data){
		for(int i=0; i<n;i++){
			channels[i].update(data[i]);
		}
	}
	
	void draw(){
		float w = ofGetWidth();
		float h = ofGetHeight();
		float chh = h / n;
		int s = channels[0].mystory.size();
		if(s<1){
			return;
		}
		float xg = w / s;
		
		for(int i=0; i<n;i++){
			
			float ya = i*chh;
			float yc = (i+1)*chh;
			float yb = yc - chh*0.5f;
			ofLine(0, yb, w, yb);
			ofDrawBitmapString(ofToString(channels[i].max), 5, ya + 0.1*chh);
			ofDrawBitmapString(ofToString(channels[i].min), 5, yc);
			ofDrawBitmapString(ofToString(channels[i].mystory[s-1]), 5, yb);
			
			for(int k=0; k<s-1; k++){
				float y0 = ofMap(channels[i].mystory[k], channels[i].min, channels[i].max, ya, yc);
				float y1 = ofMap(channels[i].mystory[k+1], channels[i].min, channels[i].max, ya, yc);
				
				ofLine(xg*k, y0, (xg+1)*k, y1);
			}
			
		}
	}
	
	
};