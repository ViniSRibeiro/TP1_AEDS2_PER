/*
	Grupo: Return NULL;
	Eduardo Vinícius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vinícius Tadeu Silva Ribeiro 2670
*/

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "TADTST.h"

void main()
{
	int arvoreAtiva = 1; //Inteiro que salva a arvore ativa, 1 = TST, 2 = PATRICIA;
	tipoApontadorTST tst; //Cria a TST;
	//TipoApontadorPAT pat;
	inicializaTST(&tst); //Inicializa a TST;
	int x = 0; //X sera usado em scanf;
	while (1)
	{
		imprimeMenuAtual(arvoreAtiva);
		scanf("%d", &x);
		if(x == 1) //Muda Arvore Ativa;
		{
			EscolheArvore(&arvoreAtiva);
		}
		if (x == 2) //Inserir Palavra
		{
			if (arvoreAtiva == TST)
			{
				inserirEmTST(&tst);
			}
			else
			{
				//inserirPalavraPAT(&pat, &palavra);
			}
		}
		if (x == 3) //Pesquisar Palavra
		{
			if (arvoreAtiva == TST)
			{
				procurarEmTST(tst);
			}
			else
			{
				//procurarPalavraPAT(&pat, &palavra);
			}
		}
		if (x == 4) //Imprimir arvore em ordem Alfabetica
		{
			if (arvoreAtiva == TST)
			{
				ordemTST(tst);
			}
			else
			{
				//imprimirOrdemPAT(pat);
			}
		}
		if (x == 5) //Numero de palavras na Arvore
		{
			if (arvoreAtiva == TST)
			{
				contarEmTST(tst);
			}
			else
			{
				//y = contarPalavrasPAT(pat);
			}
		}
		if (x == 6) //Finalizar Programa
		{
			break;
		}
	}
	return;
}
