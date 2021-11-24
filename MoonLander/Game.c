#include "Game.h"

enum State { falling, rising, destroy };

Uint32 timer(Uint32 ms, void* param) {
	SDL_Event event;
	event.type = SDL_USEREVENT;
	SDL_PushEvent(&event);
	return ms;
}

void sim(DataContainer* dc, Object* obj, double delta_t) {
	obj->x += (int) obj->vx * delta_t; // s = v*t
	obj->y += (int) obj->vy * delta_t;
	obj->vx += 0;
	obj->vy += (double) 10 * delta_t; // g*t
	if (obj->y >= dc->height - 10) {
		obj->vy *= -1;
		obj->state = rising;
	}
	if (obj->last_vy < 0 && 0 < obj->vy) obj->state = falling;

	if (obj->x <= 0) {
		obj->vx *= -1;
	} else if (obj->x >= dc->width) {
		obj->vx *= -1;
	}

	obj->last_vx = obj->vx;
	obj->last_vy = obj->vy;
}

void draw(DataContainer* dc, Object obj) {
	SDL_SetRenderDrawColor(dc->renderer, 0, 0, 0, 255);
	SDL_RenderClear(dc->renderer);
	filledCircleRGBA(dc->renderer, (Sint16) obj.x, (Sint16) obj.y, (Sint16) 10, (Uint8) 0, (Uint8) 255, (Uint8) 0, (Uint8) 255);
	aacircleRGBA(dc->renderer, (Sint16) obj.x, (Sint16) obj.y, (Sint16) 10, (Uint8) 0, (Uint8) 255, (Uint8) 0, (Uint8) 255);
	SDL_RenderPresent(dc->renderer);
}

void StartGame(DataContainer* dc, GameInitData initGame) {

	// Create terrain
	//		malloc memory
	//		Fill memory with random POINTS
	// Create the player
	//		Properties
	//			xpos, ypos, xvel, yvel, m, ...

	Object obj = (Object){falling, dc->width / 2, 500, 50, 0, 1}; // state, x, y, vx, vy, m
	obj.m = 5;

	SDL_TimerID id = SDL_AddTimer(20, timer, NULL);

	int stop = 1;
	while (stop) {
		SDL_Event event;
		SDL_WaitEvent(&event);
		switch (event.type) {
			case SDL_USEREVENT:
				sim(dc, &obj, 0.075);
				draw(dc, obj);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_UP:
					case SDLK_w:
						obj.vy -= 1;
						break;
					case SDLK_DOWN:
					case SDLK_s:
						obj.vy += 1;
						break;
					case SDLK_LEFT:
					case SDLK_a:
						obj.vx -= 1;
						break;
					case SDLK_RIGHT:
					case SDLK_d:
						obj.vx += 1;
						break;
					default:
						break;
				}
				break;
			case SDL_QUIT:
				stop = 0;
				break;
		}
	}
	SDL_RemoveTimer(id);

}