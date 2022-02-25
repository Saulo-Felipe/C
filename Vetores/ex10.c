/** 
* Questão 1967 - A Fronteira final
*/

#include <stdio.h>

/**
 * Função que conta o total de dígitos de um número
 * utilizado para formatar a matriz
 */

int contaDigitos(int valor)
{
    int totalDigitos = 1;

    while (valor > 9)
    {
        totalDigitos++;
        valor /= 10;
    }

    return totalDigitos;
}

int main()
{

    /**
     * G, A, M e C (G ≤ 600; A, C ≤ 100; M ≤ 2000), os quais representam respectivamente 
     * o número de cursos de graduação, o número total de tipos de atividade que podem ocorrer, 
     * o número total de tipos de material que podem ser necessários e o número de campi da UFFS.
     */
    int G, A, M, C;
    scanf("%d%d%d%d", &G, &A, &M, &C);

    /**
     * A primeira tabela consiste de G linhas, cada uma contendo A inteiros não maiores que 10...
     * A segunda tabela consiste de A linhas, cada uma contendo M inteiros não maiores que 10...
     * A terceira e última tabela consiste de M linhas, cada uma contendo C inteiros não maiores que 100...
     */
    int tabela1[G][A];
    int tabela2[A][M];
    int tabela3[M][C];

    int maiorNumeroColuna[C];

    int i, j, k, aux;
    // ------------------------------------------------------------------------------------
    // input dos dados das tabelas
    // ------------------------------------------------------------------------------------

    for (i = 0; i < G; i++)
    {
        for (j = 0; j < A; j++)
        {
            scanf("%d", &tabela1[i][j]);
        }
    }

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &tabela2[i][j]);
        }
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &tabela3[i][j]);
            
        }
    }

    //Inicializa vetor dos maiores nros de cada coluna
    for (j = 0; j < C; j++)
    {
        maiorNumeroColuna[j] = 0;
    }

    // ------------------------------------------------------------------------------------
    // Produto tabela 1 X tabela 2
    // ------------------------------------------------------------------------------------
    int tabela1x2[G][M];

    for (i = 0; i < G; i++)
    {
        for (j = 0; j < M; j++)
        {
            aux = 0;
            for (k = 0; k < A; k++)
            {
                aux += tabela1[i][k] * tabela2[k][j];
            }
            tabela1x2[i][j] = aux;
        }
    }

    // ------------------------------------------------------------------------------------
    // Produto (tabela 1 X tabela 2) X tabela 3
    // ------------------------------------------------------------------------------------
    int tabela1x2x3[G][C];
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            aux = 0;
            for (k = 0; k < M; k++)
            {
                aux += tabela1x2[i][k] * tabela3[k][j];
            }
            tabela1x2x3[i][j] = aux;

            /** Verifica a quantidade de dígitos de cada valor da matriz resultado 
             * e salva o maior de cada coluna para formatar a saída
             */
            
            if (aux > maiorNumeroColuna[j])
            {
                maiorNumeroColuna[j] = aux;
            }
        }
    }

    // ------------------------------------------------------------------------------------
    // Exibe Tabela Produto (tabela 1 X tabela 2) X tabela 3
    // ------------------------------------------------------------------------------------
    for (i = 0; i < G; i++)
    {
        for (j = 0; j < C; j++)
        {
            /** 
             * Entre duas colunas consecutivas de uma mesma tabela há uma coluna de espaços de 
             * largura 1, e espaços adicionais podem preceder cada inteiro duma tabela a fim de 
             * que todas as colunas daquela tabela fiquem alinhadas à direita e haja ao menos um 
             * inteiro por coluna que não seja precedido por espaços adicionais.
             * 
             * "%*""                    - permite a adição de espaços em branco
             * "digitosMaiorNumero[j]"  - especifica a quantidade de espaços em branco
             * "+(j>0)"                 - teste lógico que adiciona +1 espaço a partir da 2 coluna
             */
            printf("%*d", contaDigitos(maiorNumeroColuna[j]) + (j > 0), tabela1x2x3[i][j]);
            //printf("%d ", tabela1x2x3[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}