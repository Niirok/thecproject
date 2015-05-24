#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIFFENNEMIS 2

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

int newNiveau(char* name){
	FILE* file = fopen(name,"r");
	int vaguestotal;
	int currentvague=1;
	int i, j;
	int current;
	int time;
	char* contenu=malloc(sizeof(char)*30);
	my_fgets(contenu, 30, file);
	vaguestotal = atoi(contenu);
	while(currentvague <= vaguestotal){
	for(i=0;i<DIFFENNEMIS+9;i++){
		my_fgets(contenu, 30, file);
		current = atoi(contenu);
		for(j=0;j<current;j++){
			my_fgets(contenu, 30, file);
			time = atoi(contenu);
			switch(i){
				case 1:
					printf("boule orange");
				break;
				case 2:
					printf("boule yellow");
				break;
				case 3:
					printf("boule red");
				break;
				case 4:
					printf("boule navyblue");
				break;
				case 5:
					printf("boule turquoise");
				break;
				case 6:
					printf("boule green");
				break;
				case 7:
					printf("boule purple");
				break;
				case 8:
					printf("boule pink");
				break;
				case 9:
					printf("boule violet");
				break;
				case 10:
					createEnnemy(octogone, 60*time);
				break;
				case 11:
					createEnnemy(cross, 60*time);
				break;
				default :
					printf("apprend à coder\n");
				}

		}
	}
	currentvague++;
	}
	fclose(file);
	return 0;
}
