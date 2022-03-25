#include <stdio.h>
#include <string.h>


int verifyType(char charact[2])
{
    printf("%c", charact[0]);

    return 0;
}

int main()
{
    // +,-,*,/,^,

    char infixa[100];
    int haveParentheses = 0;
    char expressions[100][100] = {};

    //strcpy(expressions[0], "saulo");

    scanf("%s", infixa);

    for (int c = 0; c < strlen(infixa); c++) {
        if (infixa[c] == '(') {
            verifyType(infixa[c]);
        }
    }


    

    return 0;
}