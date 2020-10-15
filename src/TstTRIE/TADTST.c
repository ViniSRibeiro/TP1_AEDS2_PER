/*
	Grupo: Return NULL;
	Eduardo Vin�cius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vin�cius Tadeu Silva Ribeiro 2670
*/
#include "TADTST.h"

void inicializaTST(tipoApontadorTST *tst) //Inicializa a arvore TST como NULL;
{
	*tst = NULL;
	return;
}
tipoApontadorTST criarNo(char data) //Retorna um novo no, criado;
{
	tipoApontadorTST aux = (tipoApontadorTST) malloc(sizeof(TipoTST)); //Cria um auxiliar que vai armazenar por enquanto o novo No;
	aux->data = data; //Insere a data no no;
	aux->FimDeString = 0; //Retorna falso, n�o sendo fim da palavra;
	aux->esq = NULL; //Aponta a esquerda para NULL;
	aux->meio = NULL; //Aponta o meio para NULL;
	aux->dir = NULL; //Aponta a direita para NULL;
	return aux; //Retorna o auxiliar;
}

void inserirEmTST(tipoApontadorTST *tst) // Usado para pegar a palavra e chamar a fun��o inserirPalavraTST para inserir na arvore. Criado para maior facilidade de implementa��o.
{
	char buffer[MAX];
	printf("Digite a palavra desejada: ");
	scanf("%s", &buffer);
	inserirPalavraTST(tst, &buffer);
}

void inserirArquivoTST(tipoApontadorTST *tst) {//Insere as Palavras de um arquivo em dicionario
	FILE *dicionario;
	dicionario = fopen("dicionario.txt", "r");
	char buffer[MAX];
	int i = 0;
	while (fgets(buffer, MAX, dicionario) != NULL)
	{
		char *pos;
		if ((pos = strchr(buffer, '\n')) != NULL)
		{
			*pos = '\0';
		}
		inserirPalavraTST(tst, &buffer);

	}
	/*while ((fgetc(dicionario)) != EOF) {
		if (i == 0) {
			rewind(dicionario);
			i++;
		}
		fscanf(dicionario, "%s", buffer);
		printf("%s\n", buffer);
		inserirPalavraTST(tst, &buffer);
	}*/
	fclose(dicionario);
}

void inserirPalavraTST(tipoApontadorTST *noTST, char *palavra) //Insere uma palavra na arvore TST
{
	if (*noTST == NULL) //Verifica se a arvore ou posi��o esta vazia, se estivar, cria um novo No;
	{
		*noTST = criarNo(*palavra); //Cria um no novo na arvore atual;
	}
	if ((*noTST)->data > (*palavra))//Se o caractere atual tiver menor valor, o insere na sub-arvore a esquerda;
	{
		inserirPalavraTST(&((*noTST)->esq), palavra); //Chama a fun��o inserir para a esquerda;
	}
	else if ((*noTST)->data < (*palavra)) //Se o caractere atual tiver valor maior, o insere na sub-arvore a direita;
	{
		inserirPalavraTST(&((*noTST)->dir), palavra);//Chama a fun��o inserir para a direita;
	}
	else //Se o caractere atual tiver valor identico ao da posi��o atual na arvore.
	{
		if (*(palavra + 1))
		{
			inserirPalavraTST(&((*noTST)->meio), palavra + 1);
		}
		else // Caso seja o ultimo caractere da palavra;
		{
			(*noTST)->FimDeString = 1; //Retorna o fim da String.
		}
	}
}

void procurarEmTST(tipoApontadorTST tst) //Usado para pegar a palavra, chamar procurarPalavraTST e imprimir na tela se a palavra foi encontrada ou n�o.
{
	char buffer[MAX];
	printf("Digite a palavra desejada: ");
	scanf("%s", &buffer);

	int y = procurarPalavraTST(tst, &buffer);
	if (y == 1)
	{
		printf("A palavra esta contida na arvore TST\n");
	}
	else
	{
		printf("Erro: A palavra nao esta contida na arvore TST\n");
	}
}
int procurarPalavraTST(tipoApontadorTST noTST, char *palavra) //Procura uma palavra na arvore TST, se a palavra existir, retorna 1, caso contrario 0;
{
	if (noTST == NULL) //Verifica se a arvore ou n� atual e nulo, se sim, retorna 0;
	{
		return 0;
	}
	if ((noTST)->data > *palavra) //Verifica se o caractere contido no n� atual e maior que o caractere da palavra sendo procurada
	{
		return procurarPalavraTST(noTST->esq, palavra); //Se for maior, retorna recursivamente a fun��o atual, com a posi��o para a esquerda;
	}
	else if ((noTST)->data < *palavra) //Verifica se o caractere contido no n� atual e menor que o caractere da palavra sendo procurada
	{
		return procurarPalavraTST(noTST->dir, palavra); //Se for menor, retorna recursivamente a fun��o atual, com a posi��o para a direita;
	}
	else //Caso o caractere atual seja igual ao caractere sendo procurado.
	{
		if (*(palavra + 1) == '\0') //Verifica se o caractere atual e \0, ou seja, fim da String.
		{
			return noTST->FimDeString; //Se for, retorna o FimDaString (1)
		}
		return procurarPalavraTST(noTST->meio, palavra + 1); //Caso n�o seja, retorna recursivamente a fun��o atual com a proxima posi��o central e o proximo caractere.
		
	}
}

void ordemTST(tipoApontadorTST noTST) //Apenas usado para criar um buffer e chamar a impress�o da TST
{
	char buffer[MAX];
	imprimirOrdemTST(noTST, buffer, 0);
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
			printf("%s\n", buffer);
		}

		imprimirOrdemTST(noTST->meio, buffer, altura + 1); //Anda pela subarvore do meio (com caracter igual);

		imprimirOrdemTST(noTST->dir, buffer, altura); //Anda pela subarvore da direita;
	}
	return;
}

void contarEmTST(tipoApontadorTST tst)//Usado para chamar o contarPalavrasTST e imprimir na tela a arvore correta
{
	int quantidadePalavras = 0;
	contarPalavrasTST(tst, &quantidadePalavras);
	printf("Possuem %d palavras na arvore TST\n", quantidadePalavras);
}
void contarPalavrasTST(tipoApontadorTST noTST, int *quantidadePalavras) //Conta o numero de palavras existentes;
{
	if (noTST != NULL)
	{

		contarPalavrasTST(noTST->esq, quantidadePalavras); //Anda pela subarvore a esquerda;

		if (noTST->FimDeString) //Checa se e o fim da String, caso seja fim, finaliza o buffer com um \0 e imprime ele;
		{
			*quantidadePalavras += 1;
			//printf("%d\n", *quantidadePalavras);
		}

		contarPalavrasTST(noTST->meio, quantidadePalavras); //Anda pela subarvore do meio (com caracter igual);

		contarPalavrasTST(noTST->dir, quantidadePalavras); //Anda pela subarvore da direita;
	}
	return;
}
//Entrada Teste: Arroz, Chocolate, Amendoin, Traveseiro, Comida, Zebra