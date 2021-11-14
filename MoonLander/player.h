#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

typedef struct Player {
	int m, v, a, rotation;
	int x, y;
	int fuel;
	SDL_Rect* pos;
	SDL_Texture* texture;
} Player;

Player* newPlayer(char* file);

#endif