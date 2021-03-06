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
	divider = new Texture();
	divider->loadFile("res/pong.png");
	p1Score = new Score(1);
	p2Score = new Score(2);
}
Window::~Window ()
{
	delete p1;
	delete p2;
	delete b;
	delete divider;
	delete p1Score;
	delete p2Score;
	p1 = nullptr;
	p2 = nullptr;
	b = nullptr;
	divider = nullptr;
	p1Score = nullptr;
	p2Score = nullptr;

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
				if (event.key.keysym.sym == SDLK_RETURN) {
					if ((b->x < 0 || b->x > 800) && (p1Score->score >= 10 || p2Score->score >= 10)) {
						
						p1Score->score = 0;
						p2Score->score = 0;
						b->reset();
					}
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

	if (b->x < 0) {
		if (p2Score->score < 9) {
			p2Score->score++;
			b->reset();
		}
		else {
			p2Score->score++;
		}
	}
	else if (b->x > 800) {
		if (p1Score->score < 9) {
			p1Score->score++;
			b->reset();
		}
		else {
			p1Score->score++;
		}
	}

}

void Window::clear()
{
	SDL_Rect divClip = { 462, 0, 2, 600 };
	p1->render();
	p2->render();
	b->render();
	divider->render(399, 0, &divClip);
	p1Score->render();
	p2Score->render();

	SDL_RenderPresent(render);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);   
}
