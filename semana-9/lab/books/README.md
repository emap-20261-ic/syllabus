
# Biblioteca de Livros


Um sistema de gerenciamento de biblioteca desenvolvido em linguagem C,
com armazenamento persistente em arquivo.

## Funcionalidades

- Cadastro de livros (titulo, autor, ISBN)
- Busca por titulo (case insensitive)
- Remocao de livros
- Listagem completa do acervo
- Salvamento automatico em arquivo texto
- Carregamento de dados persistidos


## Compilação

    $ gcc linked.c -o linked

## Execução:

    $ ./linked


## Formato dos dados

Dados salvos em "biblioteca.txt" no formato:

    [ISBN: numero] "Titulo" - Autor

