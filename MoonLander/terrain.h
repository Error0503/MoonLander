#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <stdlib.h>
#include <SDL.h>

typedef struct Terrain {
	int n;
	SDL_Point* points;
} Terrain;

Terrain* newTerrain(void);
void AddPoint(Terrain* t, int x, int y);
void AddPointL(Terrain* t, int x, int y);

#endif