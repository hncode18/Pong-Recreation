#include "Paddle.h"
#include <iostream>


Paddle::Paddle(float xPos, int p)
{
	x = xPos;
	y = 300.0f;
	width = 10;
	height = 34;
	velX = 0.0f;
	velY = 0.0f;
	sprite = { 72, 234, width, height };
	player = p;
}
Paddle::~Paddle()
{

}

void Paddle::move()
{
	float dist = velY * ((float) (SDL_GetTicks() - time)) / 1000.0f;
	if (y + dist > 600 - height) {
		y = 600.0f - height;
	}
	else if (y + dist < 0) {
		y = 0.0f;
	}
	else {
		y += dist;
	}
	time = SDL_GetTicks();
}

void Paddle::pollEvents(SDL_Event &e)
{
	if (player == 2) {
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				velY = -paddleSpeed;
				time = SDL_GetTicks();
				break;
			case SDLK_DOWN:
				velY = paddleSpeed;
				time = SDL_GetTicks();
				break;
			}
		}
		else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
			if (e.key.keysym.sym == SDLK_UP && velY < 0) {
				velY = 0;
			}
			else if (e.key.keysym.sym == SDLK_DOWN && velY > 0) {
				velY = 0;
			}
		}
	}
	else if (player == 1) {
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_w:
				velY = -paddleSpeed;
				time = SDL_GetTicks();
				break;
			case SDLK_s:
				velY = paddleSpeed;
				time = SDL_GetTicks();
				break;
			}
		}
		else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
			if (e.key.keysym.sym == SDLK_w && velY < 0) {
				velY = 0;
			}
			else if (e.key.keysym.sym == SDLK_s && velY > 0) {
				velY = 0;
			}
		}
	}
}

void Paddle::render()
{
	spriteSheet.render((int) x, (int) y, &sprite);
}
