/*
 * Área do círculo: const, validação de entrada e return 1.
 *
 * Pontos a destacar:
 * - const: valor não pode ser alterado após inicialização (erro de compilação)
 *   convencão: nomes em maiúsculas para constantes
 * - validar a entrada ANTES de usar: if (raio < 0) retorna com erro
 * - return 1 (ou valor não-zero): convenção de erro em main()
 * - return 0: convenção de sucesso
 * - declaração de variável no meio do bloco (double area = ...): válido em C99+
 * - %lf para ler double com scanf; %lf (ou %f) para imprimir com printf
 */
#include <stdio.h>

int main() {
  // declaracao da constante Pi
  const double PI = 3.141592;
  double raio;

  printf("Digite o raio circulo: ");
  scanf("%lf", &raio);

  if (raio < 0) {
    printf("Erro: valor de raio negativo.\n");
    return 1;
  }

  double area = PI * raio * raio;
  printf("area do circulo: %lf\n", area);
  return 0;
}
