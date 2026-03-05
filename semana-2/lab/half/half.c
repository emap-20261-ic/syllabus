#include <stdio.h>

typedef char* string;

// declarations

float half(float bill, float tax, int tip);

float get_float(string prompt);
int   get_int(string prompt);


// main code

int main() {
  
  float bill_amount = get_float("total da nota: ");
  float tax_percent = get_float("percentual de imposto: ");
  int   tip_percent =   get_int("percentual de gorgeta: ");
  
  printf("valor individual: $%.2f\n",
	 half(bill_amount, tax_percent, tip_percent));
}


// auxiliar functions

float half(float bill, float tax, int tip)
{
    return 0.0;
}


float get_float(string prompt) {
  float tmp;
  printf("%s", prompt);
  scanf("%f", &tmp);
  return tmp;
}  

int get_int(string prompt) {
  int tmp;
  printf("%s", prompt);
  scanf("%i", &tmp);
  return tmp;
}  
