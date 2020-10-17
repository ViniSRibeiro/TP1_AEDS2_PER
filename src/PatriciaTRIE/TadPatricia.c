/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
#include "TadPatricia.h"

void InicializarPAT(TipoApontadorPAT *pAt){ //Faz a inicialização da árvore Patricia
    (*pAt) = NULL;                          //Inicializa o ponteiro como nulo
}

TipoApontadorPAT InsereEntre (char *k, TipoApontadorPAT *pAt, int i, char CarQueDiferencia){ //Função faz a inserção entre dois nós já existentes.
    
    TipoApontadorPAT pAtaux; //Criação de ponteiro auxiliar.

    if( EExterno(*pAt) || i < (*pAt)->NO.NInterno.i) { //condição: Se o no apontado é externo OU se o indice que difere é menor que O indice no do interno.
        
        pAtaux = CriaNoExterno(k);                      //pAtaux recebe a criação de um no externo. 
        if (k[i] < CarQueDiferencia){                   //comparação entre o indice da palavra inserida na posição que diferÊncia ser menor que o caracter que caracter interno.
            return (CriaNoInterno(i, CarQueDiferencia, &pAtaux, pAt));   //Faz a criação do no interno
        }
        else{
            return (CriaNoInterno(i, CarQueDiferencia,pAt, &pAtaux));  //Faz a criação do no interno
        }

    }
    else
    {
        if(k[(*pAt)->NO.NInterno.i] >= (*pAt)->NO.NInterno.caracter) //Faz a comparação da palavra no indice do no interno e compara com o caracter interno
            (*pAt)->NO.NInterno.Dir = InsereEntre(k,&((*pAt)->NO.NInterno.Dir),i,CarQueDiferencia); //Faz o ponteiro direito receber a inserção a direita.
        else
            (*pAt)->NO.NInterno.Esq = InsereEntre(k,&((*pAt)->NO.NInterno.Esq),i,CarQueDiferencia); //Faz o ponteiro esquerdo receber a inserção a esquerda.
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

TipoApontadorPAT Insere(char *palavra, TipoApontadorPAT *pAt){  //Faz a inserção da palavra, utiliza funções auxiliares para realizar essa tarefa.

    TipoApontadorPAT pAtaux;  //Criação de uma variavel auxiliar do tipo TipoApontadorPAT.
    int i,maiorValor;  // Criação de duas variaveis do tipo int: i e maiorValor. 
                                      
    if(*pAt == NULL){  // Se a arvore estiver vazia, cai nessa condição, sendo a primeira inserção na arvore.
        return CriaNoExterno(palavra);      //Cria no Externo e preenche com a palavra de entrada.
    }  
    else{                             //Caso o pAt não seja nulo. 
        pAtaux = *pAt;                //pAtaux recebe o endereço do ponteiro de entrada.
        while (!EExterno(pAtaux)) {   //Enquando a função retornar diferente de EXTERNO. 
            if (strlen(palavra) >= pAtaux->NO.NInterno.i && palavra[pAtaux->NO.NInterno.i] < (pAtaux)->NO.NInterno.caracter){ //Comapração de tamanho, Tamanho da palavra >= indice armazenado no nó interno  e sendo menor que o caracter que difere             palavra >= i < carDiferente
                pAtaux = pAtaux->NO.NInterno.Esq;      //pAtaux recebe o endereço do nó Esquerdo.
            } else {                                   // caso contrário.
                pAtaux = pAtaux->NO.NInterno.Dir;      //pAtaux recebe o endereço do nó Direito.
            }
        }
        i = ComparaPalavra((pAtaux)->NO.Chave, palavra);     //Faz a comparação entre as palavras, ou seja, retorna o primeiro indice que diferencia as palavras.
          if(i<0){
            printf("PALAVRA PRESENTE NA ARVORE\n");                                    
            return(*pAt);                              // se i indice for menor que zero retona o pAt, ocorre quando a palavra a ser inserida já está na árvore.   
        }
        
        maiorValor = maiorCaracter(palavra[i],pAtaux->NO.Chave[i]); //A variável maiorValor, recebe o maior inteiro que correponde a comparação entre os caracteres que diferencia uma palavra da outra.
        return InsereEntre(palavra,pAt,i,maiorValor);       // Faz a inserção interna no nó. 
    }
}
int maiorPalavra(char *palavraA, char *palavraB){ //Retorna um inteiro correspondendo a palavra de maior tamanho.
    if (strlen(palavraA) >= strlen(palavraB))     //Faz a comparação entre duas palavras utilizado à função strlen para determinar qual é a mior palavra.
        return strlen(palavraA);                  //Caso que a palavraA é maior.
    else
        return strlen(palavraB);                  // Caso que a palavraB é maior.
}

int ComparaPalavra(char *palavraNoArvore, char *palavraSerInserida){ //Faz a comparação entre duas palavras e retorna o indice que elas diferência uma da outra.
    
    int i=0,tamanho; //Criação de duas variáveis do tipo int: i e tamanho. 
    tamanho = maiorPalavra(palavraNoArvore,palavraSerInserida); //Tamanho receber o valor da maior paralavra.

    for( i=0; i<=tamanho; i++)    //Função for usada para percorrer os array's de 0 até tamanho.
    {
        if(palavraNoArvore[i] != palavraSerInserida[i])  //Comparação indice à indice para determinar o primeiro i que diferência ambas palavras.
            return i;                                    //retorna o i que diferência.
    }
    return -1;                                      //Retonra o valor de -1 caso as palavras sejão iguais.
}

int maiorCaracter(int caracterPalavraA, int caracterPalavraB){ //Faz a comparação entre caracteres
    if(caracterPalavraA > caracterPalavraB)                    
        return caracterPalavraA;                               //Retorna o ASCII do do caracterPalavraA, caso seja maior.
    else
        return caracterPalavraB;                               //Retorna o ASCII do do caracterPalavraB, caso seja maior.
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
        printf("->%s \n",p->NO.Chave);         //Quando desempilha a recursão, vai mostrando os valores correspondente aos nós externos. 
    }
    
}

int pesquisaPAT(char *palavra,TipoApontadorPAT pAt,int *nComparacao) //Função utilizada para pesquisar palavras nas Trie Patricia, retorna 1 para palavra presente e 0 para não presente.
{
    (*nComparacao) += 1;  //Contador de comparações.
    if(EExterno(pAt) == 1){  //Contição para verificar se o apontador é externo.
        (*nComparacao) += 1;  //Contador de comparações.                   
        if(strcmp(palavra, pAt->NO.Chave) == 0){  //compara se as palavras são iguais. 
            printf("palavra encontrada: %s",pAt->NO.Chave); //Mostra a palavra encontrada 
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
