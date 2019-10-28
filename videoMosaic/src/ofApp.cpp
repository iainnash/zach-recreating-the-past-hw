#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(1280, 720);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int grabberW = grabber.getWidth();
    int grabberH = grabber.getHeight();
    float tm = ofGetElapsedTimef()/3.0;
    unsigned char* data = grabber.getPixels().getData();
    for (unsigned int x = 0; x < grabberW; x += 10) {
        for (unsigned int y = 0; y < grabberH; y += 10) {
            unsigned char r = data[(y*grabberW+x)*3+0];
            unsigned char g = data[(y*grabberW+x)*3+1];
            unsigned char b = data[(y*grabberW+x)*3+2];
            int colorOffset = ofMap(ofNoise(tm + x*0.04 + y * 0.04), 0, 1, 100, 255);
            ofSetColor(b, r, max(0, colorOffset-g));
            float radius = ofMap(ofNoise(x*0.05 + tm, y*0.05 + tm), 0, 1, 2, 20);
            ofDrawCircle(x, y, radius);
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
