#pragma once
#include "ofMain.h"
#include "Confetti.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key) {};
	void keyReleased(int key) {};
	void mouseMoved(int x, int y) {};
	void mouseDragged(int x, int y, int button) {};
	void mousePressed(int x, int y, int button) {};
	void mouseReleased(int x, int y, int button) {};
	void mouseEntered(int x, int y) {};
	void mouseExited(int x, int y) {};
	void windowResized(int w, int h) {};
	void dragEvent(ofDragInfo dragInfo) {};
	void gotMessage(ofMessage msg) {};

	ofTrueTypeFont font;
	ofVec2f font_size_1, font_size_2;
	string message_1 = "Today is my birthday!!";
	string message_2 = "11 / 03";

	vector<shared_ptr<Confetti>> confetti;
};