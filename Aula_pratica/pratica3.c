#include <stdio.h>
#include <ctype.h>


int main()
{
  char sequencia[4];
  int loopQuant = 0, calculo = 0, i = 0;

  scanf("%d", &loopQuant);

  for (i=0; i < loopQuant; i++)
  {
    scanf("%s", &sequencia);

    if (sequencia[0] == sequencia[2])
      calculo = (sequencia[0] - '0') * (sequencia[2] - '0');

    else
      if (isupper(sequencia[1]))
        calculo = sequencia[2] - sequencia[0];
      else
        calculo = (sequencia[0] - '0') + (sequencia[2] - '0');

    printf("%d\n", calculo);
  }

  return 0;
}