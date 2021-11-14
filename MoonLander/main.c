#include "globals.h"
#include "UI/MainMenu.h"

SDL_Renderer* renderer;

int init(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		SDL_Window* window = SDL_CreateWindow("Moon Lander", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, 0, 0);
	} else {
		printf("[FATAL] Failed to initialize SDL\n");
		printf("%s", SDL_GetError());
		abort();
	}

	if (TTF_Init() != 0) {
		printf("[FATAL] Failed to initialize TTF\n");
		printf("%s", TTF_GetError());
		abort();
	}
}

// Write player data to file on exit
int onExit() {
	printf("Press Enter to exit!");
	getchar();
}

int main(int argc, char* args[]) {

	init();
	//atexit(onExit);

	MainMenu();

	/*
	Terrain* t = newTerrain();

	srand(time(NULL));

	for (int i = RESOLUTION; i < WIDTH; i += RESOLUTION) {
		AddPointL(t, i, rand() % 10);
		printf("x: %d\ty: %d\n", t->points[i/RESOLUTION].x, t->points[i/RESOLUTION].y);
	}

	Player* p = newPlayer("peace.png");

	Update(p, t);

	getchar();

	*/
	exit(0);
}