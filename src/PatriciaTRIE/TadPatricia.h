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
#define MaxTamPalavra 50 //Maior palavra do mundo tem 46, mas vamos colocar 50, vai que atualiza kk


typedef enum
{
    Interno,Externo
}TipoNo; //Enumeração interno = 0 e externo = 1;

typedef struct TipoNoPAT* TipoApontadorPAT; //Modificação de nome para melhor entedimento no apontamento. 

typedef struct TipoNoPAT //Estrutura da patricia
{
    TipoNo tipoDeNo;  //Identidica o tipo de nó: interno ou externo.
    union
    {
        struct
        {
            int i; //posição de diferença
            char caracter; //Caracter que difere
            TipoApontadorPAT Esq, Dir; //Apontadores para nós esquerdo e direito.
        }NInterno;  //Nó interno
        char Chave[MaxTamPalavra]; //Chave armazenada no nó externo.
    }NO; //Nó completo.
}TipoNoPAT; //Patricia.


//Funções utilizadas para manipular a patricia.
void InicializarPAT(TipoApontadorPAT *pAt);
TipoApontadorPAT CriaNoInterno(int i, char palavra, TipoApontadorPAT *Esq,  TipoApontadorPAT *Dir);
TipoApontadorPAT CriaNoExterno (char *palavra); 
TipoApontadorPAT InsereEntre (char *palavra, TipoApontadorPAT *pAt, int i, char CarQueDiferencia);//vvv
int EExterno (TipoApontadorPAT pAt);
TipoApontadorPAT Insere(char *palavra, TipoApontadorPAT *pAt);
int maiorPalavra(char *palavraA, char *palavraB);
int ComparaPalavra(char *palavraNaArvore, char *palavraSerInserida);
int maiorCaracter(int caracterPalavraA, int caracterPalavraB);
void quantidadePalavras(TipoApontadorPAT pAt,int *nNo);
int pesquisaPAT(char *palavra,TipoApontadorPAT pAt,int *nComparacao);
void imprimePAT(TipoApontadorPAT p);