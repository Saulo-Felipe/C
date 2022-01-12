#include <stdio.h>

int main()
{
  float kmDirigido, abastecimento, totalKm, totalAbastecimento;

  while (1)
  {

    printf("Quantidade de litros usados no abastecimento [-1 Para finalizar]: ");
    scanf("%f", &abastecimento);

    if (abastecimento == -1) break;

    printf("Número de quilômetros dirigidos [-1 Para finalizar]: ");
    scanf("%f", &kmDirigido);

    if (kmDirigido == -1) break;

    totalKm += kmDirigido;
    totalAbastecimento += abastecimento;
    
    printf("\n--> Consumo atual de %.2f Km/L. \n\n", kmDirigido/abastecimento);
  }

  printf("\n--> O consumo total foi de %f Km/L \n\n[Fim do programa]\n\n", totalKm/totalAbastecimento);

  return 0;
}