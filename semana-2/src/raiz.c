#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta;
    
    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);
    printf("c: "); scanf("%lf", &c);
    delta = pow(b, 2) - 4 * a * c;

    if (delta < 0) 
      printf("Nao existem raizes reais\n");
    else if (delta == 0) {
      double x = - b / (2 * a);
      printf("X1 = X2 = %lf\n", x);
    } else {
      double x1 = (-b + sqrt(delta)) / (2 * a);
      double x2 = (-b - sqrt(delta)) / (2 * a);
      printf("X1 = %lf, X2 = %lf\n", x1, x2);
    }
    return 0;
}

