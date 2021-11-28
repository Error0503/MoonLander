#include "StageCustomizer.h"

void StageCustomizer(DataContainer* dc) {

	SDL_SetRenderDrawColor(dc->renderer, 0, 0, 0, 255);
	SDL_RenderClear(dc->renderer);

	SDL_Rect testStageButton = (SDL_Rect){810, 100, 200, 80};
	SDL_Rect testStageText = (SDL_Rect){820, 110, 150, 70};

	SDL_Rect moonStageButton = (SDL_Rect){810, 200, 200, 80};
	SDL_Rect moonStageText = (SDL_Rect){820, 210, 150, 70};

	SDL_Rect marsStageButton = (SDL_Rect){810, 300, 200, 80};
	SDL_Rect marsStageText = (SDL_Rect){820, 310, 150, 70};

	SDL_Rect uranusStageButton = (SDL_Rect){810, 400, 200, 80};
	SDL_Rect uranusStageText = (SDL_Rect){820, 410, 220, 70};

	SDL_Rect earthStageButton = (SDL_Rect){810, 500, 200, 80};
	SDL_Rect earthStageText = (SDL_Rect){820, 510, 150, 70};

	SDL_Rect jupiterStageButton = (SDL_Rect){810, 600, 200, 80};
	SDL_Rect jupiterStageText = (SDL_Rect){820, 610, 150, 70};

	SDL_Rect customStageButton = (SDL_Rect){810, 700, 200, 80};
	SDL_Rect customStageText = (SDL_Rect){820, 710, 150, 70};

	SDL_SetRenderDrawColor(dc->renderer, 255, 255, 255, 255);

	SDL_RenderFillRect(dc->renderer, &testStageButton);
	SDL_RenderFillRect(dc->renderer, &moonStageButton);
	SDL_RenderFillRect(dc->renderer, &marsStageButton);
	SDL_RenderFillRect(dc->renderer, &uranusStageButton);
	SDL_RenderFillRect(dc->renderer, &earthStageButton);
	SDL_RenderFillRect(dc->renderer, &jupiterStageButton);
	SDL_RenderFillRect(dc->renderer, &customStageButton);

	SDL_RenderPresent(dc->renderer);

	SDL_Event event;
	while (1) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (testStageButton.x <= event.motion.x && event.motion.x <= testStageButton.x + testStageButton.w && testStageButton.y <= event.motion.y && event.motion.y <= testStageButton.y + testStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (testStageButton.x <= event.motion.x && event.motion.x <= testStageButton.x + testStageButton.w && testStageButton.y <= event.motion.y && event.motion.y <= testStageButton.y + testStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (moonStageButton.x <= event.motion.x && event.motion.x <= moonStageButton.x + moonStageButton.w && moonStageButton.y <= event.motion.y && event.motion.y <= moonStageButton.y + moonStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (marsStageButton.x <= event.motion.x && event.motion.x <= marsStageButton.x + marsStageButton.w && marsStageButton.y <= event.motion.y && event.motion.y <= marsStageButton.y + marsStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (uranusStageButton.x <= event.motion.x && event.motion.x <= uranusStageButton.x + uranusStageButton.w && uranusStageButton.y <= event.motion.y && event.motion.y <= uranusStageButton.y + uranusStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (earthStageButton.x <= event.motion.x && event.motion.x <= earthStageButton.x + earthStageButton.w && earthStageButton.y <= event.motion.y && event.motion.y <= earthStageButton.y + earthStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (jupiterStageButton.x <= event.motion.x && event.motion.x <= jupiterStageButton.x + jupiterStageButton.w && jupiterStageButton.y <= event.motion.y && event.motion.y <= jupiterStageButton.y + jupiterStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 }); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				} else if (customStageButton.x <= event.motion.x && event.motion.x <= customStageButton.x + customStageButton.w && customStageButton.y <= event.motion.y && event.motion.y <= customStageButton.y + customStageButton.h) {
					StageCustomizer(dc);
				}
			} else if (event.type == SDL_QUIT) {
				exit(0);
			}
		}
	}
}
