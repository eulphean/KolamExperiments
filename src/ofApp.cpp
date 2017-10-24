#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    ofSetCircleResolution(80);
    
    pointsInSpace = {};
    randomIndices = {};
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    // Do we have any points to draw?
    if (pointsInSpace.size() > 0) {
        // Interactively update the result.
        for (int i = 0; i < numOfPoints; i++) {
            
            // Draw the point as a small circle.
            ofFill();
            ofSetColor(ofColor::white);
            ofDrawCircle(pointsInSpace[i].x, pointsInSpace[i].y, pointsInSpace[i].z, 10);
            //ofDrawBox(pointsInSpace[i].x, pointsInSpace[i].y, pointsInSpace[i].z, 20);
            
            // Do we have random indices corresponding to points in space?
            if (randomIndices.size() > 0) {
                // Draw a line between point and point at randomIdx.
                ofDrawLine(pointsInSpace[i], randomIndices[i]);
            }
        }
    }
    
    cam.draw();
}

void ofApp::keyPressed(int key) {
    
    // Generate random points in space and then connect them randomly.
    if (key == 49) {
        pointsInSpace.clear();
        // Generate 50 random points.
        for (int i = 0; i < numOfPoints; i++) {
            // Only points in the visible range. Every point is precious.
            glm::vec3 p(ofRandom(ofGetWidth()-1), ofRandom(ofGetHeight()-1), ofRandom(-1000, 1000));
            pointsInSpace.push_back(p);
        }
        
        connectPoints();
    }
    
    // Update connection points.
    if (key == 50) {
        connectPoints();
    }
    
    // Make a 3D mesh.
    if (key == 51) {
        pointsInSpace.clear();
        for (int x = 1; x < ofGetWidth(); x = x + 40) {
            for (int y = 1; y < ofGetHeight(); y = y + 40) {
                for (int z = -100; z < 100; z = z + 20) {
                    glm::vec3 p(x, y, z);
                    pointsInSpace.push_back(p);
                }
            }
        }
        connectPoints();
    }
}

void ofApp::connectPoints() {
    randomIndices.clear();
    // Generate 50 random points.
    for (int i = 0; i < numOfPoints; i++) {
        // Keep calculating random index if new and old indices are same.
        int randomIdx = ofRandom(numOfPoints-1);
        while (randomIdx == i) {
            randomIdx = ofRandom(numOfPoints - 1);
        }
        randomIndices.push_back(pointsInSpace[randomIdx]);
    }
}
