/*
GRUPO:
Arthur Salviano Ferreira
Jônatan Barbosa Ferreira
Rafael Trajano do Nascimento
Adriana Silva Sousa
Lucas Fausto Medeiros
Saulo José Felipe
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define true 1
#define false 0

// Funções do sistema
int cadastro(int insereNaLista);
int interface();
int AtendimentoInicial();
int verificaCpf(char cpf[100]);
int mensagemAlerta(char msg[100]);
int inserirPacienteNaFila(char cpf[100], int idade);
int tamanhoFilaAtendimento();
int mostrarFilaDeAtendimento();
int organizarFila();
int compararFilaPacientes();
int tirarDaFilaDeAtendimento();

// Variaveis
int pararPrograma = false;
typedef struct
{
char cpf[15];
int idade;
int tempoEspera;
} Paciente;

struct filaC {
   char cpf[12];
   int idade;
   int temp;
   int exames;
   int prioridade;
   char tipo[15];
   char hora[11];
   struct filaC *nextPtr;
};

typedef struct filaC FilaC;
typedef FilaC *FilaCPtr;

void mostrarData(char data[]);
void registrarAtendimento(char CPF[], char horaA[], char horaC [], int nExames);
void mostrarAtendimentoDodia();
int isEmpty( FilaCPtr headPtr );
void InserirNaFilaColeta(FilaCPtr *headPtr, FilaCPtr *tailPtr, FilaC lista[], int tamanho);
void BubbleSort(FilaC  vetor[], int tamanho);
void ordenarFilaC( FilaCPtr andarPtr, FilaCPtr caldaPtr);
void mostrarHoraAtendimento(char HOra[]);
void InserirNaFilaC(FilaCPtr *headPtr, FilaCPtr *tailPtr, char CPF[], int Idade, int Temp,
int Exame, char Tipo[], char Hora[]);
void printFilaC(FilaCPtr currentPtr);
void aumentarTempo(FilaCPtr currentPtr);
int chamarParaColeta( FilaCPtr *headPtr, FilaCPtr *tailPtr );
int chamarParaAtendimento(FilaCPtr *headPtr, FilaCPtr *tailPtr);
void printFilaC(FilaCPtr currentPtr);

Paciente filaAtendimento[100];

int main()
{
    setlocale(LC_ALL, "Portuguese");
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
  int  IDade = 0, Exam = 0;
    char Cpf[12], TIpo[15], HOra[11];
  static FilaCPtr headPtr = NULL;
  static FilaCPtr tailPtr = NULL;
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
       cadastro(0);
       break;
   case 2:
       AtendimentoInicial();
       break;

   case 3:
       chamarParaAtendimento(&headPtr, &tailPtr);
       break;

   case 4:
       if(headPtr != NULL) {
           ordenarFilaC(headPtr, tailPtr);
           chamarParaColeta(&headPtr, &tailPtr);
           aumentarTempo(headPtr);
       }
       else {
           mensagemAlerta("\nA fila de coleta esta vazia\n");
       }
       break;
   case 5:
       mostrarFilaDeAtendimento();
       break;
   case 6:
       ordenarFilaC(headPtr, tailPtr);
       printFilaC(headPtr);
       break;
   case 7:
       mostrarAtendimentoDodia();
       break;

   case 8:
       pararPrograma = true;
       break;

   default:
       mensagemAlerta("\n*Opção não disponível no sistema, digite uma opção valida.\n");
       break;
 }
 return false;
}

int cadastro(int insereNaLista) {
 system("@cls||clear");
 printf("=-=-=-=-=-=| Cadastro de Paciente |=-=-=-=-=-=\n");
 char cpf[ 100 ];
 char nome[ 50 ];
 char endereco[ 50 ];
 int idade, telefone;
 FILE *paPtr;
 if ((paPtr = fopen("clients.dat", "a")) == NULL){
     printf("Nao ha arquivo\n");
 }
 else {
     printf("\nDigite o CPF: ");
     scanf("%s", cpf);
     while (strlen(cpf) != 11){
         printf("Digite um cpf valido (11 digitos sem pontos ou traços): ");
         scanf("%s", cpf);
     }
     printf("Nome Completo: ");
     scanf(" %[^\n]", nome);

     printf("Endereço: ");
     scanf(" %[^\n]", endereco);

     printf("Idade: ");
     scanf("%d", &idade);
     while (idade <= 0){
         printf("Digite uma idade maior que 0: ");
         scanf("%d", &idade);
     }
     printf("Telefone: ");
     scanf("%d", &telefone);
     if (!feof(stdin)){
         fprintf(paPtr, "[%s] [%s] [%s] [%d] [%d]\n", cpf, nome, endereco, idade, telefone);
         fclose(paPtr);
         if (insereNaLista) {
             mensagemAlerta("\n=> Cliente cadastrado com sucesso!\n=> Cliente inserido na lista de atendimento\n");
             inserirPacienteNaFila(cpf, idade);
         }
         else
             mensagemAlerta("\n=> Cliente cadastrado com sucesso!\n");

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

int idade = verificaCpf(cpf);
if (idade) {
    mensagemAlerta("\nCPF já cadastrado. Paciente encaminhado para fila de atendimento.\n");
    inserirPacienteNaFila(cpf, idade);
} else {
    mensagemAlerta("\nCPF ainda não cadastrado. Por favor cadastre-se.\n");
    cadastro(1);
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
        // Verifica idade
        int i = 0;
        for (int c = 0; c < strlen(paciente); c++) {
            if (paciente[c] == '[') {
                i++;
                int pos;
                if (i == 4) {
                    if (paciente[c+2] == ']')
                        pos = 1;
                    else if (paciente[c+3] == ']')
                        pos = 2;
                    else if (paciente[c+4] == ']')
                        pos = 3;
                    char *buff = paciente;
                    char subbuff[6];
                    memcpy(subbuff, &buff[c+1], pos);
                    subbuff[pos] = '\0';
                    fclose(pacientesFile);
                    return atoi(subbuff);
                }
            }
        }
        return false;
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

int tamanhoFilaAtendimento() {
for (int c = 0; c < (sizeof filaAtendimento / sizeof filaAtendimento[0]); c++) {
    if (strlen(filaAtendimento[c].cpf) == 0) {
        return c;
    }
}
}

int inserirPacienteNaFila(char cpf[100], int idade) {
int filaTamanho = tamanhoFilaAtendimento();
strcpy(filaAtendimento[filaTamanho].cpf, cpf);
filaAtendimento[filaTamanho].idade = idade;
filaAtendimento[filaTamanho].tempoEspera = idade;
organizarFila();
return 0;
}

int compararFilaPacientes (const void * a, const void * b)
{
Paciente *orderA = (Paciente *)a;
Paciente *orderB = (Paciente *)b;
return ( orderB->idade - orderA->idade );
}
int organizarFila() {
  int filaTamanho = tamanhoFilaAtendimento();
  qsort(filaAtendimento, filaTamanho, sizeof(Paciente), compararFilaPacientes);
   return 0;
}

int mostrarFilaDeAtendimento() {
int filaTamanho = tamanhoFilaAtendimento();
printf("=-=-=-=-= Lista de atendimento Atualizada =-=-=-=-=\n\n");
for (int c = 0; c < filaTamanho; c++) {
    printf("-> Cpf: %s\n"
           "   Idade: %d\n"
           "   Tempo de Espera: %d \n\n",
        filaAtendimento[c].cpf, filaAtendimento[c].idade, filaAtendimento[c].tempoEspera
    );
}
if (filaTamanho == 0)
    mensagemAlerta("A lista ainda está vazia :)");
else
    mensagemAlerta("Lista finalizada!");
}
int tirarDaFilaDeAtendimento() {
  int filaTamanho = tamanhoFilaAtendimento();
  strcpy(filaAtendimento[0].cpf, "");
  filaAtendimento[0].idade = 0;
  filaAtendimento[0].tempoEspera = 0;
  for (int c = 1; c < filaTamanho; c++) {
      strcpy(filaAtendimento[c-1].cpf, filaAtendimento[c].cpf);
      filaAtendimento[c-1].idade = filaAtendimento[c].idade;
      filaAtendimento[c-1].tempoEspera = filaAtendimento[c].tempoEspera;
  }
  strcpy(filaAtendimento[filaTamanho-1].cpf, "");
  filaAtendimento[filaTamanho-1].idade = 0;
  filaAtendimento[filaTamanho-1].tempoEspera = 0;
   return 0;
}
int chamarParaAtendimento(FilaCPtr *headPtr, FilaCPtr *tailPtr) {
   char TIpo[15], HOra[11];
   int Exam = 0;
   mostrarHoraAtendimento(HOra);

   printf("Tipo de enxame (convênio ou particular): ");
   scanf(" %[^\n]", TIpo);

   printf("Quantidade de enxames: ");
   scanf("%d", &Exam);

   int idade = verificaCpf(filaAtendimento[0].cpf);

   InserirNaFilaC(*&headPtr, *&tailPtr, filaAtendimento[0].cpf, idade, 0, Exam, TIpo, HOra);
   tirarDaFilaDeAtendimento();

   mensagemAlerta("\nPaciente atendido! Encaminhando para fila de coleta...!\n");

   return 0;
}

// =1-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void mostrarData(char data[]) {
   struct tm *HORA;
   time_t segundos;
   time(&segundos);
   HORA = localtime(&segundos);
   long int mes = HORA->tm_mon, ano = HORA->tm_year;
   mes += 1;
   ano += 1900;
   char auxiliar[9];
   sprintf(data, "%d", HORA->tm_mday);
   if(data[1] == '\0') {
       data[1] = data[0]; data[0] = '0';
   }
   data[2] = '/'; data[3] = '\0';
   sprintf(auxiliar, "%ld", mes);
   if(auxiliar[1] == '\0') {
       auxiliar[1] = auxiliar[0]; auxiliar[0] = '0';
   }
   auxiliar[2] = '/'; auxiliar[3] = '\0';
   strcat(data, auxiliar);
   sprintf(auxiliar, "%ld", ano);
   strcat(data, auxiliar);
}
void registrarAtendimento(char CPF[], char horaA[], char horaC [], int nExames) {
   char data[12];
   FILE *cfPtr;
   if( ( cfPtr = fopen( "atendimento.dat", "a" ) ) == NULL ) {
       printf( "Arquivo não pode ser aberto\n" );
   }
   else {
       mostrarData(data);
       fprintf(cfPtr,"%s %s %s %s %d\n", CPF, data, horaA, horaC, nExames);
       fclose( cfPtr );
   }
}
void mostrarAtendimentoDodia() {
    char cpf[12], data[12], horaAt[12], horaCo[12];
    int Exames;
    FILE *cfPtr;

    if( ( cfPtr = fopen( "atendimento.dat", "r" ) ) == NULL ) {
        printf( "Arquivo não pode ser aberto\n" );
    }
    else {
        printf("-=-=-=-=-=-=-=-=- Atendimento do dia -=-=-=-=-=-=-=-=-=-=- \n\n");
        printf("%15s %23s %23s %19s %21s \n\n", "CPF" , "Data do Atendimento" , "Hora do Atendimento" , "Hora da Coleta", "Número de Exames");
        fscanf(cfPtr, "%s%s%s%s%d", cpf, data, horaAt, horaCo, &Exames);
        while ( !feof( cfPtr ) ) {
            printf("%15s %23s %23s %19s %21d \n", cpf, data, horaAt, horaCo, Exames);
            fscanf(cfPtr, "%s%s%s%s%d", cpf, data, horaAt, horaCo, &Exames);
        }
        fclose( cfPtr );
        mensagemAlerta("\nFim\n");
    }
}

int isEmpty( FilaCPtr headPtr )
{
return headPtr == NULL;
}

void InserirNaFilaColeta(FilaCPtr *headPtr, FilaCPtr *tailPtr, FilaC lista[], int tamanho)
{
   FilaCPtr newPtr;
   int a = 0;
   for(int j = tamanho -1; j > 0; j-- , a++) {
       newPtr = malloc(sizeof(FilaC));
   if (newPtr != NULL)
   {
       strcpy(newPtr->cpf, lista[a].cpf);
       newPtr->idade = lista[a].idade;
       newPtr->temp = lista[a].temp;
       newPtr->exames = lista[a].exames;
       strcpy(newPtr->tipo, lista[a].tipo);
       strcpy(newPtr->hora, lista[a].hora);
       newPtr->prioridade = lista[a].idade + (lista[a].temp * lista[a].temp);
       newPtr->nextPtr = NULL;
       if (isEmpty(*headPtr))
       {
           *headPtr = newPtr;
       }
       else
       {
           (*tailPtr)->nextPtr = newPtr;
       }
       *tailPtr = newPtr;
   }
   else
   {
       printf(" Não inserido. Não há memória disponível.\n");
   }
   }
}
void BubbleSort(FilaC  vetor[], int tamanho)
{
 int i, j;
 FilaC auxiliar;
 for(j= 1; j < tamanho - 1; j++)
 {
   for(i=0; i< tamanho -2; i++)
   {
       if(vetor[i].prioridade == vetor[i+1].prioridade) {
           vetor[i].prioridade += vetor[i].exames;
           vetor[i+1].prioridade += vetor[i+1].exames;
       }
     if(vetor[i].prioridade < vetor[i+1].prioridade)
     {
       auxiliar=vetor[i];
       vetor[i]=vetor[i+1];
       vetor[i+1]=auxiliar;
     }
   }
 }
}
void ordenarFilaC( FilaCPtr andarPtr, FilaCPtr caldaPtr) {
   int tamanho = 1, i = 0;
   FilaCPtr temporariaPtr, temPtr = andarPtr;
   while(temPtr != NULL) {
       tamanho++;
       temPtr = temPtr->nextPtr;
   }
   FilaC lista[tamanho];
   while(andarPtr != NULL) {
       strcpy(lista[i].cpf, andarPtr->cpf);
       lista[i].exames = andarPtr->exames;
       strcpy(lista[i].hora, andarPtr->hora);
       lista[i].idade = andarPtr->idade;
       lista[i].prioridade = andarPtr->prioridade;
       lista[i].temp = andarPtr->temp;
       strcpy(lista[i].tipo, andarPtr->tipo);
       lista[i].nextPtr = NULL;
       i++;
       temporariaPtr = andarPtr;
       andarPtr = andarPtr->nextPtr;
       free((temporariaPtr));
   }
   BubbleSort(lista, tamanho);
   InserirNaFilaColeta(&andarPtr, &caldaPtr, lista, tamanho);
}

void mostrarHoraAtendimento(char HOra[]) {
   struct tm *HORA;
   time_t segundos;
   time(&segundos);
   HORA = localtime(&segundos);
   char auxiliar[12];
   sprintf(HOra, "%d", HORA->tm_hour);
   if(HOra[1] == '\0') {
       HOra[1] = HOra[0]; HOra[0] = '0';
   }
   HOra[2] = ':'; HOra[3] = '\0';
   sprintf(auxiliar, "%d", HORA->tm_min);
   if(auxiliar[1] == '\0') {
       auxiliar[1] = auxiliar[0]; auxiliar[0] = '0';
   }
   auxiliar[2] = ':'; auxiliar[3] = '\0';
   strcat(HOra, auxiliar);
   sprintf(auxiliar, "%d", HORA->tm_sec);
   if(auxiliar[1] == '\0') {
       auxiliar[1] = auxiliar[0]; auxiliar[0] = '0'; auxiliar[2] = '\0';
   }
   strcat(HOra, auxiliar);
}
void InserirNaFilaC(FilaCPtr *headPtr, FilaCPtr *tailPtr, char CPF[], int Idade, int Temp,
int Exame, char Tipo[], char Hora[])
{

    FilaCPtr newPtr;

    newPtr = malloc(sizeof(FilaC));

    if (newPtr != NULL)
    {
        strcpy(newPtr->cpf, CPF);
        newPtr->idade = Idade;
        newPtr->temp = Temp;
        newPtr->exames = Exame;
        strcpy(newPtr->tipo, Tipo);
        strcpy(newPtr->hora, Hora);
        newPtr->prioridade = Idade + (Temp * Temp);
        newPtr->nextPtr = NULL;

        if (isEmpty(*headPtr))
        {
            *headPtr = newPtr;
        }
        else
        {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    }
    else
    {
        printf(" Não inserido. Não há memória disponível.\n");
    }
}
void printFilaC(FilaCPtr currentPtr) {
    int posicao = 1;

    if (currentPtr == NULL) {
        printf("A fila está vazia.\n\n");
    }
    else {
        printf("-=-=-=-=-=-=-=-=- Fila da Coleta -=-=-=-=-=-=-\n\n");
        printf("%7s %16s %9s %18s %20s %16s %25s \n\n", "Posição", "CPF", "Idade",
         "Tempo na fila", "Total de exames", "Tipo  ", "Hora do atendimento");

        while(currentPtr != NULL) {
            printf("%7d %16s %9d %18d %20d %16s %25s \n", posicao, currentPtr->cpf, currentPtr->idade,
             currentPtr->temp, currentPtr->exames, currentPtr->tipo, currentPtr->hora);
            currentPtr = currentPtr->nextPtr;
            posicao++;
        }
        mensagemAlerta("\nFila de coleta finalizada!\n");
    }
}

void aumentarTempo(FilaCPtr currentPtr) {
   while(currentPtr != NULL) {
       currentPtr->temp += 1;
       currentPtr = currentPtr->nextPtr;
   }
}

int chamarParaColeta( FilaCPtr *headPtr, FilaCPtr *tailPtr ) {

    FilaCPtr tempPtr;
    char hora[12];
    mostrarHoraAtendimento(hora);

    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL)
    {
        *tailPtr = NULL;
    }
    registrarAtendimento(tempPtr->cpf, tempPtr->hora, hora, tempPtr->exames);
    mensagemAlerta("\nO paciente da fila será selecionado para coleta!\n");

    free(tempPtr);
    return 0;
}





