#include <iostream>
#include "Window.h"
#include "Paddle.h"
#include <vector>

int main(int argc, char * argv[])
{
	Window w("Pong", 800, 600);


	while (!w.isClose()) {
		w.pollEvents();
		w.clear();
	}

	return 0;
}