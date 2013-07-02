#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    ofxUICanvas *gui;
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void setLightOri(ofLight &light, ofVec3f rot);

    ofEasyCam cam;
    
    ofLight lightDir1;
    ofVec3f lightDir1_rot;
    ofLight lightDir2;
    ofVec3f lightDir2_rot;
    ofLight lightDir3;
    
    ofLight lightAmb;
    
    ofMaterial whiteMat;
    
    float timeCode;
};
