/*
	Grupo: Return NULL;
	Eduardo Vin�cius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vin�cius Tadeu Silva Ribeiro 2670
*/
#include "../headers/TADTST.h"

void inicializaTST(tipoApontadorTST *tst) //Inicializa a arvore TST como NULL;
{
	*tst = NULL; //Devolve a TST como NULL;
	return;
}

void inserirEmTST(tipoApontadorTST *tst) // Usado para pegar a palavra e chamar a fun��o inserirPalavraTST para inserir na arvore. Criado para maior facilidade de implementa��o.
{
	char buffer[MAX]; //Cria um buffer para armazenar a palavra;
	clock_t Ticks[2]; //Cria um vetor de Clock_T para armazenar o time;
	int comp = 0; //Cria um inteiro para armazenar compara��es feitas;

	printf("Digite a palavra desejada: ");
	scanf("%s", buffer); //Pega uma palavra digita pelo usuario;

	Ticks[0] = clock(); //Pega o tempo antes do inicio da fun��o InserirPalavraTST;
	inserirPalavraTST(tst, &buffer, &comp); //Chama a fun��o inserirPalavraTST;
	Ticks[1] = clock(); //Pega o tempo apos o fim da fun��o inserirPalavraTST;

	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Calcula o tempo percorrido em ms;

	printf("Tempo total da CPU para Inserir: %g ms\n", Tempo); //Imprime o tempo necessario;
	printf("O numero total de comparacoes para Inserir uma palavra: %d comparacoes\n", comp); //Imprime o numero de compara��es;
}

void inserirArquivoTST(tipoApontadorTST *tst) {//Insere as Palavras de um arquivo em dicionario
	
	char buffer[MAX]; //Cria um buffer para armazenar a palavra;
	char arquivo[30]; //Cria um buffer para armazenar o nome do arquivo;
	clock_t Ticks[2]; //Cria um vetor de Clock_T para armazenar o time;
	int comp = 0; //Cria um inteiro para armazenar compara��es feitas;
	FILE *dicionario; //Cria um ponteiro para arquivo;

	printf("Digite o nome do arquivo: ");
	scanf("%s", &arquivo);
	strcat(arquivo, ".txt");
	dicionario = fopen(arquivo, "r"); //Abre o arquivo Dicionario;

	if (dicionario == NULL)
	{
		printf("ERRO NA LEITURA\n");
		return;
	}

	Ticks[0] = clock(); //Pega o tempo antes do inicio de come�ar a pegar as palavras do arquivo e chamar inserirPalavraTST;
	while (fgets(buffer, MAX, dicionario) != NULL) //Enquanto o arquivo n�o terminar, ira pegar linha por linha (palavra por palavra) e ira adicionar em buffer;
	{
		char *pos;
		if ((pos = strchr(buffer, '\n')) != NULL) //Remove o \n no final da palavra pega do arquivo antes de inserir na TST;
		{
			*pos = '\0'; //Substitui o \n por \0
		}
		inserirPalavraTST(tst, &buffer, &comp); //Chama o InserirPalavraTST, enviando a arvore, a palavra e os inteiros para memoria e compara��es feitas;

	}
	fclose(dicionario); //Fecha o arquivo dicionario;
	Ticks[1] = clock(); //Pega o tempo apos o fim da inser��o de palavras do arquivo;
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Calcula o tempo percorrido em ms;

	printf("Tempo total da CPU para Inserir: %g ms\n", Tempo);
	printf("O numero total de comparacoes para Inserir por Arquivo: %d comparacoes\n", comp);
}

tipoApontadorTST criarNo(char data) //,unsigned int *bytes) //Retorna um novo no, criado;
{
	tipoApontadorTST aux = (tipoApontadorTST)malloc(sizeof(TipoTST)); //Cria um auxiliar que vai armazenar por enquanto o novo No;
	//printf("%d\n", *memTST);
	aux->data = data; //Insere a data no no;
	aux->FimDeString = 0; //Retorna falso, n�o sendo fim da palavra;
	aux->esq = NULL; //Aponta a esquerda para NULL;
	aux->meio = NULL; //Aponta o meio para NULL;
	aux->dir = NULL; //Aponta a direita para NULL;
	return aux; //Retorna o auxiliar;
}

void inserirPalavraTST(tipoApontadorTST *noTST, char *palavra, int *comp) //Insere uma palavra na arvore TST
{
	(*comp)++; //Adiciona mais um no inteiro de compara��o para o if abaixo, visto que sempre ira comparar

	if (*noTST == NULL) //Verifica se a arvore ou posi��o esta vazia, se estivar, cria um novo No;
	{
		*noTST = criarNo(*palavra); //Cria um no novo na arvore atual, enviando o caractere e o ponteiro de memoria;
	}
	(*comp)++; //Adiciona mais um no inteiro de compara��o para o if abaixo, visto que ira sempre comparar ele tamb�m.

	if ((*noTST)->data > (*palavra))//Se o caractere atual tiver menor valor, o insere na sub-arvore a esquerda;
	{
		inserirPalavraTST(&((*noTST)->esq), palavra, comp); //Chama a fun��o de inser��o, enviando um ponteiro para a esquerda do no atual;
	}
	else if ((*noTST)->data < (*palavra)) //Se o caractere atual tiver valor maior, o insere na sub-arvore a direita;
	{
		(*comp)++; //Adiciona mais um no inteiro de compara��o para esse bloco de ELSE IF, visto que pode entrar ou n�o.

		inserirPalavraTST(&((*noTST)->dir), palavra, comp);//Chama a fun��o de inser��o, enviando um ponteiro para a direita do no atual;
	}
	else //Se o caractere atual tiver valor identico ao da posi��o atual na arvore.
	{
		(*comp)++; //Adiciona mais um no inteiro de compara��o para o else if acima.
		(*comp)++; //Para o IF abaixo.
		if (*(palavra + 1)) //Se tiver mais um caractere na palavra, chama a fun��o para o ponteiro do meio.
		{
			inserirPalavraTST(&((*noTST)->meio), palavra + 1, comp); //Chama a fun��o recursivamente, enviando um ponteiro para o meio do no atual, o proximo caractere, e os inteiros de memoria e compara��o.
		}
		else // Caso seja o ultimo caractere da palavra, finaliza o codigo.
		{
			(*noTST)->FimDeString = 1; //Retorna o fim da String.
		}
	}
	return;
}

void procurarEmTST(tipoApontadorTST tst) //Usado para pegar a palavra, chamar procurarPalavraTST e imprimir na tela se a palavra foi encontrada ou n�o.
{
	char buffer[MAX]; //Cria um buffer para armazenar a palavra;
	clock_t Ticks[2]; //Cria um vetor de Clock_T para armazenar o time;
	int comp = 0; //Cria um inteiro para armazenar compara��es feitas;

	printf("Digite a palavra desejada: ");
	scanf("%s", buffer); //Armazena a palavra desejada para a procura;

	Ticks[0] = clock(); //Pega o tempo antes do inicio da fun��o procurarPalavraTST;
	int y = procurarPalavraTST(tst, &buffer, &comp); //Procura se a palavra esta na TST, se estiver, ira retornar 1, se n�o, 0;
	if (y == 1) //Se y == 1  (A palavra esta na arvore) ele imprime que sim, caso contrario, imprime que n�o esta presente;
	{
		printf("A palavra esta contida na arvore TST\n");
	}
	else
	{
		printf("Erro: A palavra nao esta contida na arvore TST\n");
	}
	Ticks[1] = clock(); //Pega o tempo apos o fim da fun��o procurarPalavraTST;

	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Calcula o tempo percorrido em ms;
	printf("Tempo total da CPU para Pesquisar: %g ms\n", Tempo);
	printf("O numero total de comparacoes para Pesquisar: %d comparacoes\n", comp);
}
int procurarPalavraTST(tipoApontadorTST noTST, char *palavra, int* comp) //Procura uma palavra na arvore TST, se a palavra existir, retorna 1, caso contrario 0;
{
	(*comp)++; //Adiciona mais um no inteiro de compara��o para o if abaixo, visto que sempre ira comparar.
	if (noTST == NULL) //Verifica se a arvore ou n� atual e nulo, se sim, retorna 0;
	{
		return 0;
	}
	(*comp)++; //Adiciona mais um no inteiro de compara��o para o if abaixo, visto que tamb�m ira comparar sempre.
	if ((noTST)->data > *palavra) //Verifica se o caractere contido no n� atual e maior que o caractere da palavra sendo procurada
	{
		return procurarPalavraTST(noTST->esq, palavra, comp); //Se for maior, retorna recursivamente a fun��o atual, com a posi��o para a esquerda;
	}
	else if ((noTST)->data < *palavra) //Verifica se o caractere contido no n� atual e menor que o caractere da palavra sendo procurada
	{
		(*comp)++; //Adiciona mais um no inteiro de compara��o para esse bloco de else IF, visto que pode entrar ou n�o.
		return procurarPalavraTST(noTST->dir, palavra, comp); //Se for menor, retorna recursivamente a fun��o atual, com a posi��o para a direita;
	}
	else //Caso o caractere atual seja igual ao caractere sendo procurado.
	{
		(*comp)++; //Adiciona mais um no inteiro de compara��o para o else if acima.
		(*comp)++; //Para o IF abaixo.

		if (*(palavra + 1) == '\0') //Verifica se o caractere atual e \0, ou seja, fim da String.
		{
			return noTST->FimDeString; //Se for, retorna o FimDaString (1)
		}
		return procurarPalavraTST(noTST->meio, palavra + 1, comp); //Caso n�o seja, retorna recursivamente a fun��o atual com a proxima posi��o central e o proximo caractere.
		
	}
}

void ordemTST(tipoApontadorTST noTST) //Apenas usado para criar um buffer e chamar a impress�o da TST
{
	char buffer[MAX]; //Cria um buffer para armazenar palavras
	imprimirOrdemTST(noTST, buffer, 0); //Chama a fun��o ImprimirOrdemTST, enviando a TST, o buffer e a altura inicial (0);
}

void imprimirOrdemTST(tipoApontadorTST noTST, char* buffer, int altura) //Ira imprimir a arvore TST em um sistema parecido com a fun��o de ORDEM;
{
	if (noTST != NULL)
	{
		/*
		Esquerda -> Guarda o caractere -> Meio -> Direita, de forma recursiva.
		*/

		imprimirOrdemTST(noTST->esq, buffer, altura); //Anda pela subarvore a esquerda;

		buffer[altura] = noTST->data; //Guarda o charactere desse no no buffer;
		
		if (noTST->FimDeString) //Checa se e o fim da String, caso seja fim, finaliza o buffer com um \0 e imprime ele;
		{
			buffer[altura + 1] = '\0';
			printf("-> %s\n", buffer);
		}

		imprimirOrdemTST(noTST->meio, buffer, altura + 1); //Anda pela subarvore do meio (com caracter igual);

		imprimirOrdemTST(noTST->dir, buffer, altura); //Anda pela subarvore da direita;
	}
	return;
}

void contarEmTST(tipoApontadorTST tst)//Usado para chamar o contarPalavrasTST e imprimir na tela a arvore correta
{
	int quantidadePalavras = 0; //Cria um inteiro para ver o numero de palavras existentes

	contarPalavrasTST(tst, &quantidadePalavras); //Chama a fun��o contarPalavrasTST, enviando a TST e o inteiro;

	printf("Possuem %d palavras na arvore TST\n", quantidadePalavras);
}

void contarPalavrasTST(tipoApontadorTST noTST, int *quantidadePalavras) //Conta o numero de palavras existentes;
{
	if (noTST != NULL)
	{

		contarPalavrasTST(noTST->esq, quantidadePalavras); //Anda pela subarvore a esquerda;

		if (noTST->FimDeString) //Checa se e o fim da String, caso seja fim, Adiciona +1 em quantidadePalavras;
		{
			*quantidadePalavras += 1; //Adiciona mais um no numero de palavras;
		}

		contarPalavrasTST(noTST->meio, quantidadePalavras); //Anda pela subarvore do meio (com caracter igual);

		contarPalavrasTST(noTST->dir, quantidadePalavras); //Anda pela subarvore da direita;
	}
	return;

}
