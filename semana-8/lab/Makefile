
OPT=-Wall -Werror -std=c17

all: test

list.o: list.c
	clang -c ${OPT} list.c

list.so: list.o
	clang -shared list.o -o list.so

test: list.so list.h test.c
	clang ${OPT} test.c list.so -o test

clean:
	rm test
	rm list.o
	rm -rf test.dSYM
	rm list.so

