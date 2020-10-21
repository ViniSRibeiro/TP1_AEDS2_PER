/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
#include "../headers/TadPatricia.h"

void InicializarPAT(TipoApontadorPAT *pAt){ //Faz a inicialização da árvore Patricia
    (*pAt) = NULL;                          //Inicializa o ponteiro como nulo
}

TipoApontadorPAT InsereEntre (char *k, TipoApontadorPAT *pAt, int i, char CarQueDiferencia, int *comp){ //Função faz a inserção entre dois nós já existentes.
    
    TipoApontadorPAT pAtaux; //Criação de ponteiro auxiliar.
	(*comp)++; //Adiciona mais um para a comparação;
    if( EExterno(*pAt) || i < (*pAt)->NO.NInterno.i) { //condição: Se o no apontado é externo OU se o indice que difere é menor que O indice no do interno.
        
        pAtaux = CriaNoExterno(k);                      //pAtaux recebe a criação de um no externo. 
		(*comp)++;									    //Adiciona mais um para a comparação;
        if (k[i] < CarQueDiferencia){                   //comparação entre o indice da palavra inserida na posição que diferÊncia ser menor que o caracter que caracter interno.
            return (CriaNoInterno(i, CarQueDiferencia, &pAtaux, pAt));   //Faz a criação do no interno
        }
        else{
            return (CriaNoInterno(i, CarQueDiferencia,pAt, &pAtaux));  //Faz a criação do no interno
        }

    }
    else
    {
		(*comp)++; //Adiciona mais um para a comparação;
        if(k[(*pAt)->NO.NInterno.i] >= (*pAt)->NO.NInterno.caracter) //Faz a comparação da palavra no indice do no interno e compara com o caracter interno
            (*pAt)->NO.NInterno.Dir = InsereEntre(k,&((*pAt)->NO.NInterno.Dir),i,CarQueDiferencia, comp); //Faz o ponteiro direito receber a inserção a direita.
        else
            (*pAt)->NO.NInterno.Esq = InsereEntre(k,&((*pAt)->NO.NInterno.Esq),i,CarQueDiferencia, comp); //Faz o ponteiro esquerdo receber a inserção a esquerda.
        return (*pAt);
    }
}

TipoApontadorPAT CriaNoInterno(int i, char CarQueDiferencia, TipoApontadorPAT *Esq,  TipoApontadorPAT *Dir){ // Funçao que cria um nó interno

    TipoApontadorPAT pAtaux; //Criação de uma variavel auxiliar do tipo TipoApontadorPAT.
    pAtaux = (TipoApontadorPAT)malloc(sizeof(TipoNoPAT)); //Alocação de memória para o apontador.
    pAtaux->tipoDeNo = Interno;   //Relaciona ele sendo um tipo de nó interno.
    pAtaux->NO.NInterno.Esq = *Esq; //Direciona o ponteiro a apontar para à Esq.
    pAtaux->NO.NInterno.Dir = *Dir; //Direciona o ponteiro a apontar para à Dir.
    pAtaux->NO.NInterno.i = i;  //Adiciona o indice que diferÊncia as palavras. 
    pAtaux->NO.NInterno.caracter = CarQueDiferencia; // Adiciona ao nó interno o caracter que diferencia as palavras.

    return pAtaux;  //Retorno do ponteiro.
}

int EExterno (TipoApontadorPAT pAt){//Função que retorna o tipo do nó 1 caso seja externo 0 caso seja interno.
    return (pAt->tipoDeNo == Externo);  //Comapração feita já no return.
}

TipoApontadorPAT CriaNoExterno (char *palavra){//Funçao cria um no externo para armazenar a palavra.

    TipoApontadorPAT pAtaux;  //Criação de uma variavel auxiliar do tipo TipoApontadorPAT.
    pAtaux = (TipoApontadorPAT) malloc(sizeof(TipoNoPAT)); //Alocação de memória para o apontador.
    pAtaux->tipoDeNo = Externo;  //Relaciona ele sendo um tipo de nó externo.
    strcpy(pAtaux->NO.Chave, palavra); //Faz a copia da palavra inserida para ele.
    return pAtaux;   //Retorna o ponteiro.
}

void inserirEmPAT(TipoApontadorPAT *pat) // Usado para pegar a palavra e chamar a função inserirPAT para inserir na arvore. Criado para maior facilidade de implementação.
{
	char buffer[MaxTamPalavra]; //Cria um buffer para armazenar a palavra;
	clock_t Ticks[2]; //Cria um vetor de Clock_T para armazenar o time;
	int comp = 0; //Cria um inteiro para armazenar comparações feitas;

	printf("Digite a palavra desejada: ");
	scanf("%s", &buffer); //Pega uma palavra digita pelo usuario;

	Ticks[0] = clock(); //Pega o tempo antes do inicio da função InserePAT;
	*pat = InserePAT(buffer, pat, &comp);
	Ticks[1] = clock(); //Pega o tempo apos o fim da função InserePAT;

	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Calcula o tempo percorrido em ms;
	printf("Tempo total da CPU para Inserir: %g ms\n", Tempo);
	printf("O numero total de comparacoes para Inserir uma palavra: %d comparacoes\n", comp);
}
void inserirArquivoPAT(TipoApontadorPAT *pat) {//Insere as Palavras de um arquivo em dicionario

	char buffer[MaxTamPalavra]; //Cria um buffer para armazenar a palavra;
	char arquivo[30]; //Cria um buffer para armazenar o nome do arquivo;
	clock_t Ticks[2]; //Cria um vetor de Clock_T para armazenar o time;
	int comp = 0; //Cria um inteiro para armazenar comparações feitas;
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

	Ticks[0] = clock(); //Pega o tempo antes do inicio de começar a pegar as palavras do arquivo e chamar InserePat;
	while (fgets(buffer, MaxTamPalavra, dicionario) != NULL) //Enquanto o arquivo não terminar, ira pegar linha por linha (palavra por palavra) e ira adicionar em buffer;
	{
		char *pos;
		if ((pos = strchr(buffer, '\n')) != NULL) //Remove o \n no final da palavra pega do arquivo antes de inserir na TST;
		{
			*pos = '\0'; //Substitui o \n por \0
		}
		*pat = InserePAT(buffer, pat, &comp); //Chama o InserePat, enviando a arvore, a palavra e os inteiros para memoria e comparações feitas;

	}
	fclose(dicionario); //Fecha o arquivo dicionario;
	Ticks[1] = clock(); //Pega o tempo apos o fim da inserção de palavras do arquivo;
	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Calcula o tempo percorrido em ms;
	printf("Tempo total da CPU para Inserir: %g ms\n", Tempo);
	printf("O numero total de comparacoes para Inserir por Arquivo: %d comparacoes\n", comp);
}


TipoApontadorPAT InserePAT(char *palavra, TipoApontadorPAT *pAt, int* comp) {  //Faz a inserção da palavra, utiliza funções auxiliares para realizar essa tarefa.

    TipoApontadorPAT pAtaux;  //Criação de uma variavel auxiliar do tipo TipoApontadorPAT.
    int i,maiorValor;  // Criação de duas variaveis do tipo int: i e maiorValor. 
	(*comp)++; //Adiciona uma comparação para baixo
    if(*pAt == NULL){  // Se a arvore estiver vazia, cai nessa condição, sendo a primeira inserção na arvore.
        return CriaNoExterno(palavra);      //Cria no Externo e preenche com a palavra de entrada.
    }  
    else{                             //Caso o pAt não seja nulo. 
        pAtaux = *pAt;                //pAtaux recebe o endereço do ponteiro de entrada.
        while (!EExterno(pAtaux)) {   //Enquando a função retornar diferente de EXTERNO. 
			(*comp)++; //Comparação do While
			(*comp)++; //Mais uma comparação
			if (strlen(palavra) >= pAtaux->NO.NInterno.i && palavra[pAtaux->NO.NInterno.i] < (pAtaux)->NO.NInterno.caracter){ //Comapração de tamanho, Tamanho da palavra >= indice armazenado no nó interno  e sendo menor que o caracter que difere             palavra >= i < carDiferente
                pAtaux = pAtaux->NO.NInterno.Esq;      //pAtaux recebe o endereço do nó Esquerdo.
            } else {                                   // caso contrário.
                pAtaux = pAtaux->NO.NInterno.Dir;      //pAtaux recebe o endereço do nó Direito.
            }
        }
        i = ComparaPalavra((pAtaux)->NO.Chave, palavra, comp);     //Faz a comparação entre as palavras, ou seja, retorna o primeiro indice que diferencia as palavras.
		(*comp)++; //Adiciona mais uma comparação
		if(i<0){
            //printf("PALAVRA PRESENTE NA ARVORE\n");                                    
            return(*pAt);                              // se i indice for menor que zero retona o pAt, ocorre quando a palavra a ser inserida já está na árvore.   
        }
        
        maiorValor = maiorCaracter(palavra[i],pAtaux->NO.Chave[i], comp); //A variável maiorValor, recebe o maior inteiro que correponde a comparação entre os caracteres que diferencia uma palavra da outra.
        return InsereEntre(palavra,pAt,i,maiorValor, comp);       // Faz a inserção interna no nó. 
    }
}
int maiorPalavra(char *palavraA, char *palavraB, int* comp){ //Retorna um inteiro correspondendo a palavra de maior tamanho.
	(*comp)++;									  //Adiciona mais um para a comparação;
	if (strlen(palavraA) >= strlen(palavraB))     //Faz a comparação entre duas palavras utilizado à função strlen para determinar qual é a mior palavra.
        return strlen(palavraA);                  //Caso que a palavraA é maior.
    else
        return strlen(palavraB);                  // Caso que a palavraB é maior.
}

int ComparaPalavra(char *palavraNoArvore, char *palavraSerInserida, int *comp){ //Faz a comparação entre duas palavras e retorna o indice que elas diferência uma da outra.
    
    int i=0,tamanho; //Criação de duas variáveis do tipo int: i e tamanho. 
    tamanho = maiorPalavra(palavraNoArvore,palavraSerInserida, comp); //Tamanho receber o valor da maior paralavra.

    for( i=0; i<=tamanho; i++)    //Função for usada para percorrer os array's de 0 até tamanho.
    {
		(*comp)++;										 //Comparação do FOR;
		(*comp)++;										 //Adiciona mais um para a comparação;
        if(palavraNoArvore[i] != palavraSerInserida[i])  //Comparação indice à indice para determinar o primeiro i que diferência ambas palavras.
            return i;                                    //retorna o i que diferência.
    }
    return -1;                                      //Retonra o valor de -1 caso as palavras sejão iguais.
}

int maiorCaracter(int caracterPalavraA, int caracterPalavraB, int *comp){ //Faz a comparação entre caracteres
	(*comp)++;												   //Adiciona mais um para a comparação;
	if(caracterPalavraA > caracterPalavraB)                    
        return caracterPalavraA;                               //Retorna o ASCII do do caracterPalavraA, caso seja maior.
    else
        return caracterPalavraB;                               //Retorna o ASCII do do caracterPalavraB, caso seja maior.
}

void contarEmPAT(TipoApontadorPAT pat)//Usado para chamar o QuantidadePalavras e imprimir na tela a arvore correta
{
	int qPalavras = 0; //Cria um inteiro para ver o numero de palavras existentes

	quantidadePalavras(pat, &qPalavras); //Chama a função quantidadePalavras, enviando a patricia e o inteiro;

	printf("Possuem %d palavras na arvore PAT\n", qPalavras);
}

void quantidadePalavras(TipoApontadorPAT pAt,int *nNo)      //Função usada para determinar a quantidade de palavras presentes na árvore.
{
    if( pAt != NULL && EExterno(pAt) == 0){                 // Condição, caso o ponterio seja diferente de nulo e o nó apontado seja interno.
        quantidadePalavras(pAt->NO.NInterno.Esq, nNo);      // "Caminha" para a Esquerda.
        quantidadePalavras(pAt->NO.NInterno.Dir, nNo);      //"Caminha" para a Direita.
    }
    else if(EExterno(pAt) == 1)                           //Caso que encontra um nó externo.
        (*nNo)++;                                         // Soma mais um no valor da variável nNo.
}

void imprimePAT(TipoApontadorPAT p){  //Função de impressa da patricia
    if(p != NULL && EExterno(p) == 0){   //Condição, caso o ponterio seja diferente de nulo e o nó apontado seja interno.
        imprimePAT(p->NO.NInterno.Esq);  //"caminha" para à esquerda.
        imprimePAT(p->NO.NInterno.Dir);  //"caminha" para à direita.
        return;                          //Parada da função recursiva.
    }else if (EExterno(p) == 1)
    {
        printf("-> %s \n",p->NO.Chave);         //Quando desempilha a recursão, vai mostrando os valores correspondente aos nós externos. 
    }
    
}

void procurarEmPAT(TipoApontadorPAT pat) //Usado para pegar a palavra, chamar pesquisarPAT e imprimir na tela se a palavra foi encontrada ou não.
{
	char buffer[MaxTamPalavra]; //Cria um buffer para armazenar a palavra;
	clock_t Ticks[2]; //Cria um vetor de Clock_T para armazenar o time;
	int comp = 0; //Cria um inteiro para armazenar comparações feitas;

	printf("Digite a palavra desejada: ");
	scanf("%s", &buffer); //Armazena a palavra desejada para a procura;

	Ticks[0] = clock(); //Pega o tempo antes do inicio da função pesquisaPAT;
	int y = pesquisaPAT(&buffer,pat, &comp); //Procura se a palavra esta na TST, se estiver, ira retornar 1, se não, 0;
	if (y == 1) //Se y == 1  (A palavra esta na arvore) ele imprime que sim, caso contrario, imprime que não esta presente;
	{
		printf("A palavra esta contida na arvore PAT\n");
	}
	else
	{
		printf("Erro: A palavra nao esta contida na arvore PAT\n");
	}
	Ticks[1] = clock(); //Pega o tempo apos o fim da função pesquisaPAT;

	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Calcula o tempo percorrido em ms;
	printf("Tempo total da CPU para Pesquisar: %g ms\n", Tempo);
	printf("O numero total de comparacoes para Pesquisar: %d comparacoes\n", comp);
}

int pesquisaPAT(char *palavra,TipoApontadorPAT pAt,int *nComparacao) //Função utilizada para pesquisar palavras nas Trie Patricia, retorna 1 para palavra presente e 0 para não presente.
{
	(*nComparacao) += 1;
	if (pAt == NULL) //Verifica se a arvore ou nó atual e nulo, se sim, retorna 0;
	{
		return 0;
	}
	(*nComparacao) += 1;  //Contador de comparações.
    if(EExterno(pAt) == 1){  //Contição para verificar se o apontador é externo.
        (*nComparacao) += 1;  //Contador de comparações.                   
		if (strcmp(palavra, pAt->NO.Chave) == 0) {  //compara se as palavras são iguais. 
			return 1;       //retorna 1 comprovando que a apalvra procurada está na árvore.
		}
		else
            return 0;    //Retonra 0 caso a palavra não esteja na árvore. 
    }
    (*nComparacao) += 1; //Contador de comparações.
    if(strlen(palavra) < pAt->NO.NInterno.i){ //comapração se a palavra é menor que o indice do no interno.
        pesquisaPAT(palavra, pAt->NO.NInterno.Esq,nComparacao);  //"Caminha" para à esqueda caso condição verdadeira.
        return 0;                                                  //Retonra 0 caso a palavra não esteja na árvore. 
    }
    (*nComparacao) += 1; //Contador de comparações.
    if(palavra[pAt->NO.NInterno.i] >= pAt->NO.NInterno.caracter) // Condição para decidir se o indice da palavra procurada é menor que o caracter armazenado.
        pesquisaPAT(palavra,pAt->NO.NInterno.Dir,nComparacao);   // "caminha" para a direita caso o Caracter que diferencia a palvra sejá maior.
    else
        pesquisaPAT(palavra, pAt->NO.NInterno.Esq,nComparacao); // "caminha" para a esquerda caso o Caracter que diferencia a palvra sejá menor.
}
