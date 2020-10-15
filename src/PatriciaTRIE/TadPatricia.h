/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum{Interno,Externo}TipoNo;

typedef struct TipoPatNo* TipoApontadorPAT;
typedef struct TipoPatNo{
    TipoNo TipoDeNo;
    union
    {
        struct
        {
            int posicao;
            char caracter;
            TipoApontadorPAT Esq, Dir;
        }NInterno;
        char Chave[55];
    }NO;
}TipoPatNo;

// Controle de implementações
// Insere Palavra   [v]                     Verificação ocorreu? Sim[]  Não[x]  Teste de mesa e compitalação
// Pesquisa Palavra [v]                     Verificação ocorreu? Sim[]  Não[x]  Teste de mesa e compitalação
// Imprime arvore em ordem Alfabetica[x]    Verificação ocorreu? Sim[]  Não[x]  Teste de mesa e compitalação
// Numero de palavras na arvore [x]         Verificação ocorreu? Sim[]  Não[x]  Teste de mesa e compitalação
// 

void InicializaPatricia(TipoApontadorPAT *p); //Faz a inicialização do ponteiro do tipo TipoApontadorPAR sendo nulo como valor base
TipoApontadorPAT CriaNoInterno (int i,char CarDiferente, TipoApontadorPAT *Esq, TipoApontadorPAT *Dir); 
TipoApontadorPAT CriaNoExterno (char *k); 
TipoApontadorPAT InsereEntre (char *k, TipoApontadorPAT *t, int i, char CarDiferente);
int EExterno (TipoApontadorPAT p);
TipoApontadorPAT Insere(char *k, TipoApontadorPAT *t);
int pesquisa(char *k, TipoApontadorPAT t,int *QuantidadeDeComp);
int ComparaPalavra(char *palavraNaArvore, char *palavraRec);
int maior(int a, int b);

