/*
	Grupo: Return NULL;
	Eduardo Vinícius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vinícius Tadeu Silva Ribeiro 2670
*/
#ifndef TADTST
#define TADTST

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#define MAX 60 //Maximo numero de caracteres em uma palavra;

typedef struct TipoTST* tipoApontadorTST; //Ponteiro para No TST;

typedef struct TipoTST //um nó de Arvore TST
{
	char data; //Charactere guardado;
	unsigned FimDeString : 1; //Retorna Verdadeiro caso for o fim da palavra;
	tipoApontadorTST esq, meio, dir; //Apontadores para esquerda/Meio/Direita;
}TipoTST;

// A utility function to create a new ternary search tree node.
void inicializaTST(tipoApontadorTST *tst); //Inicializa a arvore TST como NULL;
TipoTST* criarNo(char data); // Cria um no novo;
void inserirEmTST(tipoApontadorTST *tst); // Usado para pegar a palavra e chamar a função inserirPalavraTST para inserir na arvore. Criado para facilitar a implementação da InserirPalavraTST.
void inserirPalavraTST(tipoApontadorTST *noTST, char *palavra, int *comp);//Insere um no novo e insere um caractere;
void procurarEmTST(tipoApontadorTST TST); //Usado para pegar a palavra, chamar procurarPalavraTST e imprimir na tela se a palavra foi encontrada ou não;
int procurarPalavraTST(tipoApontadorTST noTST, char *palavra, int* comp); //Procura uma palavra na arvore TST, se a palavra existir, retorna 1, caso contrario 0;
void ordemTST(tipoApontadorTST noTST); //usado para criar um buffer e chamar ImprimirOrdemTST, criada para facilitar implementação do ImprimirOrdemTST;
void imprimirOrdemTST(tipoApontadorTST noTST, char* buffer, int altura); //Imprime em ordem as palavras contidas na lista;
void contarEmTST(tipoApontadorTST tst); //Usado para chamar o contarPalavrasTST e imprimir na tela a arvore correta
void contarPalavrasTST(tipoApontadorTST noTST, int *quantidadePalavras); //Conta o numero de palavras existentes;
void inserirArquivoTST(tipoApontadorTST *tst); //Usado para criar as variaveis basicas e abrir o arquivo dicionario, que sera inserido na Arvore TST;

#endif