/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {Interno, Externo}
TipoNo;

typedef struct TipoPatNo* TipoArvore;  // TipoArvore ponteiro para a patricia
typedef char TipoChave;

typedef struct{
  TipoChave chave; //Palavras 
}TipoDados;

typedef struct TipoPatNo {
  TipoNo tipodeNo; //Tipo que será o no: Interno ou Externo
  union{
    struct{
      int Index;
      TipoArvore Esq, Dir;
    }NInterno ;
    TipoDados Conteudo;
  }NO;
}TipoPatNo;

void inicializaPatricia(TipoArvore *t);

char Bit(char i, TipoChave palavra);

int EExterno(TipoArvore p);

TipoArvore CriaNoInt(int i, TipoArvore *Esq,  TipoArvore *Dir);

TipoArvore CriaNoExt(TipoChave palavra);

void Pesquisa(TipoChave palavra, TipoArvore t);

TipoArvore InsereEntre(TipoChave palavra, TipoArvore *t, int i);

TipoArvore Insere(TipoChave palavra, TipoArvore *t);