#include <stdio.h>

typedef char* string;

// declarations

float half(float bill, float tax, int tip);

float get_float(string prompt);
int   get_int(string prompt);


// main code

int main(void) {
  
  float bill_amount = get_float("bill total: ");
  float tax_percent = get_float("tax percent: ");
  int   tip_percent = get_int("tip percent: ");

  printf("individual amount: $%.2f\n",
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
