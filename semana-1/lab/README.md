# Laboratório 1

## Conteúdo programático

- configuração do ambiente de desenvolvimento
- compilação de programas em C
- uso do `printf` e caracteres de escape
- interpretação de mensagens de erro do compilador
- representação binária

## Objetivos

1. Configurar o ambiente de desenvolvimento (editor, terminal,
   compilador)
2. Compilar e executar o primeiro programa em C
3. Praticar o uso do `printf` e caracteres de escape
4. Aprender a interpretar mensagens de erro do compilador
5. Reforçar conceitos de representação binária

## Atividade 1 — Configuração do ambiente (30 minutos)

Instale e configure as ferramentas necessárias para o curso:

1. **Editor**: instale o [VS Code](https://code.visualstudio.com).
   Alternativamente, use o [GitHub Codespaces](https://github.com/codespaces).

2. **Terminal**: abra o terminal integrado do VS Code (`Ctrl+\``) ou o
   terminal do seu sistema operacional.

3. **Compilador**: verifique se o compilador C está instalado:

   ```bash
   clang --version
   ```

   No macOS, instale o Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```

   No Ubuntu/Debian:
   ```bash
   sudo apt install build-essential
   ```

4. **Teste**: compile e execute o programa `hello0.c`:

   ```bash
   cd semana-1/src
   make hello0
   ./hello0
   ```

   Você deve ver `hello, world` na tela. Experimente com outros
   parâmetros para o `clang`.

## Atividade 2 — Experimentando com printf (20 minutos)

Crie um arquivo `lab/apresentacao.c` e escreva um programa que
imprima:

1. Seu nome e número de matrícula
2. O nome do curso
3. Uma linha em branco
4. Uma frase sobre por que você escolheu este curso

Use `\n` para quebras de linha e `\t` para tabulação.

Depois, crie um arquivo `lab/arte.c` com um programa que imprima uma
figura usando caracteres. Por exemplo:

```
  *
 ***
*****
 ***
  *
```

Experimente também os caracteres de escape `\\` e `\"`.

## Atividade 3 — Erros de compilação (20 minutos)

[erros/README.md](erros/README.md)

## Atividade 4 — Representação binária (20 minutos)

Responda:

1. Converta para binário: 42, 100, 255
2. Converta para decimal: `1010110`, `11111111`
3. Quantos valores diferentes podem ser representados com 4 bits? E
   com 8 bits?
4. Na tabela ASCII, qual caractere corresponde ao valor 65? E ao 48?
5. Se um byte pode armazenar valores de 0 a 255, qual é o maior
   número inteiro que pode ser representado com 2 bytes (16 bits)?

## Atividade 5 — Explorando a compilação (bônus)

Para quem terminar antes, explore as etapas da compilação:

1. Gere o código assembly do `hello0.c`:
   ```bash
   clang -S hello0.c
   cat hello0.s
   ```

2. Encontre a string `"hello, world"` no arquivo assembly gerado.

3. Compile com flags de aviso e observe o que muda:
   ```bash
   clang -Wall -Wextra hello0.c -o hello
   ```

4. O que acontece se você compilar com `-Werror`?
