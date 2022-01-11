#include <stdio.h>
#include <string.h>

int main()
{
  char form[600];

  gets(form);
  
  if (strlen(form) <= 80)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
