CFLAGS=-Wall -g -I.
CC=gcc
DEPS=pe_problem6.h pe_problem14.h pe_problem22.h
OBJ=main.o pe_problem6.o pe_problem14.o pe_problem22.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

default: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	\rm *.o main
