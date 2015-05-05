jeuC : draw.o init.o input.o player.o main.o
	gcc  draw.o init.o input.o player.o main.o -o jeuC -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image

draw.o : draw.c prototypes.h
	gcc -c  draw.c

init.o : init.c prototypes.h
	gcc -c  init.c

input.o : input.c prototypes.h
	gcc -c  input.c
	
player.o : player.c prototypes.h
	gcc -c	player.c
	
main.o : main.c prototypes.h
	gcc -c	main.c

clean:
	rm -f *.o core
	
mrproper:	clean
	rm -f *.o jeuC