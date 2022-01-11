#include <stdio.h>
#include <string.h>


int main()
{
  int allPlays = 0, i = 0, game[3] = {0, 0, 0}, movePosition = 0;
  char initialPosition[128] = {};

  scanf("%d", &allPlays);

  scanf("%s", &initialPosition[0]);
  
  if (strstr(initialPosition, "A"))
    game[0] = 1;
  else if (strstr(initialPosition, "B"))
    game[1] = 1;
  else if (strstr(initialPosition, "C"))
    game[2] = 1;
  

  for (i = 0; i < allPlays; i++)
  {
    scanf("%d", &movePosition);

    if (movePosition == 1)
    {
      int pos = game[0];
      game[0] = game[1];
      game[1] = pos;
    }
    if (movePosition == 2)
    {
      int pos = game[1];
      game[1] = game[2];
      game[2] = pos;
    }
    if (movePosition == 3)
    {
      int pos = game[0];
      game[0] = game[2];
      game[2] = pos;
    }

  }
  
  printf("%s\n", game[0] == 1 ? "A" : game[1] == 1 ? "B" : "C");

  return 0;
}
