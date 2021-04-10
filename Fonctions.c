#include "fonc.h"

#define vitesse 7
#define vitesse_max 12

#define GRAVITY 10
#define MAX_JUMP_SPEED 30

#define Hero_WIDTH 128
#define Hero_HEIGHT 128



void init_perso (perso *p)
{
p->personnage=IMG_Load("hero_spr.png");
p->rect.x=0;
p->rect.y=300;


p->move1=0;
p->move2=0;
p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=128;
p->pos_sprite.w=128;

}

void init_perso1 (perso *p)
{
p->personnage=IMG_Load("hero_spr.png");
p->rect.x=0;
p->rect.y=300;

p->rect.w=100;
p->rect.h=100;
p->move1=0;
p->move2=0;
p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=128;
p->pos_sprite.w=128;
}



void afficher_perso (perso *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->personnage,&p->pos_sprite,screen,&p->rect);
}






void mouvementright (perso *p)
{

if (p->move1>=vitesse_max)
	p->move1=vitesse_max;
if (p->rect.x<750)
{

p->rect.x+=p->move1;
}
}

void animateheroR(perso *p)
{p->pos_sprite.x+=128;
p->pos_sprite.x=p->pos_sprite.x % 768;
p->pos_sprite.y=0;
}



void mouvementleft (perso *p)
{
if (p->move1>=vitesse_max)
  p->move1=vitesse_max;
if (p->rect.x>0){
p->rect.x-=p->move1;
}
}


void animateheroL(perso *p)
{p->pos_sprite.x-=Hero_WIDTH;
if (p->pos_sprite.x<0)
{
  p->pos_sprite.x=640;
}

p->pos_sprite.y=Hero_HEIGHT;
}






void saut (perso *p)
{
if (p->move1>=MAX_JUMP_SPEED)
  p->move1=MAX_JUMP_SPEED;
if (p->rect.x>0){
p->rect.x-=p->move1;
}

 
if (p->rect.x<1000)
{
  p->move1+=5;
p->rect.x+=p->move1;
}

}
/*
void Hero_Vie(Hero* p,int *collision)
{
	if(*collision)
	   if(p->vie > 0)
	      p->vie =p->vie-20;

}
*/





