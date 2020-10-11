/*
	Grupo: Return NULL;
	Eduardo Vinícius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vinícius Tadeu Silva Ribeiro 2670
*/

#include "menu.h"

void imprimeMenuAtual(int arvoreAtiva) //Função que chama a função correta com o menu sendo utilizado no momento de acordo com a arvore ativa
{
	if (arvoreAtiva == TST) //Checa qual a arvore ativa
	{
		ImprimeMenuTST();
	}
	else
	{
		ImprimeMenuPatricia();
	}
	printf("Escolha uma opcao: ");
	return;
}

void EscolheArvore(int *arvoreAtiva) //Imprime o menu para mudança de arvore e modifica a arvore ativa.
{
	int y;
	printf("|== Arvores Disponiveis ==|\n");
	printf("|1) Arvore TST            |\n");
	printf("|2) Arvore Patricia       |\n");
	printf("|=========================|\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &y);
	if (y == TST || y == PAT)
	{
		*arvoreAtiva = y;
	}
	else
	{
		printf("Opcao invalida, arvore nao existente\n");
	}
}

void ImprimeMenuPatricia() //Imprime o menu Patricia
{
	printf("|========== Menu Arvore Patricia ==========|\n");
	printf("|1) Alterar Arvore                         |\n");
	printf("|2) Inserir Palavra                        |\n");
	printf("|3) Pesquisar Palavra                      |\n");
	printf("|4) Imprimir arvore em ordem Alfabetica    |\n");
	printf("|5) Numero de palavras na Arvore           |\n");
	printf("|6) Finalizar o Programa                   |\n");
	printf("|==========================================|\n");
}

void ImprimeMenuTST() //Imprime o menu TST
{
	printf("|============ Menu Arvore TST =============|\n");
	printf("|1) Alterar Arvore                         |\n");
	printf("|2) Inserir Palavra                        |\n");
	printf("|3) Pesquisar Palavra                      |\n");
	printf("|4) Imprimir arvore em ordem Alfabetica    |\n");
	printf("|5) Numero de palavras na Arvore           |\n");
	printf("|6) Finalizar o Programa                   |\n");
	printf("|==========================================|\n");
}
