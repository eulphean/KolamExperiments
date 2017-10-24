#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    void keyPressed(int key);
    
    vector<glm::vec3> pointsInSpace;
    vector<glm::vec3> randomIndices;
    
    const int numOfPoints = 25;
    
    void connectPoints();
    
    ofEasyCam cam;
};
