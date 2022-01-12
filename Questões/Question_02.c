/*
  
  *Crie o programa apenas com o que é apresentado no capitulo 2*

  - Input
  - Output
  - Condições

*/

#include <stdio.h>

int main(void)
{
  int numb1, numb2, numb3, numb4, numb5, maior, menor;

  printf("Digite o primeiro número: ");
  scanf("%d", &numb1);
  printf("Digite o segundo número: ");
  scanf("%d", &numb2);
  printf("Digite o terceiro número: ");
  scanf("%d", &numb3);
  printf("Digite o quarto número: ");
  scanf("%d", &numb4);
  printf("Digite o quinto número: ");
  scanf("%d", &numb5);
  
  maior = numb1;
  menor = numb2;

  if (numb2 >= maior) maior = numb2;
  if (numb1 <= menor) menor = numb1;

  if (numb3 >= maior) maior = numb3;
  if (numb3 <= menor) menor = numb3;

  if (numb4 >= maior) maior = numb4;
  if (numb4 <= menor) menor = numb4;

  if (numb5 >= maior) maior = numb5;
  if (numb5 <= menor) menor = numb5;
  
  printf("\n====== O maior número é: %d ======\n", maior);
  printf("====== O menor número é: %d ======\n", menor);

  return 0;
}