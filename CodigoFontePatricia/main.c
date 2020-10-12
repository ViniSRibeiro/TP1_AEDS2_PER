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

    InicializaPatricia(&patricia);
    Insere("rato",&patricia);
    Insere("roeu",&patricia);
    Insere("roupa",&patricia);
    Insere("rei",&patricia);
    Insere("rama",&patricia);


    return 0;
} 