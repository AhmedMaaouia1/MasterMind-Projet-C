/*************************************************************
*	Developpeurs:	REZGUI Houssem && MAAOUIA Ahmed 	     *
*	Programme: 		Projet mastermind						 *
*	Section: 		ING1-Info			     				 *
*	                         								 *	                                                         *
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Joueur.h"
#include <string.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>


int main()
{
    struct Joueur j;
    struct Joueur j1;
    int h=1; // variable qu'on va utiliser pour tester si l'utilisateur veut quitter la partie ou pas
    int up=0;// update variable qu'on va utiliser pour tester si l'utilisateur veut enregistrer la partie ou pas

    menu(); // affichage de MASTERMIND


    int choix;
    bool gagne=false;
    char fich1[25];
    char nomm[20]="";

    do
    {
    do
    {
        MenuJeu();
        delay(200);
        color(9,0);
        Affich_Dynamique("\n\nDonner votre choix : ");
        color(15,0);
        scanf("%d",&choix);
    }
    while ((choix<0)||(choix>5));
   switch(choix)
    {
    case 1:
        j=saisir_joueur(j);
        color(6,0);
        printf("Nom : %s\n", j.Nom);
        color(15,0);
        printf("\n");
        j=initialisation_grille(j);
        afficher_grille(j);
        j=nbreAleatoire(j,1,6);
        printf("%d%d%d%d",j.codeMachine[0],j.codeMachine[1],j.codeMachine[2],j.codeMachine[3]);
        int code;
        int tentative=0;
        bool sortie =false;
        double time_spent = 0.0;
        clock_t begin = clock();



        while(tentative<10)
        {
                    color(6,0);
                    printf("\nTentative : %d\n", tentative);
                    printf("\n");

                    while(j.test==false)
                        {
                            color(11,0);
                            printf("\nSi Vous voulez quitter le jeu, merci d'entrez 0\n");
                            color(9,0);

                            printf("\nDonner votre code (4 chiffres): ");
                            color(15,0);
                            scanf("%d",&code);
                            printf("\n");

                            if (code==0)
                             {
                                 color(4,0);
                                 printf("\nVous avez quittez le jeu !");
                                 sortie=true;
                                 break ;
                             }
                             else
                                {
                                    j = saisie_code(code,j) ;
                               }
                        }
                        j = remplir_grille(j,tentative);

                if(sortie)
                {
                    break;
                }
                else
                {

                            afficher_grille(j);
                            if((j.grille[tentative][5]==2)&&(j.grille[tentative][6]==2)&&(j.grille[tentative][7]==2)&&(j.grille[tentative][8]==2))
                            {
                                color(14,0);
                                Affich_Dynamique("\nFelicitations vous avez gagne !");
                                break;
                            }
                            j.test = false;
                            tentative += 1;
                            j.tentative+=1;
                }
              }
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        color(10,0);
        printf("\nLe temps passe dans le jeu est %.3f secondes", time_spent);
        j.temps = time_spent;

        if(tentative == 10)
        {
            color(4,0);
            Affich_Dynamique("\nVous avez perdu !");
        }
        do
        {
            color(11,0);
            printf("\nVoulez-vous enregistrer votre partie ? (0 : si non || 1 : si oui)  ");
            color(15,0);
            scanf("%d",&up);
        }
        while ((up != 0)&&(up != 1));

        if(up==1)
        {
            char* s[50];
            strcpy(s,j.Nom);
            strcat(s,".txt");
            Enregistrer_Joueur("Joueur.txt",j);
            Enregistrer_Partie(s,j);
            if(sortie)
            {
                Enregistrer_Joueur("Partie_a_rep.txt",j);
            }
            char *s2[50];
            strcpy(s2,j.Nom);
            strcat(s2,"_Stat.txt");
            Enregistrer_Stat_Joueur(s2,j);
        }
        sortie =false ;
        break ;



    case 2:

        if(afficher_Joueur("Partie_a_rep.txt")==1)
        {
        color(9,0);
        printf("\nDonner le nom du personne : ");
        color(15,0);
        fflush(stdin);
        gets(nomm); //Pour lire un nom contenant des espaces
        j1=recherche_code("Partie_a_rep.txt", nomm);
        char fich1[20]="";
        strcpy(fich1,nomm);
        strcat(nomm,".txt");
        Reprendre_Partie(nomm,&j1);
        printf("\n j1.grille[0][5]= %d",j1.grille[0][5]);
        if(j1.grille[0][5]==0)
        {
            color(4,0);
            printf("\nUtilisateur introuvable !");
        }
        else
        {

            printf("\n code : %d%d%d%d",j1.codeMachine[0],j1.codeMachine[1],j1.codeMachine[2],j1.codeMachine[3]);
            tentative=j1.tentative;
            h=1;
            while(tentative<10)
            {
                color(11,0);
                printf("\nTentative : %d\n", tentative);
                if(h==0)
                {
                    break;
                }
                else
                {
                    while(j1.test==false)
                    {
                        color(9,0);
                        printf("\n Donne votre code (4 chiffres): ");
                        color(15,0);
                        scanf("%d",&code);
                        j1 = saisie_code(code,j1);

                    }
                    j1 = remplir_grille(j1,tentative);
                    afficher_grille(j1);
                    if((j1.grille[tentative][5]==2)&&(j1.grille[tentative][6]==2)&&(j1.grille[tentative][7]==2)&&(j1.grille[tentative][8]==2))
                    {
                        color(6,0);
                        Affich_Dynamique("\nFelicitations vous avez gagne !");
                        gagne=true;
                        break;
                    }
                    j1.test = false;
                    tentative += 1;
                }
            }

            if(tentative == 10)
            {
                color(4,0);
                printf("\nVous avez perdus");
            }
            do
            {
                color(11,0);
                printf("\nVoulez-vous enregistrer votre partie ? (1 : si oui   0 : si non) \n");
                scanf("%d",&up);
            }
            while ((up != 0)&&(up != 1));

            if(up==1)
            {
                char* s[50];
                strcpy(s, j1.Nom);
                strcat(s,".txt");
                color(11,0);
                printf("\n Nom : %s  -- fichier : %s",j1.Nom,s);
                Enregistrer_Partie(s,j1);

                if (gagne)
                {
                    effacer_partie_a_reprendre(j1.Nom);
                }
            }
            }


        }
     break;
    case 3:
        Aides();
        break;
    case 4:

        if (afficher_Joueur("Joueur.txt")==1)
        {
            color(9,0);
            printf("\nDonner le nom du personne : ");
            color(15,0);
            fflush(stdin);
            gets(nomm);
            char nom_p[20];
            strcpy(nom_p,nomm);
            strcat(nomm,".txt");
            Revisualiser_Partie(nomm,nom_p);
            break;
        }



    case 5:

        if(afficher_Joueur("Joueur.txt")==1)
        {
        color(9,0);
        printf("\nDonner le nom de la personne : ");
        color(15,0);
        scanf("%s",fich1);
        char nom1[25]="";
        strcpy(nom1,fich1);
        strcat(nom1,"_Stat.txt");
        Affiche_Stat_Joueur(nom1,fich1);
        }
    }
    }
    while(choix!=0);





    return 0;
}
