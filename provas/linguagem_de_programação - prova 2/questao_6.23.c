// Aluno: Saulo Jose Felipe
// Matrícula: 211080276

/*
  ----- Acerca do grafico de tartarugas ------

  *Como é apresentado no final da questão, poderia ser adicionado novas funcionalidades

  - Adicionei a opção 7 e 8 que limpa e imprime automaticamente o grafico a cada novo comando
  - Essas opções não interferem no funcionamento geral do grafico, por isso por padrão estarão desativadas, seu uso é opcional. Recomendo usar.
  - No lugar dos "espaços" para os campos com 0, coloquei um "." para facilitar a visualização do mapa e dos movimentos.
  - A tartaruga estará sendo representada por <, >, ^ ou v que representa o lado que a tartaruga estará virada.
  - Para virar a tartarua considerei o seguinte: 

           1|
            |
            |
    ________|________
    2       |       0
            |
           3|

  onde os numeros 0, 1, 2 e 3 representam direita, cima, esquerda e baixo, respectivamente.

  - Apesar da tartaruga conseguir se mover para cima e baixo, eu mantive o que foi pedido na questão, 
    "virar esquerda" e "virar direita". 
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
  // Todas as variáveis do jogo inicializadas
  int mapa[50][50], caneta = 1, lado = 0, movimento = 0, tartaruga[2] = {0, 0}, command = 0, limpaAuto = 0, printAuto = 0;

  for (int i=0; i < 50; i++) // Adicionando 0 para todo o mapa
    for (int e=0; e < 50; e++)
      mapa[i][e] = 0;


  // Funções do jogo
  void printMap()
  {
    for (int i=0; i < 50; i++) 
    {
      for (int e=0; e < 50; e++)
      {
        if (e == tartaruga[0] && i == tartaruga[1]) 
          printf("%s", lado == 0 ? ">" : lado == 1 ? "^" : lado == 2 ? "<" : "v");
        else
          if (mapa[e][i] == 1)
            printf("#");
          else
            printf(".");          
      }
      printf("\n");
    }

  }

  void moveTurtle()
  {
    for (int c=1; c <= movimento; c++)
    {
      if (lado == 0) { // movendo para direita
        if (tartaruga[0] < 49) {
          tartaruga[0]++;

          if (!caneta)
            mapa[tartaruga[0]][tartaruga[1]] = 1;
        }
      }
      else if (lado == 1) { // movendo para cima
        if (tartaruga[1] > 0) {
          tartaruga[1]--;

          if (!caneta)
            mapa[tartaruga[0]][tartaruga[1]] = 1;
        }
      }
      else if (lado == 2) { // movendo do para esquerda
        if (tartaruga[0] > 0) {
          tartaruga[0]--;

          if (!caneta)
            mapa[tartaruga[0]][tartaruga[1]] = 1;
        }
      }
      else if (lado == 3) { // Movendo para baixo
        if (tartaruga[1] < 49) {
          tartaruga[1]++;

          if (!caneta)
            mapa[tartaruga[0]][tartaruga[1]] = 1;
        }
      }
    }
  }

  void clearScreen()
  {
    if (limpaAuto) // Limpeza do terminal automatica
      system("clear");
  }

  // Game
  while (command != 9)
  {
    printf(
      "\n"
      "(1) Caneta para cima...............[%s]\n"
      "(2) Caneta para baixo..............[%s]\n"
      "(3) Vire à direita.................[Lado atual -> %s]\n"
      "(4) Vire à esquerda................[Lado atual -> %s]\n"
      "(5) Mover 'n' posições \n"
      "(6) Imprima o mapa \n"
      "(7) Limpar tela automaticamente....[%s]\n"
      "(8) Imprimir mapa automaticamente..[%s]\n"
      "(9) Encerre programa \n\n"

      "-> Seu comando: ", 
      caneta ? "ON" : "OFF", caneta ? "OFF" : "ON",
      lado == 0 ? "Esquerda" : lado == 1 ? "Cima" : lado == 2 ? "Direita" : "Baixo",
      lado == 0 ? "Esquerda" : lado == 1 ? "Cima" : lado == 2 ? "Direita" : "Baixo",
      limpaAuto ? "ON" : "OFF",
      printAuto ? "ON" : "OFF"
    );
    scanf("%d", &command);

    clearScreen();

    switch (command)
    {
      case 1:
        caneta = 1;
        break;

      case 2:
        caneta = 0;
        break;

      case 3:
        if (lado == 0)
          lado = 3;
        else
          lado -= 1;
        break;

      case 4:
        if (lado == 3)
          lado = 0;
        else 
          lado += 1;
        break;

      case 5:
        printf(
          "Mover quantas posições para %s? ",
          lado == 0 ? "Direita" : lado == 1 ? "Cima" : lado == 2 ? "Esquerda" : "Baixo"
        );
        scanf("%d", &movimento);
        moveTurtle();
        break;

      case 6:
        printMap();
        break;

      case 7:
        if (limpaAuto)
          limpaAuto = 0;
        else {
          limpaAuto = 1;
          clearScreen();
        }
        break;
      case 8:
        if (printAuto)
          printAuto = 0;
        else
          printAuto = 1;
        break;
      case 9:
        break;
      
      default:
        printf("\n[ERROR] Comando inválido!\n\n");
        break;
    }

    if (printAuto)
      printMap();
  }
  
  return 0;
}
