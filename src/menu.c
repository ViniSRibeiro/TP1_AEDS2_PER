/*
	Grupo: Return NULL;
	Eduardo Vin�cius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vin�cius Tadeu Silva Ribeiro 2670
*/

#include "menu.h"

void imprimeMenuAtual(int arvoreAtiva) //Fun��o que chama a fun��o correta com o menu sendo utilizado no momento de acordo com a arvore ativa
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

void EscolheArvore(int *arvoreAtiva) //Imprime o menu para mudan�a de arvore e modifica a arvore ativa.
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
	printf("|6) Insercao por arquivo Dicionario        |\n");
	printf("|7) Finalizar o Programa                   |\n");
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
	printf("|6) Insercao por arquivo Dicionario        |\n");
	printf("|7) Finalizar o Programa                   |\n");
	printf("|==========================================|\n");
}

void EscolheInserir(tipoApontadorTST *tst, int arvoreAtiva) //Criado para facilitar a implementa��o da fun��o inserir, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
{
	if (arvoreAtiva == TST)
	{
		inserirEmTST(tst);
	}
	else
	{
		//inserirPalavraPAT(pat);
	}
}
void EscolheProcurar(tipoApontadorTST tst, int arvoreAtiva) //Criado para facilitar a implementa��o da fun��o Procurar, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
{
	if (arvoreAtiva == TST)
	{
		procurarEmTST(tst);
	}
	else
	{
		//procurarPalavraPAT(&pat);
	}
}
void EscolheOrdem(tipoApontadorTST tst, int arvoreAtiva) //Criado para facilitar a implementa��o da fun��o Imprimir em Ordem Alfabetica, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
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
void EscolheContar(tipoApontadorTST tst, int arvoreAtiva) //Criado para facilitar a implementa��o da fun��o Contar numero de palavras, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
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
void EscolheInserirArquivo(tipoApontadorTST *tst, int arvoreAtiva) //Criado para facilitar a implementa��o da fun��o inserir por arquivo, ira verificar a arvore ativa (TST ou Patricia) e selecionar a correta)
{
	if (arvoreAtiva == TST)
	{
		inserirArquivoTST(tst);
	}
	else
	{
		//inserirPalavraPAT(pat);
	}
}