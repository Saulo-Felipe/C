#include <stdio.h>
#include <stdlib.h>

int **a(int lines, int COLUMN)
{
    int **m;
    m = malloc(lines * sizeof(int *));
    int z;
    for (z = 0; z < lines; z++)
        m[z] = malloc(COLUMN * sizeof(int));



    int i, j;
    for (i = 0; i < lines; i++)
    {
        for (j = 0; j < COLUMN; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    return m;
}


int ehLegal(int lines, int COLUMN, int **A)
{
    int i, j;
    for (i = 1; i < lines; i++)
    {
        for (j = 1; j < COLUMN; j++)
        {

            if ( (A[0][0] + A[i][j]) > (A[0][j] + A[i][0]) ) 
            {
                return 0;
            }
        }
    }
    return lines * COLUMN;
}

int **matrix(int li, int ci, int M, int N, int **Matriz)
{
    int **matrix;
    matrix = malloc(M * sizeof(int *));
    int z;
    for (z = 0; z < M; z++)
        matrix[z] = malloc(N * sizeof(int));

    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = Matriz[li + i][ci + j];
        }
    }    
    return matrix;
}


void exibeMatriz(int lines, int COLUMN, int **m)
{
    int i, j;
    for (i = 0; i < lines; i++)
    {
        printf("|");
        for (j = 0; j < COLUMN; j++)
        {
            printf("(%d,%d) %3d |", i, j, m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{

    int L, C;
    scanf("%d%d", &L, &C);
    int **matrizPrincipal = a(L,C);

    exibeMatriz(L, C, matrizPrincipal);
    int **submatriz;

    int li, ci, M, N;

    int maiorLegal = 0;
    for (M = 2; M <= L; M++)
    {
        for (N = 2; N <= C; N++)
        {
            printf("%d x %d\n", M, N);
            for (li = 0; li <= L - M; li++)
            {
                for (ci = 0; ci <= C - N; ci++)
                {
                    printf("  (%d,%d)\n", li, ci);
                    submatriz = matrix(li, ci, M, N, matrizPrincipal);
                    exibeMatriz(M,N,submatriz);
                    int legal = ehLegal(M, N, submatriz);
                    if (legal > maiorLegal)
                    {
                        maiorLegal = legal;
                    }
                    int z;
                    for (z = 0; z < M; z++)
                        free(submatriz[z]) ;
                    free(submatriz);
                }
            }
        }
    }

   printf("%d\n", maiorLegal);

    return 0;
}