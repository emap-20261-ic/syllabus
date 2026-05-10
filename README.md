# Introdução à Computação da EMAp 2026.1

Professor: alexandre.rademaker@fgv.br

## Estrutura do Repositório

O conteúdo está organizado por semanas. Cada subdiretório `semana-N/`
contém:

- **Notas de aula** — arquivos `aula-2026MMDD.md` com o registro do que
  foi apresentado em cada aula. Quando o conteúdo dos slides diverge das
  notas, **as notas são a fonte de verdade**.
- **Slides** — arquivos `slides-SSN.tex` (fonte LaTeX, onde `SS` é o
  número da semana e `N` o índice dentro da semana) e `slides-SSN.pdf`
  (versão compilada). Slides foram usados de forma esporádica; alguns
  ficam apenas como referência para estudo dos alunos.
- **Laboratórios** — subdiretório `lab/` com exercícios para prática
  autônoma; não são entregues nem corrigidos.

Compartilhados no topo do `syllabus/`:

- **Imagens** em `img/` (referenciadas pelos slides via
  `\graphicspath{{../img/}}`).
- **Exemplos de código** em `src/`, com os programas C usados como
  exemplos no curso. Projetos multi-arquivo ficam em subdiretórios
  (`src/filter/`, `src/list/`, `src/queue/`). Os slides referenciam estes
  arquivos via `\lstset{inputpath=../src/}`.

## Programa 

O calendário do curso segue 
[calendário 2026 EMAp](https://emap.fgv.br/sites/default/files/2025-11/calendario_2026_fgv_emap_1.pdf).

### semana 0 (23, 25, 27/fev) — aulas 1, 2, 3

Apresentação do curso, ferramentas e metodologia. Terminal e linha de
comando (navegação, comandos básicos, pipes e redirecionamento). Git e
GitHub para controle de versão (commits, staging, push/pull). GitHub
Codespaces e configuração do ambiente.

### semana 1 (2, 4, 6/mar) — aulas 4, 5, 6

Arquitetura básica de computadores (unidades lógicas, portas lógicas,
CPU). Representação de dados: bits, binário, inteiros com e sem sinal
(complemento de dois), texto (ASCII/Unicode), imagens e áudio. Hardware,
software e sistema operacional (processos, shell, CLI vs GUI). Algoritmos
e linguagens (máquina, assembly, alto nível). Compilação em C com
gcc/clang, flags, Makefile e linking.

### semana 2 (9, 11, 13/mar) — aulas 7, 8, 9, 10

(13/mar foi sexta com reposição: aula regular pela manhã + aula extra
das 11:10 às 12:50, contabilizadas como aulas 9 e 10.)

Programação estruturada (sequência, decisão, repetição). Tipos primitivos
em C (`bool`, `char`, `int`, `long`, `float`, `double` e modificadores
`signed`/`unsigned`), variáveis, expressões aritméticas, conversão
implícita e representação IEEE 754. Entrada e saída com `printf` e
`scanf`. Estruturas de decisão (`if-then-else`) e de repetição (`while`,
`do-while`, `for`, laços aninhados).

### semana 3 (27/mar) — aulas 11, 12

(Recesso de viagem entre 16 e 25/mar. A semana foi recuperada com
reposição em 27/mar — aula regular pela manhã + aula extra das 11:10 às
12:50.)

Funções com `main` como orquestrador. `switch` como alternativa ao
`if-else` encadeado. Depuração com `printf` e com o depurador do
Codespaces. Arrays e ponteiros: operadores `&` (endereço) e `*`
(desreferência), passagem por referência vs por valor. Introdução a
strings como arrays de caracteres terminados em `'\0'`.

### semana 4 (30/mar, 1/abr) — aulas 13, 14

(03/abr foi recesso de Semana Santa, sem aula na sexta.)

Números hexadecimais (base 16, prefixo `0x`, conversão binário↔hex) e
seus usos (endereços de memória, cores RGB). RAM como array de bytes
endereçados, tamanho fixo de cada tipo, `NULL` e segmentation fault.
Escopo de variáveis (locais vs globais) e passagem por valor. Aritmética
de ponteiros (`a[i]` como `*(a+i)`, `sizeof`, decay de array para
ponteiro). Argumentos de linha de comando (`argc`, `argv`, `atoi`).

### semana 5 (6, 8, 10/abr) — aulas 15, 16, 17, 18

(Semana de A1 entre 11 e 18/abr e viagem entre 16 e 25/abr. 10/abr foi
sexta com reposição: aula regular pela manhã + aula extra das 11:10 às
12:50, contabilizadas como aulas 17 e 18.)

Operações com strings (`strlen`, `<ctype.h>`, `strcmp` e por que `==` não
compara conteúdo; implementação manual de `strcmp` com aritmética de
ponteiros). Incremento pré e pós-fixado e operador ternário. Análise de
algoritmos e notação Big-O (correção vs eficiência, dominância,
constantes multiplicativas). Busca linear O(n) vs busca binária O(log n)
com implementação iterativa e recursiva.

### semana 6 (27, 29/abr) — aulas 19, 20

(01/mai foi feriado do dia do trabalho, sem aula na sexta.)

`struct` em C — motivação a partir de arrays paralelos (agenda
telefônica), `typedef struct`, agrupamento de campos relacionados num
único tipo. Solução completa do laboratório `snackbar` combinando
`struct` com `enum` para comandos e códigos de saída. Introdução a
recursão. Selection sort.

### semana 7 (4, 6, 8/mai) — aulas 21, 22, 23, 24

(08/mai foi sexta com reposição: aula regular pela manhã + aula extra
das 11:10 às 12:50, contabilizadas como aulas 23 e 24.)

Algoritmos de ordenação (bubble sort com otimizações; merge sort com
divisão e conquista, complexidade O(n log n)). Alocação dinâmica de
memória — stack vs heap, `malloc`, `free`, `sizeof`. Perigos de `scanf`
ao ler strings (buffer overflow, alternativa com `fgets`). Leitura e
escrita em arquivos (`fopen`/`fclose`, `fprintf`/`fscanf`,
`fread`/`fwrite`), byte vs char (hexdump, magic numbers, formato BMP com
`__attribute__((packed))`). Depuração de erros de memória (vazamentos
com `leaks` no macOS, use-after-free, leitura de não inicializado). Por
ser dia de reposição, antecipamos conteúdo da semana 8: `realloc` e
listas encadeadas (operações e variantes destrutivas vs não destrutivas).

### semana 8 (11, 13, 15/mai) — aulas 25, 26, 27, 28

(15/mai será sexta com reposição.)

TODO

### semana 9 (18, 20, 22/mai) — aulas 29, 30, 31, 32

(22/mai será sexta com reposição.)

TODO

### semana 10 (25, 27/mai) — aulas 33, 34

(Viagem entre 29/mai e 4/jun. Sem aula em 29/mai, 1/jun e 3/jun. 5/jun é
recesso pós-Corpus Christi.)

TODO

### semana 11 (8, 10, 12/jun) — aulas 35, 36, 37, 38

(12/jun será sexta com reposição.)

TODO

### semana 12 (15/jun) — aula 39

(Semana de A2 entre 17 e 24/jun, sem aulas regulares — apenas a prova.)

TODO

### semana 13 (26/jun) — aula 40

(Reposição em 26/jun, sexta após a semana de A2.)

TODO

## critérios de avaliação

Temos A1 e A2

$A_n$ = 50% (média simples dos assignments) + 40% Prova + 10% Participação

## Links

- http://hackerrank.com
- https://codeforwin.org/c-programming
- https://cs50.harvard.edu/x/
- https://www.codecademy.com/catalog/language/c
- https://www.indiabix.com
- https://www.pucsp.br/~so-comp/cursoc/
- https://www.sanfoundry.com/c-mcqs-file-operations/  
- https://www.tutorialspoint.com/cprogramming/c_pointers.htm
- https://www.udemy.com/course/c-programming-skills
- https://www.w3resource.com/c-programming-exercises/file-handling/index.php  
- https://www.w3schools.com/c/
- https://www.geeksforgeeks.org/top-mcqs-on-mergesort-algorithm-with-answers/
