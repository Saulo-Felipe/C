#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
#endif

#define true 1
#define false 0

// Funções do sistema
int cadastro();
int interface();
int AtendimentoInicial();
int verificaCpf(char cpf[100]);
int mensagemAlerta(char msg[100]);
int filaDeAtendimento();

// Variaveis
int pararPrograma = false;

int main()
{

	while (!pararPrograma)
    {
        interface();
    }

    printf("Programa encerrado\n");

	return false;
}

int interface() {
    system("@cls||clear"); // Limpa a tela
    printf("-=-=-=-=-=| Laboratório LAB_SAÚDE |-=-=-=-=-=\n\n");
    
    int escolha;

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
            mensagemAlerta("\n*Opção ainda não disponível no sistema.\n");
            break;
    }

    return false;
}

int cadastro() {

    char cpf[ 100 ];
    char nome[ 50 ];
    char endereco[ 50 ];
    int idade, telefone;
 
    FILE *paPtr;

    if ((paPtr = fopen("clients.dat", "a")) == NULL){ 
        printf("Nao ha arquivo\n");
    }

    else {
        printf("Digite o CPF\n");
        scanf("%s", cpf);
        while (strlen(cpf) != 11){

            printf("Digite um cpf valido (11 digitos sem pontos ou tracos): ");
            scanf("%s", cpf);
        }

        printf("O PRIMEIRO NOME\n");
        scanf("%s", nome);
        printf("O BAIRRO (CASO O BAIRRO SEJA COMPOSTO POR DUAS PALAVRAS, INSIRA APENAS AS DUAS LETRAS INICIAIS DO NOME)\n");
        scanf("%s", endereco);
        printf("A IDADE e o TELEFONE\n");
        scanf("%d%d", &idade, &telefone);
        if (idade <= 0){
           
            printf("Digite uma idade maior que 0: ");
            scanf("%d", &idade);
            
        }
        
        printf(": ");

        if (!feof(stdin)){
            fprintf(paPtr, "%s %s %s %d %d\n", cpf, nome, endereco, idade, telefone);
            fclose(paPtr);
            mensagemAlerta("\nCliente cadastrado com sucesso!\n");
        }
    }

    return 0;

}


int AtendimentoInicial() {
    system("@cls||clear");
    printf("-=-=-=-=-=| Atendimento Inicial |-=-=-=-=-=\n\n");

    char cpf[100];

    printf("CPF a ser consultado: ");
    scanf(" %[^\n]", cpf);

    while (strlen(cpf) != 11) {
        printf("Digite um CPF válido (11 digitos sem pontos ou tracos): ");
        scanf(" %[^\n]", cpf);
    }

    int estaCadastrado = verificaCpf(cpf);

    if (estaCadastrado) {
        mensagemAlerta("\nCPF já cadastrado. Paciente encaminhado para fila de atendimento.\n");

    } else {
        mensagemAlerta("\nCPF ainda não cadastrado. Por favor cadastre-se.\n");
        cadastro();
    }
    
    return true;
}


int verificaCpf(char cpf[100])
{
    FILE *pacientesFile;
    char paciente[1000];

    pacientesFile = fopen("./clients.dat", "r");
    
    if (pacientesFile == NULL) {
        printf("Erro ao abrir aquivo.");
        return false;
    }

    fgets(paciente, 1000, pacientesFile);

    while (fgets(paciente, 1000, pacientesFile)) {
        if (strstr(paciente, cpf)) {
            return true;
        }        
    }

    fclose(pacientesFile);

    return false;
}


int mensagemAlerta(char msg[100])
{
    printf("%s", msg);
    printf("\e[0;32m""\n-> Aperte ENTER para continuar ");
    
    getchar();
    char enter = 0;
    while (enter != '\n' && enter  != '\r') { 
        enter = getchar();
    }

    printf("\033[0m");

    return 0;
}



