#include <stdio.h>
#include <string.h>


int main()
{
  float number;
  char string[128] = {0};
  int i, e = 0, isNegative = 0, expoente = 0, expoenteType = 0;

  scanf("%s", string);

  if (strstr(string, "-")) { // Remove sinal de negativo
    isNegative = 1;
    for (i = 0; i < strlen(string); i++)
      string[i] = string[i+1];
  }
  
  if (strstr(string, ".")) {
    if (string[0] == '0') {
      expoenteType = 1;
      expoente = -1;
      char noZero[128] = {0};
      for (i = 0; i < strlen(string); i++) 
        if ((string[i] != '0' && string[i] != '.') || e != 0) {
          noZero[e] = string[i];
          e++;
        } else
          expoente++;

      strcpy(string, noZero);
    }

    char pt1[128] = {string[0], '.'};
    char pt2[128] = {0};

    for (i = 1; i < strlen(string); i++)
      if (string[i] != '.') {
        char pos[128] = {string[i]};
        strcat(pt2, pos);
      }

    strcat(pt1, pt2);
    strcpy(string, pt1);

  } else {
    expoente = -1;

    for (i = strlen(string); i > 0; i--)
    {
      expoente++;
      string[i+1] = string[i];
    }
    string[1] = '.';
  }

  sscanf(string, "%f", &number); // Converte a string para o numero flutuante;
  
  printf(isNegative == 1 ? "-" : "+");
  printf("%.4fE", number);
  printf(expoenteType == 1 ? "-" : "+");
  printf("%02d\n", expoente);

  return 0;
}