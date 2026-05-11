# Gabarito — Laboratório 8

Documento de apoio para os exercícios de `README.org`. Reúne notas
sobre cada tarefa, respostas das perguntas de discussão e a
comparação entre os dois algoritmos de ordenação implementados. A
solução completa em código está em `list-solution.c`; o gabarito dos
testes está em `test-solution.c`.

## Tarefa 1 — `list_array`

Inverso de `list_create`. Iteração padrão sobre a lista, copiando
`number` para o array fornecido pelo chamador.

Decisão de design: o buffer vem do chamador (não é alocado pela
função). A alternativa — devolver `int*` resultado de `malloc` —
mudaria a responsabilidade de `free` para o chamador. A versão atual
deixa a alocação onde já está (na stack, ou no espaço do chamador).

## Tarefa 2 — `list_split`

Algoritmo *tortoise and hare* de Floyd. Dois ponteiros: `slow` avança
um passo por iteração, `fast` avança dois. Quando `fast` chega ao
fim, `slow` está no nó imediatamente antes da metade.

Convenção: lista de tamanho ímpar dá a **primeira** metade o
elemento extra. `[1,2,3,4,5]` → `[1,2,3]` + `[4,5]`.

**Pré-condição silenciosa**: requer `size >= 2`. A implementação faz
`fast = source->next` sem checar `source != NULL`. Em produção, isso
exigiria documentação ou guarda explícita.

## Tarefa 3 — `list_hasloop`

Mesmo Floyd, agora para **detecção** de ciclos. Se a tartaruga
encontra a lebre em algum momento, há ciclo. Se `fast` chega a `NULL`,
não há.

A correção é matemática: num ciclo de tamanho $k$, depois que a
tartaruga entra no ciclo, a lebre fecha um ciclo a cada $k$ passos
da tartaruga — encontro garantido em no máximo $k$ passos.

## Tarefa 4 — `merge_sort`

Recursão clássica: `list_split` divide; `merge_sort` ordena cada
metade; `merge_sorted` combina duas listas ordenadas religando
ponteiros.

Diferença para a versão em array: o `merge_sorted` em lista **não
aloca buffer auxiliar**. Combina simplesmente religando o `next` do
nó com menor `number` a cada passo. A versão em array gastava
$O(n)$ de memória extra para `t`; aqui esse custo desaparece.

## Tarefa 5 — `selection_sort`

A cada iteração, encontra o **maior** nó da lista não-ordenada,
destaca via rearranjo de ponteiros, e **prepende** à lista
ordenada. Final: ordem ascendente (o maior empurrado primeiro fica
no fim; o último empurrado, menor de todos, fica no head).

A escolha "max + prepend" (em vez de "min + append") evita ter que
manter um ponteiro para o tail da lista ordenada — código mais
curto.

## Tarefa 6 — `list_del_rec_tc`

A função canônica `list_del_rec` libera os nós **depois** do retorno
da chamada recursiva:

```c
void list_del_rec(t_node *a) {
  if (a == NULL) return;
  list_del_rec(a->next);   /* trabalho APÓS o retorno */
  free(a);
}
```

A versão tail recursive reordena para que a chamada seja a **última
ação** da função:

```c
void list_del_rec_tc(t_node *a) {
  if (a == NULL) return;
  t_node *next = a->next;
  free(a);
  list_del_rec_tc(next);   /* posição de cauda */
}
```

A variável local `next` é necessária porque, depois de `free(a)`, o
campo `a->next` é memória já liberada — não pode ser lido.

### Por que isso importa: TCO

Quando a chamada recursiva está em posição de cauda, o compilador
*pode* aplicar a otimização de chamada de cauda (TCO): em vez de
empilhar um novo frame, ele reaproveita o frame atual — efetivamente
convertendo a recursão em laço. O resultado é $O(1)$ de uso de pilha
em vez de $O(n)$.

**Mas o padrão C não garante TCO.** É decisão do compilador, e
depende do nível de otimização. Em `clang -O0` (sem otimização),
nenhuma TCO acontece. Em `clang -O2`, sim.

### Experimento empírico

Lista de 10⁶ nós, stack padrão de 8 MB no macOS:

| função            | `-O0`             | `-O2`             |
|-------------------|-------------------|-------------------|
| `list_del`        | ✅ passa          | ✅ passa          |
| `list_del_rec`    | ❌ stack overflow | ❌ stack overflow |
| `list_del_rec_tc` | ❌ stack overflow | ✅ passa (TCO)    |

Três conclusões pedagógicas:

1. `list_del_rec` quebra **independentemente da otimização**: a
   transformação para laço seria complexa (precisaria mover o `free`
   para antes da chamada e provar que isso é equivalente) e nenhum
   compilador comum a faz.
2. Forma tail recursive não é suficiente sozinha — sem `-O2` (ou
   superior), clang não aplica TCO e a vulnerabilidade permanece.
3. A `list_del` iterativa é $O(1)$ na pilha por construção, sem
   depender de nenhuma promessa do compilador. **É a escolha
   padrão** quando se quer correção independente de flag de
   compilação.

Contraste com linguagens onde TCO é **garantida pela especificação**
(Scheme, OCaml): lá, recursão em posição de cauda é semanticamente
equivalente a um laço, e o programador pode confiar nisso.

## Sobre os testes

O gabarito completo (`test-solution.c`) usa `assert` e cobre:

- todas as tarefas em **casos extremos**: lista vazia, unitária, já
  ordenada, ordem inversa, com duplicatas, todos iguais;
- `list_split` em tamanhos 2 (caso mínimo), par e ímpar;
- `list_hasloop` sem ciclo, em lista vazia, em lista unitária, e com
  ciclo criado por `list_nconc(a, a)`;
- propriedades dos sorts: comprimento preservado e resultado
  efetivamente ordenado, verificado via `list_nth`.

Limitação: o tipo `t_node` é **opaco** no test, então não dá para
quebrar manualmente o ciclo criado no teste de `list_hasloop`. A
memória dessa lista cíclica é deliberadamente vazada (recuperada
pelo SO ao final do processo).

## Perguntas para discussão - o que documentar

O que **não** é evidente lendo só o `list.h`? Tudo que segue
precisaria entrar na documentação para alguém usar a biblioteca sem
sustos.

### Funções que abortam em entrada inválida

`list_first`, `list_rest` chamam `exit(1)` se `list == NULL`.
`list_nth(list, n)` aborta se `n >= list_size(list)`.

Não devolvem código de erro nem usam parâmetro de saída — terminam
o programa. Em uma biblioteca de produção isso seria inaceitável: o
idioma comum seria devolver código de erro, usar `errno`, ou
parâmetro de saída.

### Ownership não-óbvio do retorno

- `list_insert(elem, list)` devolve o **novo head**. O chamador é
  obrigado a fazer `list = list_insert(7, list)`. Esquecer essa
  atribuição faz o nó novo vazar e o `list` original não muda.
- `list_reverse(a)`, `list_copy(a)`: alocam uma **nova** lista de
  mesmo tamanho. O chamador agora tem duas listas para liberar.
- `list_append(a, b)`: copia os nós de `a`, mas **compartilha** os
  nós de `b` na lista resultante. Se alguém modificar a "cauda" do
  resultado, modifica `b` junto. Bug clássico de aliasing.

### Funções destrutivas

- `list_nconc(a, b)` muta o último nó de `a` para apontar para `b`.
  Caso especial perigoso: se `a == b`, **cria um ciclo** que
  inviabiliza qualquer percurso subsequente (`list_print`, `list_del`
  entram em loop infinito).
- `merge_sorted(a, b)`: ambas as listas de entrada são **consumidas**.
  Após a chamada, `a` e `b` referenciam nós que agora pertencem ao
  resultado.
- `merge_sort(&list)`, `selection_sort(&list)`: ordenação **in
  place**. A assinatura `t_node**` denuncia que o head pode mudar.
- `list_filter(&head, f)`: in place também; libera os nós que `f`
  rejeita.

### Pré-condições silenciosas

- `list_split(source, &a, &b)` requer `source` com **pelo menos 2
  nós**. Sem isso, segfault.
- `list_array(list, ar, size)` requer `ar` com capacidade ≥ `size`
  inteiros. Não há checagem. Se `size > list_size(list)`, o array
  termina com lixo nas posições finais.

### Riscos operacionais

- `list_print(list, sep)` imprime o separador **após cada elemento**,
  inclusive o último (`"1 2 3 "` em vez de `"1 2 3"`).

- `list_del_rec` é recursiva sem forma tail call: **pode estourar a
  pilha** em listas longas. Existe uma alternativa em forma tail
  recursive (`list_del_rec_tc` — ver tarefa 6), mas mesmo essa
  depende do compilador aplicar TCO, e o padrão C não garante. Para
  correção independente de flags de compilação, use `list_del`
  (iterativa).

## Comparação `merge_sort` × `selection_sort`

### Complexidade de pior caso

| algoritmo        | tempo         | observação                                                |
|------------------|---------------|-----------------------------------------------------------|
| `merge_sort`     | $O(n \log n)$ | $\log n$ níveis de divisão × $O(n)$ por nível             |
| `selection_sort` | $O(n^2)$      | varre o restante a cada iteração; $n + (n-1) + \dots + 1$ |

Detalhe sutil do `selection_sort` em lista: quando o max **não é o
head**, ainda é preciso percorrer para achar o predecessor e religar o
`next`. Em array isso é grátis (acessa `a[i-1]`); em lista
simplesmente encadeada, não há "voltar".

### Memória extra

| algoritmo        | extra  | onde                                              |
|------------------|--------|---------------------------------------------------|
| `merge_sort`     | $O(n)$ | pilha de chamadas (`merge_sorted` recursivo)      |
| `selection_sort` | $O(1)$ | poucas variáveis locais — implementação iterativa |

Note o contraste com merge sort **em array**: lá era preciso um buffer
auxiliar de tamanho $n$. Em lista, esse custo soma zero, pois o merge
só religa ponteiros existentes.

### Quando `selection_sort` ainda compensa

1. **Listas pequenas** ($n$ na casa de dezenas). A constante do $n
   \log n$ é alta — recursão, splits, frames. Várias implementações de
   `qsort`/`std::sort` reais comutam para selection/insertion sort
   abaixo de um limiar.

2. **Stack escassa** (microcontroladores, código sem heap). O
   `merge_sort` recursivo pode estourar a pilha; o `selection_sort`
   iterativo roda em $O(1)$ extra, independente de $n$.

3. **Simplicidade e auditabilidade**. Código curto, sem recursão, mais
   fácil de provar correto e depurar passo a passo.

4. **Número mínimo de "movimentos"**. O `selection_sort` faz no máximo
   $n$ destacamentos+religações. Importante quando o custo de mover um
   elemento é caro — não é o caso de `int` em lista, mas vale lembrar.

**Resumo**: `merge_sort` é a escolha padrão. `selection_sort` é a
ferramenta certa quando $n$ é pequeno, a stack é cara ou o código
precisa ser o mais simples possível.
