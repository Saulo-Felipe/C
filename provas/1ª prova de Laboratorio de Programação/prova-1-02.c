#include <stdio.h>

int main()
{
  int X = 1, i = 0;

  while (X != 0) {
    scanf("%d", &X);

    if (X != 0) {
      for (i = 1; i <= X; i++)
        printf( i == X ? "%d" : "%d ", i);
      
      printf("\n");
    }
  }

  return 0;
}
