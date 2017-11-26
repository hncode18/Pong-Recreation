#pragma once

#include <string>
#include <SDL.h>
#include <vector>
#include "Element.h"
#include "Paddle.h"
#include "Ball.h"

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

        bool init();
};
