#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>

enum Stage { Moon, Mars, Uranus, Earth, Jupiter, Custom } Stage;

typedef struct Object {
	int x, y;					// The x and y coordinates of the object on the window
	double vx, vy;				// The x and y velocity of the object
	double rot;					// The rotation of the object
	double m;					// The mass of the object
	int thrust;					// Marks if the thruster is enabled
	int fuel;					// The ammount of fuel remaining
	long totalTime;				// Stores the total time elapsed
} Object;

typedef struct Terrain {
	short y;
	struct Terrain* prev;
	struct Terrain* next;
} Terrain;

typedef struct GameInitData {
	int stage;
	double gravity;
	double thrustPower;
	int basePlatformChance;
	int platformWidth;
	int planetWidth;
	int heightDiff;
	int startingFuel;
	int fuelBurn;
	int landerMass;
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
	SDL_Texture* background;		// The background texture
	SDL_Texture* back;				// The back arrow texture
	Object obj;						// Physics object used for calculating physics and storing game related data
	TTF_Font* font;
	long stageRecords[5];
} DataContainer;

#endif