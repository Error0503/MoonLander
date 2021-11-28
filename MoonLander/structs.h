#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>

enum Stage { Moon, Mars, Uranus, Earth, Jupiter, Custom };

typedef struct StageRecords {
	enum Stage stage;
	long timeinmillis;
} StageRecords;

typedef struct Object {
	int x, y;					// The x and y coordinates of the object on the window
	double vx, vy;				// The x and y velocity of the object
	double rot;					// The rotation of the object
	double m;					// The mass of the object
	int thrust;					// Marks if the thruster is enabled
	long totalTime;				// Stores the total time elapsed
} Object;

typedef struct Terrain {
	short y;
	struct Terrain* prev;
	struct Terrain* next;
} Terrain;

typedef struct GameInitData {
	double gravity;
	double thrustPower;
	int basePlatformChance;
	int platformWidth;
	int heightDiff;
	int startingFuel;
	int planetWidth;
} GameInitData;

typedef struct Controls {
	char up, down, left, right, exit;
} Controls;


typedef struct DataContainer {
	int width, height;				// Width and height of the window
	FILE* savefile;					// File in which player records are saved
	SDL_Renderer* renderer;			// SDL_Renderer* for rendering
	SDL_Texture* shipTextureOff;	// The SDL_Texture* of the player
	SDL_Texture* shipTextureOn;		// The SDL_Texture* of the player
	Object obj;						// Physics object used for calculating physics and storing game related data
	GameInitData game;				// COMMENT HERE
	Controls controls;				// COMMENT HERE
	TTF_Font* font;
} DataContainer;

#endif