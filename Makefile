Testconfig: testconfig.o ini.o
		gcc testconfig.o ini.o -o Testconfig

testconfig.o: testconfig.c ini.h
	gcc -Wall -Wextra -std=c99 -g -c -o testconfig.o testconfig.c

ini.o: ini.c ini.h
	gcc -Wall -Wextra -std=c99 -g -c -o ini.o ini.c
clean:
		rm -f Testconfig *.o
