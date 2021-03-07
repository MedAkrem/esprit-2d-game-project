#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>



int main(int argc, char *argv[])
{
typedef struct
{
    SDL_Surface *text;
    SDL_Rect positiontext;
}texte;

typedef struct
{
    SDL_Surface *boutton;
    SDL_Rect positionboutton;
}options;

int position=0;
options b[20];
texte txt[7];
SDL_Surface* screen  = NULL;
SDL_Surface *background,*playbackground,*settingbackground,*creditsbackground; //reference our image
SDL_Rect positionbackground;
SDL_Event event,event1,event2,event3;
Mix_Music *musique; //Création d'un pointeur de type Mix_Music
Mix_Chunk *clic;
TTF_Font *police = NULL,*police1 = NULL;
SDL_Color couleurblanc = {255, 255, 255};
int volume;
int continuer=1,p=0,i=0;

SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
screen=SDL_SetVideoMode(1366,766,32,SDL_HWSURFACE | SDL_DOUBLEBUF); // Ouverture de la fenêtre
if(!screen)
{
printf("unable to set 1280x800 video: %s\n",SDL_GetError());
return (-1);
}
SDL_WM_SetCaption("where i am", NULL);

//musique
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
volume=MIX_MAX_VOLUME / 2;
Mix_VolumeMusic(volume); //Mettre le volume à la moitié
musique = Mix_LoadMUS("faded.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1); //Jouer infiniment la musique // 0 matet3awedsh w 1 mara barka
clic = Mix_LoadWAV("sound82.wav"); //Chargement de la musique
Mix_VolumeChunk(clic,MIX_MAX_VOLUME/2);

//background et boutton et police
background=IMG_Load("background.jpg"); //chargement background
if (background==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
settingbackground=IMG_Load("SETTINGS.jpg");
playbackground=IMG_Load("play_background.jpg");
creditsbackground=IMG_Load("credits_in.jpg");
positionbackground.x = 0;
positionbackground.y = 0; // fil west

SDL_BlitSurface(background,&positionbackground,screen,&positionbackground); //placement background

TTF_Init(); //initialisation du ttf (police)
if(TTF_Init() == -1)
    {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
    }
police = TTF_OpenFont("made_by.ttf", 90); //chargement police
if (police==NULL)
    {
        printf("police erreur\n");
    }
    txt[0].text = TTF_RenderText_Blended(police, "MADE BY", couleurblanc); //chargement text
        txt[0].positiontext.x = 50;
        txt[0].positiontext.y = 160;

police1 = TTF_OpenFont("names.ttf", 60); //chargement police
if (police1==NULL)
    {
        printf("police1 erreur\n");
    }
    txt[1].text = TTF_RenderText_Blended(police1, "mohamed akrem bargoui", couleurblanc); //chargement text
        txt[1].positiontext.x = 40;
        txt[1].positiontext.y = 280;

    txt[2].text = TTF_RenderText_Blended(police1, "chaima el jed", couleurblanc); //chargement text
        txt[2].positiontext.x = 40;
        txt[2].positiontext.y = 380;

    txt[3].text = TTF_RenderText_Blended(police1, "chaima saadallah", couleurblanc); //chargement text
        txt[3].positiontext.x = 40;
        txt[3].positiontext.y = 480;

    txt[4].text = TTF_RenderText_Blended(police1, "iheb debbech", couleurblanc); //chargement text
        txt[4].positiontext.x = 920;
        txt[4].positiontext.y = 250;

    txt[5].text = TTF_RenderText_Blended(police1, "aziz abrougui", couleurblanc); //chargement text
        txt[5].positiontext.x = 920;
        txt[5].positiontext.y = 350;

  

SDL_Surface *play,*quit,*setting,*credits=NULL,*quit1,*setting1,*play1,*credits1;
SDL_Rect positionplay,positionquit,positionsetting,positioncredits;



play=IMG_Load("play_not_pressed.png");
if (play==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
setting=IMG_Load("setting_not_pressed.png");
if (setting==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
quit=IMG_Load("quit_not_pressed.png");
if (quit==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
credits=IMG_Load("credits_not_pressed.png");
if (credits==NULL)
{
printf("credits: %s\n" , IMG_GetError());
return 1;
}
quit1=IMG_Load("quit_pressed.png");
if (quit1==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
setting1=IMG_Load("setting_pressed.png");
if (setting1==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
play1=IMG_Load("play_pressed.png");
if (play1==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
credits1=IMG_Load("credits_pressed.png");
if (credits1==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[0].boutton=IMG_Load("hb_not_pressed.png");
if (b[0].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[1].boutton=IMG_Load("hb_pressed.png");
if (b[1].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[2].boutton=IMG_Load("mute_not_pressed.png");
if (b[2].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[3].boutton=IMG_Load("mute_pressed.png");
if (b[3].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[4].boutton=IMG_Load("um_not_pressed.png");
if (b[4].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[5].boutton=IMG_Load("um_pressed.png");
if (b[5].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[6].boutton=IMG_Load("mb_not_pressed.png");
if (b[6].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[7].boutton=IMG_Load("mb_pressed.png");
if (b[7].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[8].boutton=IMG_Load("pb_not_pressed.png");
if (b[8].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[9].boutton=IMG_Load("pb_pressed.png");
if (b[9].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[10].boutton=IMG_Load("fs_not_pressed.png");
if (b[10].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[11].boutton=IMG_Load("fs_pressed.png");
if (b[11].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[12].boutton=IMG_Load("wd_not_pressed.png");
if (b[12].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[13].boutton=IMG_Load("wd_pressed.png");
if (b[13].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}

b[0].positionboutton.x=1000;
b[0].positionboutton.y=10;
b[2].positionboutton.x=1100;
b[2].positionboutton.y=10;
b[4].positionboutton.x=1200;
b[4].positionboutton.y=10;
b[6].positionboutton.x=120;    // position des images
b[6].positionboutton.y=500;
b[8].positionboutton.x=220;
b[8].positionboutton.y=500;
b[10].positionboutton.x=880;
b[10].positionboutton.y=430;
b[12].positionboutton.x=800;
b[12].positionboutton.y=580;

positionplay.x = 65;
positionplay.y = 350;
SDL_BlitSurface(play,NULL,screen,&positionplay);
positionsetting.x = 65;
positionsetting.y = 530;
SDL_BlitSurface(setting,NULL,screen,&positionsetting);
positioncredits.x = 1000;
positioncredits.y = 350;
SDL_BlitSurface(credits,NULL,screen,&positioncredits);
positionquit.x = 1000;
positionquit.y = 530;
SDL_BlitSurface(quit,NULL,screen,&positionquit);
SDL_Flip(screen);
continuer=1;
int playy=0;
int settingg=0,creditss=0;


while (continuer)
    {

SDL_BlitSurface(background,NULL,screen,&positionbackground);
    SDL_BlitSurface(play,NULL,screen,&positionplay);
    SDL_BlitSurface(setting,NULL,screen,&positionsetting);
    SDL_BlitSurface(credits,NULL,screen,&positioncredits);
    SDL_BlitSurface(quit,NULL,screen,&positionquit);
        SDL_WaitEvent(&event);
        switch(event.type) // CLACIER OU SOURIS .
        {
           
            case SDL_QUIT:
                continuer = 0;
                break;
case SDL_KEYUP:
            {
                //deplacement du clavier down
                if(event.key.keysym.sym==SDLK_DOWN)
                {
                    switch (position)
                    {
                    case 3 :
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                     
                        position =0;
                        break;
                    }
                    case 0 :
                    {
                        SDL_BlitSurface(setting1,NULL,screen,&positionsetting);
                       
                        position =1;
                        break;
                    }
                    case 1 :
                    {
                        SDL_BlitSurface(credits1,NULL,screen,&positioncredits);
                       
                        position=2;
                        break;
                    }
                    case 2 :
                    {
                        SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                       
                        position=3;
                        break;
                    }
                    case 4:
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                       
                        position =0;
                        break;
                    } SDL_Flip(screen);
                    }
                }
                //deplacement du clavier up

                else if ( event.key.keysym.sym == SDLK_UP )
                {
                    switch (position)
                    {
                    case 1 :
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                       
                        position=0;
                        break;

                    }
                    case 2 :
                    {
                        SDL_BlitSurface(setting1,NULL,screen,&positionsetting);
                       

                        position =1;
                        break;
                    }
                    case 3 :
                    {
                        SDL_BlitSurface(credits1,NULL,screen,&positioncredits);
                       

                        position=2;
                        break;
                    }

                    case 0 :
                    {
                        SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                       

                        position=3;
                        break;
                    }
                   case 4:
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                       
                        position =0;
                        break;
                    } SDL_Flip(screen);
                    }
}
                 else if ( event.key.keysym.sym == SDLK_LEFT )
                {
                    switch (position)
                    {
                    case 2 :
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                       
                        position=0;
                        break;

                    }
                    case 3 :
                    {
                        SDL_BlitSurface(setting1,NULL,screen,&positionsetting);
                       

                        position =1;
                        break;
                    }
                           case 4 :
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                       
                        position=0;
                        break;

                    }
                   
                   
                }
                }    else if ( event.key.keysym.sym == SDLK_RIGHT )
                {
                    switch (position)
                    {
                    case 0 :
                    {
                        SDL_BlitSurface(credits1,NULL,screen,&positioncredits);
                       
                        position=2;
                        break;

                    }
                    case 1 :
                    {
                        SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                       

                        position =3;
                        break;
                    }
                           case 4 :
                    {
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                       
                        position=0;
                        break;

                    }
            }}break;}
            case SDL_MOUSEBUTTONDOWN:
                        if(event.button.x >= positionquit.x && event.button.x <= (positionquit.x + 273) && event.button.y >= positionquit.y && event.button.y <= positionquit.y+138)
                             {
                                 Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                 SDL_Flip(screen);
                                 continuer = 0;
                             }
                        else if(event.button.x >= positioncredits.x && event.button.x <= (positioncredits.x + 273) && event.button.y >= positioncredits.y && event.button.y <= positioncredits.y+138)
                             {
                                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                SDL_Flip(screen);
                                SDL_BlitSurface(creditsbackground,NULL,screen,&positionbackground); // taswia fou9 l background.
                                for (i=0;i<7;i++)
                                SDL_BlitSurface(txt[i].text,NULL,screen,&txt[i].positiontext);
                                SDL_BlitSurface(b[0].boutton,NULL,screen,&b[0].positionboutton); // bsh nhoto l boutton w text f blayeshom
                                SDL_Flip(screen);
                                creditss=1;
                                while (creditss==1)
                                {
                                    SDL_WaitEvent(&event3);
                                    switch(event3.type)
                                    {
                                        case SDL_KEYDOWN:
                                            switch (event3.key.keysym.sym)
                                            {
                                            case SDLK_ESCAPE:
                                                creditss=0;
                                            break;
                                            }
                                        break;
                                        case SDL_MOUSEMOTION:
                                            if(event3.motion.x >= b[0].positionboutton.x && event3.motion.x <= (b[0].positionboutton.x + 108) && event3.motion.y >= b[0].positionboutton.y && event3.motion.y <= b[0].positionboutton.y+98)
                                                {
                                                    SDL_BlitSurface(b[1].boutton,NULL,screen,&b[0].positionboutton);
                                                    SDL_Flip(screen);  // home button pressed
                                                }
                                            else
                                                SDL_BlitSurface(b[0].boutton,NULL,screen,&b[0].positionboutton);
                                                SDL_Flip(screen);
                                        break;
                                        case SDL_MOUSEBUTTONDOWN:
                                            if(event3.button.x >= b[0].positionboutton.x && event3.button.x <= (b[0].positionboutton.x + 108) && event3.button.y >= b[0].positionboutton.y && event3.button.y <= b[0].positionboutton.y+98)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                    SDL_Flip(screen);
                                                    creditss=0;
                                                }
                                    }
                                }
                               
                             }
                        else if(event.button.x >= positionsetting.x && event.button.x <= (positionsetting.x + 273) && event.button.y >= positionsetting.y && event.button.y <= positionsetting.y+138)
                              {
                                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                SDL_Flip(screen);
                                SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                for(i=0;i<13;i=i+2) // 14 images 2 cas
                                SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                SDL_Flip(screen);
                                settingg=1;
                                while (settingg==1)
                                {
                                    SDL_WaitEvent(&event2);
                                    switch(event2.type)
                                    {
                                        case SDL_MOUSEMOTION:
                                            if(event2.motion.x >= b[0].positionboutton.x && event2.motion.x <= (b[0].positionboutton.x + 108) && event2.motion.y >= b[0].positionboutton.y && event2.motion.y <= b[0].positionboutton.y+98) // home botton
                                                {
                                                    SDL_BlitSurface(b[1].boutton,NULL,screen,&b[0].positionboutton); // home booton pressed
                                                   
                                                }
                                            else if(event2.motion.x >= b[2].positionboutton.x && event2.motion.x <= (b[2].positionboutton.x + 108) && event2.motion.y >= b[2].positionboutton.y && event2.motion.y <= b[2].positionboutton.y+98)
                                                {
                                                    SDL_BlitSurface(b[3].boutton,NULL,screen,&b[2].positionboutton);

                                                }
                                            else if(event2.motion.x >= b[4].positionboutton.x && event2.motion.x <= (b[4].positionboutton.x + 108) && event2.motion.y >= b[4].positionboutton.y && event2.motion.y <= b[4].positionboutton.y+98)
                                                {
                                                    SDL_BlitSurface(b[5].boutton,NULL,screen,&b[4].positionboutton);

                                                }
                                            else if(event2.motion.x >= b[6].positionboutton.x && event2.motion.x <= (b[6].positionboutton.x + 78) && event2.motion.y >= b[6].positionboutton.y && event2.motion.y <= b[6].positionboutton.y+63)
                                                {
                                                    SDL_BlitSurface(b[7].boutton,NULL,screen,&b[6].positionboutton);
                                                   
                                                }
                                            else if(event2.motion.x >= b[8].positionboutton.x && event2.motion.x <= (b[8].positionboutton.x + 78) && event2.motion.y >= b[8].positionboutton.y && event2.motion.y <= b[8].positionboutton.y+63)
                                                {
                                                    SDL_BlitSurface(b[9].boutton,NULL,screen,&b[8].positionboutton);
                                                   
                                                }
                                            else if(event2.motion.x >= b[10].positionboutton.x && event2.motion.x <= (b[10].positionboutton.x + 486) && event2.motion.y >= b[10].positionboutton.y && event2.motion.y <= b[10].positionboutton.y+123)
                                                {
                                                    SDL_BlitSurface(b[11].boutton,NULL,screen,&b[10].positionboutton);
                                                   
                                                }
                                            else if(event2.motion.x >= b[12].positionboutton.x && event2.motion.x <= (b[12].positionboutton.x + 486) && event2.motion.y >= b[12].positionboutton.y && event2.motion.y <= b[12].positionboutton.y+123)
                                                {
                                                    SDL_BlitSurface(b[13].boutton,NULL,screen,&b[12].positionboutton);
                                                   
                                                }
                                            else
                                                {
                                                    for(i=0;i<13;i=i+2)
                                                    SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                   
                                                }SDL_Flip(screen);
                                            break;
                                        case SDL_MOUSEBUTTONDOWN:
                                            if(event2.button.x >= b[0].positionboutton.x && event2.button.x <= (b[0].positionboutton.x + 108) && event2.button.y >= b[0].positionboutton.y && event2.button.y <= b[0].positionboutton.y+98)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                    SDL_Flip(screen);
                                                    settingg=0;
                                                }
                                            else if(event2.button.x >= b[2].positionboutton.x && event2.button.x <= (b[2].positionboutton.x + 108) && event2.button.y >= b[2].positionboutton.y && event2.button.y <= b[2].positionboutton.y+98)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic (sout mta clic)
                                                    SDL_Flip(screen);
                                                    Mix_VolumeChunk(clic,0);
                                                    Mix_PauseMusic(); //pause lil souuut
                                                }
                                            else if(event2.button.x >= b[4].positionboutton.x && event2.button.x <= (b[4].positionboutton.x + 108) && event2.button.y >= b[4].positionboutton.y && event2.button.y <= b[4].positionboutton.y+98)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                    SDL_Flip(screen);
                                                    Mix_VolumeChunk(clic,MIX_MAX_VOLUME/2);
                                                    Mix_ResumeMusic();
                                                }
                                            else if(event2.button.x >= b[6].positionboutton.x && event2.button.x <= (b[6].positionboutton.x + 78) && event2.button.y >= b[6].positionboutton.y && event2.button.y <= b[6].positionboutton.y+63)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                    SDL_Flip(screen);
                                                if (volume>0)
                                                {
                                                    volume=volume-16;
                                                }
                                                Mix_VolumeMusic(volume);
                                                }
                                            else if(event2.button.x >= b[8].positionboutton.x && event2.button.x <= (b[8].positionboutton.x + 78) && event2.button.y >= b[8].positionboutton.y && event2.button.y <= b[8].positionboutton.y+63)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                    SDL_Flip(screen);
                                                if (volume<128)
                                                {
                                                    volume=volume+16;
                                                }
                                                Mix_VolumeMusic(volume);
                                                }
                                            else if(event2.button.x >= b[10].positionboutton.x && event2.button.x <= (b[10].positionboutton.x + 486) && event2.button.y >= b[10].positionboutton.y && event2.button.y <= b[10].positionboutton.y+123)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
screen=SDL_SetVideoMode(1366,766,32,SDL_HWSURFACE | SDL_FULLSCREEN); // Ouverture de la fenêtre
if(!screen)
{
printf("unable to set 1280x800 video: %s\n",SDL_GetError());
return (-1);
}
SDL_WM_SetCaption("where i am", NULL);
SDL_BlitSurface(background,&positionbackground,screen,&positionbackground); 
                                                  SDL_Flip(screen);
                                                  //  printf("cant go fullscreen\n");
                                                }
                                            else if(event2.button.x >= b[12].positionboutton.x && event2.button.x <= (b[12].positionboutton.x + 486) && event2.button.y >= b[12].positionboutton.y && event2.button.y <= b[12].positionboutton.y+123)
                                                {
                                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                    SDL_Flip(screen);
screen=SDL_SetVideoMode(1366,766,32,SDL_HWSURFACE | SDL_DOUBLEBUF); 
if(!screen)
{
printf("unable to set 1280x800 video: %s\n",SDL_GetError());
return (-1);
}
SDL_WM_SetCaption("where i am", NULL);
SDL_BlitSurface(background,&positionbackground,screen,&positionbackground); 
        SDL_Flip(screen);
                                                }
                                            break;
                                        case SDL_KEYDOWN:
                                            switch (event2.key.keysym.sym)
                                            {

                                            case SDLK_ESCAPE:
                                                settingg=0; // yokhrrej mil setup escp
                                                break;
                                            case SDLK_LEFT:
                                                SDL_BlitSurface(b[7].boutton,NULL,screen,&b[6].positionboutton);
                                                Mix_PlayChannel(1,clic,0);
                                                SDL_Flip(screen);
                                                if (volume>0)
                                                {
                                                    volume=volume-16;
                                                }
                                                Mix_VolumeMusic(volume);
                                                break;
                                            case SDLK_RIGHT:
                                                SDL_BlitSurface(b[9].boutton,NULL,screen,&b[8].positionboutton);
                                                Mix_PlayChannel(1,clic,0);
                                                SDL_Flip(screen);
                                                if (volume<128)
                                                {
                                                    volume=volume+16;
                                                }
                                                Mix_VolumeMusic(volume);
                                                break;
                                            }
                                    }
                                }
                               
                              }
                        else if(event.button.x >= positionplay.x && event.button.x <= (positionplay.x + 273) && event.button.y >= positionplay.y && event.button.y <= positionplay.y+138)
                              {
                                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                SDL_Flip(screen);
                                SDL_BlitSurface(playbackground,NULL,screen,&positionbackground);
                                SDL_Flip(screen);
                                playy=1;
                                while (playy==1)
                                {
                                    SDL_WaitEvent(&event1);
                                    switch(event1.type)
                                    {
                                        case SDL_KEYDOWN:
                                            switch (event1.key.keysym.sym)
                                            {
                                            case SDLK_ESCAPE:
                                                playy=0;
                                                break;
                                            }
                                    }
                                }
                               
                              }
                             break;
            case SDL_MOUSEMOTION:
                        if(event.motion.x >= positionquit.x && event.motion.x <= (positionquit.x + 273) && event.motion.y >= positionquit.y && event.motion.y <= positionquit.y+138)
                             {
                                 SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                               
                             }
                        else if(event.button.x >= positioncredits.x && event.button.x <= (positioncredits.x + 273) && event.button.y >= positioncredits.y && event.button.y <= positioncredits.y+138)
                             {
                                 SDL_BlitSurface(credits1,NULL,screen,&positioncredits);
                               
                             }
                        else if(event.motion.x >= positionsetting.x && event.motion.x <= (positionsetting.x + 273) && event.motion.y >= positionsetting.y && event.motion.y <= positionsetting.y+138)
                              {
                                 SDL_BlitSurface(setting1,NULL,screen,&positionsetting);
                               
                              }
                        else if(event.motion.x >= positionplay.x && event.motion.x <= (positionplay.x + 273) && event.motion.y >= positionplay.y && event.motion.y <= positionplay.y+138)
                              {
                                 SDL_BlitSurface(play1,NULL,screen,&positionplay);
                               
                              }
                       SDL_Flip(screen);
                        break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_p:
                    SDL_BlitSurface(play1,NULL,screen,&positionplay);
                    Mix_PlayChannel(1, clic, 0);
                    SDL_Flip(screen);
                    SDL_BlitSurface(playbackground,NULL,screen,&positionbackground);
                    SDL_Flip(screen);
                    playy=1;
                    while (playy==1)
                    {
                        SDL_WaitEvent(&event1);
                        switch(event1.type)
                        {
                            case SDL_KEYDOWN:
                                switch (event1.key.keysym.sym)
                                {
                                case SDLK_ESCAPE:
                                    playy=0;
                                    break;
                                }
                        }
                    }
                   
                    break;
                    case SDLK_ESCAPE:
                    Mix_PlayChannel(1, clic, 0);
                    SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                    SDL_Flip(screen);
                    continuer=0;
                    break;
                }
        }SDL_Flip(screen);
     
    }
Mix_CloseAudio(); //Fermeture de l'API
SDL_Quit(); // Arrêt de la SDL
return EXIT_SUCCESS; // Fermeture du programme
}
