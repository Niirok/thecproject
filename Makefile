jeuC : draw.o init.o input.o map.o player.o main.o ennemy.o niveau_const.o
	gcc  draw.o init.o input.o  map.o player.o main.o ennemy.o niveau_const.o -o jeuC -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lm


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
	gcc -c  map.c -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image

ennemy.o :ennemy.c prototypes.h
	gcc -c ennemy.c

niveau_const.o : niveau_const.c prototypes.h
	gcc -c niveau_const.c
clean:
	rm -f *.o

	

