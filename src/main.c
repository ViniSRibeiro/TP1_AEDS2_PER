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
		else if (x == 2) //Inserir Palavra
		{
			EscolheInserir(&tst, arvoreAtiva);
		}
		else if (x == 3) //Pesquisar Palavra
		{
			EscolheProcurar(tst, arvoreAtiva);
		}
		else if (x == 4) //Imprimir arvore em ordem Alfabetica
		{
			EscolheOrdem(tst, arvoreAtiva);
		}
		else if (x == 5) //Numero de palavras na Arvore
		{
			EscolheContar(tst, arvoreAtiva);
		}
		else if (x == 6)
		{
			EscolheInserirArquivo(&tst, arvoreAtiva);
		}
		else if (x == 7) //Finalizar Programa
		{
			break;
		}
		else
		{
			printf("Opcao nao esta no menu\n");
			getchar();
		}
	}
	return;
}