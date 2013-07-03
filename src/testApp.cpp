#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetSmoothLighting(true);
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);


    lightDir1.setDirectional();
    lightDir1.setDiffuseColor(ofColor(84.f, 76.f, 85.f));
    lightDir1.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    lightDir1_rot = ofVec3f(0, 90, 0);
    lightDir1.setOrientation( lightDir1_rot );
    lightDir2.setDirectional();
    lightDir2.setDiffuseColor(ofColor(80.f, 77.f, 70.f));
    lightDir2.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    lightDir2_rot = ofVec3f(90, 0, 0);
    lightDir2.setOrientation( lightDir2_rot );
    lightDir3.setDirectional();
    lightDir3.setDiffuseColor(ofColor(84.f, 76.f, 85.f));
    lightDir3.setSpecularColor(ofColor(255.f, 255.f, 255.f));
    lightDir3_rot = ofVec3f(0, -90, 90);
    lightDir3.setOrientation( lightDir3_rot );

    
    lightAmb.setAmbientColor(ofColor(20.0, 20.0, 20.0, 20.0));

    
    whiteMat.setShininess( 78 );
    whiteMat.setDiffuseColor(ofColor(203, 233, 212, 255));
    whiteMat.setSpecularColor(ofColor(255, 255, 255, 50));

    ofSetSphereResolution(100);
    
    timeCode = 0.0;

    gui = new ofxUICanvas(0,0,400,ofGetScreenHeight());
    gui->addWidgetDown(new ofxUILabel("MATERIAL", OFX_UI_FONT_LARGE));
    gui->addWidgetDown(new ofxUISlider(304,8,0.0,128.0,78.0,"M SHINY"));
    
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,203.0,"M DIFF R"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,233.0,"M DIFF G"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,212.0,"M DIFF B"));
    
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,255.0,"M SPEC R"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"M SPEC G"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"M SPEC B"));
    
    gui->addWidgetDown(new ofxUILabel("AMBIENT LIGHT", OFX_UI_FONT_LARGE));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,20.0,"AMBI R"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,20.0,"AMBI G"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,20.0,"AMBI B"));
    
    gui->addWidgetDown(new ofxUILabel("DIR LIGHT 1", OFX_UI_FONT_LARGE));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,84.0,"D1 DR"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,76.0,"D1 DG"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,85.0,"D1 DB"));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,255.0,"D1 SR"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"D1 SG"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"D1 SB"));
    gui->addWidgetDown (new ofxUISlider(90,8,-180,180,0.0,"D1 X"));
    gui->addWidgetRight(new ofxUISlider(90,8,-180,180,90.0,"D1 Y"));
    gui->addWidgetRight(new ofxUISlider(90,8,-180,180,0.0,"D1 Z"));
    
    gui->addWidgetDown(new ofxUILabel("DIR LIGHT 2", OFX_UI_FONT_LARGE));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,84.0,"D2 DR"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,76.0,"D2 DG"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,85.0,"D2 DB"));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,255.0,"D2 SR"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"D2 SG"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"D2 SB"));
    gui->addWidgetDown (new ofxUISlider(90,8,-180,180,90.0,"D2 X"));
    gui->addWidgetRight(new ofxUISlider(90,8,-180,180,0.0,"D2 Y"));
    gui->addWidgetRight(new ofxUISlider(90,8,-180,180,0.0,"D2 Z"));
    
    gui->addWidgetDown(new ofxUILabel("DIR LIGHT 3", OFX_UI_FONT_LARGE));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,84.0,"D3 DR"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,76.0,"D3 DG"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,85.0,"D3 DB"));
    gui->addWidgetDown (new ofxUISlider(90,8,0.0,255.0,255.0,"D3 SR"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"D3 SG"));
    gui->addWidgetRight(new ofxUISlider(90,8,0.0,255.0,255.0,"D3 SB"));
    gui->addWidgetDown (new ofxUISlider(90,8,-180,180,0.0,"D3 X"));
    gui->addWidgetRight(new ofxUISlider(90,8,-180,180,-90.0,"D3 Y"));
    gui->addWidgetRight(new ofxUISlider(90,8,-180,180,90.0,"D3 Z"));
    
    
    gui->addLabelButton("SAVE", false, 180,20);

    
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");

}

//--------------------------------------------------------------
void testApp::update(){
    timeCode += 0.1;

}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin();
    ofEnableLighting();
    lightDir1.enable();
    lightDir2.enable();
    lightDir3.enable();
    
    lightAmb.enable();

    whiteMat.begin();

    ofSphere(0,0,0,120);
    ofSphere(sin(timeCode*0.3)*100,sin(timeCode*0.1)*50,sin(timeCode*0.35)*120,70);
    ofSphere(sin(timeCode*0.45)*120,sin(timeCode*0.05)*80,sin(timeCode*0.25)*50,120);
    whiteMat.end();
    cam.end();
}
//--------------------------------------------------------------

void testApp::guiEvent(ofxUIEventArgs &e){
    //
    // Material
    //
    if(e.widget->getName() == "M SHINY"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        whiteMat.setShininess(slider->getScaledValue());
    }
    // Material Diffusion
    if(e.widget->getName() == "M DIFF R"){
        ofColor c = whiteMat.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        whiteMat.setDiffuseColor(c);
    }
    if(e.widget->getName() == "M DIFF G"){
        ofColor c = whiteMat.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        whiteMat.setDiffuseColor(c);
    }
    if(e.widget->getName() == "M DIFF B"){
        ofColor c = whiteMat.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        whiteMat.setDiffuseColor(c);
    }
    // Material Spec
    if(e.widget->getName() == "M SPEC R"){
        ofColor c = whiteMat.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        whiteMat.setSpecularColor(c);
    }
    if(e.widget->getName() == "M SPEC G"){
        ofColor c = whiteMat.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        whiteMat.setSpecularColor(c);
    }
    if(e.widget->getName() == "M SPEC B"){
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
    // Directional 1
    if(e.widget->getName() == "D1 DR"){
        ofColor c = lightDir1.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightDir1.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D1 DG"){
        ofColor c = lightDir1.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightDir1.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D1 DB"){
        ofColor c = lightDir1.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightDir1.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D1 SR"){
        ofColor c = lightDir1.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightDir1.setSpecularColor(c);
    }
    if(e.widget->getName() == "D1 SG"){
        ofColor c = lightDir1.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightDir1.setSpecularColor(c);
    }
    if(e.widget->getName() == "D1 SB"){
        ofColor c = lightDir1.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightDir1.setSpecularColor(c);
    }
    if(e.widget->getName() == "D1 X"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir1_rot.x = slider->getScaledValue();
        setLightOri(lightDir1,lightDir1_rot);
    }
    if(e.widget->getName() == "D1 Y"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir1_rot.y = slider->getScaledValue();
        setLightOri(lightDir1,lightDir1_rot);
    }
    if(e.widget->getName() == "D1 Z"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir1_rot.z = slider->getScaledValue();
        setLightOri(lightDir1,lightDir1_rot);
    }
    
    // Directional 2
    if(e.widget->getName() == "D2 DR"){
        ofColor c = lightDir2.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightDir2.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D2 DG"){
        ofColor c = lightDir2.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightDir2.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D2 DB"){
        ofColor c = lightDir2.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightDir2.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D2 SR"){
        ofColor c = lightDir2.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightDir2.setSpecularColor(c);
    }
    if(e.widget->getName() == "D2 SG"){
        ofColor c = lightDir2.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightDir2.setSpecularColor(c);
    }
    if(e.widget->getName() == "D2 SB"){
        ofColor c = lightDir2.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightDir2.setSpecularColor(c);
    }
    if(e.widget->getName() == "D2 X"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir2_rot.x = slider->getScaledValue();
        setLightOri(lightDir2,lightDir2_rot);
    }
    if(e.widget->getName() == "D2 Y"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir2_rot.y = slider->getScaledValue();
        setLightOri(lightDir2,lightDir2_rot);
    }
    if(e.widget->getName() == "D2 Z"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir2_rot.z = slider->getScaledValue();
        setLightOri(lightDir2,lightDir2_rot);
    }
    
    // Directional 3
    if(e.widget->getName() == "D3 DR"){
        ofColor c = lightDir3.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightDir3.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D3 DG"){
        ofColor c = lightDir3.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightDir3.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D3 DB"){
        ofColor c = lightDir3.getDiffuseColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightDir3.setDiffuseColor(c);
    }
    if(e.widget->getName() == "D3 SR"){
        ofColor c = lightDir3.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.r = slider->getScaledValue();
        lightDir3.setSpecularColor(c);
    }
    if(e.widget->getName() == "D3 SG"){
        ofColor c = lightDir3.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.g = slider->getScaledValue();
        lightDir3.setSpecularColor(c);
    }
    if(e.widget->getName() == "D3 SB"){
        ofColor c = lightDir3.getSpecularColor();
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        c.b = slider->getScaledValue();
        lightDir3.setSpecularColor(c);
    }
    if(e.widget->getName() == "D3 X"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir3_rot.x = slider->getScaledValue();
        setLightOri(lightDir3,lightDir3_rot);
    }
    if(e.widget->getName() == "D3 Y"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir3_rot.y = slider->getScaledValue();
        setLightOri(lightDir3,lightDir3_rot);
    }
    if(e.widget->getName() == "D3 Z"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        lightDir3_rot.z = slider->getScaledValue();
        setLightOri(lightDir3,lightDir3_rot);
    }
    
    //
    // Controls
    //
    if(e.widget->getName() == "SAVE"){
		ofxUIButton *button = (ofxUIButton *) e.widget;
        gui->saveSettings("GUI/guiSettings.xml");
	}


}
//--------------------------------------------------------------

void testApp::setLightOri(ofLight &light, ofVec3f rot)
{
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light.setOrientation(q);
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
//    gui->saveSettings("GUI/guiSettings.xml");
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