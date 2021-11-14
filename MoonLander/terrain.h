#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <stdlib.h>
#include <SDL.h>

#include "globals.h"
#include "debug.h"

typedef struct Point {
	int value;
	struct Point* next;
} Point;

typedef struct Terrain {
	int n;
	int onScreen;
	int* points;
} Terrain;

Terrain* newTerrain(void);
void AddPoint(Terrain* t);
void AddPointL(Terrain* t);

#endif