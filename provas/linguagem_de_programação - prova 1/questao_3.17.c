// Aluno: Saulo José Felipe
// Matrícula: 211080276

#include <stdio.h>

int main()
{
  double Num_km = 0, liter = 0, tot_km = 0, tot_liters = 0;
  
  while (1) {
    printf("Informe quantos litros abasteceu [-1 para sair]: ");
    scanf("%lf", &liter);

    if (liter == -1) break;

    printf("Informe quantos Km dirigiu [-1 para sair]: ");
    scanf("%lf", &Num_km);

    if (Num_km == -1) break;

    printf("O consumo atual é de: %lf km/l \n\n", Num_km/liter);

    tot_km += Num_km;
    tot_liters += liter;
  }

  printf("\nO consumo geral foi de %lf km/l\n", tot_km/tot_liters >= 0 ? tot_km/tot_liters : 0);

  return 0;
}

