#pragma once

#include <string>
#include <SDL.h>
#include <vector>
#include "Element.h"
#include "Paddle.h"
#include "Ball.h"
#include"Score.h"

class Window
{
    public:
        Window(const std::string &t, int w, int h);
        ~Window();
        inline bool isClose() const {return closed;};
		void pollEvents();
		void clear();
		
		static SDL_Renderer *render;

    private:
        std::string title;
        int width = 800;
        int height = 600;
        bool closed = false;
        SDL_Window *window = nullptr;

		Paddle *p1 = nullptr;
		Paddle *p2 = nullptr;
		Ball *b = nullptr;
		Texture *divider = nullptr;
		Score *p1Score = nullptr;
		Score *p2Score = nullptr;

        bool init();
};
