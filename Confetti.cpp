#include "Confetti.h"

Confetti::Confetti() {
	this->location = ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight(), ofRandom(-50, 50)));
	this->velocity = ofVec3f(ofRandom(-3, 3), ofRandom(0.5, 3), ofRandom(-0.5, 0.5));
	this->rotate = ofVec3f(0, 0, 0);
	this->body_color.setHsb(ofRandom(255), 255, 255);
}

void Confetti::update() {
	this->location += this->velocity;

	if (this->location.x < 0) {
		this->location.x = ofGetWidth();
	}
	
	if (this->location.x > ofGetWidth()) {
		this->location.x = 0;
	}

	if (this->location.y > ofGetHeight()) {
		this->location.y = -20;

		if (this->location.z < -50) {
			this->location.z = 50;
		}

		if (this->location.z > 50) {
			this->location.z = -50;
		}
	}

	this->rotate.x += this->velocity.x;
	this->rotate.y += this->velocity.y;
	this->rotate.z += this->velocity.z;
}

void Confetti::draw() {
	ofPushMatrix();
	ofTranslate(this->location);
	ofRotateX(this->rotate.x);
	ofRotateY(this->rotate.y);
	ofRotateZ(this->rotate.z);

	ofSetColor(this->body_color);
	ofDrawRectangle(ofVec3f(), 15, 15);

	ofPopMatrix();
}