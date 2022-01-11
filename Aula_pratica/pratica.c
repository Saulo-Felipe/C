#include <stdio.h>



int main()
{

  float numbers[6] = {};
  float soma = 0;

  int i = 0;
  int countPositivos = 0;

  for (i=0; i < 6; ++i)
    scanf("%f", &numbers[i]);

  for (i=0; i < 6; ++i)
  {
    if (numbers[i] > 0)
    {      
      soma = soma + numbers[i];
      ++countPositivos;
    }
  }

  printf("%d valores positivos\n%.1f\n", countPositivos, soma/countPositivos);

  return 0;
}