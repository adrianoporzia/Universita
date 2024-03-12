#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;          // informazione del nodo
    struct node *next; // puntatore al prossimo nodo

} node;

typedef struct pila {
    node *first;
    int len;

} pila;

node *init_node(int);
pila *init_pila();
int is_empty(pila *);
void push(pila *, int);
int pop(pila *);
int top(pila *);
void print_pila(pila *);

node *init_node(int e) {
    node *nd = malloc(sizeof(node));
    nd->info = e;
    nd->next = NULL;
    return nd;
}

pila *init_pila() {
    pila *p = malloc(sizeof(pila));
    p->first = NULL;
    p->len = 0;
    return p;
}

int is_empty(pila *p) {
    if (p->len == 0)
        return 1;
    else
        return 0;
}

void push(pila *p, int e) {
    node *nd = init_node(e);
    if (is_empty(p)) {
        p->first = nd;
    } else {
        nd->next = p->first;
        p->first = nd;
    }
    p->len++;
}

int pop(pila *p) {
    if (is_empty(p))
        return -1;
    node *nd = p->first;
    int e = p->first->info;
    p->first = nd->next;
    free(nd);
    p->len--;
    return e;
}

int top(pila *p) {
    node *nd = p->first;
    int e = nd->info;
    return e;
}

void print_pila(pila *p) {
    node *nd = p->first;
    int i = 0;
    while (i < p->len) {
        printf("%d ", nd->info);
        nd = nd->next;
        i++;
    }
    printf("\n");
}

int main() {
    pila *p = init_pila();
    for (int i = 0; i < 10; i++) {
        push(p, i);
        printf("%d\n", p->first->info);
    }

    print_pila(p);
    int e = pop(p);
    printf("%d ", e);
}
