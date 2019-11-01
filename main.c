#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

//Aqui � a estrutura do Aluno
typedef struct{
int idade;
char Nome[100];
char Telefone[10];
}Aluno;

// Aqui � a estrutura da base
typedef struct{
    Aluno data;
    struct node *pLink;
}node;

// Aqui � para chamar a a��o desejada pelo usu�rio
void executar(char tecla){
  if(tecla == '1'){
   //inserir();
  }else if(tecla == '2'){
   //pesquisar();
  }else if(tecla=='3'){
   //remover();
  }else if(tecla=='4'){
   //listar();
  }else{
   exit(0);
  }
}


//APENAS UM EXEMPLO DE CRIAÇÃO DE LISTA, PRECISAMOS ADAPTAR PARA NOSSA VERSÃO
void criarLista(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //verifica se o fnnode é NULL e se não houver alocação de memória
    {
        printf(" Impossível alocar memória");
    }
    else
    {
// Leitura

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL; // links the address field to NULL
        tmp = stnode;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);

                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL

                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
}

node inserir(){
node *novoNo = NULL;

Aluno aluno_1;

printf("Qual o nome do Aluno que voc� deseja inserir?\n");
scanf("%c",&aluno_1.Nome);

printf("Qual a idade do Aluno que voc� deseja inserir?\n");
scanf("%i",&aluno_1.idade);

printf("Qual o telefone do Aluno que voc� deseja inserir?\n");
scanf("%c",&aluno_1.Telefone);

novoNo = (struct node*) malloc(sizeof(struct node*));
novoNo->data=aluno_1;

return *novoNo;
}

//Funcao que vai procurar na lista encadeada
long search(long *pointer, long n, long find)
{
   long c;

   for (c = 0; c < n; c++) {
      if (*(pointer+c) == find)
         return c;
   }

   return -1;
}

//Funcao que vai listar nossa lista encadeada
void printKeys(LinkedList *list){
    item* ptrTemp = list->head;
    while (ptrTemp->next != NULL) {
        printf("%d",ptrTemp->data);
        ptrTemp = ptrTemp->next;
    }
    printf("%d\n",ptrTemp->data);
}


//Fun��o respons�vel pela cria��o do Menu
 void CriaMenu(){
  char tecla;
    printf("1 - Para Inserir um Aluno;\n");
    printf("2 - Para Pesquisar um Aluno\n");
    printf("3 - Para Remover um Aluno;\n");
    printf("4 - Para Mostrar todos os Alunos;\n");
    printf("O que deseja fazer?\n");
    scanf("%c",&tecla);
  if(tecla = "1"){
    executar(tecla);
  }else if(tecla = "2"){
    executar(tecla);
  }else if(tecla = "3"){
    executar(tecla);
  }else if(tecla = "4"){
    executar(tecla);
  }else{
    exit(0);
  }

}
//teste para joao
//teste para tassia

int main()
{
    setlocale(LC_ALL, "Portuguese");
    CriaMenu();
    return 0;
}
