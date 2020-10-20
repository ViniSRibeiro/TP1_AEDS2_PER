/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
#ifndef TADPAT
#define TADPAT

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MaxTamPalavra 60 //Maior palavra do mundo tem 46, mas vamos colocar 60, vai que atualiza kk


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
void InicializarPAT(TipoApontadorPAT *pAt); //Faz a inicialização da árvore Patricia
void inserirEmPAT(TipoApontadorPAT *pat); // Usado para pegar a palavra e chamar a função inserirPAT para inserir na arvore. Criado para maior facilidade de implementação.
void inserirArquivoPAT(TipoApontadorPAT *pat); //Insere as Palavras de um arquivo em dicionario
TipoApontadorPAT CriaNoInterno(int i, char palavra, TipoApontadorPAT *Esq,  TipoApontadorPAT *Dir); // Funçao que cria um nó interno
TipoApontadorPAT CriaNoExterno (char *palavra); // Funçao que cria um nó externo
TipoApontadorPAT InsereEntre (char *palavra, TipoApontadorPAT *pAt, int i, char CarQueDiferencia, int* comp);//Função faz a inserção entre dois nós já existentes.
int EExterno (TipoApontadorPAT pAt); //Função que retorna o tipo do nó 1 caso seja externo 0 caso seja interno.
TipoApontadorPAT InserePAT(char *palavra, TipoApontadorPAT *pAt, int* comp); //Faz a inserção da palavra, utiliza funções auxiliares para realizar essa tarefa.
int maiorPalavra(char *palavraA, char *palavraB, int* comp); //Retorna um inteiro correspondendo a palavra de maior tamanho.
int ComparaPalavra(char *palavraNaArvore, char *palavraSerInserida, int* comp);  //Faz a comparação entre duas palavras e retorna o indice que elas diferência uma da outra.
int maiorCaracter(int caracterPalavraA, int caracterPalavraB, int* comp); //Faz a comparação entre caracteres
void contarEmPAT(TipoApontadorPAT pat);//Usado para chamar o QuantidadePalavras e imprimir na tela a arvore correta
void quantidadePalavras(TipoApontadorPAT pAt,int *nNo); //Função usada para determinar a quantidade de palavras presentes na árvore.
void procurarEmPAT(TipoApontadorPAT pat); //Usado para pegar a palavra, chamar pesquisarPAT e imprimir na tela se a palavra foi encontrada ou não.
int pesquisaPAT(char *palavra,TipoApontadorPAT pAt,int *nComparacao); //Função utilizada para pesquisar palavras nas Trie Patricia, retorna 1 para palavra presente e 0 para não presente.
void imprimePAT(TipoApontadorPAT p); //Função de impressao da patricia

#endif