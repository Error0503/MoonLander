#include "terrain.h"

Terrain* newTerrain(void) {
	Terrain* t = (Terrain*) malloc(sizeof(Terrain));
	if (t != NULL) {
		t->n = 1;
		t->onScreen = 0;
		t->points = (int*) malloc(sizeof(int));
		if (t->points != NULL) {
			t->points[0] = HEIGHT;
		}
	}
	return t;
}

void AddPoint(Terrain* t, int y) {
	t->n++;
	t->points = (int*) realloc(t->points, t->n * sizeof(int));
	if (t->points != NULL) {
		t->points[t->n - 1] = y;
	}
}

void AddPointL(Terrain* t, int y) {
	t->n++;
	int* temp = t->points;
	t->points = (int*) realloc(t->points, t->n * sizeof(int));
	if (t->points != NULL) {
		t->points[0] = y;
		for (int i = 1; i < t->n; i++) {
			t->points[i] = temp[i - 1];
		}
	}
}
