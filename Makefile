<<<<<<< HEAD
jeuC : draw.o init.o input.o main.o map.o
	gcc  draw.o init.o input.o main.o map.o -o jeuC -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image
=======
jeuC : draw.o init.o input.o player.o main.o
	gcc  draw.o init.o input.o player.o main.o -o jeuC -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image
>>>>>>> AnthoPlayer

draw.o : draw.c prototypes.h
	gcc -c  draw.c

init.o : init.c prototypes.h
	gcc -c  init.c

input.o : input.c prototypes.h
	gcc -c  input.c
	
player.o : player.c prototypes.h
	gcc -c	player.c
	
main.o : main.c prototypes.h
<<<<<<< HEAD
	gcc -c   main.c

map.o  : map.c prototypes.h
	gcc -c  map.c -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image
=======
	gcc -c	main.c

clean:
	rm -f *.o core
	
mrproper:	clean
	rm -f *.o jeuC
>>>>>>> AnthoPlayer
