#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>

typedef struct StageRecords {
	char* stagename;
	long timeinmillis;
} StageRecords;

typedef struct Player {
	StageRecords records;
} Player;

typedef struct GameInitData {
	float gravity;
	int basePlatformChance;
	int platformWidth;
	int heightDiff;
	int startingFuel;
} GameInitData;

typedef struct Game {
	int state;
	Sint16* points;
} Game;

typedef struct Controls {
	char up, down, left, right, exit;
} Controls;


typedef struct DataContainer {
	int width, height;				// Width and height of the window
	FILE* savefile;					// COMMENT HERE
	SDL_Renderer* renderer;			// COMMENT HERE
	SDL_Texture* playerTexture;		// COMMENT HERE
	Player player;					// COMMENT HERE
	GameInitData game;					// COMMENT HERE
	Controls controls;				// COMMENT HERE
	TTF_Font* font;
} DataContainer;

#endif