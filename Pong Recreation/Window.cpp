#include "Window.h"
#include <iostream>
#include <SDL_image.h>

SDL_Renderer *Window::render = nullptr;

Window::Window (const std::string &t, int w, int h) :
    title(t), width(w), height(h)
{
    // check if initialization failed
    if (!init()) {
        closed = true;
    }

	p1 = new Paddle(50, 1);
	p2 = new Paddle(740, 2);
	b = new Ball();
}
Window::~Window ()
{
	delete p1;
	delete p2;
	delete b;
	p1 = nullptr;
	p2 = nullptr;
	b = nullptr;

    SDL_DestroyWindow(window);
    SDL_Quit();
}

// initialize window
bool Window::init ()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Fail to initialize SDL" << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (window == nullptr) {
        std::cerr << "Fail to create window" << std::endl;
        return false;
    }

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (render == nullptr) {
		std::cerr << "Fail to create renderer" << std::endl;
		return false;
	}

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Fail to load SDL_image\n";
		return false;
	}

    return true;
}
// check events of windows
void Window::pollEvents ()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                closed = true;
                break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					closed = true;
				}
				break;
            default:
                break;
        }
		p1->pollEvents(event);
		p2->pollEvents(event);
    }

	p1->move();
	p2->move();
	b->move(p1->x, p1->y, p1->width, p1->height, p2->x, p2->y, p2->width, p2->height);
}

void Window::clear()
{
	p1->render();
	p2->render();
	b->render();

	SDL_RenderPresent(render);
	SDL_SetRenderDrawColor(render, 81, 137, 226, 255);
	SDL_RenderClear(render);   
}
