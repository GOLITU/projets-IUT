
valeur_tab = input("Nombre de lignes et de colonnes séparé par un espace (si + de 2 valeurs => ignoré) : ").split(" ")
position_pion = input("Position du pion (ligne colonne) : ").split(" ")

NB_LIGNES = int(valeur_tab[0])
NB_COLONNES = int(valeur_tab[1])
NB_CASES = NB_COLONNES * NB_LIGNES  # Nombre de cases de la grille


def init_graphe():  # Création du graphe des cases et de leurs voisins
    graphe_mouv = {}

    for ligne in range(NB_LIGNES):
        for colonne in range(NB_COLONNES):
            graphe_mouv[(ligne, colonne)] = init_case((ligne, colonne))

    return graphe_mouv


def afficher_graphe(graphe):  # Affiche le graphe
    for key in graphe:
        print(key, ":", graphe[key])


def init_grille():  # Création de la grille selon les dimensions
    return [[0 for colonne in range(NB_COLONNES)] for ligne in range(NB_LIGNES)]


def init_case(case):  # Retourne la liste des cases disponibles
    ligne, colonne = case
    liste_case_dispo = []
    mouv_possible = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]  # (ligne, colonne)

    for l_mouv, c_mouv in mouv_possible:
        if 0 <= colonne + c_mouv < NB_COLONNES and 0 <= ligne + l_mouv < NB_LIGNES:
            liste_case_dispo.append((ligne+l_mouv, colonne+c_mouv))

    return liste_case_dispo


def parcours_cavalier(pos_init, tab_chemin, graphe, grille):
    grille[pos_init[0]][pos_init[1]] = 1  # On marque la case initiale comme visitée

    if len(tab_chemin) == NB_CASES:  # Si le nombre de cases parcourues est égal au nombre de cases de la grille
        print("Chemin trouvé !")
        return tab_chemin

    mouv = []
    for voisinPos in graphe[pos_init]:
        if grille[voisinPos[0]][voisinPos[1]] == 0:
            mouv.append((voisinPos, len(graphe[voisinPos])))  # On ajoute la case et le nombre de cases disponibles

    mouv.sort(key=lambda x: x[1])  # On trie la liste en fonction du nombre de cases disponibles

    for voisinPos, _ in mouv:  # Pour chaque case, on vérifie si un chemin est possible
        tab_chemin.append(voisinPos)
        grille[voisinPos[0]][voisinPos[1]] = 1

        resultat = parcours_cavalier(voisinPos, tab_chemin, graphe, grille)
        if resultat:
            return resultat

        tab_chemin.pop()  # Sinon, on supprime la case de la liste et on continue
        grille[voisinPos[0]][voisinPos[1]] = 0

    return []


def main():
    graphe_cavalier = init_graphe()
    grille_cavalier = init_grille()

    x, y = int(position_pion[0]), int(position_pion[1])

    print(parcours_cavalier((x, y), [(x, y)], graphe_cavalier, grille_cavalier))

main()
