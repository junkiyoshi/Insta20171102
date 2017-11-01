#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	for (int i = 0; i < 2048; i++) {
		this->confetti.push_back(shared_ptr<Confetti>(new Confetti()));
	}

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 48);
	this->font_size_1.x = this->font.stringWidth(message_1);
	this->font_size_1.y = this->font.stringHeight(message_1);
	this->font_size_2.x = this->font.stringWidth(message_2);
	this->font_size_2.y = this->font.stringHeight(message_2);

}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < this->confetti.size(); i++) {
		this->confetti[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(0, 128, 255);
	this->font.drawString(message_1, ofGetWidth() / 2 - this->font_size_1.x / 2, ofGetHeight() / 2 - this->font_size_1.y / 2);
	this->font.drawString(message_2, ofGetWidth() / 2 - this->font_size_2.x / 2, ofGetHeight() / 2 + this->font_size_2.y / 2);

	for (int i = 0; i < this->confetti.size(); i++) {
		this->confetti[i]->draw();
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(1920, 1080, OF_WINDOW);
	ofRunApp(new ofApp());
}