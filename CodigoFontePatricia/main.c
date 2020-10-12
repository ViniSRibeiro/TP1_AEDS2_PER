/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
//gcc -o teste main.c TadPatricia.c TadPatricia.h
#include "TadPatricia.h"

int main(){ 
    TipoArvore patricia;
    char nome1[30] = "rato";
    char nome2[30] = "roeu";
    char nome3[30] = "rata";
    char nome4[30] = "rena";
    int qt = 0, z;

    InicializaPatricia(&patricia);

    patricia = Insere(nome1,&patricia);
    patricia = Insere(nome2,&patricia);
    patricia = Insere(nome3,&patricia);
    
    z = pesquisa(nome2,patricia,&qt);
    printf("z = %d\n",z);
    
    printf("qt %d\n",qt);
    return 0;
} 