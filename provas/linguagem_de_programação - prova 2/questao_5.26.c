// Aluno: Saulo Jose Felipe
// Matrícula: 211080276

#include <stdio.h>

int perfect(int number) 
{
  for (int i=1; i <= number; i++) {
    int sum = 0, isPerfect = 0; 

    for (int e=1; e <= i; e++) { // Verifica se é perfeito
      sum += e;

      if (sum == i) {
        isPerfect = 1;
        break;
      }
    }

    if (isPerfect) {
      sum = 0;
      printf("(%d) ➔ ", i);

      for (int e=1; e <= i; e++) { // Imprime os fatores (apenas se for perfeito)
        printf("%d", e);
        sum += e;

        if (sum == i) {
          printf(" = %d\n", sum);
          break;
        } else
          printf(" + ");

      }
    }    
  }

  return 0;
}

int main()
{
  perfect(1000);

  return 0;
}