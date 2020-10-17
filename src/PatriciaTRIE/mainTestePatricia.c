#include "TadPatricia.h"

/*
  Grupo: Return NULL;
  Eduardo Vinícius Bittencourt Esquivel 3498
	Emanuel Vitor Carvalho Ruella 3891
	Roniel Nunes Barbosa 3464
	Vinícius Tadeu Silva Ribeiro 2670
*/
int  main()
{
    FILE *arquivo = NULL;
    TipoApontadorPAT patricia;

    char  palavra[MaxTamPalavra],nomeArquivo[MaxTamPalavra];
    int z = 1;
    int nPalavras = 0,ni = 0,option,pesquisa,nCompracao = 0, nPalavra =0;

    InicializarPAT(&patricia);


    do
    {
    printf("=========================Menu=======================\n");
    printf("|1) Insere palavras                                |\n");
    printf("|2) Pesquisa palavra                               |\n");
    printf("|3) Imprime em ordem alfabetica                    |\n");
    printf("|4) Numero de palavras na arvore                   |\n");
    printf("|5) insercao por arquivo                           |\n");
    printf("|x) para interromper digite qualquer numero >=6    |\n");
    printf("===================================================|\n");
    printf("Difgite a opcao: ");
    scanf("%d",&option);


    if (option == 1)
    {
      printf("\n=====Op 1 INSERCAO MANUAL=====\n");

      printf("Quantas palavras deseja inserir: ");
      scanf("%d",&nPalavras);

      for (size_t i = 0; i < nPalavras; i++)
      {
        printf("Digite a palavra a ser inserida: ");
        scanf("%s",palavra);
        strlwr(palavra);
        patricia = Insere(palavra,&patricia);
      }
      
      
    }
    else if (option == 2){
      printf("\n=====Op 2 PESQUISAR PALAVRA=====\n");
      printf("Qual palavra deseja pesquisar: ");
      scanf("%s",&palavra);


      pesquisa = pesquisaPAT(palavra,patricia,&nCompracao);

      if (pesquisa == 1)
      {
        printf("\n-Palavra encontrada na arvore.\nNumero de comparacoes: %d\n",nCompracao);
        nCompracao = 0;
      }else{
        printf("\npalavra nao encontrada\n");
      }
      

      
    }else if (option == 3)
    {
      printf("\n=====Op 3 IMPRIME PATRICIA=====\n");
      
      imprimePAT(patricia);
      
    }else if (option == 4){
      printf("\n=====Op 4 QUANTIDADE DE PALAVRAS=====\n");

      quantidadePalavras(patricia,&nPalavra);
      printf("quantidade de palavras na arvore: %d \n",nPalavra);
      nPalavra = 0;
    }
    else if (option == 5){
      printf("\n=====Op 5 INSERCAO POR ARQUIVO=====\n");
      printf("Digite o nome do arquivo a ser aberto: ");
      scanf("%s",nomeArquivo);
      
      strcat(nomeArquivo,".txt");
      arquivo = fopen(nomeArquivo,"r");

      if(arquivo == NULL)
        printf("ERRO NA LEITURA");

      while(fscanf(arquivo,"%s", palavra)!= EOF){
        strlwr(palavra);
        patricia = Insere(palavra, &patricia);
      }
      fclose(arquivo); 
    }
    

    } while (option <7);
    
    return 0;
}



