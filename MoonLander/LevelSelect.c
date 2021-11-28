#include "LevelSelect.h"

void LevelSelect(DataContainer* dc) {

	SDL_SetRenderDrawColor(dc->renderer, 0, 0, 0, 255);
	SDL_RenderClear(dc->renderer);

	SDL_Rect moonStageButton = (SDL_Rect){dc->width / 2 - 100, 200, 200, 80};
	SDL_Rect moonStageText = (SDL_Rect){820, 210, 150, 70};
	SDL_Rect moonTimeText = (SDL_Rect){820, 210, 150, 70};

	SDL_Rect marsStageButton = (SDL_Rect){dc->width / 2 - 100, 300, 200, 80};
	SDL_Rect marsStageText = (SDL_Rect){820, 310, 150, 70};
	SDL_Rect marsTimeText = (SDL_Rect){820, 310, 150, 70};

	SDL_Rect uranusStageButton = (SDL_Rect){dc->width / 2 - 100, 400, 200, 80};
	SDL_Rect uranusStageText = (SDL_Rect){820, 410, 220, 70};
	SDL_Rect uranusTimeText = (SDL_Rect){820, 410, 220, 70};

	SDL_Rect earthStageButton = (SDL_Rect){dc->width / 2 - 100, 500, 200, 80};
	SDL_Rect earthStageText = (SDL_Rect){820, 510, 150, 70};
	SDL_Rect earthTimeText = (SDL_Rect){820, 510, 150, 70};

	SDL_Rect jupiterStageButton = (SDL_Rect){dc->width / 2 - 100, 600, 200, 80};
	SDL_Rect jupiterStageText = (SDL_Rect){820, 610, 150, 70};
	SDL_Rect jupiterTimeText = (SDL_Rect){820, 610, 150, 70};

	SDL_Rect customStageButton = (SDL_Rect){dc->width / 2 - 100, 700, 200, 80};
	SDL_Rect customStageText = (SDL_Rect){820, 710, 150, 70};
	SDL_Rect customTimeText = (SDL_Rect){820, 710, 150, 70};

	char moonTime[9];
	sprintf(moonTime, "%.2d:%.2d:%.2d", (dc->obj.totalTime / 60000) % 60, (dc->obj.totalTime / 1000) % 60);
	SDL_Surface* moonTimeTextSurface = TTF_RenderUTF8_Blended(dc->font, asdasdads, (SDL_Color) { 0, 0, 0, 255 });

	SDL_Surface* time_text = TTF_RenderText_Solid(dc->font, time, (SDL_Color) { 0, 255, 0, 255 });							// 

	SDL_Texture* vx_texture = SDL_CreateTextureFromSurface(dc->renderer, vx_text);											//
	SDL_Texture* vy_texture = SDL_CreateTextureFromSurface(dc->renderer, vy_text);											// Text textures
	SDL_Texture* time_texture = SDL_CreateTextureFromSurface(dc->renderer, time_text);										//

	SDL_RenderCopy(dc->renderer, vx_texture, NULL, &(SDL_Rect){0, 0, vx_text->w, vx_text->h});

	char vx[13];																											//
	sprintf(vx, "x vel: %.0f", dc->obj.vx);


	SDL_SetRenderDrawColor(dc->renderer, 255, 255, 255, 255);

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
				// gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
				if (moonStageButton.x <= event.motion.x && event.motion.x <= moonStageButton.x + moonStageButton.w && moonStageButton.y <= event.motion.y && event.motion.y <= moonStageButton.y + moonStageButton.h) {
					StartGame(dc, (GameInitData) { 1.7, 1.25, 10, 150, 400, 10, 3 });	// Moon
				} else if (marsStageButton.x <= event.motion.x && event.motion.x <= marsStageButton.x + marsStageButton.w && marsStageButton.y <= event.motion.y && event.motion.y <= marsStageButton.y + marsStageButton.h) {
					StartGame(dc, (GameInitData) { 3.7, 1.25, 10, 150, 400, 10, 3 });	// Mars
				} else if (uranusStageButton.x <= event.motion.x && event.motion.x <= uranusStageButton.x + uranusStageButton.w && uranusStageButton.y <= event.motion.y && event.motion.y <= uranusStageButton.y + uranusStageButton.h) {
					StartGame(dc, (GameInitData) { 9.0, 1.25, 10, 150, 400, 10, 3 });	// Uranus
				} else if (earthStageButton.x <= event.motion.x && event.motion.x <= earthStageButton.x + earthStageButton.w && earthStageButton.y <= event.motion.y && event.motion.y <= earthStageButton.y + earthStageButton.h) {
					StartGame(dc, (GameInitData) { 10, 1.25, 10, 150, 400, 10, 3 });	// Earth
				} else if (jupiterStageButton.x <= event.motion.x && event.motion.x <= jupiterStageButton.x + jupiterStageButton.w && jupiterStageButton.y <= event.motion.y && event.motion.y <= jupiterStageButton.y + jupiterStageButton.h) {
					StartGame(dc, (GameInitData) { 24.7, 1.25, 10, 150, 400, 10, 3 });	// Jupiter
				} else if (customStageButton.x <= event.motion.x && event.motion.x <= customStageButton.x + customStageButton.w && customStageButton.y <= event.motion.y && event.motion.y <= customStageButton.y + customStageButton.h) {
					StageCustomizer(dc);												// Custom
				} else if (0 /* Back button */) {
					return;
				}
			} else if (event.type == SDL_QUIT) {
				exit(0);
			}
		}
	}
}