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
bool Element::checkCollision(float x1, float y1, int w1, int h1)
{
	int topA, topB;
	int bottomA, bottomB;
	int rightA, rightB;
	int leftA, leftB;

	topA = (int) y;
	topB = (int) y1;
	bottomA = ((int) y) + height;
	bottomB = ((int) y1) + h1;
	leftA = (int) x;
	leftB = (int) x1;
	rightA = ((int) x) + width;
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

void Element::pollEvents(SDL_Event &e) 
{

}

void Element::render()
{

}

void Element::move()
{

}
