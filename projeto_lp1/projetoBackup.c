#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
 
#ifdef _WIN32
  #include <windows.h>
#elif __linux__
  #include <unistd.h>
#endif
 
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
 
// Variaveis
int pararPrograma = false;
 
typedef struct
{
  char cpf[15];
  int idade;
  int tempoEspera;
} Paciente;
 
Paciente filaAtendimento[100];
 
 
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
          cadastro(0);
          break;
      case 2:
          AtendimentoInicial();
          break;
      case 5:
          mostrarFilaDeAtendimento();
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
};
 
 
int inserirPacienteNaFila(char cpf[100], int idade) {
  int filaTamanho = tamanhoFilaAtendimento();
  strcpy(filaAtendimento[filaTamanho].cpf, cpf);
  filaAtendimento[filaTamanho].idade = idade;
  filaAtendimento[filaTamanho].tempoEspera = idade;
  return 0;
}
 
 
int mostrarFilaDeAtendimento() {
  system("@cls||clear"); // Limpa a tela

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
      mensagemAlerta("A lista de atendimento ainda está vazia :)");
  else
      mensagemAlerta("Lista finalizada!");
}
 


