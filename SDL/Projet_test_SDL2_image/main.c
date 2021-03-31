#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

//fonction qui affiche les grilles
void affiche(char (*pQ)[8]){
	int i, j;
    printf("        1       2       3       4       5       6       7       8");
    printf("\n");
	for(i=0; i<8; i++)
	{   printf("%d",i+1);
        printf("       ");
		for(j=0; j<8; j++)
		{
			printf("%c\t", (*(pQ + i))[j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}


int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture, *tmp = NULL;
    SDL_Surface *surface = NULL;


    if (NULL != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }

    {
        window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 1000, SDL_WINDOW_FULLSCREEN);

        if(window)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if ( renderer )
            {
                surface = SDL_LoadBMP("test.bmp");//chargement de l'image
                if (surface)
                {
                    texture = SDL_CreateTextureFromSurface(renderer, surface);
                    if (texture)
                    {
                        //SDL_Rect dest = { 575 - surface->w/2,480 - surface->h/2, 1000, 500};//un SDL_Rect qui sers de destination à l'image
                        SDL_RenderCopy(renderer, texture, NULL, 0); // copie de surface grâce au SDL_Renderer

                        SDL_RenderPresent(renderer); //Affichage
                        SDL_Delay(3000);

                        SDL_DestroyTexture(texture);//fin de programme, destruction des entitées utilisées
                    }
                    else
                    {
                        fprintf(stderr, "Echec de création de la texture : %s", SDL_GetError());
                    }
                    SDL_FreeSurface (surface);

                }
                else
                {
                    fprintf(stderr, "Echec de chargement du sprite : %s ", SDL_GetError());
                }
                SDL_DestroyRenderer(renderer);
            }
            else
            {
                fprintf(stderr, "echec de création du renderer : %s", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, "Erreur creation window : %s", SDL_GetError());
        }
    }

    SDL_Quit();

int i,j,k;
int tc1=0, tc2=0;
char tab[64],machaine[24];
int c1,c2;
FILE* fichier = NULL;

//grille_j1 représente la grille du joueur numéro 1
//grille_j2 représente la grille du joueur numéro 2 ou du PC
char grille_j1[8][8];
char grille_j1_tirs[8][8];
char grille_j2[8][8];
char grille_j2_tirs[8][8];


//initialisation des deux grilles à la valeur "-"
    for (i = 0; i < 8; i = i + 1){
        for (j = 0; j < 8; j = j + 1){
        grille_j1[i][j] = '-';
        grille_j2[i][j] = '-';
        grille_j1_tirs[i][j] = '-';
        grille_j2_tirs[i][j] = '-';
        }
    }

    printf("\n\n            Nouvelle partie (entrez 0) ou reprise d'une partie entam%ce (entrez 1)    ",130);
    scanf("%d",&k);
    printf("%d",k);
    if (k == 1)
    goto charger;

//Rappel des règles
    printf("       Pr%ct pour la bataille !!\n",136);
    printf("       1. Vous avez trois b%ctiments : un Torpilleur (2 cases), un Croiseur (3 cases) et un Porte-avions (4 cases)\n",131);
    printf("       2. La grille a une dimension de 8x8; x correspond %c l'axe vertical et y %c l'axe horizontal\n",133,133);
    printf("       3. Les coordonn%ces x et y sont des entiers compris entre 1 et 8\n",130);
    printf("       4. Pour stopper la partie en cours de jeu, le joueur J1 doit entrer un 99 comme une des coordonn%ces de tir",130);

//mise en place des bâtiments par le joueur j1
    printf("\nJOUEUR J1\n");
    for (i = 0; i < 3; i = i + 1){
    if (i==0)
    printf("\nEntrez les coordonn%ces x et y du Torpilleur : \n",130);
    else if (i==1)
    printf("\nEntrez les coordonn%ces x et y du Croiseur : \n",130);
    else
    printf("\nEntrez les coordonn%ces x et y du Porte-avions : \n",130);
    for (j = 0; j < i + 2; j = j + 1){
    printf("Entrez x (entre 1 et 8) : ");
    scanf("%d", &c1);
    printf("Entrez y (entre 1 et 8) : ");
    scanf("%d", &c2);
    if (i==0)
    grille_j1[c1-1][c2-1] = 'T';
    else if (i==1)
    grille_j1[c1-1][c2-1] = 'C';
    else
    grille_j1[c1-1][c2-1] = 'P';
    system("cls");
    affiche(grille_j1);
    }
    }
    //sauvegarde(grille_j1);
    //FILE* fichier = NULL;
    fichier = fopen("grille_j1.txt","w");
	fputs(grille_j1[0],fichier);
    fclose(fichier);
    system("PAUSE");
    system("cls");


//mise en place des bâtiments par le joueur j2
    printf("\nJOUEUR J2\n");
    for (i = 0; i < 3; i = i + 1){
    if (i==0)
    printf("\nEntrez les coordonn%ces x et y du Torpilleur : \n",130);
    else if (i==1)
    printf("\nEntrez les coordonn%ces x et y du Croiseur : \n",130);
    else
    printf("\nEntrez les coordonn%ces x et y du Porte-avions : \n",130);
    for (j = 0; j < i + 2; j = j + 1){
    printf("Entrez x (entre 1 et 8) : ");
    scanf("%d", &c1);
    printf("Entrez y (entre 1 et 8) : ");
    scanf("%d", &c2);
    if (i==0)
    grille_j2[c1-1][c2-1] = 'T';
    else if (i==1)
    grille_j2[c1-1][c2-1] = 'C';
    else
    grille_j2[c1-1][c2-1] = 'P';
    system("cls");
    affiche(grille_j2);
    }
    }

//sauvegarde(grille_j2);
    fichier = fopen("grille_j2.txt","w");
	fputs(grille_j2[0],fichier);
    fclose(fichier);
    system("PAUSE");
    system("cls");

jeu:
//Déroulement du jeu
    for (i = 0; i < 64; i = i + 1){
        printf("\nTir JOUEUR J1\n");
        printf("Entrez x (entre 1 et 8) : ");
        scanf("%d", &c1);
        printf("Entrez y (entre 1 et 8) : ");
        scanf("%d", &c2);
        if (c1 == 99 || c2 == 99){
        printf("\nPARTIE STOPPEE\n");
        exit(0);
        }
        c1 = c1-1; c2=c2-1;
        if (grille_j2[c1][c2] == 'T' || grille_j2[c1][c2] == 'C' || grille_j2[c1][c2] == 'P'){
        printf("Touch%c !!\n",130);
        grille_j1_tirs[c1][c2] = 'O';
        if (grille_j2[c1][c2] == 'T') tc1 = tc1 + 1;
        if (grille_j2[c1][c2] == 'C') tc1 = tc1 + 10;
        if (grille_j2[c1][c2] == 'P' && tc1 < 100) tc1 = tc1 + 100;
        if (tc1 >= 111) {
            printf("\nVOUS AVEZ GAGNE !!!\n");
            system("PAUSE");}
        }
        else {printf("Dans l'eau !!\n");
        grille_j1_tirs[c1][c2] = 'X';}
        affiche(grille_j1_tirs);

        system("cls");
        printf("\nTir JOUEUR J2\n");
        printf("Entrez x (entre 1 et 8) : ");
        scanf("%d", &c1);
        printf("Entrez y (entre 1 et 8) : ");
        scanf("%d", &c2);
        c1 = c1-1; c2=c2-1;
        if (grille_j1[c1][c2] == 'T' || grille_j1[c1][c2] == 'C' || grille_j1[c1][c2] == 'P'){
        printf("Touch%c !!\n",130);
        grille_j2_tirs[c1][c2] = 'O';
        if (grille_j1[c1][c2] == 'T') tc2 = tc2 + 1;
        if (grille_j1[c1][c2] == 'C') tc2 = tc2 + 10;
        if (grille_j1[c1][c2] == 'P' && tc2 < 100) tc2 = tc2 + 100;
        if (tc2 >= 111) {
            printf("\nVOUS AVEZ GAGNE !!!\n");
            system("PAUSE");}
        }
        else {printf("Dans l'eau !!\n");
        grille_j2_tirs[c1][c2] = 'X';}
        affiche(grille_j2_tirs);
        system("PAUSE");

sauvegarde_tir:
//sauvegarde(grille_j1_tirs);
        fichier = fopen("grille_j1_tir.txt","w");
        fputs(*grille_j1_tirs,fichier);
        fclose(fichier);

//sauvegarde (grille_j2_tirs);
        fichier = fopen("grille_j2_tir.txt","w");
        fputs(*grille_j2_tirs,fichier);
        fclose(fichier);
        system("cls");
        system("PAUSE");

//sauvegarde touché-coulé;
        fichier = fopen("tc1.txt","w");
        itoa (tc1,machaine,10);
        fputs(machaine,fichier);
        fclose(fichier);
        system("cls");
        system("PAUSE");

        fichier = fopen("tc2.txt","w");
        itoa (tc2,machaine,10);
        fputs(machaine,fichier);
        fclose(fichier);
        system("cls");
        system("PAUSE");
     }


charger:
//charger (grille_j1);
        fichier = fopen("grille_j1.txt","r");
            for(i=0;i<64;i++)
            fscanf(fichier,"%c\n",tab+i);
        fclose(fichier);
            for(i=0;i<8;i++){
            for(j=0;j<8;j++)
            grille_j1[i][j] = tab[i*8+j];
            }
        printf("Grille de J1\n");
        affiche(grille_j1);
        system("PAUSE");
        system("cls");

//charger (grille_j2);
        fichier = fopen("grille_j2.txt","r");
            for(i=0;i<64;i++)
            fscanf(fichier,"%c\n",tab+i);
        fclose(fichier);
            for(i=0;i<8;i++){
            for(j=0;j<8;j++)
            grille_j2[i][j] = tab[i*8+j];
            }
        printf("Grille de J2\n");
        affiche(grille_j2);
        system("PAUSE");
        system("cls");

//charger (grille_j1_tirs);
        fichier = fopen("grille_j1_tir.txt","r");
            for(i=0;i<64;i++)
            fscanf(fichier,"%c\n",tab+i);
        fclose(fichier);
            for(i=0;i<8;i++){
            for(j=0;j<8;j++)
            grille_j1_tirs[i][j] = tab[i*8+j];
            }
        affiche(grille_j1_tirs);

//charger (grille_j2_tirs);
        fichier = fopen("grille_j2_tir.txt","r");
            for(i=0;i<64;i++)
            fscanf(fichier,"%c\n",tab+i);
        fclose(fichier);
            for(i=0;i<8;i++){
            for(j=0;j<8;j++)
            grille_j2_tirs[i][j] = tab[i*8+j];
            }
        affiche(grille_j2_tirs);

//charger tc1 et tc2;
   fichier = fopen("tc1.txt" , "r");
   fgets (machaine, 60, fichier);
   fclose(fichier);
        tc1 = atoi(machaine);
        printf("%d\n",tc1);
     fichier = fopen("tc2.txt" , "r");
   fgets(machaine, 60, fichier);
   fclose(fichier);
        tc2 = atoi(machaine);
        printf("%d\n",tc2);
        system("PAUSE");

        goto jeu;
        return(0);

}
