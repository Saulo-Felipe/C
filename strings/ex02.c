#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  int i = 0, e = 0, c = 0, n = 0, a = 0;
  char cript01[512] = {0}, cript02[512] = {0}, frase[512] = {0};

  while (scanf("%d %d", &c, &n) != EOF)
  {
    scanf("%s", &cript01);
    scanf("%s", &cript02);

    for (i = 0; i < n; i++)
    {
      scanf(" %[^\n]s", frase);

      for (e = 0; e < strlen(frase); e++)
      {
        int isComplete = 1;

        for (a = 0; a < strlen(cript01); a++)
          if (tolower(frase[e]) == tolower(cript01[a])) {
            isComplete = 0;
            frase[e] = isupper(frase[e]) ? toupper(cript02[a]) : tolower(cript02[a]);
          }

        if (isComplete)
          for (a = 0; a < strlen(cript02); a++)
            if (tolower(frase[e]) == tolower(cript02[a]))
              frase[e] = isupper(frase[e]) ? toupper(cript01[a]) : tolower(cript01[a]);
      }

      printf("%s\n", frase);
    }
  }

  return 0;
}
