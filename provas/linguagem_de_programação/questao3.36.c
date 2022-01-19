// Aluno: Saulo José Felipe
// Matrícula: 211080276

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int decimal = 0;
  char binario[150];

  scanf("%s", &binario[0]);
  
  for (int i = 0; i < strlen(binario); i++)
    decimal += (binario[i] - '0')*(pow(2, strlen(binario)-i-1)); // Soma o resultado da formula [binário * 2 ^ x]

  printf("Binário: %s\nDecimal: %d\n", binario, decimal);

  return 0;
}
