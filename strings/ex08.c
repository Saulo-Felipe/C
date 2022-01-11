#include <stdio.h>


int main()
{
  int A = 0, B = 0, C = 0;

  scanf("%d %d %d", &A, &B, &C);

  if (A > B && B <= C)
    printf(":) 1\n");
  else if (A < B && B >= C)                                                                                                                                                                                                                                                 
    printf(":( 2\n");
  else if (A < B && C > B && C - B < B - A)
    printf(":( 3\n");


  printf("Hello, world!");

  return 0;
}
