#include <time.h>
#include <math.h>

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "structs.h"

Uint32 timer(Uint32 ms, void* param);
int getTerrainHeight(int x);
void sim(double delta_t);
void draw(void);
void drawTerrain(void);
void drawHUD(void);
void StartGame(DataContainer* dc, GameInitData game);
void GameLoop(void);
void DestroyGame(void);