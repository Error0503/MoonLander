#include "main.h"

DataContainer init() {

	DataContainer dc = (DataContainer){NULL};
	dc.controls.up = SDLK_w;
	dc.controls.down = SDLK_s;
	dc.controls.left = SDLK_a;
	dc.controls.right = SDLK_d;
	dc.controls.exit = SDLK_ESCAPE;

	// Create the player


	// Initialize the savefile and if it exists read it's data
	dc.savefile = fopen("moonlander.sav", "r");
	if (dc.savefile != NULL) {
		char buffer[11];
		size_t red;
		while ((red = fread(buffer, sizeof(char), 10, dc.savefile) > 0)) {
			// Read saved leaderboard times...
		}
	}
	dc.savefile = fopen("moonlander.sav", "w");


	// Initialize SDL and it's subcomponents
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to initialize SDL!", NULL);
		exit(1);
	}

	if (TTF_Init() != 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to initialize TTF!", NULL);
		exit(1);
	}

	// Import TTF font for later use
	dc.font = TTF_OpenFont("consola.ttf", 24);

	dc.width = 1440;
	dc.height = 810;

	// Create the necessary components for display
	SDL_Window* window = SDL_CreateWindow("Moon Lander", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dc.width, dc.height, SDL_WINDOW_SHOWN);
	dc.renderer = SDL_CreateRenderer(window, -1, 0);

	if (dc.renderer == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to create renderer!", NULL);
		exit(1);
	}

	SDL_SetRenderDrawColor(dc.renderer, 0, 0, 0, 255);
	SDL_RenderClear(dc.renderer);

	// Import the player texture
	dc.playerTexture = SDL_CreateTextureFromSurface(dc.renderer, IMG_Load("craft.png"));
	if (dc.playerTexture == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to load player texture!", NULL);
		exit(1);
	}

	return dc;
}

int main(int argc, char* argv) {

	DataContainer dc;
	dc = init();
	GameInitData init = (GameInitData){0};
	StartGame(&dc, init);

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "End", "Press ok to quit", NULL);
}