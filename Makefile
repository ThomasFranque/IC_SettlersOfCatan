# Antes de usar fazer: cp Makefile1 Makefile

Settlers_of_Japan: main.o diceroll.o fad.o map_print.o readConfig.o
	gcc main.o diceroll.o fad.o map_print.o readConfig.o -o Settlers_of_Japan

main.o: main.c diceroll.h fad.h map_print.h readConfig.h
	gcc -Wall -Wextra -Wpedantic -std=c99 -g -c -o -IHEADER main.o main.c

diceroll.o: diceroll.c diceroll.h
	gcc -Wall -Wextra -Wpedantic -std=c99 -g -c -o -IHEADER diceroll.o diceroll.c

fad.o: fad.c fad.h
	gcc -Wall -Wextra -Wpedantic -std=c99 -g -c -o -IHEADER fad.o fad.c

map_print.o: map_print.o map_print.c
	gcc -Wall -Wextra -Wpedantic -std=c99 -g -c -o -IHEADER fad.o fad.c

readConfig.o: readConfig.c readConfig.h
	gcc -Wall -Wextra -Wpedantic -std=c99 -g -c -o -IHEADER fad.o fad.c

#mais files e so seguir a receita

clean:
	rm -f Settlers_of_Japan *.o

