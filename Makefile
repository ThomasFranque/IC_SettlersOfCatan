Settlers_of_Ja_pun: main.o configmap.o diceroll.o game_logic.o ini.o
		gcc main.o configmap.o diceroll.o game_logic.o ini.o -o Settlers_of_Ja_pun

main.o: main.o ini.h diceroll.h configmap.h
		gcc -Wall -Wextra -std=c99 -g -c -o main.o main.c
configmap.o: configmap.c configmap.h
	gcc -Wall -Wextra -std=c99 -g -c -o configmap.o configmap.c
diceroll.o: diceroll.c diceroll.h
	gcc -Wall -Wextra -std=c99 -g -c -o diceroll.o diceroll.c
ini.o: ini.c ini.h
	gcc -Wall -Wextra -std=c99 -g -c -o ini.o ini.c
clean:
		rm -f Settlers_of_Ja_pun *.o
