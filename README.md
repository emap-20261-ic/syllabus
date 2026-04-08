# Introdução à Computação da EMAp 2026.1

Professor: alexandre.rademaker@fgv.br

## Estrutura do Repositório

O conteúdo está organizado por semanas. Cada subdiretório `semana-N/`
contém:

- **Notas de aula** — arquivos `aula-2026MMDD.md` com o registro do
   que foi apresentado em cada aula.
- **Slides** — arquivos `slides-NN.tex` (fonte LaTeX) e
  `slides-NN.pdf` (versão compilada), cujo conteúdo geralmente é
  apresentado nas aulas quando não usamos os códigos C diretamente.
- **Exemplos de código** — subdiretório `src/` com os programas
   usados como exemplos durante as aulas.
- **Laboratórios** — subdiretório `lab/` com exercícios para prática
  autônoma; não são entregues nem corrigidos.


## Programa

O calendário do curso segue [calendário 2026 EMAp](https://emap.fgv.br/sites/default/files/2025-11/calendario_2026_fgv_emap_1.pdf).

### semana 0 (23, 25, 27/fev)

- apresentação do curso, ferramentas e metodologia
- terminal e linha de comando: navegação, comandos básicos, pipes e
  redirecionamento
- git e controle de versão: repositórios, commits, staging area,
  push/pull, GitHub
- GitHub Codespaces e configuração do ambiente

### semana 1 (2, 4, 6/mar)

- arquitetura de computadores: unidades lógicas, portas lógicas, CPU
- representação de dados: bits, binário, inteiros (com/sem sinal,
  complemento de dois), texto (ASCII/Unicode), imagens, áudio
- hardware, software e sistema operacional: processos, shell, CLI vs
  GUI
- algoritmos e linguagens de programação: linguagem de máquina,
  assembly, alto nível
- compilação em C: fases, gcc/clang, flags, make e Makefile, linking

### semana 2 (9, 11, 13/mar)

- programação estruturada: sequência, decisão, repetição
- tipos de dados em C: bool, char, int, long, float, double;
  modificadores signed/unsigned
- variáveis e memória: declaração, inicialização, atribuição, const,
  expressões aritméticas, conversão implícita, representação IEEE 754
- printf e scanf: especificadores de formato
- decisão: if-then-else, validação de entrada, tratamento de erros
- repetição: while, do-while, for, laços aninhados

### semana 3 (27/mar)

- funções: definição, protótipos, modularização, main como
  orquestrador
- switch como alternativa ao if-else encadeado
- depuração (debug): técnicas com printf, uso do depurador no
  Codespaces
- arrays: declaração, inicialização, acesso por índice
- ponteiros: operadores `&` (endereço) e `*` (desreferência), passagem
  por referência vs por valor
  

### semana 4 (30/mar, 1/abr)

- números hexadecimais: base 16, dígitos 0–9 e A–F, prefixo `0x` em
  C, conversão binário↔hex agrupando 4 bits por dígito
- uso do hexadecimal: representação compacta de endereços de memória
  (32-bit ~4 GB, 64-bit muito maior) e de cores RGB (`#RRGGBB`)
- endereços de memória e ponteiros: RAM como array de bytes endereçados,
  tamanho fixo de cada tipo (`int`: 4, `char`: 1, `double`: 8,
  ponteiro: 8 em 64-bit), operadores `&` (endereço) e `*`
  (dereferenciação), `NULL` e segmentation fault
- escopo de variáveis: variáveis locais vs globais, passagem por valor
  (função recebe cópia, não afeta o chamador)
- arrays e aritmética de ponteiros: `a[i]` é açúcar sintático para
  `*(a+i)`, diferença entre array (bloco fixo de memória) e ponteiro
  (variável que guarda endereço), `sizeof`, decay de array para ponteiro
  ao passar para funções
- argumentos de linha de comando: `argc` e `argv`, `atoi`, código de
  retorno de `main` e encadeamento com `&&` no shell

### semana 5 (6/abr, 8/abr)

- operações com strings: `strlen` e o tipo `size_t`, impressão eficiente
  (calcular comprimento uma única vez), conversão de maiúsculas/minúsculas
  via tabela ASCII e via `<ctype.h>` (`islower`, `toupper`), `strcmp`
  para comparação de strings
- incremento pré e pós-fixado: `++a` vs `a++` e quando a diferença importa
- análise de algoritmos e notação O: correção vs eficiência, complexidade
  de tempo e memória, notação Big-O e suas propriedades (dominância,
  constantes multiplicativas)
- busca linear vs busca binária: busca linear O(n) sem pré-requisito de
  ordenação; busca binária O(log n) exigindo array ordenado; implementação
  iterativa vs recursiva; instrumentação para entender o comportamento
- estruturas em C (`struct`): motivação (agrupar campos heterogêneos),
  declaração e acesso a membros


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
