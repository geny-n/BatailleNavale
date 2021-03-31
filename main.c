
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//ramdom
//#include <SDL.h>

//fonction qui affiche les grilles
void affiche(char (*ptab)[8]){
	int i, j;
    printf("                        1       2       3       4       5       6       7       8");
    printf("\n");
	for(i=0; i<8; i++){
	    printf("\t\t%d",i+1);
        //printf("       ");
            for(j=0; j<8; j++){
                printf("\t%c", (*(ptab + i))[j]);
            }
		printf("\n");
	}
	printf("\n");
	return;
}

//fonction qui retourne un nombre entier au hazard compris entre imin et imax
int Random (int _iMin, int _iMax){
    srand (time (NULL)); //source de démmarage de la fonction rand
    return (_iMin + (rand () % (_iMax-_iMin+1)));// () epres % donne la valeur maximale de l'entier retourné
}

int main(int argc, char *argv[])
{

//SDL_Init(SDL_INIT_EVERYTHING);

int i,j,k,mPC;
//k = reprendre ou nouvelle partie
int tc1=0, tc2=0;
char tab[64],machaine[24],Joueur1[24],Joueur2[24];
int c1,c2;
FILE* fichier = NULL;
int iRandomPx, iRandomPy,iRandomD;


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
printf("\n\n\n\n\n\n");
printf("                       _________________________________________________________________________");
printf("                                                                                 \n");
printf("                                           BIENVENUE SUR LE CHAMP DE BATAILLE                    \n");
printf("                                                                                 \n");
printf("                       _________________________________________________________________________\n\n");


printf("                                                                      R%calisation de Ghassen et Ninon\n\n\n\n\n\n\n\n\n\n",130);//130 pur é (%c)
    getch();//pause
    i = 0;
    system("cls");
    while(i == 0){
        printf("\n\n            Partie %c deux (entrez 0) ou partie contre le PC (entrez 1)   ",133);
        scanf("%d",&mPC);
        if (mPC==0 || mPC == 1)
           break;
        else
            printf("\n\n            ERREUR !! ");
    }
    printf("\n\n            Votre pseudo :   ");
    scanf("%s",Joueur1);
    if(mPC == 0){ //losqu'y a 2 joueurs
    printf("\n\n            Pseudo du second joueur :   ");
    scanf("%s",Joueur2);
    }

//choisir la partie
    i = 0;
    system("cls");
    while(i == 0){
        printf("\n\n            Nouvelle partie (entrez 0) ou reprise d'une partie entam%ce (entrez 1)   ",130);
        scanf("%d",&k);
        if (k==0 || k == 1)
            break;
        else
            printf("\n\n            ERREUR !! ");
    }

    if (k == 1)
    goto charger;

//Rappel des règles
    system("cls");
    printf("       Pr%ct pour la bataille !!\n\n",136);
    printf("       1. Vous avez trois b%ctiments : un Torpilleur (2 cases), un Croiseur (3 cases) et un Porte-avions (4 cases)\n",131);
    printf("       2. La grille a une dimension de 8x8; x correspond %c l'axe vertical et y %c l'axe horizontal\n",133,133);
    printf("       3. Les coordonn%ces x et y sont des entiers compris entre 1 et 8\n",130);
    printf("       4. Pour stopper la partie en cours de jeu, le joueur J1 doit entrer un 99 comme une des coordonn%ces de tir",130);

//mise en place des bâtiments par le joueur j1
    printf("\n\n   A toi de jouer %s\n",Joueur1);
    for (i = 0; i < 3; i = i + 1){
    if (i==0)
    printf("\n        Entrez les coordonn%ces x et y du Torpilleur : \n",130);
    else if (i==1)
    printf("\n        Entrez les coordonn%ces x et y du Croiseur : \n",130);
    else
    printf("\n        Entrez les coordonn%ces x et y du Porte-avions : \n",130);
    for (j = 0; j < i + 2; j = j + 1){
    printf("        Entrez x (entre 1 et 8) : ");
    scanf("%d", &c1);
    printf("        Entrez y (entre 1 et 8) : ");
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
    system("PAUSE");// =getch
    system("cls");


//mise en place des bâtiments par le joueur j2 ou par le PC
    if(mPC == 0){
        printf("\n\n   A toi de jouer %s\n",Joueur2);
        for (i = 0; i < 3; i = i + 1){
            if (i==0)
                printf("\n        Entrez les coordonn%ces x et y du Torpilleur : \n",130);
            else if (i==1)
                printf("\n        Entrez les coordonn%ces x et y du Croiseur : \n",130);
            else
                printf("\n        Entrez les coordonn%ces x et y du Porte-avions : \n",130);

            for (j = 0; j < i + 2; j = j + 1){
            printf("        Entrez x (entre 1 et 8) : ");
            scanf("%d", &c1);
            printf("        Entrez y (entre 1 et 8) : ");
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
    } else {
    //Construction grille PC
        k = 0;
        while(k != 55){ //boucle pour vérifier qu'il n'y a pas eu ded chevauchement de bateau, les trois bateaux sont visibles
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    grille_j2[i][j] = '-';//initialisation du tableau du pc avec "-"
                }
            }

    //Coordonn%ces PC x et y du Torpilleur
            iRandomPx = Random (1,8);
            iRandomPy = Random (1,8);
            iRandomD = Random (1,4);//orientation
            grille_j2[iRandomPx-1][iRandomPy-1] = 'T';//position du la première case du bateau
                if(iRandomD == 1 && 0<=iRandomPx-2<8) grille_j2[iRandomPx-2][iRandomPy-1] = 'T';//direction en haut
                if(iRandomD == 2 && 0<=iRandomPy<8) grille_j2[iRandomPx-1][iRandomPy] = 'T';//à droite
                if(iRandomD == 3 && 0<=iRandomPx<8) grille_j2[iRandomPx][iRandomPy-1] = 'T';//en bas
                if(iRandomD == 4 && 0<=iRandomPy-2<8) grille_j2[iRandomPx-1][iRandomPy-2] = 'T';//à gauche

    //Coordonn%ces PC x et y du Croiseur
            iRandomPx = Random (1,8);
            iRandomPy = Random (1,8);
            iRandomD = Random (1,4);
            grille_j2[iRandomPx-1][iRandomPy-1] = 'C';
                if(iRandomD == 1 && 0<=iRandomPx-2<8) grille_j2[iRandomPx-2][iRandomPy-1] = 'C';//en haut
                if(iRandomD == 2 && 0<=iRandomPy<8) grille_j2[iRandomPx-1][iRandomPy] = 'C';//a droite
                if(iRandomD == 3 && 0<=iRandomPx<8) grille_j2[iRandomPx][iRandomPy-1] = 'C';//en bas
                if(iRandomD == 4 && 0<=iRandomPy-2<8) grille_j2[iRandomPx-1][iRandomPy-2] = 'C';//a gauche

                if(iRandomD == 1 && 0<=iRandomPx-3<8) grille_j2[iRandomPx-3][iRandomPy-1] = 'C';//en haut
                if(iRandomD == 2 && 0<=iRandomPy+1<8) grille_j2[iRandomPx-1][iRandomPy+1] = 'C';//a droite
                if(iRandomD == 3 && 0<=iRandomPx+1<8) grille_j2[iRandomPx+1][iRandomPy-1] = 'C';//en bas
                if(iRandomD == 4 && 0<=iRandomPy-3<8) grille_j2[iRandomPx-1][iRandomPy-3] = 'C';//a gauche

    //Coordonn%ces PC x et y du Porte-avions
            iRandomPx = Random (1,8);
            iRandomPy = Random (1,8);
            iRandomD = Random (1,4);
            grille_j2[iRandomPx-1][iRandomPy-1] = 'P';
                if(iRandomD == 1 && 0<=iRandomPx-2<8) grille_j2[iRandomPx-2][iRandomPy-1] = 'P';
                if(iRandomD == 2 && 0<=iRandomPy<8) grille_j2[iRandomPx-1][iRandomPy] = 'P';
                if(iRandomD == 3 && 0<=iRandomPx<8) grille_j2[iRandomPx][iRandomPy-1] = 'P';
                if(iRandomD == 4 && 0<=iRandomPy-2<8) grille_j2[iRandomPx-1][iRandomPy-2] = 'P';

                if(iRandomD == 1 && 0<=iRandomPx-3<8) grille_j2[iRandomPx-3][iRandomPy-1] = 'P';
                if(iRandomD == 2 && 0<=iRandomPy+1<8) grille_j2[iRandomPx-1][iRandomPy+1] = 'P';
                if(iRandomD == 3 && 0<=iRandomPx+1<8) grille_j2[iRandomPx+1][iRandomPy-1] = 'P';
                if(iRandomD == 4 && 0<=iRandomPy-3<8) grille_j2[iRandomPx-1][iRandomPy-3] = 'P';

                if(iRandomD == 1 && 0<=iRandomPx-4<8) grille_j2[iRandomPx-4][iRandomPy-1] = 'P';
                if(iRandomD == 2 && 0<=iRandomPy+2<8) grille_j2[iRandomPx-1][iRandomPy+2] = 'P';
                if(iRandomD == 3 && 0<=iRandomPx+2<8) grille_j2[iRandomPx+2][iRandomPy-1] = 'P';
                if(iRandomD == 4 && 0<=iRandomPy-4<8) grille_j2[iRandomPx-1][iRandomPy-4] = 'P';

            //compter les cases ou il y a "-" jusq'a ce que k=55
            k=0;
            for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    if(grille_j2[i][j] == '-')
                        k=k+1;
                }
            }
        }
        system("cls");
        printf("\n                    Grille du PC\n\n");
        affiche(grille_j2);
        getch();
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
        tirJ1:
        system("cls");
        printf("\n        Tir JOUEUR %s\n",Joueur1);
        printf("        Entrez x (entre 1 et 8) : ");
        scanf("%d", &c1);
        printf("        Entrez y (entre 1 et 8) : ");
        scanf("%d", &c2);
            if (grille_j1_tirs[c1-1][c2-1] == 'O'|| grille_j1_tirs[c1][c2] == 'X'){
            printf("\n        TIR DEJA EFFECTUE. CHOISIR D'AUTRES COORDONNEES.\n");
            system("PAUSE"); goto tirJ1;
            }
            if (c1 == 99 || c2 == 99){
            printf("\n        PARTIE STOPPEE\n");
            exit(0);
            }
        c1 = c1-1; c2=c2-1;
        if (grille_j2[c1][c2] == 'T' || grille_j2[c1][c2] == 'C' || grille_j2[c1][c2] == 'P'){
            printf("        Touch%c !!\n",130);
            system("PAUSE");
            grille_j1_tirs[c1][c2] = 'O';
            if (grille_j2[c1][c2] == 'T')
                tc1 = tc1 + 1;
            if (grille_j2[c1][c2] == 'C')
                tc1 = tc1 + 10;
            if (grille_j2[c1][c2] == 'P' && tc1 < 100)
                tc1 = tc1 + 100;
            if (tc1 >= 111) {
                    printf("\n\n\n\n\n\n");
                    printf("                       _________________________________________________________________________");
                    printf("                                                                                 \n");
                    printf("                                             BRAVO %s TU AS GAGNE !!                    \n",Joueur1);
                    printf("                                                                                 \n");
                    printf("                       _________________________________________________________________________\n\n");


                system("PAUSE");}
        }
        else {
            printf("Dans l'eau !!\n");
            grille_j1_tirs[c1][c2] = 'X';
        }
        affiche(grille_j1_tirs);
        system("PAUSE");

//cas à 2 joueurs ou PC
        if (mPC == 0){
            tirJ2:
            system("cls");
            printf("\n        Tir JOUEUR %s\n",Joueur2);
        } else {
            printf("\n        Le PC a r%calis%c son tir\n",130,130);
            system("PAUSE");
        }
        if(mPC == 0){
            printf("        Entrez x (entre 1 et 8) : ");
            scanf("%d", &c1);
            printf("        Entrez y (entre 1 et 8) : ");
            scanf("%d", &c2);
                if (grille_j2_tirs[c1-1][c2-1] == 'O'|| grille_j2_tirs[c1][c2] == 'X'){
                    printf("\n        TIR DEJA EFFECTUE. CHOISIR D'AUTRES COORDONNEES.\n");
                    system("PAUSE"); goto tirJ2;
                }
            c1 = c1-1; c2=c2-1;
        }else{
            iRandomPx = Random (1,8);
            iRandomPy = Random (1,8);
            c1 = iRandomPx-1; c2=iRandomPy-1;
        }
        if (grille_j1[c1][c2] == 'T' || grille_j1[c1][c2] == 'C' || grille_j1[c1][c2] == 'P'){
        printf("        Touch%c !!\n",130);
        affiche(grille_j2_tirs);
        system("PAUSE");
        grille_j2_tirs[c1][c2] = 'O';
        if (grille_j1[c1][c2] == 'T') tc2 = tc2 + 1;
        if (grille_j1[c1][c2] == 'C') tc2 = tc2 + 10;
        if (grille_j1[c1][c2] == 'P' && tc2 < 100) tc2 = tc2 + 100;
        if (tc2 >= 111 && mPC == 0) {
printf("\n\n\n\n\n\n");
printf("                       _________________________________________________________________________");
printf("                                                                                 \n");
printf("                                                BRAVO %s TU AS GAGNE !!                    \n",Joueur2);
printf("                                                                                 \n");
printf("                       _________________________________________________________________________\n\n");


        system("PAUSE");}

        if (tc2 >= 111 && mPC == 1) {
printf("\n\n\n\n\n\n");
printf("                       _________________________________________________________________________");
printf("                                                                                 \n");
printf("                                            H%cLAS %s LA MACHINE VOUS A BATTU !                    \n",144,Joueur1);
printf("                                                                                 \n");
printf("                       _________________________________________________________________________\n\n");


        system("PAUSE");}

        }
        else {printf("Dans l'eau !!\n");
        grille_j2_tirs[c1][c2] = 'X';
        affiche(grille_j2_tirs);
        system("PAUSE");}

sauvegarde_tir:
//sauvegarde(grille_j1_tirs);
        fichier = fopen("grille_j1_tirs.txt","w");
        fputs(*grille_j1_tirs,fichier);
        fclose(fichier);

//sauvegarde (grille_j2_tirs);
        fichier = fopen("grille_j2_tirs.txt","w");
        fputs(*grille_j2_tirs,fichier);
        fclose(fichier);
        system("cls");

//sauvegarde touché-coulé;
        fichier = fopen("tc1.txt","w");
        itoa (tc1,machaine,10);
        fputs(machaine,fichier);
        fclose(fichier);
        system("cls");
        //system("PAUSE");

        fichier = fopen("tc2.txt","w");
        itoa (tc2,machaine,10);
        fputs(machaine,fichier);
        fclose(fichier);
        system("cls");
        goto jeu;
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
        printf("\n\tGrille de %s\n",Joueur1);
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
        if(mPC == 0)
            printf("\n\tGrille de %s\n",Joueur2);
        else
            printf("\n\tGrille du PC\n");
            affiche(grille_j2);
            system("PAUSE");
            system("cls");

//charger (grille_j1_tirs);
        fichier = fopen("grille_j1_tirs.txt","r");
            for(i=0;i<64;i++)
            fscanf(fichier,"%c\n",tab+i);
        fclose(fichier);
            for(i=0;i<8;i++){
            for(j=0;j<8;j++)
            grille_j1_tirs[i][j] = tab[i*8+j];
            }
            affiche(grille_j1_tirs);
            system("PAUSE");
//charger (grille_j2_tirs);
        fichier = fopen("grille_j2_tirs.txt","r");
            for(i=0;i<64;i++)
            fscanf(fichier,"%c\n",tab+i);
        fclose(fichier);
            for(i=0;i<8;i++){
            for(j=0;j<8;j++)
            grille_j2_tirs[i][j] = tab[i*8+j];
            }
            affiche(grille_j2_tirs);
            system("PAUSE");

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
        //SDL_Quit();

}
