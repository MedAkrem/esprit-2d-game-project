#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>



typedef struct perso
{


SDL_Surface *personnage;
SDL_Rect rect;
SDL_Rect pos_sprite;
float move1,move2; 
int vie ;
}perso;
typedef struct input
{

int saut,saut1;
}input;



void init_perso (perso *p);
void init_perso1 (perso *p);
void afficher_perso (perso *p,SDL_Surface *screen);

void mouvementright (perso *p);
void mouvementleft (perso *p);

void saut (perso *p);
void animateheroR(perso *p);
void animateheroL(perso *p);
//void Hero_Vie(Hero* p,int *collision);



 #endif

