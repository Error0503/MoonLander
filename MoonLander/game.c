#include "game.h"

void RunGame() {
	extern SDL_Renderer* renderer;
	ClearWindow(renderer, BLACK);
	Terrain* t = newTerrain();

	srand(time(NULL));
	for (int i = 0; i <= WIDTH * 2; i += RESOLUTION) {
		AddPoint(t, HEIGHT - (rand() % 100));
	}

	Player* p = NULL;

	int forward = 1, backward = 0;
	while (1) {
		while (forward) {
			if (Update(p, t) != 0) {
				backward = 1;
				forward = 0;
				t->onScreen--;
			} else {
				t->onScreen++;
				SDL_Delay(150);
			}
		}
		while (backward) {
			if (Update(p, t) != 0) {
				backward = 0;
				forward = 1;
				t->onScreen++;
			} else {
				t->onScreen--;
				SDL_Delay(150);
			}
		}
	}
}