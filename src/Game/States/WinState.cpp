#include "WinState.h"

WinState::WinState()
{
	img1.load("images/win-screen.jpg");
	restartButton = new Button(ofGetWidth() / 2 - 64, ofGetHeight() / 2 + 150, 64, 50, "Restart");
}

void WinState::tick()
{
	restartButton->tick();
	if (restartButton->wasPressed())
	{
		setNextState("Game");
		setFinished(true);
	}
}

void WinState::render()
{
	ofSetColor(255, 255, 255);
	img1.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255, 255, 255);
	restartButton->setPosition(ofGetWidth()/2 - 64, ofGetHeight()/2 + 150);
	restartButton->render();
}

void WinState::keyPressed(int key)
{
}

void WinState::mousePressed(int x, int y, int button)
{
	restartButton->mousePressed(x, y);
}

void WinState::keyReleased(int key)
{
}

void WinState::reset()
{
	setFinished(false);
	setNextState("");
	restartButton->reset();
}