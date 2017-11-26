#pragma once

#include "Element.h"

class Ball : public Element
{
	public:
		Ball();
		~Ball();

		void move(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2);
		void render();

	private:
		const float ballSpeed = 200.0f;
		Uint32 time;
};