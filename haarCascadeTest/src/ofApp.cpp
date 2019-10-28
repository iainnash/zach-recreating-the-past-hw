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
    
    vidTexture.allocate(camWidth, camHeight, OF_PIXELS_RGB);

    ofSetVerticalSync(true);
    
    font.load("outwrite.ttf", 20);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    if (vidGrabber.isFrameNew()) {
        ofPixels & pixelsGrabber = vidGrabber.getPixels();
        vidTexture.loadData(pixelsGrabber);
        finder.blobs.clear();
        finder.findHaarObjects(pixelsGrabber);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(100);
    ofSetColor(200, 40);
    vidTexture.draw(0, 0);
    ofSetColor(255);
    ofNoFill();
    
    for (unsigned int i = 0; i < min((unsigned long)3, finder.blobs.size()); i++) {
        ofRectangle sz = font.getStringBoundingBox("person", 0, 0);
        ofRectangle cur = finder.blobs[i].boundingRect;
        for (int xi = cur.x; xi < cur.x + cur.width; xi += sz.getWidth()) {
            for (int yi = cur.y; yi < cur.y + cur.height; yi += sz.getHeight()) {
                font.drawString("person", xi, yi);
            }
        }
        ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
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
