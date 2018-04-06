#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    angle = 0;
    oneShot = false;
    pdfRendering = false;
    
    ofBackground(225,225,225);
    ofSetVerticalSync(true);
    //load a custom font
    //the ttf file must be inside your bin/data directory
    //font.load("frabk.ttf", 24, true, false, true);
    svg1.load("test2.svg");
}

//--------------------------------------------------------------
void ofApp::update(){
    angle++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    if( oneShot ){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
    }
    
    ofSetColor(54);
    if( pdfRendering ){
        ofDrawBitmapString("press r to stop pdf multipage rendering", 32, 92);
    }else{
        ofDrawBitmapString("press r to start pdf multipage rendering\npress s to save a single screenshot as pdf to disk", 32, 92);
    }
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2-svg1.getWidth()/2 - 26, 30);
    svg1.draw();
    
    ofPopMatrix();
    ofFill();
    ofSetColor(54,54,54);
    //ofDrawBitmapString("TTF Font embdedded into pdf as vector shapes", 32, 460);
    
    /*if( oneShot || pdfRendering ){
     //important if we want our font to draw
     //as a shape
     font.drawStringAsShapes("Current Frame: ",  32, 500);
     ofSetColor(245, 58, 135);
     font.drawStringAsShapes( ofToString(ofGetFrameNum()), 32 + font.getStringBoundingBox("Current Frame: ", 0, 0).width + 9, 500);
     }else{
     font.drawString("Current Frame: ",  32, 500);
     ofSetColor(245, 58, 135);
     font.drawString( ofToString(ofGetFrameNum()), 32 + font.getStringBoundingBox("Current Frame: ", 0, 0).width + 9, 500);
     }
     */
    
    
    
    //lets draw a box with a trail
    ofSetColor(245, 58, 135);
    
    
    
    
    if( oneShot ){
        ofEndSaveScreenAsPDF();
        oneShot = false;
    }
    float angle2 = 0;
    int resolution = 22;
    float angle = 0;
    float rad = 75;
    float stroke = 12;
    float x = ofGetWidth()/2;
    float y = ofGetHeight()/2;
    for(int i = 0; i< 12; i ++){
        
        ofBeginShape();
        
        for( int i=0; i<resolution; i++ ){
            angle = i * 2 * PI / resolution;
            ofVertex(x+ rad*cos(angle2) + rad*sin(angle), y + rad*cos(angle) + rad*sin(angle2));
        }
        
        ofNextContour(true);
        int rad2 = rad - stroke;
        
        for( int i=0; i<resolution; i++ ){
            angle = i * 2 * PI / resolution;
            ofVertex(x + rad*cos(angle2) + rad2*sin(angle), y + rad2*cos(angle)+ rad*sin(angle2));
        }
        
        ofEndShape(true);
        angle2 = i * 2 * PI / 11;
        
    }
    
    for(int i = 0; i< 24; i ++){
        ofPushMatrix();
        ofTranslate(x + 2 * (rad + 5) * cos(angle2), y + 2 * (rad + 5) * sin(angle2),0);
        ofRotateZ(45 + i * 15);
        
        ofDrawRectangle(0, 0, 15, 15);
        ofPopMatrix();
        
        angle2 = i * 2 * PI / 23;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key=='r'){
        pdfRendering = !pdfRendering;
        if( pdfRendering ){
            ofSetFrameRate(12);  // so it doesn't generate tons of pages
            ofBeginSaveScreenAsPDF("recording-"+ofGetTimestampString()+".pdf", true);
        }else{
            ofSetFrameRate(60);
            ofEndSaveScreenAsPDF();
        }
    }
    
    if( !pdfRendering && key == 's' ){
        oneShot = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}



