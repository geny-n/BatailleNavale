//
//* main.c
//* test4
//
//* Created by Benoit Castagnetto on 10/02/2016.
//* Copyright © 2016 Benoit Castagnetto. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main (int argc, char** argv)
{
TTF_Init();
    SDL_Window *ecran = NULL;
    SDL_Surface *texte = NULL; //*fond = NULL;
    TTF_Font *police = NULL;
    SDL_Color couleur = {180, 180, 180};


    ecran = SDL_CreateWindow("BIENVENU SUR NOTRE JEU DE BATAILLE NAVALE !!!", 300, 300, 640, 480, SDL_WINDOW_SHOWN);
    texte = TTF_RenderText_Blended(police, "Salut", couleur);

    TTF_Quit();
    SDL_Quit();

    return 0;
}
