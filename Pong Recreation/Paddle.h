#pragma once

#include "Element.h"

class Paddle : public Element
{
	public:
		Paddle(float xPos, int p);
		~Paddle();

		void move();
		void pollEvents(SDL_Event &e);
		void render();

	private:
		const float paddleSpeed = 200.0f;
		int player;
		Uint32 time;

};
