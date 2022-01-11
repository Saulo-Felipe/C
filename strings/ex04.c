#include <stdio.h>
#include <string.h>


int main(void)
{
  int T = 0, i = 0;
  float tentativas[99] = {}, menor = 0;

  while (scanf("%d", &T) != EOF) 
  {
    for (i = 0; i < T; i++)
    {
      float num = 0;
      scanf("%f", &num);

      tentativas[i] = num;
    }

    for (i = 0; i < T; i++)
    {
      if (i == 0)
        menor = tentativas[i];
      
      if (tentativas[i] < menor)
        menor = tentativas[i];
    }
      printf("%.2f\n", menor);

    
  }


  return 0;
}