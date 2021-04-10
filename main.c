#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "fonc.h"



#define GRAVITY 10
#define SPEED 6
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 30




int main()
{

SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *screen;

screen=SDL_SetVideoMode (800,535,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("hero",NULL);


input I;
perso p,p1;
SDL_Event event;
SDL_Surface *back;

init_perso (&p);
init_perso1 (&p1);

bool running=true;
back=IMG_Load("image.jpg");

SDL_EnableKeyRepeat(60,0);



while(running)
{




while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

		running=false;


		break;
		case SDL_KEYDOWN:


			switch (event.key.keysym.sym)
			{
			


			case SDLK_LEFT :
				p.move1+=1;
				mouvementleft (&p);
			animateheroL(&p);
				if (I.saut==1) saut (&p);



      		break;
			
      		case SDLK_RIGHT :



				p.move1+=1;
				mouvementright (&p);

				animateheroR(&p);
					if (I.saut==1) saut (&p);
				
			break;

				animateheroR(&p);



			case SDLK_UP :


		I.saut=1;
		if(p.rect.y==250)
		p.move2 = -50;
		p.move1=MAX_JUMP_SPEED;
			break;	
				


      		
			case SDLK_q :
				p1.move1+=1;
				mouvementleft (&p1);
				animateheroL(&p1);
				if (I.saut1==1) saut (&p1);
			
			break; 
			case SDLK_d :
			p1.move1+=1;
			mouvementright (&p1);
			animateheroR(&p1);
			if (I.saut1==1) saut (&p1);

			break;
			case SDLK_z :
			I.saut1=1;
			if(p1.rect.y==250)
			p1.move2 = -50;
			p1.move1=MAX_JUMP_SPEED;
			break;
			}
		break;

		break;
		}
	}


p.move2+=GRAVITY;
 p.rect.y += p.move2;
 if(p.rect.y >= 250)
 	 {
 		 p.rect.y= 250;
 		 p.move2 = 0;
}

p1.move2+=GRAVITY;
 p1.rect.y += p1.move2;
 if(p1.rect.y >= 250)
 	 {
 		 p1.rect.y= 250;
 		 p1.move2 = 0;



}
SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (&p,screen);
	afficher_perso (&p1,screen);



	SDL_Flip(screen);
	SDL_Delay(60);

}
TTF_Quit();




}



