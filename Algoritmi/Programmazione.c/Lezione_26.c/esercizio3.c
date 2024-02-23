#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

void inserisciNodo(Nodo** testa, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = NULL;

    if (*testa == NULL) {
        *testa = nuovoNodo;
    } else {
        Nodo* corrente = *testa;
        while (corrente->prossimo != NULL) {
            corrente = corrente->prossimo;
        }
        corrente->prossimo = nuovoNodo;
    }
}

void generaNuovaLista(Nodo* A, Nodo** B) {
    Nodo* correnteA = A;
    Nodo* correnteB = NULL;
    int primoElemento = 1;

    while (correnteA != NULL) {
        int valore = 0;

        if (primoElemento) {
            valore = correnteA->dato;
            primoElemento = 0;
        } else {
            if (correnteA->dato % 2 == 0) {
                valore = correnteB->dato - correnteA->dato;
            } else {
                valore = correnteB->dato + correnteA->dato;
            }
        }

        inserisciNodo(B, valore);

        if (correnteB == NULL) {
            correnteB = *B;
        } else {
            correnteB = correnteB->prossimo;
        }

        correnteA = correnteA->prossimo;
    }
}

void stampaLista(Nodo* testa) {
    Nodo* corrente = testa;
    while (corrente != NULL) {
        printf("%d ", corrente->dato);
        corrente = corrente->prossimo;
    }
    printf("\n");
}

void liberaLista(Nodo* testa) {
    Nodo* corrente = testa;
    while (corrente != NULL) {
        Nodo* prossimo = corrente->prossimo;
        free(corrente);
        corrente = prossimo;
    }
}

void generaEStampaLista(int A[], int n) {
    Nodo* testaA = NULL;
    Nodo* testaB = NULL;

    for (int i = 0; i < n; i++) {
        inserisciNodo(&testaA, A[i]);
    }

    generaNuovaLista(testaA, &testaB);

    printf("Lista A: ");
    stampaLista(testaA);
    printf("Lista B: ");
    stampaLista(testaB);

    liberaLista(testaA);
    liberaLista(testaB);
}

int main() {
    int A[] = {5, 9, 7, 4, 6};
    int n = sizeof(A) / sizeof(A[0]);

    generaEStampaLista(A, n);

    return 0;
}
