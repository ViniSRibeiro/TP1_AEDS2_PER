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

typedef enum {Interno, Externo}TipoNo;

typedef struct TipoPatNo* TipoArvore;  // TipoArvore ponteiro para a patricia
typedef char* TipoChave; //char* para TioChave, novo nome 

typedef struct{
  TipoChave Chave; //Palavras 
}TipoDados;

typedef struct TipoPatNo {
  TipoNo TipoDeNo; //Tipo que será o no: Interno ou Externo
  union{
    struct{
      int Index;
      TipoArvore Esq, Dir;
    }NInterno ;
    TipoDados Conteudo;
  }NO;
}TipoPatNo;

void inicializaPatricia(TipoArvore *t); //Inicializa o pontiero para a arvore com valor NULL
void ImprimePatricia(TipoArvore t);//Imprime a árvore PATRICIA

int EExterno(TipoArvore p); //Verifica se o nó passado como parâmetro é externo, retornando 1 se for ou 0 se não for
TipoArvore CriaNoExt(TipoChave palavra); //Realiza a criação de um nó externo
TipoArvore CriaNoInt(int i, TipoArvore *Esq,  TipoArvore *Dir); //Realiza a criação de um nó interno
// char Bit(char i, char palavra);
TipoArvore InsereEntre(TipoChave palavra, TipoArvore *t, int i);

// TipoArvore Insere(TipoChave palavra, TipoArvore *t);
// TipoArvore Pesquisa(TipoChave palavra, TipoArvore t); //Pesquisa uma dada chave na árvore, retornando o endereço de seu Nó se encontrar ou NULL se não encontrar


