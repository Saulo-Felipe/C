#include <stdio.h>
#include <stdlib.h>


int main() {

  char name[1000];
  FILE *filePtr;

  filePtr = fopen("./arquivo.txt", "r");

  if (filePtr == NULL) {
    printf("Erro ao abrir arquivo");
    exit(1);
  }

  fgets(name, 1000, filePtr);

  printf("O valor do arquivo é:\n %s", name);

  fclose(filePtr);

  return 1;
}