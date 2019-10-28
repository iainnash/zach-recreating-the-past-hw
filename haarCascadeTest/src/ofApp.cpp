#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    finder.setup("haarcascade_frontalface_default.xml");
    
    int camWidth = 1280;
    int camHeight = 720;
    
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    for (size_t i = 0; i < devices.size(); i++) {
        if (devices[i].bAvailable) {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }
    }
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(15);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    fbo.allocate(camWidth, camHeight, OF_PIXELS_RGB);

    ofSetVerticalSync(true);
    
    font.load("silom.ttf", 10);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    if (vidGrabber.isFrameNew()) {
        pixelsGrabber = vidGrabber.getPixels();
        finder.blobs.clear();
        finder.findHaarObjects(pixelsGrabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(100);
    ofNoFill();
    
    for (unsigned int i = 0; i < min((unsigned long)2, finder.blobs.size()); i++) {
        ofRectangle sz = font.getStringBoundingBox("person", 0, 0);
        ofRectangle cur = finder.blobs[i].boundingRect;
        
        ofTexture pixTex;
        pixTex.allocate(cur.width, cur.height, OF_PIXELS_RGBA);
        ofPixels cropped;
        pixelsGrabber.cropTo(cropped, cur.x, cur.y, cur.width, cur.height);
        pixTex.loadData(cropped);
        ofSetColor(255, 40);
        for (int xi = 0; xi < ofGetWidth(); xi += cur.width) {
            for (int yi = 0; yi < ofGetHeight(); yi += cur.height) {
                pixTex.draw(xi, yi);
            }
        }
        ofSetColor(255, 255);
        pixTex.draw(cur.x, cur.y);
        
        ofSetColor(0, 255);
        ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
        for (int xi = cur.x; xi < cur.x + cur.width; xi += sz.getWidth()) {
            for (int yi = cur.y; yi < cur.y + cur.height; yi += sz.getHeight()) {
                ofSetColor(255, 50);
                font.drawString("person", xi, yi);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
