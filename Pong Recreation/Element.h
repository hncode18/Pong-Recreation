#pragma once

#include "Texture.h"

class Element
{
	public:
		Element();
		~Element();

		bool checkOverlap(float x0, float y0, float x1, float y1, int w1, int h1);
		int collisionDetection(float dX, float dY, float x1, float y1, int w1, int h1);
		virtual void pollEvents(SDL_Event &e);
		virtual void move();
		virtual void render();
		
		float x, y;
		float velX, velY;
		int width, height;

		Texture spriteSheet;
		SDL_Rect sprite;
};