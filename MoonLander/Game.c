#include "Game.h"

#ifdef _DEBUG
#include "debugmalloc.h"
#endif


// Variables that are referenced across multiple functions are declared here
DataContainer* dc;		//
GameInitData initData;	// Basic game data
Terrain* start;			// First element of the linked list storing the terrain
SDL_TimerID id;			// The id of the game clock timer
int stop = 1;			// "bool" signalling weather the game is running

// Timer from https://infoc.eet.bme.hu/ea10/tuzijatek.c
Uint32 timer(Uint32 ms, void* param) {
	SDL_Event event;
	event.type = SDL_USEREVENT;
	SDL_PushEvent(&event);
	return ms;
}

// Returns the height of the terrain at a given x point
int getTerrainHeight(int x) {

	Terrain* head = start;

	for (int i = 0; i < x; i++, head = head->next); // Skip to the relevant part

	return head->y;
}

// Physics simulation
void sim(double delta_t) {
	dc->obj.x += (int) dc->obj.vx * delta_t; // Calculating new position
	dc->obj.y += (int) dc->obj.vy * delta_t; //

	dc->obj.vx += cos(dc->obj.rot * (M_PI / 180)) * dc->obj.thrust * initData.thrustPower; // Calculating velocity
	dc->obj.vy += sin(dc->obj.rot * (M_PI / 180)) * dc->obj.thrust * initData.thrustPower; // 

	if (getTerrainHeight(dc->obj.x) - dc->obj.y >= 85 && getTerrainHeight(dc->obj.x + 100) - dc->obj.y >= 95) // Applying gravitational pull if the player is not on the ground already
		dc->obj.vy += initData.gravity * delta_t;
	else
		// If the x and y velocities are small enough AND there is no height difference between the left and right side of the shuttle (i.e. the terrain is flat) AND the player is looking directly up
		if (abs(dc->obj.vx) <= 20 && dc->obj.vy <= 40 && getTerrainHeight(dc->obj.x - 40) == getTerrainHeight(dc->obj.x + 40) && dc->obj.rot == 270) {	// the player wins
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Success!", "You landed successfully!", NULL);
			stop = 0;
		} else {																																		// otherwise the player loses
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Game Over", "You crashed!", NULL);
			stop = 0;
		}

	if (dc->obj.x - 5 < 0) {										// Checking if the player reached the left side of the screen
		for (int i = 0; i < dc->width; i++, start = start->prev);	// Shifting the linked list to the previous screen of points
		dc->obj.x = dc->width - 90;
	} else if (dc->obj.x + 5 > dc->width) {							//							   the right side of the screen
		for (int i = 0; i < dc->width; i++, start = start->next);	// Shifting the linked list to the next screen of points
		dc->obj.x = 10;
	}
}

// Handles all the rendering
void draw(void) {
	SDL_SetRenderDrawColor(dc->renderer, 0, 0, 0, 255);
	SDL_RenderClear(dc->renderer);
	if (dc->obj.thrust == 1)
		SDL_RenderCopyEx(dc->renderer, dc->shipTextureOn, NULL, &(SDL_Rect) {dc->obj.x, dc->obj.y, 101, 101}, dc->obj.rot + 90, & (SDL_Point) {50, 50}, SDL_FLIP_NONE);
	else
		SDL_RenderCopyEx(dc->renderer, dc->shipTextureOff, NULL, &(SDL_Rect) {dc->obj.x, dc->obj.y, 101, 101}, dc->obj.rot + 90, & (SDL_Point) {50, 50}, SDL_FLIP_NONE);
#ifdef _DEBUG 
	rectangleRGBA(dc->renderer, dc->obj.x, dc->obj.y, dc->obj.x + 100, dc->obj.y + 100, 0, 0, 255, 255); // Draw collision box if debugging is enabled
#endif
	drawTerrain();
	drawHUD();
	SDL_RenderPresent(dc->renderer);
}

// Draws the terrain
void drawTerrain(void) {

	Sint16* vx = malloc(dc->width * sizeof(Sint16) + 2);
	Sint16* vy = malloc(dc->width * sizeof(Sint16) + 2);

	if (vx == NULL || vy == NULL) exit(2);

	Terrain* current = start;

	vx[0] = 0;
	vy[0] = dc->height;

	for (int i = 1; i < dc->width; i++, current = current->next) {
		vx[i] = (Sint16) i;
		vy[i] = (Sint16) current->y;
	}
	vx[dc->width] = dc->width;
	vy[dc->width] = dc->height;

	filledPolygonRGBA(dc->renderer, vx, vy, dc->width + 1, 255, 0, 0, 255);

	free(vx);
	free(vy);
}

// Draws the velocities, elapsed time, (and remaining fuel) on screen
void drawHUD(void) {
	char vx[13];																											//
	sprintf(vx, "x vel: %.0f", dc->obj.vx);																					//
	char vy[13];																											// Int / double to string conversion
	sprintf(vy, "y vel: %.0f", dc->obj.vy);																					//
	char time[14];																											//
	sprintf(time, "Time: %.2d:%.2d", (dc->obj.totalTime / 60000) % 60, (dc->obj.totalTime / 1000) % 60);					//

	SDL_Surface* vx_text = TTF_RenderText_Solid(dc->font, vx, (SDL_Color) { 0, 255, 0, 255 });								// 
	SDL_Surface* vy_text = TTF_RenderText_Solid(dc->font, vy, (SDL_Color) { 0, 255, 0, 255 });								// Text surfaces
	SDL_Surface* time_text = TTF_RenderText_Solid(dc->font, time, (SDL_Color) { 0, 255, 0, 255 });							// 

	SDL_Texture* vx_texture = SDL_CreateTextureFromSurface(dc->renderer, vx_text);											//
	SDL_Texture* vy_texture = SDL_CreateTextureFromSurface(dc->renderer, vy_text);											// Text textures
	SDL_Texture* time_texture = SDL_CreateTextureFromSurface(dc->renderer, time_text);										//

	SDL_RenderCopy(dc->renderer, vx_texture, NULL, &(SDL_Rect){0, 0, vx_text->w, vx_text->h});								//
	SDL_RenderCopy(dc->renderer, vy_texture, NULL, &(SDL_Rect){0, vx_text->h, vy_text->w, vy_text->h});						// Rendering the textures
	SDL_RenderCopy(dc->renderer, time_texture, NULL, &(SDL_Rect){0, vx_text->h + vy_text->h, time_text->w, time_text->h});	//

	SDL_FreeSurface(vx_text);																								// 
	SDL_FreeSurface(vy_text);																								// 
	SDL_FreeSurface(time_text);																								// Freeing everything to avoid memory leaks
	SDL_DestroyTexture(vx_texture);																							// 
	SDL_DestroyTexture(vy_texture);																							// 
	SDL_DestroyTexture(time_texture);																						// 
}

void StartGame(DataContainer* datac, GameInitData initGame) {
	dc = datac;
	initData = initGame;

	dc->obj = (Object){dc->width / 2, 10, 0, 0, 270, 1, 0}; // x, y, vx, vy, rot, m, thrust

	srand(time(NULL));

	start = (Terrain*) malloc(sizeof(Terrain));
	start->y = dc->height - rand() % initGame.heightDiff;
	Terrain* last = start;

	double value = rand() % initData.heightDiff;
	double begin = rand() % initData.heightDiff;
	int target;
	for (int i = 0; i < initData.planetWidth * dc->width / initData.platformWidth; i++) {
		target = rand() % initData.heightDiff;
		begin = value;

		if (i % initGame.basePlatformChance == 0) {
			for (int j = 0; j <= initData.platformWidth; j++) {
				Terrain* new = (Terrain*) malloc(sizeof(Terrain));
				new->y = dc->height - value;
				new->prev = last;
				last->next = new;
				last = new;
			}
		} else {
			if ((target - value) >= 0) {
				for (int j = 0; j <= initData.platformWidth; j++) {
					Terrain* new = (Terrain*) malloc(sizeof(Terrain));
					value = (j / (double)initData.platformWidth) * (target - value);
					new->y = dc->height - value;
					new->prev = last;
					last->next = new;
					last = new;
				}
			} else {
				for (int j = initData.platformWidth; j >= 0; j--) {
					Terrain* new = (Terrain*) malloc(sizeof(Terrain));
					value = (j / (double)initData.platformWidth) * (target - value);
					new->y = dc->height - value;
					new->prev = last;
					last->next = new;
					last = new;
				}
			}
		}
	}

	last->next = start;
	start->prev = last;

	id = SDL_AddTimer(20, timer, NULL); // 20!
	GameLoop(start);
}

void GameLoop(void) {
	while (stop) {
		SDL_Event event;
		SDL_WaitEvent(&event);
		switch (event.type) {
			case SDL_USEREVENT:
				dc->obj.totalTime += 20;
				sim(0.075);
				draw();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_UP:
					case SDLK_w:
						dc->obj.thrust = 1;
						break;
					case SDLK_q:
						if (dc->obj.rot > 180) dc->obj.rot -= 5;
						break;
					case SDLK_e:
						if (dc->obj.rot < 360) dc->obj.rot += 5;
						break;
					default:
						break;
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP) dc->obj.thrust = 0;
				break;
			case SDL_QUIT:
				stop = 0;
				dc->obj.totalTime = 0;	// The player did not complete the level, so his time should not be saved
				break;
		}
	}
	DestroyGame();
}

// Frees allocated memory by the terrain
void DestroyGame(void) {
	SDL_RemoveTimer(id);
	Terrain* head = start->next;
	do {
		Terrain* next = head->next;
		free(head);
		head = next;
	} while (head != start);
	free(head);
}