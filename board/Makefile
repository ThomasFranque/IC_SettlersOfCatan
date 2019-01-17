CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -g
LDFLAGS=
LDLIBS=

PROGRAM=test_agents

$(PROGRAM): $(PROGRAM).o world_canvas_ascii.o world.o

$(PROGRAM).o: $(PROGRAM).c agent.h world.h world_canvas.h

world.o: world.c world.h agent.h

world_canvas_ascii.o: world_canvas_ascii.c world_canvas.h world.h agent.h

.PHONY: clean
clean:
	rm -f $(PROGRAM) *.o
