#include <iostream>
#include "lista.h"

void listaInit(Lista *lista)
{
    /*INICIA A LISTA VAZIA*/
    lista->primeiro = nullptr;
}

void escreveLista(Lista *lista) {
    /*VERIFICAÇÃO DA LISTA VAZIA*/
    if (listaIsEmpty(lista) ) {
        std::cout << "Lista Vazia!\n";
        return;
    }

    No *pNo;  /*VERIFICANDO SE TEM ELEMENTOS NA LISTA PARA UM PONTEIRO TIPO NO*/
     /*LAÇO DE REPETIÇÃO PERCORRENDO ELEMENTOS DA LISTA ATÉ ACHAR O FINAL DA MESMA*/
    for( pNo = lista->primeiro; pNo != nullptr; pNo = pNo->proximo){
        std::cout << pNo->valor << "\t";
    }
    std::cout << "\n";
}

int listaIsEmpty(Lista *lista)
{    /*VERIFICANDO SE A LISTA ESTÁ VAZIA OU NÃO*/
    if(lista->primeiro == nullptr) {
        return true;
    } else {
        return false;
    }
}

void listaInsere(Lista *lista, int n)
{
    /*ALOCA MEMÓRIA PARA O NOVO NÓ (PONTEIRO)*/
    No *novo = new No;
    novo->valor = n;
    novo->proximo = nullptr;

    /*ACHA O LOCAL PARA INSERÇÃO (ORDENADA)*/
    No *pAnterior, *pAtual;
    pAnterior = nullptr;
    pAtual = lista->primeiro;

     /*A LISTA É PERCORRIDA ALTERANDO O VALOR DO pAnterior, APONTANDO PARA O pAtual E O pAtual APONTA PARA O ELEMENTO SEGUINTE*/
    while ( (pAtual != nullptr) && (pAtual->valor < n) ) {
        pAnterior = pAtual;
        pAtual =pAtual->proximo;
    }

    /*INSERE NOVO NÓ NO COMEÇO*/
    if( pAtual == lista->primeiro ) {
        novo->proximo = pAtual;
        lista->primeiro = novo;
    } else {
        /*INSERE NOVO NÓ ENTRE pAnterior E pAtual*/
        novo->proximo = pAtual;
        pAnterior->proximo = novo;
    }
}

void listaRemove(Lista *lista, int n)
{
    /*PROCURA O ELEMENTO*/
    No *pAnterior, *pAtual; /*PONTEIROS CRIADOS PARA NO*/
    pAnterior = nullptr;
    pAtual = lista->primeiro;

    /*VARRENDO LISTA ATÉ ACHAR O ELEMENTO*/
    while ( (pAtual != nullptr) && (pAtual->valor != n) ) {
        pAnterior = pAtual;
        pAtual =pAtual->proximo;
    }

    /*VERIFICA SE O ELEMENTO EXISTE NA LISTA*/
    if ( pAtual == nullptr ) { /*SE pAtual ESTIVER APONTANDO PARA O FINAL DA LISTA, A MENSAGEM QUE O ELEMENTO NÃO EXISTE SERÁ EXIBIDA*/
        std::cout << "Elemento nao existe na lista\n";
    } else { /*E SE pAtual ESTIVER APONTANDO PARA O ELEMENTO, ELE SERÁ REMOVIDO */
        if ( pAtual == lista->primeiro) {/*REMOVE DO INICIO*/
            lista->primeiro = pAtual->proximo;
        } else { /*REMOVE DO MEIO DA LISTA*/
            pAnterior->proximo = pAtual->proximo;
        }
        delete(pAtual); //libera memória
    }
}
