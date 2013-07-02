#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetSmoothLighting(true);
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);

    lightDir1.setDirectional();
    lightDir1.setDiffuseColor(ofColor(84.f, 76.f, 85.f));
    lightDir1.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    lightDir1.setOrientation( ofVec3f(0, 90, 0) );
    lightDir2.setDirectional();
    lightDir2.setDiffuseColor(ofColor(80.f, 77.f, 70.f));
    lightDir2.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    lightDir2.setOrientation( ofVec3f(90, 0, 0) );
    lightDir3.setDirectional();
    lightDir3.setDiffuseColor(ofColor(84.f, 76.f, 85.f));
    lightDir3.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    lightDir3.setOrientation( ofVec3f(0, -90, 90) );

    lightAmb.setAmbientColor(ofColor(20.0, 20.0, 20.0, 20.0));

    
    whiteMat.setShininess( 78 );
    whiteMat.setDiffuseColor(ofColor(203, 233, 212, 255));
    whiteMat.setSpecularColor(ofColor(255, 255, 255, 50));

    ofSetSphereResolution(100);

    gui = new ofxUICanvas(0,0,320,320);
    gui->addWidgetDown(new ofxUISlider(304,8,0.0,128.0,78.0,"MAT SHINY"));
    
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,203.0,"MAT DIFF R"));
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,233.0,"MAT DIFF G"));
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,212.0,"MAT DIFF B"));
    
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,255.0,"MAT SPEC R"));
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,255.0,"MAT SPEC G"));
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,255.0,"MAT SPEC B"));
    
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,20.0,"AMBI R"));
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,20.0,"AMBI G"));
    gui->addWidgetDown(new ofxUISlider(90,8,0.0,255.0,20.0,"AMBI B"));
    
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin();
    ofEnableLighting();
    lightDir1.enable();
    lightDir2.enable();
    lightDir3.enable();

    lightAmb.enable();
    
    ofLogNotice() << whiteMat.getDiffuseColor();

    whiteMat.begin();

    ofSphere(0,0,0,120);
    ofSphere(100,50,20,70);
    ofSphere(-40,-80,-100,120);
    whiteMat.end();
    cam.end();
}
//--------------------------------------------------------------

void testApp::guiEvent(ofxUIEventArgs &e){
    //
    // Material
    //
    if(e.widget->getName() == "MAT SHINY"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        whiteMat.setShininess(slider->getScaledValue());
    }
    // Material Diffusion
    if(e.widget->getName() == "MAT DIFF R"){
        ofColor c = whiteMat.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        whiteMat.setDiffuseColor(c);
    }
    if(e.widget->getName() == "MAT DIFF G"){
        ofColor c = whiteMat.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        whiteMat.setDiffuseColor(c);
    }
    if(e.widget->getName() == "MAT DIFF B"){
        ofColor c = whiteMat.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        whiteMat.setDiffuseColor(c);
    }
    // Material Spec
    if(e.widget->getName() == "MAT SPEC R"){
        ofColor c = whiteMat.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        whiteMat.setSpecularColor(c);
    }
    if(e.widget->getName() == "MAT SPEC G"){
        ofColor c = whiteMat.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        whiteMat.setSpecularColor(c);
    }
    if(e.widget->getName() == "MAT SPEC B"){
        ofColor c = whiteMat.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        whiteMat.setSpecularColor(c);
    }
    //
    // Lighting
    //
    if(e.widget->getName() == "AMBI R"){
        ofColor c = lightAmb.getAmbientColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightAmb.setAmbientColor(c);
    }
    if(e.widget->getName() == "AMBI G"){
        ofColor c = lightAmb.getAmbientColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightAmb.setAmbientColor(c);
    }
    if(e.widget->getName() == "AMBI B"){
        ofColor c = lightAmb.getAmbientColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightAmb.setAmbientColor(c);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}
//--------------------------------------------------------------

void testApp::exit(){
    gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}