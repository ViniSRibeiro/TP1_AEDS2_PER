/*
    Grupo: Return NULL;
    Eduardo Vinícius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vinícius Tadeu Silva Ribeiro 2670
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

void EscolheArvore(int *arvoreAtiva); //Imprime o menu para mudança de arvore e modifica a arvore ativa.
void ImprimeMenuPatricia(); //Imprime o menu Patricia
void ImprimeMenuTST(); //Imprime o menu TST
void EscolheInserir(tipoApontadorTST *tst, TipoApontadorPAT *pat, int arvoreAtiva); //Criado para facilitar a implementação da função inserir, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheProcurar(tipoApontadorTST tst, TipoApontadorPAT pat, int arvoreAtiva); //Criado para facilitar a implementação da função Procurar, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheOrdem(tipoApontadorTST tst, TipoApontadorPAT pat, int arvoreAtiva); //Criado para facilitar a implementação da função Imprimir em Ordem Alfabetica, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheContar(tipoApontadorTST tst, TipoApontadorPAT pat, int arvoreAtiva); //Criado para facilitar a implementação da função Contar numero de palavras, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void EscolheInserirArquivo(tipoApontadorTST *tst, TipoApontadorPAT *pat, int arvoreAtiva); //Criado para facilitar a implementação da função inserir por arquivo, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
void imprimeMenuAtual(int arvoreAtiva); //Função que chama a função correta com o menu sendo utilizado no momento de acordo com a arvore ativa

#endif