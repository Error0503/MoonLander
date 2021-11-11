#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>

#include "player.h"
#include "terrain.h"
#include "Colour.h"

void Update(Player* player, Terrain* terrain);
void RenderPlayer(Player* player);
void RenderHUD(Player* player);
void ClearWindow(SDL_Renderer* r, Colour c);
void RenderTerrain(Terrain* t);
void SetRenderDrawColour(SDL_Renderer* r, Colour c);
void drawFilledRect(SDL_Rect rect, Colour c);
void text(char* txt);

#endif