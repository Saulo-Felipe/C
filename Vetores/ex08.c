#include <stdio.h>

int N = 0, F = 0, C = 0, totalVisitas = 0, passos = 1, casas = 0, k = 0;

int logicaC(int type) {
  for (k = 0; k < passos; k++) {
    if (totalVisitas < (N*N)) {
      C = type ? C+1 : C-1;
      casas++;

      if (C >= 0 && C < N && F >= 0 && F < N) {
        printf(" %d", (F * N) + (C + 1));
        totalVisitas++;
      }
    }
  }
  return 0;
}

int logicaF(int type) {
  for (k = 0; k < passos; k++) {
    if (totalVisitas < (N*N)) {
      F = type ? F+1 : F-1;
      casas++;
      if (C >= 0 && C < N && F >= 0 && F < N) {
        printf(" %d", (F * N) + (C + 1));
        totalVisitas++;
      }
    }
  }
  return 0;
}

int main() 
{
  scanf("%d", &N);
  scanf("%d %d", &F, &C);

  if (C >= 0 && C < N && F >= 0 && F < N) {
    printf("%d", (F * N) + (C + 1));
    totalVisitas++;
    casas++;
  }
  
  while (totalVisitas < (N*N))
  {
    if (passos % 2 != 0) {
      logicaC(1);
      logicaF(1);
      passos++;
    }
    else {
      logicaC(0);
      logicaF(0);
      passos++;
    }
  }

  printf("\n%d\n", casas);

  return 0;
}