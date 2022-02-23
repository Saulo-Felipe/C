// Aluno: Saulo Jose Felipe
// Matrícula: 211080276

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST };

int saldoBanca = 1000, aposta = 0;

int rollDice( void );

int main( void )
{
  // OBS: destaquei usando os comentários as partes do código editadas por mim
  
  // --------------- Parte do meu código -------------------
  char *frasesGanho[2];
  char *frasesPerca[2];

  frasesPerca[0] = "Ei, assim você quebra!";
  frasesPerca[1] = "Vamos lá, continue tentando!";
  frasesGanho[0] = "Você está ganhando. Agora é hora de aproveitar suas fichas!";
  frasesGanho[1] = "A vitória é bela.";

  printf("Informe uma aposta: ");
  scanf("%d", &aposta);

  while (!(aposta <= saldoBanca) || aposta <= 0) {
    printf("[ERROR] Por favor, insira uma aposta menor ou igual ao saldo da banca.\n\n");    

    printf("Informe a aposta novamente: ");
    scanf("%d", &aposta);
  }
  // --------------- Parte do meu código -------------------


  int sum; 
  int myPoint; 

  enum Status gameStatus;

  srand(time(NULL));

  sum = rollDice();

  switch(sum) {
    case 7:

    case 11:
      gameStatus = WON;
    break;

    case 2:

    case 3:

    case 12:
      gameStatus = LOST;
      break;

    default:
      gameStatus = CONTINUE;
      myPoint = sum;
      printf("Ponto é %d\n", myPoint);
      break;
  }

  while ( gameStatus == CONTINUE ) {
    sum = rollDice();

    if ( sum == myPoint ) {
      gameStatus = WON;
    }
    else {
      if ( sum == 7 ) {
        gameStatus = LOST;
      }
    }

  }


  if ( gameStatus == WON ) {
    printf("Jogador vence\n");

    // --------------- Parte do meu código -------------------
    saldoBanca += aposta;
    printf("[Saldo da banca] %d\n", saldoBanca);
    printf("%s\n", frasesGanho[rand() % 2]);
    // --------------- Parte do meu código -------------------
  }
  else {
    printf("Jogador perde\n");
    
    // --------------- Parte do meu código -------------------
    saldoBanca -= aposta;
    printf("[Saldo da banca] %d\n", saldoBanca);
    if (saldoBanca == 0)
      printf("Sinto muito. Você está quebrado!\n");
    else {
      printf("%s\n", frasesPerca[rand() % 2]);
    }
    // --------------- Parte do meu código -------------------
  }

  return 0;
}

int rollDice( void )
{
  int die1;
  int die2;
  int workSum;

  die1 = 1 + (rand() % 6);
  die2 = 1 + (rand() % 6);
  workSum = die1 + die2;

  printf("Jogador rolou %d + %d = %d\n", die1, die2, workSum);
  return workSum;
}