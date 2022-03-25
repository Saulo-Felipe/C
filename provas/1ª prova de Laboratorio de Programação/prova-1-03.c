#include <stdio.h>
#include <ctype.h>


int main()
{

  int PA = 0, PB = 0, T = 0, i = 0;
  double G1, G2;

  scanf("%d", &T);

  for (i = 0; i < T; i++)
  {
    scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);

    int anos = 0;
    while (PA <= PB)
    {
      double porcentA = (G1/100.0) * PA;
      double porcentB = (G2/100.0) * PB;

      anos+=1;
      PA += (int)porcentA;      
      PB += (int)porcentB;
    }
    if (anos > 100)
      printf("Mais de 1 seculo.\n");
    else 
      printf("%d anos.\n", anos);    
  }


  return 0;
}
