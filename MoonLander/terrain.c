#include "terrain.h"

Terrain* newTerrain(void) {
	Terrain* t = (Terrain*) malloc(sizeof(Terrain));
	if (t != NULL) {
		t->n = 1;
		t->points = (SDL_Point*) malloc(sizeof(SDL_Point));
		extern int HEIGHT;
		t->points[0] = (SDL_Point){0, HEIGHT};
	}
	return t;
}

void AddPoint(Terrain* t, int x, int y) {
	t->n++;
	t->points = (SDL_Point*) realloc(t->points, t->n * sizeof(SDL_Point));
	t->points[t->n - 1] = (SDL_Point){x, y};
}

void AddPointL(Terrain* t, int x, int y) {
	t->n++;
	SDL_Point* temp = t->points;
	t->points = (SDL_Point*) realloc(t->points, t->n * sizeof(SDL_Point));
	t->points[0] = (SDL_Point){x, y};
	for (int i = 1; i < t->n; i++) {
		t->points[i] = temp[i - 1];
	}
}
