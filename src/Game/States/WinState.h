#pragma once

#include "State.h"
#include "Button.h"

class WinState: public State {
    private:
	ofImage img1;
	Button *restartButton;

	public: 
        WinState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);	
};