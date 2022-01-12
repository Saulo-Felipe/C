#include <stdio.h>


int main()
{
  int N[20], i = 0, a = 0;

  for (i = 0; i < 20; i++)
  {
    scanf("%d", &N[i]);
  }

  
  a = 0;
  for (i = 20-1; i >= 0; i--)
  {
    printf("N[%d] = %d\n", a, N[i]);
    a++;
  }


  return 0;
}
