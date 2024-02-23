#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;          // informazione del nodo
    struct node *next; // puntatore al prossimo nodo

} node;

typedef struct queue {
    node *first;
    node *last;
    int len;

} queue;

node *init_node(int);
queue *init_queue();
int is_empty(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
int first(queue *);
void print_queue(queue *);

node *init_node(int e) {
    node *nd = malloc(sizeof(node));
    nd->info = e;
    nd->next = NULL;
    return nd;
}

queue *init_queue() {
    queue *q = malloc(sizeof(queue));
    q->first = NULL;
    q->last = NULL;
    q->len = 0;
}

int is_empty(queue *q) {
    if (q->len == 0)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int e) {
    node *nd = init_node(e);
    if (is_empty(q)) {
        q->first = nd;
        q->last = nd;

    } else {
        q->last->next = nd;
        q->last = nd;
    }
    q->len++;
}

int dequeue(queue *q) {
    if (is_empty(q))
        return -1;
    else {
        node *nd = q->first;
        int e = 0;
        q->first = nd->next;
        e = nd->info;
        free(nd);
        q->len--;
        return e;
    }
}

int first(queue *q) {
    if (is_empty(q))
        return -1;
    else {
        node *nd = q->first;
        int e = nd->info;
        return e;
    }
}

void print_queue(queue *q) {
    node *nd = q->first;
    int i = 0;
    while (i < q->len) {
        printf("%d ", nd->info);
        nd = nd->next;
        i++;
    }
    printf("\n");
}

int main() {
    queue *q = init_queue();
    for (int i = 0; i < 10; i++) {
        enqueue(q, i);
    }

    print_queue(q);
    int e = dequeue(q);
    printf("%d\n ", e);
    print_queue(q);
}
