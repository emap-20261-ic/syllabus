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
