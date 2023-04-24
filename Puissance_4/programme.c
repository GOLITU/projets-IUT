/** 
 * @brief Code source puissance 4
 * @author Etienne Le Bellec 1B1
 * @version 1.0
 * @date 27/10/2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*****************************/
/*DÉFINITION DU TYPE CHAINE19*/
/*****************************/

typedef char chaine19[20];

/*******************************/
/*INITIALISATION DES CONSTANTES*/
/*******************************/

/**
* @def NBLIG
* @brief Nombre de ligne de la grille de jeu
*/
#define NBLIG 6
/**
* @def NBCOL
* @brief Nombre de colonnes de la grille de jeu
*/
#define NBCOL 7


/**
* @def PION_A
* @brief Constante qui représente le pion du premier joueur
*/
const char PION_A = 'O';

/**
* @def PION_B
* @brief Constante qui représente le pion du second joueur
*/
const char PION_B = 'X';

/**
* @def VIDE
* @brief Constante qui représente les espaces vides de la grille
*/
const char VIDE = ' ';

/**
* @def INCONNU
* @brief Constante qui représente les caractères inconnus/vides
*/
const char INCONNU = ' ';

/**
* @def COLONNE_DEBUT
* @brief Constante qui représente la colonne de départ
*/
const int COLONNE_DEBUT = NBCOL/2;

/**
* @def GAUCHE
* @brief Constante qui représente le caractère pour se déplacer à gauche
*/
const char GAUCHE = 'g';

/**
* @def DROITE
* @brief Constante qui représente le caractère pour se déplacer à droite
*/
const char DROITE = 'd';

/**
* @def PLACER
* @brief Constante qui représente le caractère pour placer un jeton
*/
const char PLACER = ' ';

/**
* @def LIGNE
* @brief Constante qui représente l'alignement de jetons requis pour finir une partie
*/
const int LIGNE = 4;

//nom des variables à donner encore

/***************************/
/*DÉFINITION DU TYPE GRILLE*/
/***************************/

/**
* @typedef grille
* @brief Type tableau, de tableau, de caractère NBLIG-1 et NBCOL-1
*
* Le type char Grille permet de définir la grille de jeu 
*/ 
typedef char Grille [NBCOL][NBLIG];

/***********************************/
/*DÉFINITION PROCÉDURES & FONCTIONS*/
/***********************************/

void debutPartie(chaine19 *nom1, chaine19 *nom2, Grille g);
void initGrille (Grille grille);
void afficher (Grille grille, char pion, int val, chaine19 nom1, chaine19 nom2);
int grillePleine (Grille grille); //(retourne booléen)
void jouer (Grille grille, char car, int *lig, int *col, chaine19 nom1, chaine19 nom2);
int choisirColone (Grille grille, char pion, int coldep, chaine19 nom1, chaine19 nom2); //(retourne entier)
int trouverLigne (Grille grille, int col); //(retourne entier)
int estVainqueur (Grille grille, int lig, int col); //(retourne booléen)
void finDePartie (char pion);


/*********************/
/*PROGRAMME PRINCIPAL*/
/*********************/


/**
 * @fn int main()
 * 
 * @brief programme principal
 * 
 * @return int : EXIT_SUCCESS
 * 
 * Programme principal, lance le jeu, appelle les fonctions et procédures
 */

int main(){
    char vainqueur;
    int ligne, colonne;
    chaine19 joueur1, joueur2;
    vainqueur = INCONNU;
    Grille g;
    initGrille(g);
    debutPartie(&joueur1, &joueur2, g);
    afficher(g, PION_B, COLONNE_DEBUT, joueur1, joueur2);
    printf("%s : %c      %s : %c \n",joueur1, PION_A, joueur2, PION_B);

    while ((vainqueur == INCONNU) && !grillePleine(g))
    {
        jouer(g, PION_A, &ligne, &colonne, joueur1, joueur2);
        afficher(g, PION_B, COLONNE_DEBUT, joueur1, joueur2);
        printf("%s : %c      %s : %c \n",joueur1, PION_A, joueur2, PION_B);
        if (estVainqueur(g, ligne, colonne))
        {
            vainqueur = PION_A;
        }
        else if (!grillePleine(g))
        {
            jouer(g, PION_B, &ligne, &colonne, joueur1, joueur2);
            afficher(g, PION_A, COLONNE_DEBUT, joueur1, joueur2);
            if (estVainqueur(g, ligne, colonne))
            {
                vainqueur = PION_B;
            }
        }
    }
    finDePartie(vainqueur);

    return EXIT_SUCCESS;
}

/********************/
/*MAIN POUR LES TEST*/
/********************/

/*
int main(){//initGrille
    Grille g;
    char test;
    afficherGrille(g);
    initGrille(g);
    scanf("%c",&test);
    afficherGrille(g);
    return EXIT_SUCCESS;
*/
    
/****************************************************************************************************************************************************/

/******************************/
/*CODE PROCÉDURES ET FONCTIONS*/
/******************************/

/**
*   @fn void initGrille(Grille grille)
* 
*   @brief Procedure qui initialise la grille : la remplit du caractère VIDE.
*
*   @param grille de jeu : grille.
*/

void initGrille(Grille grille){
    int i,j;
    for (i = 0; i < NBLIG; i++)
    {
        for (j = 0; j < NBCOL; j++)
        {
            grille[i][j] = VIDE;
        }
    }
}

/*******************************************************************/

/**
 * @fn void afficher (Grille grille, char pion, int col, chaine19 nom1, chaine19 nom2)
 *
 * @brief Procédure qui affiche la grille 
 * 
 * @param grille : grille de jeu
 * @param pion : pion qui va être placé
 * @param col : colonne de départ pour l'affichage du curseur
 * @param nom1 : nom joueur 1
 * @param nom2 : nom joueur 2
 */
void afficher (Grille grille, char pion, int col, chaine19 nom1, chaine19 nom2)
{
    int i,j;
    system("clear");
/*    while (grille[col][0] != VIDE)
    {
        if (col == 0)
        {
            col = NBCOL - 1;
        }

        col-- ;
        col = col - 1;
    }
    */

    /*Placement du jeton au dessus de la grille*/

    for (i = 1; i < col; i++)
    {
        printf("    ");
    }

    printf("  %c\n",pion);

    /*Placement du curseur au dessus de la grille, sous le jeton*/

    for (i = 1; i < col; i++)
    {
        printf("    ");
    }

    printf("  V\n");

    /* Affichage de la grille*/

    printf("  ➊   ➋   ➌   ➍   ➎   ➏   ➐\n");
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
    for (i = 0; i < NBLIG; i++)
    {
        printf("\n");
        for (j = 0; j < NBCOL; j++)
        {
            printf("| %c ",grille[i][j] );
        }
        printf("|");
    }
    printf("\n░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    printf("%s : %c      %s : %c \n",nom1, PION_A, nom2, PION_B);
}

/*******************************************************************/

/**
 * @fn void debutPartie(chaine19 *nom1, chaine19 *nom2, Grille grille)
 *
 * @brief Procédure qui demande les noms des joueurs 1 & 2, pour commencer la partie
 * 
 * @param nom1 : nom joueur 1
 * @param nom2 : nom joueur 2
 * @param grille : grille de jeu
 */
void debutPartie(chaine19 *nom1, chaine19 *nom2, Grille grille){
    printf("Nom joueur 1 : ");
    scanf("%s",*nom1);
    printf("Nom joueur 2 : ");
    scanf("%s",*nom2);
    initGrille(grille);
}
/*******************************************************************/

/**
*   @fn bool grillePleine(Grille grille) 
*   @brief Fonction qui vérifie si la grille est pleine de pions.
*   @param  grille de jeu : grille.
*   @return true si la grille est pleine et false sinon. 
*/
int grillePleine (Grille grille){
    bool test=true;
    int i=0,j=0;
    while ((test == true) && (i < NBCOL))
    {
        while ((test == true) && (i < NBCOL))
        {
            if (grille[i][j] != VIDE)
            {
                test = false;
            }
            j++;
        }
        i++;
    }
    return test;
}

/*******************************************************************/

/**
 * @fn void jouer (Grille grille, char pion, int *lig, int *col, chaine19 nom1, chaine19 nom2
 * 
 * @brief Procédure qui récupère la ligne et la colonne pour y placer le pion
 * 
 * @param grille : grille de jeu
 * @param pion : pion à jouer
 * @param lig : colonne où placer le jeton
 * @param col : ligne où placer le jeton
 * @param nom1 : nom joueur1
 * @param nom2 : nom joueur2
 */
void jouer (Grille grille, char pion, int *lig, int *col, chaine19 nom1, chaine19 nom2){
    *col = choisirColone(grille, pion, COLONNE_DEBUT, nom1, nom2)-1;
    *lig = trouverLigne(grille, *col);

    grille[*lig][*col] = pion;
}

/*******************************************************************/

/**
 * 
 * @fn int choisirColone (Grille grille, char pion, int coldep, chaine19 nom1, chaine19 nom2)

 * 
 * @brief fonction qui retourne l'indice de la colonne où poser le jeton
 * 
 * @param grille : grille de jeu
 * @param pion : pion à jouer
 * @param coldep : colonne de départ 
 * @param nom1 : nom joueur1
 * @param nom2 : nom joueur2
 * @return int : colonne disponible pour y placer un jeton
 */
int choisirColone (Grille grille, char pion, int coldep, chaine19 nom1, chaine19 nom2){ //(retourne entier : indice de la colone où poser le jeton)
    char direction;
    direction = INCONNU;
    int colonne;
    colonne = coldep;

    do
    {
        afficher(grille, pion, colonne, nom1, nom2);
        printf("VEUILLEZ SAISIR '%c', '%c' OU '%c'\n",GAUCHE,DROITE,PLACER);
        scanf("%c",&direction);
        if (direction == DROITE)
            {
                if (colonne < 7)
                {
                    colonne++;
                }
            }

        else if (direction == GAUCHE)
            {
                if (colonne > 1)
                {
                    colonne--;
                }
            }

    } while ((direction != PLACER));

    return colonne;
}

/*******************************************************************/

/**
 * 
 * @fn int trouverLigne (Grille grille, int col)
 * 
 * @brief fonction qui retourne l'indice de la ligne où le jeton peut être placé
 * 
 * @param grille : grille de jeu
 * @param col : colonne choisie où on va chercher la ligne disponible
 * @return int : l'indice de la ligne où il y a un espace vide ; -1 sinon
 */
int trouverLigne (Grille grille, int col){ //(retourne entier : indice de la ligne où poser le jeton)
    int i,res=-1;
    for (i = 0; i < NBLIG ; i++)
    {
        if (grille[i][col] == VIDE)
        {
            res = i; // i+1 car on veut la colonne pour l'affichage, l'indice se retrouve en faisant -1
        }
    }

    return res;

}

/*******************************************************************/

/**
 * 
 * @fn : int estVainqueur(Grille g, int lig, int col)
 *
 * @brief : fonction qui vérifie si 4 pions sont alignés : si oui renvoie true, sinon renvoie false
 * 
 * @param g : grille du jeu après qu'un pion soit placé
 * @param lig : numéro de la ligne du pion qui vient d'être placé
 * @param col : numéro de la colonne du pion qui vient d'être placé
 * @return int : renvoie un booléen : si le jeu est fini => true ; si le jeton placé ne finis pas la partie on renvoie false
 */

int estVainqueur(Grille g, int lig, int col) { //retourne booléen : vrai si 4 pions sont alignée, faux sinon
    int i=0,j=0,totLig=0, totCol=0, totDiagGauc=0, totDiagDroi=0;// totDiag compte les diagonales gauches et droites
    bool vainqueur = false;

    // alignement des 4 jetons en colone
    while (i<NBLIG) {
        while (g[i][col] == VIDE){
            i++;
        }
        if (i < NBLIG) {
            if (g[i][col] == g[lig][col]) {
                totCol++;
                i++;
            }
            else {
                if (totCol >= LIGNE) {
                    vainqueur = true;
                }
                else {
                    totCol = 0;
                    i++;
                }
            }
        }
    }

    // alignement des 4 jetons en ligne
    i=0;
    while (i < NBCOL) {
        while (g[lig][i] == VIDE) {
            i++;
        }
        if (i < NBCOL) {
            if (g[lig][i] == g[lig][col]) {
                totLig++;
                i++;
            }
            else {
                if (totLig >= LIGNE) {
                    vainqueur = true;
                }
                else {
                    totLig = 0;
                    i++;
                }
            }
        }
    }

    // alignement des 4 jetons en diagonale : de gauche à droite et de haut en bas
    i=lig;
    j=col;
    while(j>0 && i>0) {
        i--;
        j--;
    }

    while ((i < NBLIG) && (j < NBCOL)) {
        while (g[i][j] == VIDE) {
            i++;
            j++;
        }
        if (g[i][j] == g[lig][col]) {
            totDiagGauc++;
            i++;
            j++;
        }
        else {
            if (totDiagGauc >= LIGNE) {
                vainqueur = true;
                printf("gagne en diag hg");
            }
            else {
                totDiagGauc = 0;
                i++;
                j++;
            }
        }
    }

    // alignement des 4 jetons en diagonale : de droite à gauche et de bas en haut
    i=lig;
    j=col;
    while(j<NBCOL-1 && i>0) {
        i--;
        j++;
    }

    while ((i < NBLIG) && (j < NBCOL)) {
        while (g[i][j] == VIDE) {
            i++;
            j--;
        } 
        if (g[i][j] == g[lig][col]) {
            totDiagDroi++;
            i++;
            j--;
        }
        else {
            if (totDiagDroi >= LIGNE) {
                vainqueur = true;
                printf("gagne en diag hd");
            }
            else {
                totDiagDroi = 0;
                i++;
                j--;
            }
        }
    }

    if (totCol >= LIGNE || totLig >= LIGNE || totDiagGauc >= LIGNE || totDiagDroi >= LIGNE) {
        vainqueur = true;
    }
    return vainqueur;
}

/*******************************************************************/

/**
 * 
 * @fn void finDePartie(char pion)
 * 
 * @brief la procédure renvoie le résultat de la partie
 * 
 * @param pion : on donne le pion qui a gagné la partie 
 * 
 * La procédure permet de renvoyer le pion du joueur qui a gagné la partie
 */
void finDePartie(char pion){
    printf("%c a gagné la partie\n",pion);
}

/*******************************************************************/

