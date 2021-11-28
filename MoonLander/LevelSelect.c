#include "LevelSelect.h"

void LevelSelect(DataContainer* dc) {

	SDL_Event event;
	int run = 1;
	while (run) {
		SDL_RenderCopy(dc->renderer, dc->background, NULL, NULL);

		SDL_Rect moonStageButton = (SDL_Rect){dc->width / 2 - 100, 200, 200, 80};
		SDL_Rect marsStageButton = (SDL_Rect){dc->width / 2 - 100, 300, 200, 80};
		SDL_Rect uranusStageButton = (SDL_Rect){dc->width / 2 - 100, 400, 200, 80};
		SDL_Rect earthStageButton = (SDL_Rect){dc->width / 2 - 100, 500, 200, 80};
		SDL_Rect jupiterStageButton = (SDL_Rect){dc->width / 2 - 100, 600, 200, 80};
		SDL_Rect customStageButton = (SDL_Rect){dc->width / 2 - 100, 700, 200, 80};
		SDL_Rect backButton = (SDL_Rect){10, dc->height - 60, 100, 50};

		SDL_SetRenderDrawColor(dc->renderer, 158, 158, 158, 255);

		SDL_RenderFillRect(dc->renderer, &moonStageButton);
		SDL_RenderFillRect(dc->renderer, &marsStageButton);
		SDL_RenderFillRect(dc->renderer, &uranusStageButton);
		SDL_RenderFillRect(dc->renderer, &earthStageButton);
		SDL_RenderFillRect(dc->renderer, &jupiterStageButton);
		SDL_SetRenderDrawColor(dc->renderer, 45, 45, 48, 255);
		SDL_RenderFillRect(dc->renderer, &customStageButton);
		SDL_RenderCopy(dc->renderer, dc->back, NULL, &backButton);

		SDL_Surface* moonTextSurface = TTF_RenderText_Blended(dc->font, "Moon", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* marsTextSurface = TTF_RenderText_Blended(dc->font, "Mars", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* uranusTextSurface = TTF_RenderText_Blended(dc->font, "Uranus", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* earthTextSurface = TTF_RenderText_Blended(dc->font, "Earth", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* jupiterTextSurface = TTF_RenderText_Blended(dc->font, "Jupiter", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* customTextSurface = TTF_RenderText_Blended(dc->font, "Custom", (SDL_Color) { 97, 97, 108, 255 });

		SDL_Texture* moonTexture = SDL_CreateTextureFromSurface(dc->renderer, moonTextSurface);
		SDL_Texture* marsTexture = SDL_CreateTextureFromSurface(dc->renderer, marsTextSurface);
		SDL_Texture* uranusTexture = SDL_CreateTextureFromSurface(dc->renderer, uranusTextSurface);
		SDL_Texture* earthTexture = SDL_CreateTextureFromSurface(dc->renderer, earthTextSurface);
		SDL_Texture* jupiterTexture = SDL_CreateTextureFromSurface(dc->renderer, jupiterTextSurface);
		SDL_Texture* customTexture = SDL_CreateTextureFromSurface(dc->renderer, customTextSurface);

		SDL_RenderCopy(dc->renderer, moonTexture, NULL, &(SDL_Rect){moonStageButton.x + moonStageButton.w / 2 - moonTextSurface->w / 2, moonStageButton.y + moonStageButton.h / 2 - moonTextSurface->h / 2, moonTextSurface->w, moonTextSurface->h});
		SDL_RenderCopy(dc->renderer, marsTexture, NULL, &(SDL_Rect){marsStageButton.x + marsStageButton.w / 2 - marsTextSurface->w / 2, marsStageButton.y + marsStageButton.h / 2 - marsTextSurface->h / 2, marsTextSurface->w, marsTextSurface->h});
		SDL_RenderCopy(dc->renderer, uranusTexture, NULL, &(SDL_Rect){uranusStageButton.x + uranusStageButton.w / 2 - uranusTextSurface->w / 2, uranusStageButton.y + uranusStageButton.h / 2 - uranusTextSurface->h / 2, uranusTextSurface->w, uranusTextSurface->h});
		SDL_RenderCopy(dc->renderer, earthTexture, NULL, &(SDL_Rect){earthStageButton.x + earthStageButton.w / 2 - earthTextSurface->w / 2, earthStageButton.y + earthStageButton.h / 2 - earthTextSurface->h / 2, earthTextSurface->w, earthTextSurface->h});
		SDL_RenderCopy(dc->renderer, jupiterTexture, NULL, &(SDL_Rect){jupiterStageButton.x + jupiterStageButton.w / 2 - jupiterTextSurface->w / 2, jupiterStageButton.y + jupiterStageButton.h / 2 - jupiterTextSurface->h / 2, jupiterTextSurface->w, jupiterTextSurface->h});
		SDL_RenderCopy(dc->renderer, customTexture, NULL, &(SDL_Rect){customStageButton.x + customStageButton.w / 2 - customTextSurface->w / 2, customStageButton.y + customStageButton.h / 2 - customTextSurface->h / 2, customTextSurface->w, customTextSurface->h});

		SDL_FreeSurface(moonTextSurface);
		SDL_FreeSurface(marsTextSurface);
		SDL_FreeSurface(uranusTextSurface);
		SDL_FreeSurface(earthTextSurface);
		SDL_FreeSurface(jupiterTextSurface);
		SDL_FreeSurface(customTextSurface);
		SDL_DestroyTexture(moonTexture);
		SDL_DestroyTexture(marsTexture);
		SDL_DestroyTexture(uranusTexture);
		SDL_DestroyTexture(earthTexture);
		SDL_DestroyTexture(jupiterTexture);
		SDL_DestroyTexture(customTexture);

		char moonTime[6];
		sprintf(moonTime, "%.2d:%.2d", (dc->stageRecords[0] / 60000) % 60, (dc->stageRecords[0] / 1000) % 60);
		char marsTime[6];
		sprintf(marsTime, "%.2d:%.2d", (dc->stageRecords[0] / 60000) % 60, (dc->stageRecords[1] / 1000) % 60);
		char uranusTime[6];
		sprintf(uranusTime, "%.2d:%.2d", (dc->stageRecords[0] / 60000) % 60, (dc->stageRecords[2] / 1000) % 60);
		char earthTime[6];
		sprintf(earthTime, "%.2d:%.2d", (dc->stageRecords[0] / 60000) % 60, (dc->stageRecords[3] / 1000) % 60);
		char jupiterTime[6];
		sprintf(jupiterTime, "%.2d:%.2d", (dc->stageRecords[0] / 60000) % 60, (dc->stageRecords[4] / 1000) % 60);

		SDL_Surface* moonTimeTextSurface = TTF_RenderText_Blended(dc->font, (dc->stageRecords[0] != 0) ? moonTime : " ", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* marsTimeTextSurface = TTF_RenderText_Blended(dc->font, (dc->stageRecords[1] != 0) ? marsTime : " ", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* uranusTimeTextSurface = TTF_RenderText_Blended(dc->font, (dc->stageRecords[2] != 0) ? uranusTime : " ", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* earthTimeTextSurface = TTF_RenderText_Blended(dc->font, (dc->stageRecords[3] != 0) ? earthTime : " ", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Surface* jupiterTimeTextSurface = TTF_RenderText_Blended(dc->font, (dc->stageRecords[4] != 0) ? jupiterTime : " ", (SDL_Color) { 255, 255, 255, 255 });

		SDL_Texture* moonTimeTexture = SDL_CreateTextureFromSurface(dc->renderer, moonTimeTextSurface);
		SDL_Texture* marsTimeTexture = SDL_CreateTextureFromSurface(dc->renderer, marsTimeTextSurface);
		SDL_Texture* uranusTimeTexture = SDL_CreateTextureFromSurface(dc->renderer, uranusTimeTextSurface);
		SDL_Texture* earthTimeTexture = SDL_CreateTextureFromSurface(dc->renderer, earthTimeTextSurface);
		SDL_Texture* jupiterTimeTexture = SDL_CreateTextureFromSurface(dc->renderer, jupiterTimeTextSurface);

		SDL_RenderCopy(dc->renderer, moonTimeTexture, NULL, &(SDL_Rect){moonStageButton.x + moonStageButton.w + moonTimeTextSurface->w + 20, moonStageButton.y + moonStageButton.h / 2 - moonTimeTextSurface->h / 2, moonTimeTextSurface->w, moonTimeTextSurface->h});
		SDL_RenderCopy(dc->renderer, marsTimeTexture, NULL, &(SDL_Rect){marsStageButton.x + marsStageButton.w + marsTimeTextSurface->w + 20, marsStageButton.y + marsStageButton.h / 2 - marsTimeTextSurface->h / 2, marsTimeTextSurface->w, marsTimeTextSurface->h});
		SDL_RenderCopy(dc->renderer, uranusTimeTexture, NULL, &(SDL_Rect){uranusStageButton.x + uranusStageButton.w + uranusTimeTextSurface->w + 20, uranusStageButton.y + uranusStageButton.h / 2 - uranusTimeTextSurface->h / 2, uranusTimeTextSurface->w, uranusTimeTextSurface->h});
		SDL_RenderCopy(dc->renderer, earthTimeTexture, NULL, &(SDL_Rect){earthStageButton.x + earthStageButton.w + earthTimeTextSurface->w + 20, earthStageButton.y + earthStageButton.h / 2 - earthTimeTextSurface->h / 2, earthTimeTextSurface->w, earthTimeTextSurface->h});
		SDL_RenderCopy(dc->renderer, jupiterTimeTexture, NULL, &(SDL_Rect){jupiterStageButton.x + jupiterStageButton.w + jupiterTimeTextSurface->w + 20, jupiterStageButton.y + jupiterStageButton.h / 2 - jupiterTimeTextSurface->h / 2, jupiterTimeTextSurface->w, jupiterTimeTextSurface->h});

		SDL_FreeSurface(moonTimeTextSurface);
		SDL_FreeSurface(marsTimeTextSurface);
		SDL_FreeSurface(uranusTimeTextSurface);
		SDL_FreeSurface(earthTimeTextSurface);
		SDL_FreeSurface(jupiterTimeTextSurface);
		SDL_DestroyTexture(moonTimeTexture);
		SDL_DestroyTexture(marsTimeTexture);
		SDL_DestroyTexture(uranusTimeTexture);
		SDL_DestroyTexture(earthTimeTexture);
		SDL_DestroyTexture(jupiterTimeTexture);

		SDL_RenderPresent(dc->renderer);

		SDL_WaitEvent(&event);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			// gravity, thrustPower, basePlatformChance, platformWidth, planetWidth, heightDiff, startingFuel, fuelBurn, landerMass
			if (moonStageButton.x <= event.motion.x && event.motion.x <= moonStageButton.x + moonStageButton.w && moonStageButton.y <= event.motion.y && event.motion.y <= moonStageButton.y + moonStageButton.h) {
				StartGame(dc, (GameInitData) { Moon, 1.7, 0.75, 10, 200, 3, 100, 5000, 1, 3 });			// Moon
				run = 0;
			} else if (marsStageButton.x <= event.motion.x && event.motion.x <= marsStageButton.x + marsStageButton.w && marsStageButton.y <= event.motion.y && event.motion.y <= marsStageButton.y + marsStageButton.h) {
				StartGame(dc, (GameInitData) { Mars, 3.7, 1.25, 25, 175, 5, 250, 2500, 1, 3 });			// Mars
				run = 0;
			} else if (uranusStageButton.x <= event.motion.x && event.motion.x <= uranusStageButton.x + uranusStageButton.w && uranusStageButton.y <= event.motion.y && event.motion.y <= uranusStageButton.y + uranusStageButton.h) {
				StartGame(dc, (GameInitData) { Uranus, 9.0, 1.5, 50, 150, 10, 500, 1500, 1, 3 });		// Uranus
				run = 0;
			} else if (earthStageButton.x <= event.motion.x && event.motion.x <= earthStageButton.x + earthStageButton.w && earthStageButton.y <= event.motion.y && event.motion.y <= earthStageButton.y + earthStageButton.h) {
				StartGame(dc, (GameInitData) { Earth, 10, 1.75, 100, 125, 20, 650, 1500, 1, 3 });		// Earth
				run = 0;
			} else if (jupiterStageButton.x <= event.motion.x && event.motion.x <= jupiterStageButton.x + jupiterStageButton.w && jupiterStageButton.y <= event.motion.y && event.motion.y <= jupiterStageButton.y + jupiterStageButton.h) {
				StartGame(dc, (GameInitData) { Jupiter, 24.7, 2.25, 150, 100, 50, 700, 2000, 1, 3 });	// Jupiter
				run = 0;
			} else if (customStageButton.x <= event.motion.x && event.motion.x <= customStageButton.x + customStageButton.w && customStageButton.y <= event.motion.y && event.motion.y <= customStageButton.y + customStageButton.h) {
				//StageCustomizer(dc);																	// Custom
				//run = 0;
			} else if (backButton.x <= event.motion.x && event.motion.x <= backButton.x + backButton.w && backButton.y <= event.motion.y && event.motion.y <= backButton.y + backButton.h) {
				run = 0;
			}
		} else if (event.type == SDL_QUIT) {
			run = 0;
		}

	}
}