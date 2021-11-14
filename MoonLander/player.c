#include "player.h"

Player* newPlayer(char* file) {
	Player* p = (Player*) malloc(sizeof(Player));
	if (p != NULL) {
		p->m = 0;
		p->v = 0;
		p->a = 0;
		p->rotation = 0;
		p->fuel = 0;
		p->pos = &((SDL_Rect) { 0, 0, 0, 0 });
		extern SDL_Renderer* renderer;
		p->texture = SDL_CreateTextureFromSurface(renderer, IMG_Load(file));
	}
	return p;
}