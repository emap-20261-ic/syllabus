
# OPT controla as flags do compilador.
#
# Sobre otimização (importante para a tarefa 6):
#
#   -O0    sem otimização (default do clang). Bom para depuração,
#          mas o compilador NÃO aplica tail call optimization (TCO).
#          Com -O0, list_del_rec_tc se comporta igual à versão não
#          tail recursive: cada chamada empilha um frame, e listas
#          longas estouram a pilha.
#
#   -O2    otimização padrão de produção. Clang aplica TCO nas
#          chamadas em posição de cauda, convertendo a recursão em
#          laço e usando O(1) de pilha. Necessário para o stress
#          test de 1M nós em test-solution.c passar.
#
# Para o laboratório, vale experimentar trocando -O0 ↔ -O2 e ver
# como list_del_rec_tc muda de comportamento. -O0 é o default da
# turma; mude para -O2 quando quiser ver TCO em ação.
OPT=-Wall -Werror -std=c17 -O0

all: test

list.o: list.c
	clang -c ${OPT} $< -o $@

list.so: list.o
	clang -shared $< -o $@

test: list.so list.h test.c
	clang ${OPT} test.c $< -o $@

clean:
	rm -f test list.o list.so
	rm -rf test.dSYM

