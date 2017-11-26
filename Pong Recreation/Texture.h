#pragma once

#include <SDL_image.h>
#include <SDL.h>
#include <string>

class Texture
{
	public:
		Texture();
		~Texture();

		bool loadFile(std::string path);

		void free();

		void render(int x, int y, SDL_Rect *clip);

		inline int getWidth() { return imgW; };
		inline int getHeight() { return imgH; };

	private:
		SDL_Texture *t;

		int imgW;
		int imgH;
};