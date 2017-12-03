#include "Score.h"

Score::Score(int p)
{
	spriteSheet.loadFile("res/pong.png");
	player = p;
	score = 0;
}
Score::~Score()
{
	spriteSheet.free();
}

void Score::render()
{
	if (score <= 10) {
		switch (score) {
			case 0:
				clip1 = { 10, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 1:
				clip1 = { 58, 8, 8, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 2:
				clip1 = { 74, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 3:
				clip1 = { 122, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 4:
				clip1 = { 168, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 5:
				clip1 = { 216, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 6:
				clip1 = { 262, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 7:
				clip1 = { 310, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 8:
				clip1 = { 358, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 9:
				clip1 = { 404, 8, 40, 78 };
				clip2 = { 0, 0, 0, 0 };
				break;
			case 10:
				clip1 = { 58, 8, 8, 78 };
				clip2 = { 10, 8, 40, 78 };
				break;
		}
	}

	if (player == 1) {
		if (clip1.w != 0) {
			if (clip2.w == 0) {
				spriteSheet.render(340, 5, &clip1);
			}
			else {
				spriteSheet.render(340, 5, &clip2);
				spriteSheet.render(295, 5, &clip1);
			}
		}
	}
	else if (player == 2) {
		if (clip1.w != 0) {
			if (clip2.w == 0) {
				spriteSheet.render(420, 5, &clip1);
			}
			else {
				spriteSheet.render(465, 5, &clip2);
				spriteSheet.render(420, 5, &clip1);
			}
		}
	}
}