#include "MainMenu.h"

void MainMenu(void) {

	extern SDL_Renderer* renderer;

	SetRenderDrawColour(renderer, DARK_GREY);
	SDL_RenderClear(renderer);

	SDL_Rect playButton = (SDL_Rect){400,		250,	400,	100};
	SDL_Rect settingsButton = (SDL_Rect){400,		400,	400,	100};
	SDL_Rect exitButton = (SDL_Rect){400,		550,	400,	100};

	SDL_Rect playText = (SDL_Rect){500,		265,	200,	80};
	SDL_Rect settingsText = (SDL_Rect){410,		415,	380,	80};
	SDL_Rect exitText = (SDL_Rect){500,		565,	200,	80};

	drawFilledRect(playButton, GREY);
	drawFilledRect(settingsButton, GREY);
	drawFilledRect(exitButton, GREY);

	RenderText("Moon Lander", &((SDL_Rect) { 300, 0, 600, 200 }), 100);
	RenderText("Play", &playText, 150);
	RenderText("Settings", &settingsText, 150);
	RenderText("Exit", &exitText, 150);

	SDL_RenderPresent(renderer);

	int isRunning = 1;
	int nextState = 0; // >:(
	SDL_Event event;

	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (playButton.x <= event.motion.x && event.motion.x <= playButton.x + playButton.w && playButton.y <= event.motion.y && event.motion.y <= playButton.y + playButton.h) {
					LevelSelect();
				} else if (settingsButton.x <= event.motion.x && event.motion.x <= settingsButton.x + settingsButton.w && settingsButton.y <= event.motion.y && event.motion.y <= settingsButton.y + settingsButton.h) {
					nextState = 2;
				} else if (exitButton.x <= event.motion.x && event.motion.x <= exitButton.x + exitButton.w && exitButton.y <= event.motion.y && event.motion.y <= exitButton.y + exitButton.h) {
					exit(0);
				} else {
					nextState = 0;
				}
			} else if (event.type == SDL_QUIT) {
				isRunning = 0;
			}
		}
	}
	return;
}