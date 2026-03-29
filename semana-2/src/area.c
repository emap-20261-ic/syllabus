#include <stdio.h>

int main() {
  // Pi constant
  const double PI = 3.141592;
  double radius;

  printf("Enter circle radius: ");
  scanf("%lf", &radius);

  if (radius < 0) {
    printf("Error: negative radius.\n");
    return 1;
  }

  double area = PI * radius * radius;
  printf("circle area: %lf\n", area);
  return 0;
}
