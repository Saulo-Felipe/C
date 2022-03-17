#include <stdio.h>
#include <stdlib.h>

int main() 
{
  FILE *filePtr;

  filePtr = fopen("./arquivo.txt", "w");

  if (filePtr == NULL) {
    printf("Erro ao abrir arquivo");
    exit(1);
  }

  char name[1000];
  printf("Conteúdo: ");
  fgets(name, 1000, stdin);

  fprintf(filePtr, "%s", name);
  fclose(filePtr);

  return 0;
}