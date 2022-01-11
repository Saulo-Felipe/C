#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  int N = 0, i = 0, a = 0;
  char placa[128];

  scanf("%d", &N);

  for (i = 0; i < N; i++)
  {
    scanf("%s", &placa);
    int haveError = 0;

    if ( (strlen(placa) != 8) || (strstr(placa, "-") == strlen(placa)) || ((int) (strchr(placa, '-') - placa) != 3)) {
      printf("FAILURE\n");
      haveError = 1;
      continue;

    } else {
      for (a = 0; placa[a] != '\0'; a++)
      {
        if ( (a <= 2 && isdigit(placa[a])) || (a >= 4 && isalpha(placa[a]) || islower(placa[a]))) {
          printf("FAILURE\n");
          haveError = 1;
          break;
        }
      }
    }

    if (!haveError)  {
      int theLastPos = placa[strlen(placa)-1] - '0';

      if (theLastPos == 1 || theLastPos == 2) {
        printf("MONDAY\n");
      } else if (theLastPos == 3 || theLastPos == 4) {
        printf("TUESDAY\n");
      } else if (theLastPos == 5 || theLastPos == 6) {
        printf("WEDNESDAY\n");
      } else if (theLastPos == 7 || theLastPos == 8) {
        printf("THURSDAY\n");
      } else if (theLastPos == 9 || theLastPos == 0) {
        printf("FRIDAY\n");
      }
    }
  }

  return 0;
}