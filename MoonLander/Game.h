#include <time.h>

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "structs.h"

typedef struct Object {
	int state;					// The current state of the object
	int x, y;					// The x and y coordinates of the object on the window
	double vx, vy;				// The x and y velocity of the object
	double last_vx, last_vy;	// The x and y velocity of the object on the last frame
	double m;					// The mass of the object
} Object;

Uint32 timer(Uint32 ms, void* param);
void sim(DataContainer* dc, Object* obj, double delta_t);
void draw(DataContainer* dc, Object obj);
void StartGame(DataContainer* dc, GameInitData game);