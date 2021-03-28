#ifndef HERO_H_
#define HERO_H_

#include "background.h"

#define SCREEN_W 1000
#define SCREEN_H 400

#define Hero_WIDTH 100
#define Hero_HEIGHT 170

typedef struct
{
SDL_Surface *personnage;
SDL_Rect poshero;
SDL_Rect posimage;
int vie;
int direction;
SDL_Rect posheroRel;
SDL_Surface* image;
 
}Hero; 


void loadHero(Hero *H);
void initialiser_hero(Hero *H);
void blithero(Hero H,SDL_Surface *screen);
void animateheroR(Hero *H); 
void animateheroL(Hero *H); 
void MoveheroR(Hero *H);
void MoveheroL(Hero *H);
void free_Hero(Hero *H);
void Hero_Vie(Hero* H,int *collision);
void saut ( Hero *H , SDL_Surface *ecran);
void initialiser_saut ( Hero *hero);
#endif
