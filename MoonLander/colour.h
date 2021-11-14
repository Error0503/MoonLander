#ifndef Colour_H_INCLUDED
#define Colour_H_INCLUDED

#define RED			(Colour){255,	0,		0,		255}
#define GREEN		(Colour){0,		255,	0,		255}
#define BLUE		(Colour){0,		0,		255,	255}
#define WHITE		(Colour){255,	255,	255,	255}
#define BLACK		(Colour){0,		0,		0,		255}
#define GREY		(Colour){135,	135,	135,	255}
#define DARK_GREY	(Colour){30,	30,		30,		255}
#define MOON		(Colour){146,	144,	141,	255};

#define SDL_RED			(SDL_Color){255,	0,		0,		255}
#define SDL_GREEN		(SDL_Color){0,		255,	0,		255}
#define SDL_BLUE		(SDL_Color){0,		0,		255,	255}
#define SDL_WHITE		(SDL_Color){255,	255,	255,	255}
#define SDL_BLACK		(SDL_Color){0,		0,		0,		255}
#define SDL_GREY		(SDL_Color){135,	135,	135,	255}
#define SDL_DARK_GREY	(SDL_Color){30,		30,		30,		255}

typedef struct Colour {
	int r;
	int g;
	int b;
	int a;
} Colour;

#endif