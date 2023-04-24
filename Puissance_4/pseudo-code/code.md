```
programme puissance4 c'est 

/*******************************/
/*    Appel des procédures     */
/*******************************/

procédure debutJeu(entF/sortF nom1 : chaîne, entF/sortF nom2 : chaîne);
    //Lancement du jeu ; affichage des règles, du titre, et la demande des noms des joueurs


procédure afficheGrille (entF tab : tableau); 
    //Permet d'afficher la grille, même quand les pions on étés placé


procédure tour(entF numeroTour : entier , entF joueur : chaîne); 
    //Affiche le numéro du tour, la grille et le nom du joueur (à qui est le tour)


procédure deplaceCurseur(sortF p : entier); 
    //Permet de déplacer le curseur de gauche à droite 
    //Variable direction (procédurale): g (va a gauche) | d (va a droite) | p (donne l'information qu'on place un jeton)
    //p : numéro de colone sortie pour placer le jeton dans la procédure d'après


fonction placeJeton(entF p : entier, entF tab : tableau) delivre tableau; 
    //p : donne l'indication de la colone de placement du jeton
    //Permet de poser un jeton dans la colone du curseur (puis replace le curseur au début)
    //Permet donc de modifier le tableau en y rajoutant un jeton ; une seule sortie


fonction alignement(entF p : entier, entF tab : tableau) délivre booléen;
    //Permet de savoir si le pion place forme une suite de 4 jetons, renvoie donc un booléen selon l'alignement des jetons


procédure finJeu(entF tab : tableau, sortF finJeu : booleen) ;
    //Permet de dire que le jeu est terminé grâce à au booléen de la fonction alignement


fonction tourAdverse(entF nom : chaîne) delivre chaîne;
    //Permet de passer du joueur1 au joueur2 et inversement

procédure recommencer(sortF continuer : booleen); 
    //Affiche les résultats et demande si la partie veux être recommencée


/*******************************/
/*    Appel des constantes     */
/*******************************/

constante entière NLIGNES : 7 ; //On fixe le nombre de lignes de la grille
constante entière NCOLONES : 6 ; //On fixe le nombre de colones de la grille




début 

    type TAB = tableau [1..NLIGNES] [1..NCOLONES]

        /*******************************/
        /*     Appel des variables     */
        /*******************************/

    tab : TAB;
    finJeu, continuer : booleen;
    direction : caractere ;
    joueur,nom1,nom2 : chaine ;
    numeroTour : entier ;

        /*******************************/
        /*     Debut du programme      */
        /*******************************/

    répéter //déroulement d'une partie

        procédure debutJeu(entE/sortE nom1 : chaîne, entE/sortE nom2 : chaîne);

        joueur := nom1 ;

        finjeu := FAUX ;

        numeroTour := 0 ;
        
        tant que (NON(finJeu)) faire //déroulement d'un tour

            numeroTour ++ ;
            
            procédure afficheGrille (entE tab : tableau); 

            procédure tour(entE numeroTour : entier , entE joueur : chaîne); 
            
            procédure deplaceCurseur(sortE p : entier);

            tab := fonction placeJeton (entE p : entier, entF tab : tableau) delivre tableau; 

            finJeu := fonction alignement(entE p : entier, entE tab : tableau) délivre booléen;

            procédure finJeu(entE finJeu : booléen);

            joueur := fonction tourAdverse(entE joueur : chaîne) délivre chaîne;

        finfaire
    
        procédure recommencer(entE/sortE continuer);  

    jusqu'a (continuer) ; //pour relancer une partie si l'envie nous prend

    ecrireEcran("fin du jeu"); 

fin
```