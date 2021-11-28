#include "Menu.h"
#include "LevelSelect.h"

void Menu(DataContainer* dc) {

	SDL_Event event;
	int run = 1;
	while (run) {
		SDL_Surface* menuBackgroundImageSurface = IMG_Load("main_menu_background.png");
		SDL_Texture* menuBackgroundImageTexture = SDL_CreateTextureFromSurface(dc->renderer, menuBackgroundImageSurface);
		SDL_RenderCopy(dc->renderer, menuBackgroundImageTexture, NULL, NULL);

		SDL_FreeSurface(menuBackgroundImageSurface);
		SDL_DestroyTexture(menuBackgroundImageTexture);

		SDL_Rect playButton = (SDL_Rect){dc->width / 2 - 200 / 2, 450, 200, 50};
		SDL_Rect exitButton = (SDL_Rect){dc->width / 2 - 200 / 2, 550, 200, 50};

		SDL_SetRenderDrawColor(dc->renderer, 158, 158, 158, 255);

		SDL_RenderFillRect(dc->renderer, &playButton);
		SDL_RenderFillRect(dc->renderer, &exitButton);

		SDL_Surface* playTextSurface = TTF_RenderText_Blended(dc->font, "Play", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Texture* playTexture = SDL_CreateTextureFromSurface(dc->renderer, playTextSurface);
		SDL_RenderCopy(dc->renderer, playTexture, NULL, &(SDL_Rect){playButton.x + playButton.w / 2 - playTextSurface->w / 2, playButton.y + playButton.h / 2 - playTextSurface->h / 2, playTextSurface->w, playTextSurface->h});

		SDL_Surface* exitTextSurface = TTF_RenderText_Blended(dc->font, "Exit", (SDL_Color) { 255, 255, 255, 255 });
		SDL_Texture* exitTexture = SDL_CreateTextureFromSurface(dc->renderer, exitTextSurface);
		SDL_RenderCopy(dc->renderer, exitTexture, NULL, &(SDL_Rect){exitButton.x + exitButton.w / 2 - exitTextSurface->w / 2, exitButton.y + exitButton.h / 2 - exitTextSurface->h / 2, exitTextSurface->w, exitTextSurface->h});

		SDL_RenderPresent(dc->renderer);

		SDL_FreeSurface(playTextSurface);
		SDL_FreeSurface(exitTextSurface);
		SDL_DestroyTexture(playTexture);
		SDL_DestroyTexture(exitTexture);

		SDL_WaitEvent(&event);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (playButton.x <= event.motion.x && event.motion.x <= playButton.x + playButton.w && playButton.y <= event.motion.y && event.motion.y <= playButton.y + playButton.h) {
				LevelSelect(dc);
				SDL_FlushEvent(SDL_MOUSEMOTION);
				SDL_FlushEvent(SDL_KEYDOWN);
				SDL_FlushEvent(SDL_KEYUP);
			} else if (exitButton.x <= event.motion.x && event.motion.x <= exitButton.x + exitButton.w && exitButton.y <= event.motion.y && event.motion.y <= exitButton.y + exitButton.h) {
				run = 0;
			}
		}
	}
}