#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>

#include "player.h"
#include "terrain.h"
#include "Colour.h"

int Update(Player* player, Terrain* terrain);
int RenderPlayer(Player* player);
int RenderHUD(Player* player);
void ClearWindow();
int RenderTerrain(Terrain* t);
void SetRenderDrawColour(SDL_Renderer* r, Colour c);
void drawFilledRect(SDL_Rect rect, Colour c);
void RenderText(char* txt, SDL_Rect* pos, int fontSize);

#endif