
colorize: colorize.c helpers.c
	clang -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -o colorize colorize.c helpers.c

clean:
	rm colorize
