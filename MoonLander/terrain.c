#include "terrain.h"

Terrain* newTerrain(void) {
	Terrain* t = (Terrain*) malloc(sizeof(Terrain));
	if (t != NULL) {
		t->n = 1;
		t->onScreen = 0;
		t->points = (int*) malloc(sizeof(int));
		if (t->points != NULL) {
			t->points[0] = HEIGHT;
		} else {
			Log("Failed to allocate memory for t->points!", 4);
			abort();
		}
	}
	return t;
}

void AddPoint(Terrain* t) {
	t->n++;
	t->points = (int*) realloc(t->points, t->n * sizeof(int));
	if (t->points != NULL) {
		t->points[t->n - 1] = HEIGHT - (rand() % 100);
	} else {
		Log("Failed to realloc t->points! (AddPoint)", 4);
		abort();
	}
}

void AddPointL(Terrain* t) {
	t->n++;
	t->onScreen = 0;
	int* temp = t->points;
	t->points = (int*) realloc(t->points, t->n * sizeof(int));
	if (t->points != NULL) {
		t->points[0] = HEIGHT - (rand() % 100);
		for (int i = 1; i < t->n; i++) {
			t->points[i] = temp[i - 1];
		}
	} else {
		Log("Failed to realloc t->points! (AddPointL)", 4);
		abort();
	}
}
