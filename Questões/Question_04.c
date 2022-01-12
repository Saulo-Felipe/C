#include <stdio.h>


int main()
{
  int number[5] = {};
  int i, a = 0;

  // Capturar valores do input do usuario
  for (i=0; i < 5; ++i)
  {
    printf("Digite um valor ente 1 e 30 para ser inserido no gráfico: ");
    scanf("%d", &number[i]);

    if (number[i] < 1 || number[i] > 30)
    {
      printf("\n[Valor inválido, finalizando programa]\n\n");
      return 0;
    }
  }

  // Inserir valores no gráfico
  printf("\n====== Gráfico ======\n\n");

  for (i=0; i < 5; ++i)
  {
    for (a=0; a < number[i]; a++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}