// Aluno: Saulo José Felipe
// Matrícula: 211080276

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int decimal = 0;
  char binary[150];

  scanf("%s", &binary[0]);
  
  for (int i = 0; i < strlen(binary); i++)
    decimal += (binary[i] - '0')*(pow(2, strlen(binary)-i-1)); // Soma o resultado da formula [binário * 2 ^ x]

  printf("\nBinário: %s\nDecimal: %d\n", binary, decimal);

  return 0;
}
