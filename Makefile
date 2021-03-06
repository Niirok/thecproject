jeuC : draw.o init.o input.o map.o player.o main.o ennemy.o shoot.o
	gcc  draw.o init.o input.o map.o player.o main.o ennemy.o shoot.o -o jeuC -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lm

draw.o : draw.c prototypes.h
	gcc -c  draw.c

init.o : init.c prototypes.h
	gcc -c  init.c

input.o : input.c prototypes.h
	gcc -c  input.c

player.o : player.c prototypes.h
	gcc -c	player.c
	
main.o : main.c prototypes.h
	gcc -c   main.c

map.o  : map.c prototypes.h
	gcc -c  map.c 

shoot.o : shoot.c prototypes.h
	gcc -c	shoot.c

ennemy.o : ennemy.c prototypes.h
	gcc -c ennemy.c

clean:
	rm -f *.o 
	
mrproper:	clean
	rm -f *.o jeuC

