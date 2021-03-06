#include "Ball.h"
#include <math.h>
#include <iostream>

Ball::Ball()
{
	x = 400.0f;
	y = 300.0f;
	width = 10;
	height = 10;

	velX = ballSpeed / ((float)sqrt(2));
	velY = ballSpeed / ((float)sqrt(2));
	sprite = { 180, 258, width, height };

	time = SDL_GetTicks();
}
Ball::~Ball()
{

}

void Ball::move(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2)
{
	float distY = velY * ((float)(SDL_GetTicks() - time)) / 1000.0f;
	float distX = velX * ((float)(SDL_GetTicks() - time)) / 1000.0f;

	if (x > 800 || x < 0) {
		velX = 0;
		velY = 0;
	}

	if (y + distY > 600) {
		y = 600;
		velY *= -1;
	}
	else if (y + distY < 0) {
		y = 0;
		velY *= -1;
	}

	int result1 = collisionDetection(distX, distY, x1, y1, w1, h1);
	int result2 = collisionDetection(distX, distY, x2, y2, w2, h2);

	if (result1 == 1 || result2 == 1) {
		velX *= -1;
	}
	else if (result1 == 2 || result2 == 2) {
		velY *= -1;
	}
	else if (result1 == 3 || result2 == 3) {
		velX *= -1;
	}
	else {
		x += distX;
		y += distY;
	}

	time = SDL_GetTicks();
}

void Ball::render()
{
	spriteSheet.render((int) x, (int) y, &sprite);
}

void Ball::reset()
{
	x = 400;
	y = 300;
	velX = ballSpeed / ((float)sqrt(2));
	velY = ballSpeed / ((float)sqrt(2));
}