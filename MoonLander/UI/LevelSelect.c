#include "LevelSelect.h"

void LevelSelect(void) {

	extern SDL_Renderer* renderer;

	SetRenderDrawColour(renderer, DARK_GREY);
	SDL_RenderClear(renderer);

	SDL_Rect testStageButton = (SDL_Rect){400, 250, 400, 100};
	SDL_Rect testStageText = (SDL_Rect){500, 265, 200, 80};

	drawFilledRect(testStageButton, GREY);

	RenderText("Test", &testStageText, 150);

	SDL_RenderPresent(renderer);

	int isRunning = 1;
	SDL_Event event;

	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (testStageButton.x <= event.motion.x && event.motion.x <= testStageButton.x + testStageButton.w && testStageButton.y <= event.motion.y && event.motion.y <= testStageButton.y + testStageButton.h) {
					RunGame();
				}
			} else if (event.type == SDL_QUIT) {
				isRunning = 0;
			}
		}
	}
	return;
}