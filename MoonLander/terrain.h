#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <stdlib.h>
#include <SDL.h>

#include "globals.h"

typedef struct Terrain {
	int n;
	int onScreen;
	int* points;
} Terrain;

Terrain* newTerrain(void);
void AddPoint(Terrain* t, int y);
void AddPointL(Terrain* t, int y);

#endif