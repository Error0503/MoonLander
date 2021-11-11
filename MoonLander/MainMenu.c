#include "MainMenu.h"

void MainMenu(void) {

	extern SDL_Renderer* renderer;

	SetRenderDrawColour(renderer, DARK_GREY);
	SDL_RenderClear(renderer);

	SDL_Rect playButton = (SDL_Rect){0,		0,		50,		50};
	SDL_Rect settingsButton = (SDL_Rect){100,	100,	50,		50};
	SDL_Rect exitButton = (SDL_Rect){200,	200,	50,		50};

	drawFilledRect(playButton, GREY);
	drawFilledRect(settingsButton, GREY);
	drawFilledRect(exitButton, GREY);

	text("Hello!");

	SDL_RenderPresent(renderer);

	int isRunning = 1;
	int nextState = 0; // >:(
	SDL_Event event;

	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				printf("event.motion.x: %d\nevent.motion.y: %d\nplayButton.x: %d\nplayButton.w: %d\nplayButton.x: %d\nplayButton.h: %d\n", event.motion.x, event.motion.y, playButton.x, playButton.w, playButton.x, playButton.h);
				if (playButton.x <= event.motion.x && event.motion.x <= playButton.x + playButton.w && playButton.y <= event.motion.y && event.motion.y <= playButton.y + playButton.h) {
					nextState = 1;
				} else if (settingsButton.x <= event.motion.x && event.motion.x <= settingsButton.x + settingsButton.w && settingsButton.y <= event.motion.y && event.motion.y <= settingsButton.y + settingsButton.h) {
					nextState = 2;
				} else if (exitButton.x <= event.motion.x && event.motion.x <= exitButton.x + exitButton.w && exitButton.y <= event.motion.y && event.motion.y <= exitButton.y + exitButton.h) {
					nextState = 3;
				} else {
					nextState = 0;
				}
				printf("nextState: %d\n\n", nextState);
			} else if (event.type == SDL_QUIT) {
				isRunning = 0;
			}
		}
	}

	return nextState;
}