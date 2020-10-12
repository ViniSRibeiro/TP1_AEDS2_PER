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

typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo{
    TipoNo TipoDeNo;
    union
    {
        struct
        {
            int posicao;
            char letra;
            TipoArvore Esq, Dir;
        }NInterno;
        char Chave[55];
    }NO;
}TipoPatNo;


void InicializaPatricia(TipoArvore *p);
TipoArvore CriaNoInterno (int i,char CarDiferente, TipoArvore *Esq, TipoArvore *Dir);
TipoArvore CriaNoExterno (char *k);
TipoArvore InsereEntre (char *k, TipoArvore *t, int i, char CarDiferente);
int EExterno (TipoArvore p);
TipoArvore Insere(char *k, TipoArvore *t);
int pesquisa(char *k, TipoArvore t, int *qtComp,int *altura);
int ComparaPalavra(char *palavraArvore, char *palavraRecebida);
int maior(int a, int b);
void imprime(TipoArvore p);