/*
  Grupo: Return NULL;
  Eduardo Vinícius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vinícius Tadeu Silva Ribeiro 2670
*/
#pragma once
#include <stdio.h> 
#include <stdlib.h> 
#include "TADTST.h";
//#include "TADPatricia.h";

#define TST 1
#define PAT 2

void EscolheArvore(int *arvoreAtiva); //Imprime o menu para mudança de arvore e modifica a arvore ativa.
void ImprimeMenuPatricia(); //Imprime o menu Patricia
void ImprimeMenuTST(); //Imprime o menu TST
void imprimeMenuAtual(int arvoreAtiva); //Função que chama a função correta com o menu sendo utilizado no momento de acordo com a arvore ativa
