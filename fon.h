#ifndef FON_H_INCLUDED
#define FON_H_INCLUDED

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
int menu(int argc, char *argv[]);

#endif // FON_H_INCLUDED

