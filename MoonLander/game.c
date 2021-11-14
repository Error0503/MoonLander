#include "game.h"

void RunGame() {
	extern SDL_Renderer* renderer;
	Terrain* t = newTerrain();

	Player* p = NULL;

	int isRunning = 1, forward = 0, backward = 1, i = 0;
	SDL_Event event;
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit(0);
			}
		}
		if (forward) {
			if (i == 50) {
				backward = 1;
				forward = 0;
				t->onScreen--;
				i = 0;
			} else {
				Update(p, t);
				t->onScreen++;
				SDL_Delay(150);
			}
		}
		if (backward) {
			if (i == 25) {
				backward = 0;
				forward = 1;
				t->onScreen++;
				i = 0;
			} else {
				Update(p, t);
				t->onScreen--;
				SDL_Delay(150);
			}
		}
		i++;
	}
}