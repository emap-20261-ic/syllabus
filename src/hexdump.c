// uso: ./hexdump arquivo
//
// imprime os primeiros 64 bytes do arquivo em hexadecimal.
// compare a saida em um arquivo de texto (ex: cat.c) com a de
// uma imagem (ex: lecture.jpg) para ver a diferenca entre ler
// bytes interpretados como char e bytes "crus".

#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
  if (argc != 2) return 1;

  FILE *f = fopen(argv[1], "r");
  if (!f) return 1;

  BYTE b;
  int n = 0;
  while (fread(&b, sizeof(BYTE), 1, f) == 1 && n < 64) {
    printf("%02x ", b);
    if (++n % 16 == 0) printf("\n");
  }
  printf("\n");

  fclose(f);
  return 0;
}
