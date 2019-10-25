#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

struct Usuario{
int idade;
char Nome[100];
char Telefone[10];
};

void criarLista(){

}

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

int main()
{
    setlocale(LC_ALL, "Portuguese");
    CriaMenu();
    return 0;
}
