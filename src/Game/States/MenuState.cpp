#include "MenuState.h"

MenuState::MenuState()
{
	img1.load("images/title.jpg");
	scroll.load("images/Scroll.png");
	startButton = new Button(ofGetWidth()-298, ofGetHeight()-194, 64, 50, "Start");
}
void MenuState::tick()
{
	startButton->tick();
	if (startButton->wasPressed())
	{
		setNextState("Game");
		setFinished(true);
	}
}
void MenuState::render()
{	ofSetColor(255, 255, 255);
	img1.draw(0, 0, ofGetWidth(), ofGetHeight());
	scroll.draw(ofGetWidth()-400, ofGetHeight()-459);
	ofSetColor(0);
	startButton->setPosition(ofGetWidth()-298, ofGetHeight()-194);
	startButton->render();
	ofDrawBitmapString("1) Pickup ingredients when", ofGetWidth()-360, ofGetHeight()-379);
	ofDrawBitmapString("the player is in front of", ofGetWidth()-360, ofGetHeight()-369);
	ofDrawBitmapString("the counter by pressing (e)", ofGetWidth()-360, ofGetHeight()-359);
	ofDrawBitmapString("2) Serve by pressing (s)", ofGetWidth()-360, ofGetHeight()-319);
	ofDrawBitmapString("3) Delete wrongly picked", ofGetWidth()-360, ofGetHeight()-279);
	ofDrawBitmapString("ingredients by pressing (u)", ofGetWidth()-360, ofGetHeight()-269);

}

void MenuState::keyPressed(int key)
{
}

void MenuState::mousePressed(int x, int y, int button)
{
	startButton->mousePressed(x, y);
}

void MenuState::reset()
{
	setFinished(false);
	setNextState("");
	startButton->reset();
}