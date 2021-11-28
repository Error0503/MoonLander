#include "Menu.h"
#include "LevelSelect.h"

void Menu(DataContainer* dc) {

	SDL_Rect playButton = (SDL_Rect){dc->width / 2 - 200 / 2, 200, 200, 50};
	SDL_Rect settingsButton = (SDL_Rect){dc->width / 2 - 200 / 2, 300, 200, 50};
	SDL_Rect exitButton = (SDL_Rect){dc->width / 2 - 200 / 2, 400, 200, 50};

	SDL_SetRenderDrawColor(dc->renderer, 255, 255, 255, 255);

	SDL_RenderFillRect(dc->renderer, &playButton);
	SDL_RenderFillRect(dc->renderer, &settingsButton);
	SDL_RenderFillRect(dc->renderer, &exitButton);

	SDL_Surface* text = TTF_RenderText_Blended(dc->font, "Text", (SDL_Color) { 0, 255, 0, 255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(dc->renderer, text);
	SDL_RenderCopy(dc->renderer, texture, NULL, &(SDL_Rect){0,0,text->w,text->h});

	SDL_RenderPresent(dc->renderer);

	SDL_FreeSurface(text);

	SDL_Event event;
	while (1) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (playButton.x <= event.motion.x && event.motion.x <= playButton.x + playButton.w && playButton.y <= event.motion.y && event.motion.y <= playButton.y + playButton.h) {
					LevelSelect(dc);
					StartGame(dc, (GameInitData) {10, 1.25, 10, 100, 400, 10, 3}); // gravity, thrustPower, basePlatformChance, platformWidth, heightDiff, startingFuel, planetWidth
					return;
				} else if (settingsButton.x <= event.motion.x && event.motion.x <= settingsButton.x + settingsButton.w && settingsButton.y <= event.motion.y && event.motion.y <= settingsButton.y + settingsButton.h) {
					//
				} else if (exitButton.x <= event.motion.x && event.motion.x <= exitButton.x + exitButton.w && exitButton.y <= event.motion.y && event.motion.y <= exitButton.y + exitButton.h) {
					exit(0);
				}
			}
		}
	}
}