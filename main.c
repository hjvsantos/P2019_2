#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

//Aqui é a estrutura do Aluno
typedef struct{
int idade;
char Nome[100];
char Telefone[10];
}Aluno;

// Aqui é a estrutura da base
typedef struct{
    Aluno data;
    struct node *pLink;
}node;

// Aqui é para chamar a ação desejada pelo usuário
void executar(char tecla){
  if(tecla == '1'){
   //inserir();
  }else if(tecla == '2'){
   //  pesquisar();
  }else if(tecla=='3'){
   //   remover();
  }else if(tecla=='4'){
   //  listar();
  }else{
   exit(0);
  }
}

node inserir(){
node *novoNo = NULL;

Aluno aluno_1;

printf("Qual o nome do Aluno que você deseja inserir?\n");
scanf("%c",&aluno_1.Nome);

printf("Qual a idade do Aluno que você deseja inserir?\n");
scanf("%i",&aluno_1.idade);

printf("Qual o telefone do Aluno que você deseja inserir?\n");
scanf("%c",&aluno_1.Telefone);

novoNo = (struct node*) malloc(sizeof(struct node*));
novoNo->data=aluno_1;

return *novoNo;
}


//Função responsável pela criação do Menu
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
