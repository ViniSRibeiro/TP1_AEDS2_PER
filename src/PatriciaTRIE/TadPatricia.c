/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
#include "TadPatricia.h"

void InicializaPatricia(TipoApontadorPAT *p){
    *p=NULL;
}

TipoApontadorPAT CriaNoInterno(int i, char CarDiferente, TipoApontadorPAT *Esq,  TipoApontadorPAT *Dir)
{

    TipoApontadorPAT pArvore;
    pArvore = (TipoApontadorPAT) malloc(sizeof(TipoPatNo));
    pArvore->TipoDeNo = Interno;
    pArvore->NO.NInterno.Esq = *Esq;
    pArvore->NO.NInterno.Dir = *Dir;
    pArvore->NO.NInterno.posicao = i;
    pArvore->NO.NInterno.caracter = CarDiferente;

    return pArvore;
}
int EExterno (TipoApontadorPAT p){
    return (p->TipoDeNo == Externo);
}

TipoApontadorPAT CriaNoExterno (char *palavra)
{
    
    TipoApontadorPAT pArvore;
    pArvore = (TipoApontadorPAT) malloc(sizeof(TipoPatNo));
    pArvore->TipoDeNo = Externo;
    strcpy(pArvore->NO.Chave, palavra);
    return pArvore;
}

TipoApontadorPAT Insere(char *k, TipoApontadorPAT *t)
{

    TipoApontadorPAT pArvore;
    int i;
    if(*t == NULL){
        return CriaNoExterno(k);
    }
    else
    {
        pArvore = *t;
        while (!EExterno(pArvore)) {
            if (strlen(k) >= pArvore->NO.NInterno.posicao && k[pArvore->NO.NInterno.posicao] < (pArvore)->NO.NInterno.caracter) {

                pArvore = pArvore->NO.NInterno.Esq;
            } else {

                pArvore = pArvore->NO.NInterno.Dir;
            }
        }
        i = ComparaPalavra((pArvore)->NO.Chave, k);
        if(i<0){
            return(*t);
        }
        return InsereEntre(k,t,i,maior(k[i],pArvore->NO.Chave[i]));
    }
}


TipoApontadorPAT InsereEntre (char *k, TipoApontadorPAT *t, int i, char CarDiferente)
{
    TipoApontadorPAT pArvore;
    if(EExterno(*t) || i < (*t)->NO.NInterno.posicao) {

        pArvore = CriaNoExterno(k);
        if (k[i] < CarDiferente)
            return (CriaNoInterno(i, CarDiferente, &pArvore, t));

        else
            return (CriaNoInterno(i, CarDiferente, t, &pArvore));

    }

    else
    {
        if(k[(*t)->NO.NInterno.posicao] >= (*t)->NO.NInterno.caracter)
            (*t)->NO.NInterno.Dir = InsereEntre(k,&((*t)->NO.NInterno.Dir),i,CarDiferente);
        else
            (*t)->NO.NInterno.Esq = InsereEntre(k,&((*t)->NO.NInterno.Esq),i,CarDiferente);
        return (*t);
    }
}

int ComparaPalavra(char *palavraNaArvore, char *palavraRec)
{
    int i=0,tam;
    if(strlen(palavraNaArvore)<= strlen(palavraRec))
        tam = strlen(palavraRec);
    else
        tam = strlen(palavraNaArvore);
    for( i=0; i<=tam; i++)
    {
        if(palavraNaArvore[i] != palavraRec[i])
            return i;
    }
    return -1;

}

int maior(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

int pesquisa(char *k, TipoApontadorPAT t,int *QuantidadeDeComp)
{
    (*QuantidadeDeComp)+=1;
    if(EExterno(t))
    {
        (*QuantidadeDeComp)+=1;
        if(strcmp(k, t->NO.Chave)==0)
        {
            printf("Chave Encontrada: %s\n",t->NO.Chave);
            return 1;
        }
        else
        {
            return 0;
        }
        // return ;
    }

    (*QuantidadeDeComp)+=1;
    if(t->NO.NInterno.posicao > strlen(k))
    {
        pesquisa(k, t->NO.NInterno.Esq,QuantidadeDeComp);
        return 0;
    }
    (*QuantidadeDeComp)+=1;
    if(k[t->NO.NInterno.posicao] >= t->NO.NInterno.caracter)
    {
        pesquisa(k,t->NO.NInterno.Dir,QuantidadeDeComp);
    }
    else
    {
        pesquisa(k, t->NO.NInterno.Esq,QuantidadeDeComp);
    }
    // return ;
}