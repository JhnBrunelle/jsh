CC=gcc
CFLAGS=-c
CMATH=-lm

all: clean jsh

jsh: jsh.o shell.o utils.o command.o
	$(CC) -o $@ $^ $(CMATH)

jsh.o: jsh.c jsh.h
	$(CC) $(CFLAGS) -o $@ $<

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -o $@ $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -o $@ $<

command.o: command.c command.h
		$(CC) $(CFLAGS) -o $@ $<


test: clean myOS

clean:
	rm -f *.o jsh
