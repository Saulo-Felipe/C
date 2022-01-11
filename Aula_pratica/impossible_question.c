#include <stdio.h>


int main(void)
{
  float money = 0;
  int notas[6] = {0, 0, 0, 0, 0, 0};
  int moedas[6] = {0, 0, 0, 0, 0, 0};

  scanf("%f", &money);
  money += 0.001;

  while (1)
  {
    if (money >= 100) {
      money -= 100;
      notas[0] += 1;

    } else if (money >= 50) {
      money -= 50;
      notas[1] += 1;

    } else if (money >= 20) {
      money -= 20;
      notas[2] += 1;

    } else if (money >= 10) {
      money -= 10;
      notas[3] += 1;

    } else if (money >= 5) {
      money -= 5;
      notas[4] += 1;

    } else if (money >= 2) {
      money -= 2;
      notas[5] += 1;

    } else if (money >= 1) {
      money -= 1;
      moedas[0] += 1;

    } else if (money >= 0.50) {
      money -= 0.5;
      moedas[1] += 1;

    } else if (money >= 0.25) {
      money -= 0.25;
      moedas[2] += 1;
      
    } else if (money >= 0.10) {
      money -= 0.10;
      moedas[3] += 1;
      
    } else if (money >= 0.05) {
      money -= 0.05;
      moedas[4] += 1;
      
    } else if (money >= 0.01) {
      money -= 0.01;
      moedas[5] += 1;

    } else {
      break;
    }    
  }

  printf("NOTAS:\n"
  "%d nota(s) de R$ 100.00\n"
  "%d nota(s) de R$ 50.00\n"
  "%d nota(s) de R$ 20.00\n"
  "%d nota(s) de R$ 10.00\n"
  "%d nota(s) de R$ 5.00\n"
  "%d nota(s) de R$ 2.00\n"
  "MOEDAS:\n"
  "%d moeda(s) de R$ 1.00\n"
  "%d moeda(s) de R$ 0.50\n"
  "%d moeda(s) de R$ 0.25\n"
  "%d moeda(s) de R$ 0.10\n"
  "%d moeda(s) de R$ 0.05\n"
  "%d moeda(s) de R$ 0.01\n",

  notas[0], notas[1], notas[2],
  notas[3], notas[4], notas[5], 
  moedas[0], moedas[1], moedas[2],
  moedas[3], moedas[4], moedas[5]

  );

  return 0;
}