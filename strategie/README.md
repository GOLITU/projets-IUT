La stratégie consiste à regarder les places jouables (7 si aucune colonne n'est remplie), et on regarde les priorités de jeu
elles sont décrites en dessous.

- on commence la partie, on essaye de défendre le plateau suivant le jeu de l'adversaire 
- si rien n'est disponible en défense, on attaque à notre tour (on vérifie quand même si on peut gagner la partie)


## Début de la partie 
Quel sera le premier coup de la stratégie
stratégie:
|joue au 1er coup |joue au 2ème coup                             |
|:---------------:|:--------------------------------------------:|
|placer au millieu|placer à gauche du millieu ou alors au millieu|

--- 

## Tour de la stratégie : cas de défense
|cas 1               |cas 2                     |cas 3                       |
|:------------------:|:------------------------:|:--------------------------:|
|3 JETON_IA alignés  |3 JETON_ADVERSAIRE alignés|2 JETON_ADVERSAIRE alignés  |
|L'IA gagne la partie|L'IA empêche sa défaite   |L'IA continue l'enchainement|

--- 

## Tour de la stratégie : cas d'attaque si la défense n'a pas été prise en compte

|cas 4                       |cas 5                                           |cas 6                                                                  |
|:--------------------------:|:----------------------------------------------:|:---------------------------------------------------------------------:|
|2 JETON_IA alignés|1 JETON_IA seul                                 |Aucun jeton IA dispo                                                   |
|La stratégie continue l'enchainement|La stratégie place dessus, sur les côtés ou en diagonale|La stratégie place à l'endroit le plus bas|

