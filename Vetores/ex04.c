#include <stdio.h>

int main()
{
  int T = 0, num = 0, i = 0, e = 0, sequence[999] = {0, 1};

  scanf("%d", &T);

  for (i = 0; i < T; i++)
  {
    scanf("%d", &num);

    if (num == 0 || num == 1) {
      printf("Fib(%d) = 0\n", num);
      continue;
    }
    for (e = 2; e < num; e++)
      sequence[e] = sequence[e-2] + sequence[e-1];

    int sum = sequence[num-1] + sequence[num-2];
    printf("Fib(%d) = %d\n", num, sum < 0 ? sum * -1 : sum);
  }

  return 0;
}