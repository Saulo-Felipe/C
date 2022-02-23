// Aluno: Saulo Jose Felipe
// Matrícula: 211080276

#include <stdio.h>

int main()
{
  int binaryArray[1000];

  for (int c=0; c < 1000; c++)
    binaryArray[c] = 1;

  for (int i=2; i < 1000; i++) { // Determina os números que não são binários (inserindo 0 na posição)
    if (binaryArray[i] == 1) {
      for (int e=i+1; e < 1000; e++) {
        if (e%i == 0) {
          binaryArray[e] = 0;
        }
      }
    }
  }

  for (int a=2; a < 1000; a++) { // Imprime os números primos
    if (binaryArray[a] == 1) {
      printf("%d%s ", a, a != 997 ? "," : ".");
    }
  }

  return 0;
}