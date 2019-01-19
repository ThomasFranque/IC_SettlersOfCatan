# Antes de usar fazer: cp Makefile1 Makefile

Settlers_of_Japan: main.o diceroll.o fad.o map.o readConfig.o
	gcc main.o diceroll.o fad.o map_print.o readConfig.o -o Settlers_of_Japan

main.o: main.c fad.h map.h readconfig.h
	gcc -Wall -Wextra -std=c99 -g -c -o main.o main.c

diceroll.o: diceroll.c diceroll.h
	gcc -Wall -Wextra -std=c99 -g -c -o diceroll.o diceroll.c

fad.o: fad.c fad.h
	gcc -Wall -Wextra -std=c99 -g -c -o fad.o fad.c

map.o: map.h map.c
	gcc -Wall -Wextra -std=c99 -g -c -o map.o map.c

readConfig.o: readConfig.c readconfig.h
	gcc -Wall -Wextra -std=c99 -g -c -o readConfig.o readConfig.c

clean:
	rm -f Settlers_of_Japan *.o

