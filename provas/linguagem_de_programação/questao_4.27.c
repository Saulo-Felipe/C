// Aluno: Saulo José Felipe
// Matrícula: 211080276

#include <stdio.h>

int main() {

  printf("Hipotenusa² = Cateto_01² + Cateto_02²\n");
  printf("--------------------------------------\n");

  for (int h = 1; h < 500; h++)
    for (int c1 = 1; c1 < 500; c1++)
      for (int c2 = 1; c2 < 500; c2++)
        if (h*h == c1*c1 + c2*c2)
          printf("➔ %d - %d - %d\n", h, c1, c2);
  
  printf("--------------------------------------\n");
  printf("Hipotenusa² = Cateto_01² + Cateto_02²\n");

  return 0;
}