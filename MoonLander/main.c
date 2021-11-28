#include "main.h"

DataContainer init() {

	DataContainer dc = (DataContainer){NULL};

	// Initialize the savefile and if it exists read it's data
	dc.savefile = fopen("moonlander.sav", "r");
	if (dc.savefile != NULL) {
		for (int i = 0; i < 5; i++) {
			char buf[20];
			fgets(buf, 20, dc.savefile);
			dc.stageRecords[i] = strtol(buf, NULL, 10);
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
	dc.font = TTF_OpenFont("consola.ttf", 35);

	if (dc.font == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to open font", NULL);
		exit(1);
	}

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
	dc.shipTextureOff = SDL_CreateTextureFromSurface(dc.renderer, IMG_Load("ship_off.png"));
	if (dc.shipTextureOff == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to load player texture!", NULL);
		exit(1);
	}

	dc.shipTextureOn = SDL_CreateTextureFromSurface(dc.renderer, IMG_Load("ship_on.png"));
	if (dc.shipTextureOn == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Failed to load player texture!", NULL);
		exit(1);
	}

	dc.background = SDL_CreateTextureFromSurface(dc.renderer, IMG_Load("background.png"));
	if (dc.background == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to load background texture!", NULL);
	}

	dc.back = SDL_CreateTextureFromSurface(dc.renderer, IMG_Load("back.png"));
	if (dc.back == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to load back texture!", NULL);
	}

	return dc;
}

int main(int argc, char* argv) {

	DataContainer dc;
	dc = init();

	Menu(&dc);

	for (int i = 0; i < 5; i++) {
		fprintf(dc.savefile, "%d\n", dc.stageRecords[i]);
	}

	SDL_DestroyTexture(dc.background);
	SDL_DestroyTexture(dc.shipTextureOff);
	SDL_DestroyTexture(dc.shipTextureOn);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}