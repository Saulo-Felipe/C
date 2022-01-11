#include <stdio.h>


int main()
{
  char teste = "ola";
  int test = 0;

  for (int i=0; i < 4; ++i)
  {

    scanf("%s", &teste);

    printf("Fim do loop: %d\n", i);
  }


  return 0;
}