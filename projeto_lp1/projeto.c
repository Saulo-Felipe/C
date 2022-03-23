#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

// Funções do sistema
int cadastro();
int interface();
int AtendimentoInicial();

// Variaveis
int pararPrograma = false;

int main()
{

	while (!pararPrograma)
    {
        interface();
    }

    printf("Programa encerrado\n");

	return 0;
}

int interface() {
    //system("@cls||clear"); // Limpa a tela
    
    int escolha;

    printf("-=-=-=-=-=| Laboratório LAB_SAÚDE |-=-=-=-=-=\n\n");

    printf(
        "[1] Cadastrar paciente\n"
        "[2] Atendimento inicial\n"
        "[3] Chamar para atendimento\n"
        "[4] Chamar para coleta\n"
        "[5] Mostrar fila para atendimento\n"
        "[6] Mostrar fila para coleta\n"
        "[7] Mostrar atendimento do dia\n"
        "[8] Sair\n\n"
    );

    printf("Sua opção -> ");

    scanf("%d", &escolha);

    switch (escolha)
    {
        case 1:
            cadastro();
            break;

        case 2:
            AtendimentoInicial();
            break;
        
        case 8:
            pararPrograma = true;
            break;

        default:
            printf("*Opção %d ainda não disponível no sistema.\n\n", escolha);
            break;
    }

    return 0;
}

int cadastro() {

    char cpf[ 14 ];
    char nome[ 50 ];
    char endereco[ 50 ];
    int idade, telefone;

    FILE *paPtr;

    if ((paPtr = fopen("clients.dat", "a")) == NULL){ 
        printf("Nao ha arquivo\n");
    }

    else {
        printf("Digite o cpf, o nome, o endereço, a idade e o telefone\n");
        printf("Aperte CTRL + Z para terminar\n");
        printf(": ");

        scanf("%s%s%s%d%d", cpf, nome, endereco, &idade, &telefone);
    
        while (!feof(stdin)) {
            fprintf(paPtr, "%s %s %s %d %d\n", cpf, nome, endereco, idade, telefone);
            scanf("%s%s%s%d%d", cpf, nome, endereco, &idade, &telefone);
        }

        fclose(paPtr);

    }

    return 0;

}

int AtendimentoInicial() {
    FILE *pacientesPtr;
    char dados[1000];

    pacientesPtr = fopen("clients.dat", "r");

    if (pacientesPtr == NULL) {
        printf("Erro ao abrir arquivo.");
        return 0;
    }

    fgets(dados, 1000, pacientesPtr);

    printf("Arquivo: \n%s", dados);

    fclose(pacientesPtr);

    return 1;
}




