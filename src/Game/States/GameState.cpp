#include "GameState.h"

GameState::GameState()
{
	this->restaurant = new Restaurant();
	music.load("background-music.mp3");
	music.setLoop(true);
}
void GameState::tick()
{
	if(!music.isPlaying()) music.play();
	restaurant->tick();
	if (restaurant->getAngryClientCount() == 10)
	{
		setNextState("LoseState");
		setFinished(true);
	}
	else if (restaurant->getMoney() == 100)
	{
		setNextState("WinState");
		setFinished(true);
	}
}
void GameState::render()
{
	restaurant->render();
}

void GameState::keyPressed(int key)
{
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button)
{
}

void GameState::keyReleased(int key)
{
}

void GameState::reset()
{
	setFinished(false);
	setNextState("");
	restaurant->reset();
}