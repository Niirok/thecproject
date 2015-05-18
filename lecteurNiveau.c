#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/**
*Pour lancer un niveau, appeler la fonction lireNiveau avec le nom du fichier en parametre
*/

char* my_fgets(char* s,int size, FILE* stream){
	char c='0';
	int i=0;
	fgets(s,size,stream);
	while(c != '\0'){
		c=*(s+i);
		if (c=='\n'){
			*(s+i)='\0';
			c='\0';
		}
		i++;
	}
	return s;
} 
void lireNiveau(char* niveau){
	int flag = 1;
	long i;
	char* contenu=malloc(sizeof(char)*10);
	FILE* fic=fopen(niveau, "r");
	if(fic == NULL){
		printf("echec");
	}
	else {
		while(flag){
		my_fgets(contenu, 10, fic);
		if (strcmp(contenu, "1") == 0){
			printf("voici une boule orange\n");
			//orange ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atol(contenu);i++){}
		}
		else if (strcmp(contenu, "2") == 0){
			printf("voici une boule jaune\n");
			//yellow ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "3") == 0){
			printf("voici une boule rouge\n");
			//red ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "4") == 0){
			printf("voici une boule bleu marine\n");
			//navyblue ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "5") == 0){
			printf("voici une boule turquoise\n");
			//turquoise ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "6") == 0){
			printf("voici une boule verte\n");
			//green ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "7") == 0){
			printf("voici une boule purple\n");
			//purple ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "8") == 0){
			printf("voici une boule rose\n");
			//pink ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		} 
		else if (strcmp(contenu, "9") == 0){
			printf("voici une boule violette\n");
			//violet ball
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "10") == 0){
			printf("c'est un ennemi carré\n");
			//first enemy
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "11") == 0){
			printf("c'est un ennemi rapide\n");
			//second enemy
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "12") == 0){
			printf("c'est un ennemi croix\n");
			//third enemy
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "13") == 0){
			printf("c'est un ennemi qui change de dimension\n");
			//fourth ennemy
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "14") == 0){
			printf("c'est un ennemi qui se téléporte\n");
			//fifth ennemy
			my_fgets(contenu, 10, fic);
			for(i=1;i<100000*atoi(contenu);i++){}
		}
		else if (strcmp(contenu, "0") == 0){
			printf("c'est la fin du niveau\n");
			//modification du flag
			flag = 0;
		}
		else{
			printf("erreur non prévue :-%s-\n", contenu);
		}
		}	
	}
printf("fin du niveau\n");
free(contenu);
fclose(fic);
}
