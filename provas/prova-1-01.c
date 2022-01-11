#include <stdio.h>


int main()
{

  int M = 1, N = 1, i = 0;
  
  while (1) {
    scanf("%d %d", &M, &N);

    if (M <= 0 || N <= 0)
      break;
    
    int maior = 0;
    int menor = 0;
    int soma = 0;

    if (M > N) {
      maior = M;
      menor = N;
    }
    else {
      maior = N;
      menor = M;
    }

    for (i=menor; i <= maior; i++) {
      soma += i;
      printf("%d ", i);
    }
    printf("Sum=%d", soma);

    printf("\n");
  }




  return 0;
}
