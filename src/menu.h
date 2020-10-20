/*
    Grupo: Return NULL;
    Eduardo Vin�cius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vin�cius Tadeu Silva Ribeiro 2670
*/
#ifndef MENU
#define MENU

#include <stdio.h> 
#include <stdlib.h> 
#include "TADTST.h"
#include <time.h>
#include "TadPatricia.h"

//#include "TADPatricia.h";

#define TST 1
#define PAT 2

void EscolheArvore(int *arvoreAtiva); //Imprime o menu para mudan�a de arvore e modifica a arvore ativa.
void ImprimeMenuPatricia(); //Imprime o menu Patricia
void ImprimeMenuTST(); //Imprime o menu TST
void EscolheInserir(tipoApontadorTST *tst, TipoApontadorPAT *pat, int arvoreAtiva); //Criado para facilitar a implementa��o da fun��o inserir, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheProcurar(tipoApontadorTST tst, TipoApontadorPAT pat, int arvoreAtiva); //Criado para facilitar a implementa��o da fun��o Procurar, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheOrdem(tipoApontadorTST tst, TipoApontadorPAT pat, int arvoreAtiva); //Criado para facilitar a implementa��o da fun��o Imprimir em Ordem Alfabetica, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheContar(tipoApontadorTST tst, TipoApontadorPAT pat, int arvoreAtiva); //Criado para facilitar a implementa��o da fun��o Contar numero de palavras, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheInserirArquivo(tipoApontadorTST *tst, TipoApontadorPAT *pat, int arvoreAtiva); //Criado para facilitar a implementa��o da fun��o inserir por arquivo, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void imprimeMenuAtual(int arvoreAtiva); //Fun��o que chama a fun��o correta com o menu sendo utilizado no momento de acordo com a arvore ativa

#endif