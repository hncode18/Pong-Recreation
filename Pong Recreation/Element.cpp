#include "Element.h"

Element::Element()
{
	spriteSheet.loadFile("res/pong.png");
}
Element::~Element()
{
	spriteSheet.free();
}

// true = collisions, false = no collision
bool Element::checkOverlap(float x0, float y0, float x1, float y1, int w1, int h1)
{
	int topA, topB;
	int bottomA, bottomB;
	int rightA, rightB;
	int leftA, leftB;

	topA = (int) y0;
	topB = (int) y1;
	bottomA = ((int) y0) + height;
	bottomB = ((int) y1) + h1;
	leftA = (int) x0;
	leftB = (int) x1;
	rightA = ((int) x0) + width;
	rightB = ((int) x1) + w1;

	// checking y axis
	if (topA >= bottomB) {    // no collision
		return false;
	}
	if (topB >= bottomA) {    // no collision
		return false;
	}
	if (leftA >= rightB) {    // no collision
		return false;
	}
	if (leftB >= rightA) {    // no collision
		return false;
	}

	return true;
}

int Element::collisionDetection(float dX, float dY, float x1, float y1, int w1, int h1)
{
	if (checkOverlap(x, y, x1, y1, w1, h1)) {
		if (x + width > x1) {
			x -= x + width - x1;
		}
		else if (x < x1 + w1) {
			x -= x1 + w1 - x;
		}
	}

	if (checkOverlap(x + dX, y, x1, y1, w1, h1)) {
		return 1;
	}
	else if (checkOverlap(x, y + dY, x1, y1, w1, h1)) {
		return 2;
	}
	else if (checkOverlap(x + dX, y + dY, x1, y1, w1, h1)) {
		return 3;
	}
	else {
		return 0;
	}
}

void Element::pollEvents(SDL_Event &e) 
{

}

void Element::render()
{

}

void Element::move()
{

}
