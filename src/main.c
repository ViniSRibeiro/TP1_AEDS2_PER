/*
	Grupo: Return NULL;
	Eduardo Vin�cius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vin�cius Tadeu Silva Ribeiro 2670
*/

#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "TADTST.h"
#include <time.h>

void main()
{
	int arvoreAtiva = 1; //Inteiro que salva a arvore ativa, 1 = TST, 2 = PATRICIA;
	tipoApontadorTST tst; //Cria a TST;
	TipoApontadorPAT pat; //Cria a Patricia;

	inicializaTST(&tst); //Inicializa a TST;
	InicializarPAT(&pat); //Inicializa a Pat;

	int x = 0; //X sera usado em scanf;
	while (1)
	{
		imprimeMenuAtual(arvoreAtiva);
		scanf("%d", &x);
		if(x == 1) //Muda Arvore Ativa;
		{
			EscolheArvore(&arvoreAtiva);
		}
		else if (x == 2) //Inserir Palavra manualmente
		{
			EscolheInserir(&tst, &pat, arvoreAtiva);
		}
		else if (x == 3) //Pesquisar Palavra
		{
			EscolheProcurar(tst, pat, arvoreAtiva);
		}
		else if (x == 4) //Imprimir arvore em ordem Alfabetica
		{
			EscolheOrdem(tst, pat, arvoreAtiva);
		}
		else if (x == 5) //Numero de palavras na Arvore
		{
			EscolheContar(tst,pat, arvoreAtiva);
		}
		else if (x == 6) //Inser��o por arquivo
		{
			EscolheInserirArquivo(&tst, &pat, arvoreAtiva);
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
