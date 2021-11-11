#include "graphics.h"

void Update(Player* player, Terrain* terrain) {
	RenderPlayer(player);
	RenderTerrain(terrain);
	RenderHUD(player);
}

void RenderPlayer(Player* player) {
	return;
}

void RenderHUD(Player* player) {
	return;
}

void RenderTerrain(Terrain* t) {
	extern SDL_Renderer* renderer;
	Sint16* x = malloc(t->n * sizeof(Sint16));
	Sint16* y = malloc(t->n * sizeof(Sint16));

	for (int i = 0; i < t->n; i++) {
		x[i] = (Sint16) t->points[i].x;
		y[i] = (Sint16) t->points[i].y;
	}

	Uint8 r, g, b, a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	filledPolygonRGBA(renderer, x, y, t->n, r, g, b, a);
	SDL_RenderPresent(renderer);
}


void ClearWindow(SDL_Renderer* r, Colour c) {
	SetRenderDrawColour(r, c);
	SDL_RenderClear(r);
	SDL_RenderPresent(r);
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

void text(char* txt) {
	extern SDL_Renderer* renderer;
	extern int WIDTH;
	extern int HEIGHT;
	TTF_Font* font = TTF_OpenFont("Formula1-Regular.ttf", 2000);
	SDL_Surface* txtSurface = TTF_RenderText_Solid(font, txt, SDL_WHITE);
	SDL_Texture* txtTexture = SDL_CreateTextureFromSurface(renderer, txtSurface);
	SDL_RenderCopy(renderer, txtTexture, NULL, &((SDL_Rect){0, 0, WIDTH, HEIGHT}));
}