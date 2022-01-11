#include <stdio.h>
#include <string.h>



int main()
{
  int A1 = 0, A2 = 0, A3 = 0, total = 0, i = 0, andar = 0;

  scanf("%d", &A1);
  scanf("%d", &A2);
  scanf("%d", &A3);

  int allNumbers[3] = {
    A2*2 + A3*4, 
    A1*2 + A3*2, 
    A2*2 + A1*4
  };

  for (i = 0; i < 3; i++)
    if (allNumbers[i] <= allNumbers[0] && allNumbers[i] <= allNumbers[1] && allNumbers[i] <= allNumbers[2]) {
      printf("%d\n", allNumbers[i]);
      break;
    }
  
  return 0;
}