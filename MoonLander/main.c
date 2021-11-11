#include "MainMenu.h"

SDL_Renderer* renderer;
int WIDTH = 1200;
int HEIGHT = 800;

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

int onExit() {
	printf("Press Enter to exit!");
	getchar();
}

int main(int argc, char* args[]) {

	init();
	//atexit(onExit);
	
	MainMenu();

	exit(0);
}