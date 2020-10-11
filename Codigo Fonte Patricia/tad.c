/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
#include "tad.h"

void inicializaPatricia(TipoArvore *t){
    (*t) = NULL;
}

TipoArvore CriaNoInt(int i, TipoArvore *Esq,  TipoArvore *Dir){ 
    TipoArvore p;
    p = (TipoArvore)malloc(sizeof(TipoPatNo));
    p->tipodeNo = Interno; 
    p->NO.NInterno.Esq = *Esq;
    p->NO.NInterno.Dir = *Dir; 
    p->NO.NInterno.Index = i; 
    return p;
} 

char Bit(char i, TipoChave palavra){ 
    /* Retorna o i-esimo bit da chave k a partir da esquerda */
    int  c, j;
    if (i == 0)
        return 0;
    else{ 
        c = palavra;
        for (j = 1; j <= 8 - i; j++) c /= 2;
        return (c & 1);
    }
} 


int EExterno(TipoArvore p){ /* Verifica se p^ e no do externo */
    return (p->tipodeNo == Externo);
}

TipoArvore CriaNoExt(TipoChave palavra){ 
    TipoArvore p;
    p = (TipoArvore)malloc(sizeof(TipoPatNo));
    p->tipodeNo = Externo; 
    strcpy(p->NO.Conteudo.chave, palavra); //aqui tem que usar srtcmp
    return p;
}  

void Pesquisa(TipoChave palavra, TipoArvore t){ 
    if (EExterno(t)){ 
        if (strcmp(palavra,t->NO.Conteudo.chave) == 0){
            printf("Elemento encontrado\n");
            return t;
        }
    else 
        printf("Elemento nao encontrado\n");
    return;
    }
  
    if(Bit(t->NO.NInterno.Index, palavra) == 0) 
        Pesquisa(palavra, t->NO.NInterno.Esq);
    else 
        Pesquisa(palavra, t->NO.NInterno.Dir);
} 

TipoArvore InsereEntre(TipoChave palavra, TipoArvore *t, int i){ 
    TipoArvore p;
    
    if (EExterno(*t) || i < (*t)->NO.NInterno.Index){
        p = CriaNoExt(palavra); /*cria um novo no externo */
        if (Bit(i, palavra) == 1) 
        return (CriaNoInt(i, t, &p));
        else return (CriaNoInt(i, &p, t));
    } 
    else{ 
        if (Bit((*t)->NO.NInterno.Index, palavra) == 1)
            (*t)->NO.NInterno.Dir = InsereEntre(palavra,&(*t)->NO.NInterno.Dir,i);
        else
            (*t)->NO.NInterno.Esq = InsereEntre(palavra,&(*t)->NO.NInterno.Esq,i);
        return (*t);
    }
}

TipoArvore Insere(TipoChave palavra, TipoArvore *t){ 
    TipoArvore p;
    int i;
    if (*t == NULL) 
        return (CriaNoExt(palavra));
    else{ 
        p = *t;
        while (!EExterno(p)){ 
            if (Bit(p->NO.NInterno.Index, palavra) == 1)
                p = p->NO.NInterno.Dir;
            else 
                p = p->NO.NInterno.Esq;
        }   
                        /* acha o primeiro bit diferente */
        i = 1;
        while ((i <= 8) & (Bit((int)i, palavra) == Bit((int)i, p->NO.Conteudo.chave))) 
        i++;
        if (i > 8){
            printf("Erro: chave ja esta na arvore\n");  
            return (*t); 
        } 
        else 
            return (InsereEntre(palavra, t, i));
    }
}