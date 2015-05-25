jeuC : *.c *.h
	gcc  *.c -o jeuC -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lm

clean:
	rm -f *.o

	

