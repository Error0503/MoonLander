#include "graphics.h"

int Update(Player* player, Terrain* terrain) {
	int status = 0b0;
	status = RenderPlayer(player) << 2 | RenderTerrain(terrain) << 1 | RenderHUD(player);
	return status;
}

int RenderPlayer(Player* player) {
	return 0;
}

int RenderHUD(Player* player) {
	return 0;
}

int RenderTerrain(Terrain* t) {
	extern SDL_Renderer* renderer;

	Sint16* x = malloc(((WIDTH / RESOLUTION) + 2) * sizeof(Sint16));
	Sint16* y = malloc(((WIDTH / RESOLUTION) + 2) * sizeof(Sint16));

	if (x != NULL && y != NULL && 0 <= t->onScreen && t->onScreen < t->n - (WIDTH / RESOLUTION)) {
		ClearWindow();
		x[0] = 0;
		y[0] = HEIGHT;
		for (int i = 0; i <= WIDTH / RESOLUTION; i++) {
			x[i + 1] = i * RESOLUTION;
			y[i + 1] = t->points[t->onScreen + i];
		}
		x[(WIDTH / RESOLUTION) + 1] = WIDTH;
		y[(WIDTH / RESOLUTION) + 1] = HEIGHT;

		Colour c = MOON;
		Uint16 r = c.r, g = c.g, b = c.b, a = c.a;

		filledPolygonRGBA(renderer, x, y, (WIDTH / RESOLUTION) + 2, r, g, b, a);
		SDL_RenderPresent(renderer);
		return 0b0;
	} else if (t->n == 1) {
		for (int i = 0; i <= WIDTH * 2; i += RESOLUTION) {
			AddPoint(t);
		}
		//RenderTerrain(t);
		return 0b0;
	} else if (t->onScreen == t->n - (WIDTH / RESOLUTION)) {
		AddPoint(t);
		RenderTerrain(t);
		return 0b0;
	} else if (t->onScreen < 0) {
		AddPointL(t);
		RenderTerrain(t);
		if (t->n > 77) {
			Log("t->n = ", 2);
			LogInt(t->n);
			printf("\n");
		}
		return 0b0;
	}
	return 0b1;
}


void ClearWindow() {
	extern SDL_Renderer* renderer;
	SetRenderDrawColour(renderer, BLACK);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void SetRenderDrawColour(SDL_Renderer* r, Colour c) {
	SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
}

void drawFilledRect(SDL_Rect rect, Colour c) {
	extern SDL_Renderer* renderer;

	Sint16 x[] = {rect.x, rect.x + rect.w, rect.x + rect.w, rect.x};
	Sint16 y[] = {rect.y, rect.y, rect.y + rect.h, rect.y + rect.h};

	filledPolygonRGBA(renderer, x, y, 4, c.r, c.g, c.b, c.a);
}

void RenderText(char* txt, SDL_Rect* pos, int fontSize) {
	extern SDL_Renderer* renderer;
	TTF_Font* font = TTF_OpenFont("consola.ttf", fontSize);
	SDL_Surface* txtSurface = TTF_RenderText_Solid(font, txt, SDL_WHITE);
	SDL_Texture* txtTexture = SDL_CreateTextureFromSurface(renderer, txtSurface);
	SDL_RenderCopy(renderer, txtTexture, NULL, pos);
}