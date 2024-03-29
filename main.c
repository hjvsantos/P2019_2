#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERSAO1
#define VERSAO2
#define VERSAO3


//Ajustes - tassia
typedef struct Temp
  {
    int idade;
    char nome[40];
    char telefone[11];
    struct Temp *prox;
  }lista;
  // cria o inicio da lista
  lista *inicio;
//--------------------------------------------------------

// Funcao que define a lista como vazia.
void criaLista()
{
  inicio = NULL;
}

int cadastro()
{
  lista *ponteiro;
  ponteiro =  (lista *) malloc(sizeof(lista));
    if (ponteiro==NULL)
    {
      printf("Erro de alocacao\n");
      return 0;
    }
  printf("Digite a idade:");
  scanf("%d",&ponteiro->idade);
  printf("Digite o nome:");
  scanf(" %[^\n]",ponteiro->nome);
  printf("Digite o telefone:");
  scanf(" %[^\n]",ponteiro->telefone);
  ponteiro->prox = NULL;
    if (inicio==NULL)
      {
        inicio = ponteiro;
      }
    else
      {
     ponteiro->prox = inicio;
     inicio  = ponteiro;
     }
   return 1;
}

void imprime()
{
  lista *ponteirolista;
  if (inicio == NULL) // Caso a lista nao esteja vazia
  {
    printf("funcao-impressao>>lista-null--\n\n");
    return;
  }
  ponteirolista = inicio;
  while (ponteirolista !=NULL) {
    printf("Idade = %d\n",ponteirolista->idade);
    printf("Nome = %s\n",ponteirolista->nome);
    printf("Telefone = %s\n",ponteirolista->telefone);
    ponteirolista = ponteirolista->prox;
    getchar();
    getchar();
  }
  printf("funcao-impressao>>fim-da-lista ---\n\n");
}

void imprimeponterio(lista *ponteirolista)///para imprimir resultado da função busca
{

  if (ponteirolista == NULL) // Caso a função busca restorne null
  {
    printf("Não achou!!");
    return;
  }
    printf("funcao-impressao--ponteiro ---\n\n");
    printf("Idade = %d\n",ponteirolista->idade);
    printf("Nome = %s\n",ponteirolista->nome);
    printf("Telefone = %s\n",ponteirolista->telefone);
    getchar();
    getchar();
}

///-------------------------------------------------pesquisa
///pesquisa por telefone

lista *pesquisatelefone()
{
   char pesq[11];
   printf("Digite o telefone:");
   scanf(" %[^\n]",pesq);
  lista *ponteiro;
  if (inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ponteiro = inicio;
  while (ponteiro !=NULL) {
     //printf("procurando %s==%s\n",pesq,ponteiro->telefone);///comentar para parar de mostra lixo na tela
     getchar();
    if (strcmp (ponteiro->telefone,pesq)== 0 )  // achou !!
    {
            printf("\nRegistro encontrado\n");
         return (ponteiro);        // retorna um ponteiro para função imprimr

                   }
    else
    {

        ponteiro = ponteiro->prox;

     }
  }
  return NULL;
}


lista *atualizarAluno()
{
   char pesq[11];
   printf("Digite o telefone:");
   scanf(" %[^\n]",pesq);
  lista *ponteiro;
  if (inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ponteiro = inicio;
  while (ponteiro !=NULL) {
     printf("procurando %s==%s\n",pesq,ponteiro->telefone);///comentar parar para de mostra lixo na tela
     getchar();///comentar ai ñ pede enter
    if (strcmp (ponteiro->telefone,pesq)== 0 )  // achou !!
    {
            printf("\nRegistro encontrado\n");
            char novo_nome[40];
            int nova_idade;
            printf("\nInforme o novo nome?");
            scanf("%s", &novo_nome);
            printf("\nInforme a nova idade?");
            scanf("%i", &nova_idade);
            ponteiro->idade = nova_idade;
            sprintf(ponteiro->nome,"%s", novo_nome);
            //ponteiro->nome = novo_nome;
            printf("\n\nAtualizacao realizada com sucesso!!!");

         return (ponteiro);        // retorna um ponteiro para função imprimr

                   }
    else
    {

        ponteiro = ponteiro->prox;

     }
  }
  return NULL;
}


///esvazia a fila
void  libera (lista* l)
{
   printf("\nFuncao liberar\n");
  lista* ponteiro = l;
  while (ponteiro != NULL)
      {
        lista* t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
      }

}

///remove elemento
void removedado(char *dado)
{
  lista *ptr, *antes;
  if (inicio==NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {  // Caso a lista nao esteja vazia
      ptr = inicio;
      antes = inicio;
      while (ptr !=NULL)
      {
    if (strcmp(ptr->telefone,dado)==0) // achou !!
    {
      if (ptr == inicio) // se esta removendo o primeiro da lista
      {
        inicio = inicio->prox;
        free(ptr);
        return 1; // removeu !!
      }
      else  // esta removendo do meio da lista
      {
        antes->prox = ptr->prox;  // Refaz o encadeamento
        free(ptr);                // Libera a area do nodo
        return 1;  // removeu !!
      }
    }
    else  // continua procurando no prox. nodo
    {
      antes = ptr;
      ptr = ptr->prox;
    }
      }
      return 0; // Nao achou !!!
  }
}
//teste1
configuraMenu(int op){
printf("Insira qual versao voce quer usar: 1, 2 ou 3.  \n");
scanf("%d", &op);

    if(op==1){

#ifdef VERSAO1
  criaLista();
  voltamenu:
  printf("\nMenu:\n\n1_Inserir\n0_Sair:\n:");
  scanf("%d",&op);
  switch (op)
            {

             case 1:
                    {
                     cadastro();
                     break;
                    }
              case 0:
                    {
                 libera (inicio);
                      return 0;
                      break;
                    }
            }
        goto voltamenu;
#endif
    }else if(op == 2){

#ifdef VERSAO2
  criaLista();
  voltamenu1:
  printf("\nMenu:\n\n1_Inserir\n2_Remover\n0_Sair:\n:");
  scanf("%d",&op);
  switch (op)
            {

             case 1:
                    {
                     cadastro();
                     break;
                    }
              case 2:
                    {
                   //imprime();
                   removedado(pesquisatelefone()->telefone);///a pesquisa retorna um ponteiro para a funcao remover
                   printf("Removido!!! \n");
                   //imprime();
                   break;
                    }
              case 0:
                    {
                 libera (inicio);
                      return 0;
                      break;
                    }
            }
#endif
    goto voltamenu1;
    }else if(op == 3){

#ifdef VERSAO3
  criaLista();
  voltamenu2:
  printf("\nMenu:\n\n1_Inserir\n2_Atualizar\n3_Remover\n4_Imprimir\n0_Sair:\n:");
  scanf("%d",&op);
  switch (op)
            {

             case 1:
                    {
                     cadastro();
                     break;
                    }
              case 2:
                    {
                      atualizarAluno();
                      break;
                    }
              case 3:
                    {
                   //imprime();
                   removedado(pesquisatelefone()->telefone);///a pesquisa retorna um ponteiro para a funcao remover
                   printf("Removido!!! \n");
                   //imprime();
                   break;
                    }
              case 4:
                    {
                      imprime();
                      break;
                    }
              case 0:
                    {
                 libera (inicio);
                      return 0;
                      break;
                    }
            }
       goto voltamenu2;
#endif
    }else{
        printf("Opcao invalida");
    }
}

int main()
{
  FILE *arq;
  char Linha[100];
  char *result;
  int i;
  int op;

  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("versoes.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      int tam = strlen(result);

      if (op == result[tam-1])  // Se foi possível ler
	  printf("Linha %d : %s",i,Linha);
      i++;
  }
  fclose(arq);
  criaLista();
  configuraMenu(op);
  return 0;
}
