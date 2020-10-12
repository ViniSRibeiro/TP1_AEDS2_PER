/*
    Grupo: Return NULL;

    Eduardo Vinícius Bittencourt Esquivel 3498
    Emamanuel Vitor Carvalho Ruela 3891
    Roniel Nunes Barbosa 3464
    Vinícius Tadeu Silva Ribeiro 2670
*/
#include "TadPatricia.h"

void inicializaPatricia(TipoArvore *t){
    (*t) = NULL;
}


TipoArvore CriaNoInt(int i, TipoArvore *Esq,  TipoArvore *Dir){
    TipoArvore p; //Cria uma varivavel do TipoArvore

    p = (TipoArvore)malloc(sizeof(TipoPatNo)); //Faz a alocação de memoria para essa variavel
    
    p->TipoDeNo = Interno; //Declara que seu tipo e interno
    p->NO.NInterno.Esq = *Esq; //Faz o noInternoEsq = O endereço do apontador Esquerdo
    p->NO.NInterno.Dir = *Dir; //Faz o noInternoDir = o Endereço do apontador Direito
    p->NO.NInterno.Index = i; //Faz o noInternoIndex =  o i; 

    return p; //Retorna o ponteiro
}


TipoArvore CriaNoExt(TipoChave palavra){
    TipoArvore p; //Cria uma variavel do TipoArvore

    p = (TipoArvore)malloc(sizeof(TipoPatNo)); // Faz a alocação de memoria para essa variavel
    p->TipoDeNo = Externo;// Identifica o TipoDeNo = Externo
    p->NO.Conteudo.Chave = palavra; //Faz a copia da palavra para o conteudo do no externo.
    
    return p;
}

void ImprimePatricia(TipoArvore t){
    if (t == NULL){
        printf("Arvore vazia!\n");
        return;
    }
    
    if (EExterno(t)){
        printf("[palavra]: %s ",t->NO.Conteudo.Chave);
    }else{
        if (t->NO.NInterno.Esq != NULL)
            ImprimePatricia(t->NO.NInterno.Esq);
        if (t->NO.NInterno.Dir !=NULL)
            ImprimePatricia(t->NO.Conteudo.Chave);
    }
}

int EExterno(TipoArvore p){
    return (p->TipoDeNo == Externo); //retorna 0 se TipoDeNo for Externo, caso contraio 1.
}

// TipoArvore InsereEntre(TipoChave palavra, TipoArvore *t, int i){
//     TipoArvore p;

//     if (EExterno(*t) || i < (*t)->NO.NInterno.Index){
//         p = CriaNoExt(palavra); //Cria um novo no externo
//     }
// }

// TipoArvore InsereEntre(char palavra, TipoArvore *t, int i){ 
//     TipoArvore p;
//     if (EExterno(*t) || i < (*t)->NO.NInterno.Index){
//         p = CriaNoExt(palavra); /*cria um novo no externo */
//         if (Bit(i, palavra) == 1) 
//         return (CriaNoInt(i, t, &p));
//         else return (CriaNoInt(i, &p, t));
//     }else{ 
//         if (Bit((*t)->NO.NInterno.Index, palavra) == 1)
//             (*t)->NO.NInterno.Dir = InsereEntre(palavra,&(*t)->NO.NInterno.Dir,i);
//         else
//             (*t)->NO.NInterno.Esq = InsereEntre(palavra,&(*t)->NO.NInterno.Esq,i);
//         return (*t);
//     }
// }
// char Bit(char i, char palavra){ 
//     /* Retorna o i-esimo bit da chave k a partir da esquerda */
//     int  c, j;
//     if (i == 0)
//         return 0;
//     else{ 
//         c = palavra;
//         for (j = 1; j <= 8 - i; j++) c /= 2;
//         return (c & 1);
//     }
// } 
// void Pesquisa(char palavra, TipoArvore t){ 
//     if (EExterno(t)){ 
//         if (strcmp(palavra,t->NO.Conteudo.chave) == 0){
//             printf("Elemento encontrado\n");
//            // return t;
//         }
//     else 
//         printf("Elemento nao encontrado\n");
//     return;
//     }
  
//     if(Bit(t->NO.NInterno.Index, palavra) == 0) 
//         Pesquisa(palavra, t->NO.NInterno.Esq);
//     else 
//         Pesquisa(palavra, t->NO.NInterno.Dir);
// } 

// TipoArvore InsereEntre(char palavra, TipoArvore *t, int i){ 
//     TipoArvore p;
    
//     if (EExterno(*t) || i < (*t)->NO.NInterno.Index){
//         p = CriaNoExt(palavra); /*cria um novo no externo */
//         if (Bit(i, palavra) == 1) 
//         return (CriaNoInt(i, t, &p));
//         else return (CriaNoInt(i, &p, t));
//     } 
//     else{ 
//         if (Bit((*t)->NO.NInterno.Index, palavra) == 1)
//             (*t)->NO.NInterno.Dir = InsereEntre(palavra,&(*t)->NO.NInterno.Dir,i);
//         else
//             (*t)->NO.NInterno.Esq = InsereEntre(palavra,&(*t)->NO.NInterno.Esq,i);
//         return (*t);
//     }
// }

// TipoArvore Insere(char palavra, TipoArvore *t){ 
//     TipoArvore p;
//     int i;
//     if (*t == NULL) 
//         return (CriaNoExt(palavra));
//     else{ 
//         p = *t;
//         while (!EExterno(p)){ 
//             if (Bit(p->NO.NInterno.Index, palavra) == 1)
//                 p = p->NO.NInterno.Dir;
//             else 
//                 p = p->NO.NInterno.Esq;
//         }   
//                         /* acha o primeiro bit diferente */
//         i = 1;
//         while ((i <= 8) & (Bit((int)i, palavra) == Bit((int)i, p->NO.Conteudo.chave))) 
//         i++;
//         if (i > 8){
//             printf("Erro: chave ja esta na arvore\n");  
//             return (*t); 
//         } 
//         else 
//             return (InsereEntre(palavra, t, i));
//     }
// }