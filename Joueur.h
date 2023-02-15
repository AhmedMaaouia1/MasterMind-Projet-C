#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include <stdbool.h>

//structure de type joueur
typedef struct Joueur
{
    int CodeJoueur[4];
    int codeMachine[4];
    bool test;
    char Nom[20];
    int grille[10][9];
    int tentative;
    double temps;
}Joueur;

//fonction qui permet d'afficher un menu du MOT MasterMind
void menu();

//fonction qui permet d'afficher le menu du jeu accompagné des choix
void MenuJeu();

//fonction qui permet de afficher les regles du jeu
void Aides();

//fonction qui permet de lire le nom qu joueur et vérifie s'il existe déja ou non dans ce cas elle affiche le message"Ce nom de joueur existe deja !"
Joueur saisir_joueur(Joueur j);

//fonction qui permet de rechercher le nom d'un joueur et retourne une valeur boolénne
bool recherche_joueur(char nom[50]);

//fonction qui permet d'initialiser la grille avec des 0
Joueur initialisation_grille (Joueur j);

//fonction qui permet d'afficher la grille
void afficher_grille(Joueur j);

//fonction qui permet d'avoir un affichage dynamique de la grille
void afficher_grille_D(Joueur j);

//fonction qui permet d'avoir un nombre aleatoire entre la valeur min et max
Joueur nbreAleatoire(Joueur j, int borneMin, int borneMax);

//fonction qui permet de vérifier le code donné par le joueur
Joueur saisie_code (int code, Joueur j);

//fonction qui permet de remplir la grille par les codes donnés de la part du joueur
Joueur remplir_grille(Joueur j, int tentative);

//fonction qui permet d'enregistrer une partie jouée dans un fichier au nom du joueur
void Enregistrer_Partie(char nomfich[], Joueur j);

//fonction qui permet d'enregistrer le code du joueur ainsi que le code géré par la machine
void Enregistrer_Joueur(char nomfich[], Joueur j);

//fonction qui permet de revisualiser une partie jouée si elle existe sinon elle retourne "Partie introuvable"
void Revisualiser_Partie(char nomfich[], char nom[20]);

//fonction qui retourne 1 et affiche la liste des joueurs si elle existe ,sinon retourne 0 et affiche" pas de joueurs "
int afficher_Joueur(char nomfich[]);

//fonction qui permet d'enregistrer les statistiques du joueur dans un fichier
void Enregistrer_Stat_Joueur(char nomfich[],Joueur j);

//fonction qui permet d'afficher les statistiques du joueur dont son nom est donnée en paramètre
void Affiche_Stat_Joueur(char nomfich[],char nom[]);

//fonction qui permet de reprendre une partie jouée qui n'est pas encore terminée
void Reprendre_Partie(char nomfich[], Joueur* j);

//fonction qui permet de récupérer le code de la partie du joueur avec le nom donné en paramétre
Joueur recherche_code(char nomfich[], char nom[20]);

//fonction supplémentaire qui permet de convertir un caractère chiffre en entier int
int affectation(char c);

//fonction qui permet d'effacer une partie à reprendre aprés l'avoir terminée
void effacer_partie_a_reprendre(char nom[20]); // lorsque le joueur reprend une partie et la termine il faut l'effacer du fichier Partie_a_rep.txt

//fonction qui permet un retard de quelques millisecondes durant un affichage
void delay(unsigned int msec);

//Affichage dynamique qui dure 0.5 sec
void Affich_Dynamique(char ch[100]);

//Gestion couleurs
void color(int Couleur_Txt,int Couleur_Fond);

#endif // JOUEUR_H_INCLUDED
