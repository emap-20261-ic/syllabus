# Semana 1 — Introdução à Computação

## Aula 1 — Arquitetura básica dos computadores (slides 1)

### O que é um computador?

O que diferencia um computador de outras máquinas que inventamos — um
microondas, um trator, uma máquina de lavar louças? Ao invés de nos
ajudar com trabalhos manuais, movendo ou manipulando coisas físicas,
computadores nos ajudam a resolver equações, rastrear estrelas no céu,
manipular informações ou dados.

Os computadores processam **dados** executando uma sequência de
instruções. Chamamos uma sequência de instruções de **programa de
computador**. Os **programadores de computador** são as pessoas que
criam esses programas.

Dentro de um computador temos cabos, circuitos, dispositivos de
entrada (teclado, mouse) e saída (monitor), placas de memória,
conectores — o que chamamos de **hardware**. Os **softwares** são os
programas armazenados no computador, na memória secundária
(disco). Podem ser jogos, planilhas, editores de imagens, etc.

Historicamente, os primeiros computadores tinham muitas partes
mecânicas, depois passaram a usar componentes eletrônicos (anos
1920–30) — grandes calculadoras.

### Tarefas fundamentais de todo computador

- **Input**: receber dados via teclado, mouse, sensores, etc.
- **Storage**: armazenar informações e dados
- **Processing**: transformar dados em outros dados
- **Output**: produzir saídas — vídeo, imagens, textos, sinais

### Organização do computador

Praticamente todos os computadores podem ser divididos em seis unidades lógicas:

1. **Dispositivos de entrada** — obtêm informações e as colocam à
   disposição das outras unidades. Exemplos: teclados, touch screens,
   mouse, microfone, webcam, GPS, acelerômetro.

2. **Dispositivos de saída** — a maioria das informações é exibida em
   telas, impressa em papel ou enviada a outros dispositivos e redes.

3. **Armazenamento principal (RAM)** — armazena os programas durante a
   execução. Acesso rápido mas capacidade relativamente
   pequena. **Volátil**: as informações são perdidas quando o
   computador é desligado.

4. **Armazenamento secundário** — HDs, SSDs, CDs, DVDs. Alta
   capacidade, acesso mais lento (SSDs são mais rápidos que HDDs
   mecânicos). **Persistente**: preservado ao desligar. Custo por
   unidade bem menor que a RAM.

5. **Unidade de aritmética e lógica (ALU)** — realiza cálculos
   (adição, subtração, multiplicação, divisão) e comparações. Nos
   sistemas atuais é implementada como parte da CPU.

6. **Unidade Central de Processamento (CPU)** — coordena todas as
   partes do computador. Computadores modernos têm múltiplas CPUs ou
   processadores *multi-core* (dual-core, quad-core…), capazes de
   executar muitas operações simultaneamente.

### Circuitos e portas lógicas

Sinais elétricos produzidos na entrada são processados produzindo
sinais nas saídas. Para isso os bits precisam ser combinados.

Componentes básicos chamados **portas lógicas** (AND, OR, NOT…)
produzem novos bits a partir dos bits que recebem. Esses componentes
se combinam em circuitos com tarefas especializadas: um somador de 1
bit, por exemplo, pode ser combinado para formar um somador de 8
bits. Da mesma forma constroem-se multiplicadores binários.

Nos antigos computadores os circuitos eram longos e demandavam minutos
para operações simples. À medida que foram miniaturizados, o
desempenho aumentou enormemente — sinais transmitidos à velocidade da
luz em distâncias microscópicas.

> Para saber mais: [How Computers
> Work](https://youtube.com/playlist?list=PLzdnOPI1iJNcsRwJhvksEo1tJqjIqWbN-)


## Aula 2 — Representação de dados e sistema operacional (slides 2 e 3)

### Representação de dados

Circuitos eletrônicos transmitem sinais elétricos. Com um único fio
condutor podemos indicar dois estados — **bits**: ligado e desligado,
0 ou 1, Verdade ou Falso. Com mais fios, representamos mais bits
simultaneamente.

**Em um computador, tudo são bits: 0 ou 1.**

### Representação binária

Números decimais usam base 10:

$$123 = 1 \times 10^2 + 2 \times 10^1 + 3 \times 10^0 = 100 + 20 + 3$$

Números binários usam base 2:

$$1101_2 = 1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0 = 8 + 4 + 0 + 1 = 13$$

| Binário | Decimal |
|---------|---------|
| 000     | 0       |
| 001     | 1       |
| 010     | 2       |
| 011     | 3       |
| 100     | 4       |
| 111     | 7       |

A maioria dos computadores usa **palavras de 8 bits** (1 byte). Com 32
bits representamos $2^{32}$ ≈ 4 bilhões de números.

> **Observação:** 1 kilobyte = $2^{10}$ = 1.024 bytes, não
> 1.000. Computadores operam em base 2, então potências de 2 são mais
> naturais. Ver: [Binary
> prefix](https://en.wikipedia.org/wiki/Binary_prefix).

### Representação de texto

Um caractere pode ser representado por um byte. Por exemplo: `A = 65 =
01000001`. O padrão de codificação
[ASCII](https://en.wikipedia.org/wiki/ASCII) mapeia números para
caracteres.

Uma sequência de caracteres: `HI! = 01001000 01001001 00100001`

Com 8 bits temos $2^8 = 256$ valores possíveis (0 a 255). Para acentos
e outros símbolos existe o
[Unicode](https://en.wikipedia.org/wiki/Unicode), que usa mais bits
por caractere. Um emoji é apenas um número mapeado na tabela Unicode
para uma descrição. Exemplo: "face with medical mask" = `11110000
10011111 10011000 10110111`.

> Não existem arquivos "texto" em sentido absoluto — todo arquivo é uma sequência de bytes.

### Representando imagens

Cores também são mapeadas por bits. O sistema mais usado é o
[RGB](https://en.wikipedia.org/wiki/RGB_color_model): três valores
(vermelho, verde, azul), cada um com 8 bits. Os pontos de uma imagem
são chamados **pixels** e um array de pixels compõe a imagem.

### Áudios, vídeos e outros formatos

- **Vídeos** são sequências de imagens (como um flipbook).

- **Músicas**: o formato [MIDI](https://en.wikipedia.org/wiki/MIDI)
  representa notas, duração e volume como números. Outros formatos
  como [MP3](https://en.wikipedia.org/wiki/MP3) permitem compressão.

- Formatos mais complexos combinam imagens, textos e áudio (ex.:
  [DOCX](https://en.wikipedia.org/wiki/Office_Open_XML_file_formats)).

- Organizações como [Unicode
  Consortium](https://en.wikipedia.org/wiki/Unicode_Consortium),
  [IEEE](https://en.wikipedia.org/wiki/Institute_of_Electrical_and_Electronics_Engineers)
  e [W3C](https://www.w3.org) padronizam formatos.

### Hardware, software e sistema operacional

A CPU coordena tudo que é executado. Sequências de comandos
armazenados na memória são enviados para a CPU para execução. Mas um
computador pode rodar vários programas ao mesmo tempo!

O **sistema operacional (SO)** é o programa que gerencia o computador,
controlando como cada software usa cada parte do hardware. Exemplos:
Linux, Windows, macOS, iOS, Android. O SO cria a ilusão de que vários
programas rodam simultaneamente: cada programa recebe uma fração de
segundos da CPU por vez.

### Utilitários e tipos de programas

Sistemas operacionais modernos incluem:

- **Utilitários**: gerenciador de arquivos, drivers para impressão,
  configurações, relógio, interpretador de comandos, etc.

- **Aplicativos**: editores de texto, editores de imagem, navegadores,
  etc.

Os programas podem ser:

- **CLI (Command Line Interface)**: operam por interface texto — o
  usuário digita comandos e recebe texto como resposta, em um
  terminal.

- **GUI (Graphical User Interface)**: o usuário interage por elementos
  visuais como botões, menus, janelas e ícones.

> Neste curso vamos aprender a implementar programas CLI.

### Gerenciador de arquivos e shell

O **gerenciador de arquivos** (Windows Explorer, Finder no macOS,
Nautilus no Linux) manipula arquivos e diretórios armazenados no
**sistema de arquivos** do SO no hard-drive.

O **interpretador de comandos (shell)** permite interagir com o SO por
linha de comando, ler comandos digitados, executá-los e exibir
resultados. O shell também gerencia **variáveis de ambiente** e pode
executar **scripts**. Exemplos: CMD (Windows), `bash`, `zsh`.


## Aula 3 — Linha de comando, programação e compilação (slides 4 e 5)

### Linha de comando

Comandos básicos no Linux/macOS: `pwd`, `cd`, `ls`, `cp`, `mv`,
`mkdir`, `rm`, `rmdir`, `touch`, `cat`, `tail`, `head`, `less`, `ps`,
`history`, `find`, `grep`, `df`, `diff`, `echo`, `man`, `tar`, `zip`,
etc.

> Tutorial: [Command Line Basics](https://github.com/JulianEducation/CommandLineBasics)

Conceitos importantes:

- **Caminhos de arquivo**: `/Users/ar/work/teste.txt` (caminho completo, nome base e extensão).
- **Diretórios especiais**: `.` (diretório atual) e `..` (diretório pai).
- **Opções e argumentos**: `ls -l`, `rm -rf`.

### Códigos de retorno

Em sistemas Unix/Linux, programas CLI produzem **códigos numéricos de
retorno**:

- `0` — sucesso
- `1` — erro genérico
- `2` — erro na linha de comando
- `126` — permissão negada
- `127` — comando não encontrado
- `> 128` — casos específicos

### Operadores de encadeamento

| Operador   | Comportamento                                   |
|------------|-------------------------------------------------|
| `A; B`     | Executa A e depois B                            |
| `A && B`   | B só executa se A retornar 0 (sucesso)          |
| `A \|\| B` | B só executa se A retornar valor diferente de 0 |

### Canais padrão e redirecionamento

Entre um programa e seu ambiente (shell) existem **canais de
comunicação padrão**:

- **STDIN** — entrada padrão (onde entram os dados)
- **STDOUT** — saída padrão (onde saem os dados)
- **STDERR** — saída de erros

Geralmente esses fluxos são herdados do processo pai (o shell). Mas
podemos **redirecionar** entrada e saída para arquivos:

```sh
ls -l > lista.txt
```

### Controle de versão

Um **controlador de versão** é uma ferramenta que gerencia alterações
feitas em arquivos de um projeto ao longo do tempo.

O mais famoso é o [Git](https://git-scm.com/doc). O site
[GitHub](https://docs.github.com/pt) é o maior repositório de projetos
open source usando Git.

- [Guia rápido de Git](https://rogerdudler.github.io/git-guide/)
- [Curso no Coursera](https://www.coursera.org/learn/introduction-git-github)

### O que é programação?

**Programação é resolver problemas.** Programas recebem entradas e
geram saídas.

Considere o problema de calcular raízes quadradas. Matematicamente
podemos definir:

$$\sqrt{x} = y \quad \text{tal que} \quad y > 0 \;\text{e}\; y^2 = x$$

Essa definição matemática nos permite *reconhecer* se um número é raiz
quadrada de outro, mas não descreve um *procedimento* para *encontrar*
a raiz quadrada. Esse é o ponto central da diferença entre
**matemática e computação**: a computação requer um algoritmo, uma
sequência de passos que a máquina possa seguir.

### Linguagens de programação

Existem três tipos gerais:

1. **Linguagem de máquina** — sequências de bits (0s e 1s) entendidas
   diretamente pelo hardware. Dependente de máquina (específica por
   tipo de computador). Difícil de compreender por humanos.

2. **Linguagem Assembly** — mnemônicos associados às operações
   elementares (ex.: `MOV`, `ADD`, `RET`). Um **assembler** traduz
   assembly para linguagem de máquina. Mais legível para humanos, mas
   ainda verbosa.

3. **Linguagens de alto nível** — instruções mais expressivas, cada
   linha pode representar várias instruções de
   máquina. **Compiladores** traduzem para assembly e/ou linguagem de
   máquina diretamente. Exemplos: C, C++, Python.

### Programação estruturada

**Programação estruturada** é uma metodologia baseada em três
estruturas:

- **Sequência**: instruções executadas uma após a outra.

- **Decisão**: desvio condicional — algumas ações só são realizadas se
  uma condição for atendida.

- **Iteração (laço)**: repetição de uma instrução ou sequência um
  número pré-definido de vezes ou enquanto uma condição for
  satisfeita.

As instruções podem ser representadas graficamente por
**fluxogramas**.

Exemplo — converter Celsius para Fahrenheit:

$$T_f = \left(T_c \times \frac{9}{5}\right) + 32$$

> Explore programação visual em: [Scratch](https://scratch.mit.edu)

### A linguagem C

C foi desenvolvida por Dennis Ritchie na Bell Laboratories. Junto com
C++, está entre as linguagens mais populares para desenvolvimento de
software.

- **C99** — último padrão ANSI para C.

- **C++** — extensão de C, desenvolvida por Bjarne Stroustrup nos anos
  1980 no Bell Labs. Padrão atual: C11 (já existe C14).

Além das linguagens compiladas, existem as **linguagens
interpretadas**, como Python, que não passam por compilação explícita.

### Fases do desenvolvimento em C

1. **Edição** — escrever o código-fonte em um editor de texto (não um
   processador de texto como Word). Arquivos C têm extensão
   `.c`. Ferramentas: VS Code, Emacs, ou IDEs online como
   [replit.com](http://replit.com).

2. **Pré-processamento** — o pré-processador executa antes da
   compilação, seguindo **diretivas** (ex.: `#include`). Junta
   arquivos e realiza substituições no texto.

3. **Compilação** — o compilador traduz o código-fonte (alto nível)
   para **código objeto** (linguagem de máquina).

4. **Ligação (linking)** — o **linker** liga o código objeto com as
   bibliotecas necessárias, produzindo o **executável**.

5. **Carga (loading)** — o **loader** transfere o executável do disco
   para a memória principal (RAM) antes da execução. Bibliotecas
   dinâmicas podem ser carregadas neste momento.

6. **Execução** — a CPU executa o programa, uma instrução por
   vez. Arquiteturas modernas executam várias instruções em paralelo.

**Exemplo de compilação** — o código C:

```c
#include <stdio.h>

int main() {
    int x = 42;
    return 0;
}
```

Gera assembly como:

```asm
main:
    push    ebp
    mov     ebp, esp
    sub     esp, 16
    mov     DWORD PTR [esp+12], 42
    mov     eax, 0
    leave
    ret
```

Que por sua vez corresponde a bytes em linguagem de máquina:

```
55          push ebp
89 E5       mov ebp, esp
C7 44 24 0C 2A 00 00 00   mov DWORD PTR [esp+0xc], 0x2a
B8 00 00 00 00   mov eax, 0x0
C9          leave
C3          ret
```
