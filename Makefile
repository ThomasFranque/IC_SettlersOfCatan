SettlersOfJapun: main.o configmap.o diceroll.o gamelogic.o ini.o aiai.o
		gcc main.o configmap.o diceroll.o gamelogic.o ini.o aiai.o -o SettlersOfJapun

main.o: main.c ini.h diceroll.h configmap.h gamelogic.h aiai.h
		gcc -Wall -Wextra -std=c99 -g -c -o main.o main.c
configmap.o: configmap.c configmap.h
	gcc -Wall -Wextra -std=c99 -g -c -o configmap.o configmap.c
diceroll.o: diceroll.c diceroll.h
	gcc -Wall -Wextra -std=c99 -g -c -o diceroll.o diceroll.c
ini.o: ini.c ini.h
	gcc -Wall -Wextra -std=c99 -g -c -o ini.o ini.c
aiai.o: aiai.c aiai.h
	gcc -Wall -Wextra -std=c99 -g -c -o aiai.o aiai.c
gamelogic.o: gamelogic.c gamelogic.h
	gcc -Wall -Wextra -std=c99 -g -c -o gamelogic.o gamelogic.c
clean:
		rm -f SettlersOfJapun *.o
