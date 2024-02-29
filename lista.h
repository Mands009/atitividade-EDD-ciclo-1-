#ifndef LISTA_H
#define LISTA_H

/*estrutura do n�*/
typedef struct no { /*CRIAÇÃO DE UM TIPO DE DADO DEFINIDO PELO USUARIO*/
    int valor;
    struct no * proximo;
} No;

/*DEFINIÇÃO DA ESTRUTURA DA LISTA*/
typedef struct lista {
    No * primeiro; /*CRIAÇÃO DE APENAS UM PONTEIRO PARA O PRIMEIRO ITEM DA LISTA*/
} Lista;

/*PROTOTIPO DAS FUNÇÕES PARA MANIPULAR A ESTRUTURA*/
void listaInit(Lista *lista);
void escreveLista(Lista *lista);
int listaIsEmpty(Lista *lista);
void listaInsere(Lista *lista, int n);
void listaRemove(Lista *lista, int n);

#endif // LISTA_H