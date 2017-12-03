#pragma once

#include "Texture.h"

class Score
{
	public: 
		Score(int);
		~Score();

		void render();

		int score;
		int player;

	private:
		Texture spriteSheet;
		SDL_Rect clip1;
		SDL_Rect clip2;
};
