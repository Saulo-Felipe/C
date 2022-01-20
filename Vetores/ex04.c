#include <stdio.h>

int main()
{
  int T = 0, i = 0, e = 0, num; 
  long long int sequence[999] = {0, 1};

  scanf("%d", &T);

  for (i = 0; i < T; i++)
  {
    scanf("%d", &num);

    if (num == 0 || num == 1) {
      printf("Fib(%d) = %d\n", num, num);
      continue;
    }
    for (e = 2; e < num; e++)
      sequence[e] = sequence[e-2] + sequence[e-1];

    printf("Fib(%d) = %lld\n", num, sequence[num-1] + sequence[num-2]);
  }

  return 0;
}