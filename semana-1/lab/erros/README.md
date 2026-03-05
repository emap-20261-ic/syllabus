# Erros de compilação

## Objetivos

- aprender a interpretar as mensagens de erro do compilador C
- praticar a depuração de erros sintáticos
- familiarizar-se com erros comuns em programas C

## Contexto

Ao escrever um programa em C, é muito comum cometer erros de
sintaxe. O compilador detecta esses erros e exibe mensagens que, a
princípio, podem parecer confusas. Aprender a ler essas mensagens é
uma habilidade fundamental.

Neste exercício, cada arquivo contém um programa C com um ou mais
erros. Tente compilar cada programa, leia a mensagem de erro e corrija
o código.

## Instruções

Para cada arquivo (`erro1.c` até `erro5.c`):

1. Tente compilar o programa:
   ```bash
   clang erroN.c -o erroN
   ```

2. Leia a mensagem de erro com atenção. Note o número da linha e a
   descrição do erro.

3. Corrija o programa e compile novamente até não haver mais erros.

4. Execute o programa corrigido e verifique que funciona.

## Pergunta

Qual a diferença entre um erro sintático e um erro lógico? Você
consegue pensar em um exemplo de erro lógico?
