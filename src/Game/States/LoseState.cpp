#include "LoseState.h"

LoseState::LoseState()
{
	img1.load("images/game-over.png");
	restartButton = new Button(ofGetWidth()/2 - 64, ofGetHeight()/2 + 150, 64, 50, "Restart");
}

void LoseState::tick()
{
	restartButton->tick();
	if (restartButton->wasPressed())
	{
		setNextState("Game");
		setFinished(true);
	}
}
void LoseState::render()
{
	ofSetColor(255, 255, 255);
	img1.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255,255,255);
	restartButton->setPosition(ofGetWidth()/2 - 64, ofGetHeight()/2 + 150);
	restartButton->render();
}

void LoseState::keyPressed(int key)
{
}

void LoseState::mousePressed(int x, int y, int button)
{
	restartButton->mousePressed(x, y);
}

void LoseState::keyReleased(int key)
{
}

void LoseState::reset()
{
	setFinished(false);
	setNextState("");
	restartButton->reset();
}