#include <stdio.h>
#include <stdlib.h>
#include "Joueur.h"
#include <string.h>
#include <time.h>
#include <windows.h>


////fonction qui permet d'afficher un menu du MOT MasterMind

void menu()
{
    color(14,0);
	printf("	------------------------------------------------------\n");
	delay(100);
	printf("	-				                     -\n");
	delay(100);
	printf("	-				                     -\n");
	delay(100);
	printf("	-");
	delay(100);
	color(2,0);
	printf("		  MASTER MIND             	");
	delay(100);
	color(14,0);
	printf("     -\n");
	delay(100);
	printf("	-				                     -\n");
	color(14,0);
	delay(100);
	printf("	-				                     -\n");
	delay(100);
	printf("	------------------------------------------------------\n\n\n");
	color(14,0);
	delay(1000);
}

//fonction qui permet d'afficher le menu du jeu accompagné des choix

void MenuJeu()
{
    color(11,0);
    printf("\n|--------------------------------------------------------------------------------|");
    delay(100);
    color(14,0);
    printf("\n|------------------------Menu----------------------------------------------------|");
    color(15,0);
    delay(200);
    color(14,0);
    printf("\n|-------------1:Commencer le Jeu-------------------------------------------------|");
    color(15,0);
    delay(100);
    color(14,0);
    printf("\n|-------------2:Reprendre une partie---------------------------------------------|");
    color(15,0);
    delay(100);
    color(14,0);
    printf("\n|-------------3:Regles du jeu----------------------------------------------------|");
    color(15,0);
    delay(100);
    color(14,0);
    printf("\n|-------------4:Revisualiser une partie------------------------------------------|");
    color(15,0);
    delay(100);
    color(14,0);
    printf("\n|-------------5:Consulter ses statistiques---------------------------------------|");
    color(14,0);
    delay(100);
    printf("\n|-------------0:Quitter----------------------------------------------------------|");
    color(11,0);
    delay(100);
    printf("\n|--------------------------------------------------------------------------------|");
    color(15,0);
    delay(500);
}

//fonction qui permet de afficher les regles du jeu

void Aides()
{
    color(2,0);
    printf("\n\n|--------------------------------------------------------------------------------|");
    printf("\n|-----------------------------Regles du Jeu--------------------------------------|");
    printf("\n|--------------------------------------------------------------------------------|");
    printf("\n|Mastermind est un jeu de reflexion qui consiste a trouver un code secret compose|");
    printf("\n|d une sequence de numeros.                                                      |");
    printf("\n|Chaque tour, apres avoir fait une proposition d une combinaison de numeros      |");
    printf("\n|entre 1 et 6 , vous recevez des indices qui vous permettent d ameliorer vos     |");
    printf("\n|futures propositions. Vous avez au maximum 10 tentatives d essai.               |");
    printf("\n|A chaque tentative vous trouverez ces indices C , P, F :                        |");
    printf("\n|C : Si le numero saisi est correct alors le programme affiche la lettre C.      |");
    printf("\n|P : Si le numero saisi est correct mais pas dans la bonne position alors le     |");
    printf("\n|programme affiche la lettre P.                                                  |");
    printf("\n|F : Si le numero saisi est incorrect alors le programme affiche la lettre F     |");
    printf("\n|--------------------------------------------------------------------------------|");
    printf("\n|--------------------------------------------------------------------------------|\n\n");
    color(15,0);
}

//fonction qui permet de lire le nom qu joueur et vérifie s'il existe déja ou non dans ce cas elle affiche le message"Ce nom de joueur existe deja !"

Joueur saisir_joueur(Joueur j)
{
    bool test=true;
    do
    {
        color(9,0);
        printf("\nDonner Votre Nom: ");
        color(15,0);
        fflush(stdin);
        gets(j.Nom);
        test = recherche_joueur(j.Nom);

        if(test==true)
        {
            color(4,0);
            printf("\n Ce nom de joueur existe deja ! \n");
        }
	}
	while (test==true);
	color(11,0);
	printf("\n=> Good Luck %s! \n\n",j.Nom);
	color(15,0);

	j.test = false;
	int i=0;
	for(i=0;i<4;i++)
    {
        j.CodeJoueur[i] = 0;
    }
    return j;

}

//fonction qui permet de rechercher le nom d'un joueur et retourne une valeur boolénne

bool recherche_joueur(char nom[50])
{
    char* s[50];
    strcpy(s, nom);
    strcat(s,".txt");
    FILE *pf=NULL;
    pf = fopen(s,"r");
    if(pf != NULL)
   {
       fclose(pf);
       return true;
   }
   else
        return false;

}

//fonction qui permet d'initialiser la grille avec des 0

Joueur initialisation_grille (Joueur j)
{
    int i,o;
	for (i=0;i<10;i++)
    {
		for (o=0;o<9;o++)
		{
			j.grille[i][o]= 0;

		}
	}
	j.tentative=1;
	return j;
}

//fonction qui permet d'afficher la grille

void afficher_grille(Joueur j)
{
    int i,o;
	for (i=0;i<10;i++)
    {

		for (o=0;o<9;o++)
		{
			if (o > 4)
			{
				if (j.grille[i][o] == 2)
				{
					color(10,0);
					printf("C");
					color(15,0);
					printf("| ");
				}
				else if (j.grille[i][o] == 1)
				{
					color(5,0);
					printf("P");
					color(15,0);
					printf("| ");
				}
				else if (j.grille[i][1] == 0)
				{
				    printf(" | ");
				}
                else if (j.grille[i][o] == 3)
				{
				    color(4,0);
				    printf("F");
				    color(15,0);
				    printf("| ");
				}
			}
			else printf(" %d | ",j.grille[i][o]);
		}
		printf("\n");
	}
}

//fonction qui permet d'avoir un affichage dynamique de la grille

void afficher_grille_D(Joueur j)
{
    int i,o;
    bool gagne=false;
	for (i=0;i<10;i++)
    {
        delay(300);
		for (o=0;o<9;o++)
		{
			if (o > 4)
			{
				if (j.grille[i][o] == 2)
				{
					color(10,0);
					printf("C");
					color(15,0);
					printf("| ");
				}
				else if (j.grille[i][o] == 1)
				{
					color(5,0);
					printf("P");
					color(15,0);
					printf("| ");
				}
				else if (j.grille[i][1] == 0)
				{
				    printf(" | ");
				}
                else if (j.grille[i][o] == 3)
				{
				    color(4,0);
				    printf("F");
				    color(15,0);
				    printf("| ");
				}
			}
			else printf(" %d | ",j.grille[i][o]);
		}
		if((j.grille[i][5]==2)&&(j.grille[i][6]==2)&&(j.grille[i][7]==2)&&(j.grille[i][8]==2)) // Si on trouve que le joueur a trouvé le code, la variable gagne sera vrai
        {
            gagne=true;
        }
		printf("\n");
	}
	if(gagne)
    {
        printf("\n Partie terminee : %s a trouve le code.",j.Nom);
    }
    if(j.grille[i-1][2]!=0)
    {
        printf("\n Partie terminee : %s n'a pas trouve le code.",j.Nom);
    }
}

//fonction qui permet d'avoir un nombre aleatoire entre la valeur min et max

Joueur nbreAleatoire(Joueur j, int Min, int Max)
{
    srand(time(NULL));
    for(int i=0;i<4;i++)
    {
        j.codeMachine[i] = (rand() % (Max - Min + 1)) + Min;
    }
    return j;

}

//fonction qui permet de vérifier le code donné par le joueur

Joueur saisie_code (int code, Joueur j)
{
	if (((code>6666)||(code<1111)) )
    {
        color(4,0);
        printf("\nCode Invalide, le code doit avoir 4 chiffres\n");
        j.test = false;
    }
    else
    {
        int a = (code/1000);
        int b = (code%1000)/100;
        int c = (code%100)/10;
        int d = code%10;

        if((6 < a)||(a<1)||(6 < b)||(b<1)||(6 < c)||(c<1)||(6 < d)||(d<1))
        {
            color(4,0);
            printf("\nCode Invalide, le code doit avoir des chiffres entre 1 et 6\n");
            color(15,0);
            j.test = false;
        }
        else
        {
            j.CodeJoueur[0]= a;
            j.CodeJoueur[1]= b;
            j.CodeJoueur[2]= c;
            j.CodeJoueur[3]= d;
            j.test= true;

        }
    }
    return j;

}

//fonction qui permet de remplir la grille par les codes donnés de la part du joueur

Joueur remplir_grille(Joueur j, int tentative)
{
    int k=0;
    bool a = true;

    //Mettre les chiffres donnés par l'utilisateur dans la grille
    j.grille[tentative][0] = tentative;
    j.grille[tentative][1] = j.CodeJoueur[0];
    j.grille[tentative][2] = j.CodeJoueur[1];
    j.grille[tentative][3] = j.CodeJoueur[2];
    j.grille[tentative][4] = j.CodeJoueur[3];
    //vérifier si les chiffres sont correctes (2) , mal placé(1) ou incorrect(3)

    for(k = 1; k < 5; k++)
        {
			if (j.grille[tentative][k] == j.codeMachine[k-1]) //si le chiffre = le chiffre du code machine alors on met 2
			{
				j.grille[tentative][k+4] = 2;
            }
            else
            {
                for (int i=0;i<4;i++)
                {
                    if (j.grille[tentative][k] == j.codeMachine[i]) //si le chiffre existe dans les chiffre du code machine alors on met 1
                    {
                        j.grille[tentative][k+4] = 1;
                        a = false;
                        break;
                    }

                }
                if (a == true)
                {
                    j.grille[tentative][k+4] = 3; //si le chiffre n'existe pas dans les chiffre du code machine alors on met 1
                }
            }
            a = true;
        }
    return j;

}

//fonction qui permet d'enregistrer une partie jouée dans un fichier au nom du joueur


void Enregistrer_Partie(char nomfich[], Joueur j)
{
    int i,o;
    FILE *pf=NULL;
    pf = fopen(nomfich,"w");

   if(pf != NULL)
   {
   for(i=0;i<10;i++)
   {
       for(o=0;o<9;o++)
       {
           int b;  // Le but est de convertir un entier en chaine de caractere pour l'ajouter dans le fichier
           b = j.grille[i][o];
           fprintf(pf,"%d ",b);
       }
       fprintf(pf,"\n");
   }
   fclose(pf);
    }
    else
        printf("erreur");
}

//fonction qui permet d'enregistrer le code du joueur ainsi que le code géré par la machine

void Enregistrer_Joueur(char nomfich[], Joueur j)
{
     int i,o;
    FILE *pf=NULL;
    pf = fopen(nomfich,"a");

   if(pf != NULL)
   {
       fprintf(pf,"\n%s ",j.Nom);
       fprintf(pf,"%d%d%d%d",j.codeMachine[0],j.codeMachine[1],j.codeMachine[2],j.codeMachine[3]);
       fclose(pf);
   }
   else
        printf("erreur");
}

//fonction qui permet de revisualiser une partie jouée si elle existe sinon elle retourne "Partie introuvable"

void Revisualiser_Partie(char nomfich[], char nom[20])
{
    FILE *pf=NULL;
    Joueur j;
    strcpy(j.Nom,nom);
    initialisation_grille(j);
    int p,n1,n2,n3,n4,v1,v2,v3,v4;
    int i = 0;
    pf = fopen(nomfich,"r");
    if(pf == NULL)
        {
        color(4,0);
        printf("\nPartie introuvable !");
        }
    else
    {

        for(i=0;i<10;i++)
        {

            fscanf(pf,"%d %d %d %d %d %d %d %d %d\n",&p,&n1,&n2,&n3,&n4,&v1,&v2,&v3,&v4);
            j.grille[i][0]=p;
            j.grille[i][1]=n1;
            j.grille[i][2]=n2;
            j.grille[i][3]=n3;
            j.grille[i][4]=n4;
            j.grille[i][5]=v1;
            j.grille[i][6]=v2;
            j.grille[i][7]=v3;
            j.grille[i][8]=v4;

        }
    color(6,0);
    printf("\n PARTIE : \n");
    color(15,0);
    printf("\n");
    afficher_grille_D(j);

    }
}

//fonction qui retourne 1 et affiche la liste des joueurs si elle existe ,sinon retourne 0 et affiche" pas de joueurs "

int afficher_Joueur(char nomfich[])
{
    FILE *pf=NULL;
    char* s[50];
    char* s1[50];
    int m;
    pf = fopen(nomfich,"r");
    if(pf == NULL)
        {
        color(4,0);
        printf("\nPas de Joueurs !");
        color(15,0);
        m=0;
        }

    else
    {
        color(11,0);
        printf("\nVoici la Liste des Joueurs : \n");
        color(15,0);
        printf("\n");
        while (fscanf(pf,"%s %s",s,s1)!=EOF)
        {
            printf("-%s\n",s);
        }
        m=1;
    }

    return m  ;
}

//fonction qui permet d'enregistrer les statistiques du joueur dans un fichier

void Enregistrer_Stat_Joueur(char nomfich[],Joueur j)
{
    FILE *pf=NULL;
    pf = fopen(nomfich,"a");

   if(pf != NULL)
   {
       color(1,0);
       fprintf(pf,"%s %d %f\n",j.Nom,j.tentative,j.temps);
       fclose(pf);
   }
   else
        {
            color(4,0);
            printf("erreur");
        }
}



//fonction qui permet d'afficher les statistiques du joueur dont son nom est donnée en paramètre

void Affiche_Stat_Joueur(char nomfich[],char nom[])
{
    FILE *pf=NULL;
    char* s[50];
    char* c[10];
    char* t[20];
    pf = fopen(nomfich,"r");
    if(pf == NULL)
        {color(4,0);
        printf("\n Pas de joueurs !");
        }
    else
    {
        while (fscanf(pf,"%s %s %s\n",s,c,t)!=EOF)
        {
            if(strcmp(s,nom)==0)
            {
                color(2,0);
                printf("\nVoici les statistiques de la partie de %s : \n",s);
                color(11,0);
                printf("\nLe nombre de Tentatives est : %s",c);
                printf("\nLe Temps du jeu est: %s secondes\n",t);
                color(15,0);
            }
        }
    }
}

//fonction qui permet de reprendre une partie jouée qui n'est pas encore terminée

void Reprendre_Partie(char nomfich[], Joueur* j)
{
    int p,n1,n2,n3,n4,v1,v2,v3,v4;
    int i = 0;

    FILE *pf=NULL;
    *j=initialisation_grille(*j); // initialiser la grille à 0
    j->tentative=0; //le nombre de tentative commence de 0
    pf = fopen(nomfich,"r"); // ouvrir le fichier passé en paramétre
    if(pf == NULL)
        {
            color(4,0);
            printf("\n Partie introuvable !"); // Si le fichier est vide donc il n'y a pas de parties à reprendre
            color(15,0);
        }
    else
    {
        //Si le fichier est ouvert, on va récupérer les lignes enregistrés dans le fichier
        for(i=0;i<10;i++) //puisqu'il y a 10 lignes qui sont les lignes de la grilles, on va parcourir de 0 jusqu'à 9
        {
            //On va lire les chiffres du fichier et les mettre dans les variables déclarés au dessus.
            fscanf(pf,"%d %d %d %d %d %d %d %d %d\n",&p,&n1,&n2,&n3,&n4,&v1,&v2,&v3,&v4);
            j->grille[i][0]=p;
            j->grille[i][1]=n1;
            j->grille[i][2]=n2;
            j->grille[i][3]=n3;
            j->grille[i][4]=n4;
            j->grille[i][5]=v1;
            j->grille[i][6]=v2;
            j->grille[i][7]=v3;
            j->grille[i][8]=v4;
            if(v1!=0) //si la colonne 5  de la ligne i  est different de 0 donc on incrémente le nombre de tentatives
            {
                j->tentative +=1;
            }

        }
    color(1,0);
    printf("\n PARTIE : \n");
    color(15,0);
    afficher_grille(*j); // Ici on affiche la grille
    }

}

//fonction qui permet de récupérer le code de la partie du joueur avec le nom donné en paramétre

Joueur recherche_code(char nomfich[], char nom[50])
{
    FILE *pf=NULL;
    Joueur j;
    strcpy(j.Nom,nom);
    j=initialisation_grille(j);
    char s[50];
    char s1[4];
    int k1=0,k2=0,k3=0,k4=0;
    pf = fopen(nomfich,"r");
    if(pf == NULL)
    {
        printf("\n Erreur !");
    }
    else
    {
        printf("\n Liste des joueurs : \n");
        while (fscanf(pf,"%s %s",s,s1)!=EOF)
        {
            if(strcmp(s,nom)==0)
            {
                k1=affectation(s1[0]);
                k2=affectation(s1[1]);
                k3=affectation(s1[2]);
                k4=affectation(s1[3]);

                printf("%s\n",s);
                j.codeMachine[3]=k4;
                j.codeMachine[2]=k3;
                j.codeMachine[1]=k2;
                j.codeMachine[0]=k1;
                printf("\n code mach : %d%d%d%d",j.codeMachine[0],j.codeMachine[1],j.codeMachine[2],j.codeMachine[3]);
                return j;
            }
        }
    }
    return j;

}

//fonction supplémentaire qui permet de convertir un caractère chiffre en entier int

int affectation(char c)
{
    if (c=='0')
    {
        return 0;
    }
    if (c=='1')
    {
        return 1;
    }
    if (c=='2')
    {
        return 2;
    }
    if (c=='3')
    {
        return 3;
    }
    if (c=='4')
    {
        return 4;
    }
    if (c=='5')
    {
        return 5;
    }
    if (c=='6')
    {
        return 6;
    }

    return 0;
}

//fonction qui permet d'effacer une partie à reprendre aprés l'avoir terminée

void effacer_partie_a_reprendre(char nom[50])
{
    FILE *pf=NULL;
    FILE *f=NULL;
    f = fopen("Partie_a_rep_tmp.txt","w"); //Création d'un fichier temporaire pour enregister dedans les données utiles
    pf = fopen("Partie_a_rep.txt","r"); //Ouverture du fichier pour prendre les données utiles puis le supprimer
    char s[50];
    char s1[10];
    if((pf == NULL)||(f==NULL))
        printf("erreur");
    else
    {
    while (fscanf(pf,"%s %s\n",s,s1)!=EOF)
    {
        // à chaque fois que le nom donné en paramétre ne correspond pas au nom écrit dans la ligne, on écrit toute la ligne dans le nouveau fichier
        if (strcmp(nom,s)!=0)
        {
            fprintf(f,"%s %s\n",s,s1);
        }
    }
    fclose(pf);
    fclose(f);


    int a=remove("Partie_a_rep.txt");
    if(a != 0)
    {
        printf("\n Ne peut pas supprimer le fichier");
    }
    rename("Partie_a_rep_tmp.txt","Partie_a_rep.txt");
    }
}

//Affichage dynamique qui dure 0.5 sec

void Affich_Dynamique(char ch[100])
{

     for(int i=0;i<strlen(ch);i++)
     {
         printf("%c",ch[i]);
         delay(50);
     }
}

//Gestion couleurs

void color(int Couleur_Txt,int Couleur_Fond)
 {
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,Couleur_Fond*16+Couleur_Txt);
}

//fonction qui permet un retard de quelques millisecondes durant un affichage

void delay(unsigned int msec)
{
    clock_t goal = msec + clock();
    while (goal > clock());
}
