
OPT=-Wall -Werror -Wpedantic -std=c17
COMPILER=clang

all: test

list.o: list.c
	${COMPILER} -c ${OPT} list.c

list.so: list.o
	${COMPILER} -shared list.o -o list.so

test: list.so list.h list-test.c
	${COMPILER} ${OPT} list-test.c list.so -o test

clean:
	rm test
	rm list.o
	rm -rf test.dSYM
	rm list.so

