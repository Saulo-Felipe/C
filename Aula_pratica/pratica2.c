#include <stdio.h>


int main()
{
  int quantCasos, i, a, numero, ehPrimo;

  scanf("%d", &quantCasos);

  for (i=0; i < quantCasos; ++i)
  {
    scanf("%d", &numero);

    for (a=2; a < numero; ++a)
      if (numero%a == 0 && a != numero)
      {
        ehPrimo = 0;
        break;
      }

    if (ehPrimo)
      printf("%d eh primo\n", numero);
    else
      printf("%d nao eh primo\n", numero);
    
    ehPrimo = 1;
  }

  return 0;
}