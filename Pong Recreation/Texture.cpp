#include "Texture.h"
#include "Window.h"
#include <iostream>

Texture::Texture()
{
	t = nullptr;
	imgW = 0;
	imgH = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFile(std::string path)
{
	free();

	SDL_Texture *newT = nullptr;

	SDL_Surface *loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == nullptr) {
		std::cerr << "unable to load surface\n";
		return false;
	}

	newT = SDL_CreateTextureFromSurface(Window::render, loadedSurface);

	if (newT == nullptr) {
		std::cerr << "Unable to create texture\n";
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	imgW = loadedSurface->w;
	imgH = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

	t = newT;

	return true;
}

void Texture::free()
{
	if (t == nullptr) {
		SDL_DestroyTexture(t);
		t = nullptr;
		imgW = 0;
		imgH = 0;
	}
}

void Texture::render(int x, int y, SDL_Rect *clip)
{
	SDL_Rect renderRect = { x, y, imgW, imgH };

	if (clip != nullptr) {
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}

	SDL_RenderCopy(Window::render, t, clip, &renderRect);
}
