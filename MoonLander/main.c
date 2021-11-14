#include "globals.h"
#include "UI/MainMenu.h"
#include "debug.h"

SDL_Renderer* renderer;

void init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		SDL_Window* window = SDL_CreateWindow("Moon Lander", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, 0, 0);
	} else {
		Log("Failed to initialize SDL\n", 4);
		Log(SDL_GetError(), 3);
		abort();
	}

	if (TTF_Init() != 0) {
		Log("Failed to initialize TTF\n", 4);
		Log(TTF_GetError(), 3);
		abort();
	}
	srand(time(NULL));
}

// Write player data to file on exit
int onExit() {
	FILE* savefile = fopen("moonlander.sav", "w");
	if (savefile != NULL) {
		fprintf(savefile, "Saved data here...");
		fclose(savefile);
	} else {
		abort();
	}
}

int main(int argc, char* args[]) {

	init();
	atexit(onExit);

	MainMenu();

	exit(0);
}