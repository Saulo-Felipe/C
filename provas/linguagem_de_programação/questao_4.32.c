// Aluno: Saulo José Felipe
// Matrícula: 211080276

#include <stdio.h>

int main()
{
  int spaces = 0, asterisk = 1, lineAmount;

  scanf("%d", &lineAmount);
  spaces = lineAmount;

  for (int l = 0; l < lineAmount; l++)
  {
    for (int c = 1; c <= lineAmount; c++)
      printf(c <= spaces/2 || c > spaces/2+asterisk ? " " : "*");
    
    spaces = l < lineAmount/2 ? spaces - 2 : spaces + 2;
    asterisk = l < lineAmount/2 ? asterisk + 2 : asterisk - 2;
    
    printf("\n");
  }

  return 0;
}

