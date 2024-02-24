/*1. Scrivere un programma C che segue le seguenti specifiche. Il processo eseguito, inizialmente crea un buffer
come array di 11 numeri interi, inizializzati a zero. In seguito genera tre thread utilizzando le librerie POSIX
secondo le seguenti specifiche:
• Il primo thread sceglie casualmente una cella del buffer e vi scrive il numero +1, qualsiasi sia il valore
presente nella cella.
• Il secondo thread sceglie casualmente una cella del buffer e vi scrive il numero -1, qualsiasi sia il valore
presente nella cella.
• Il terzo thread controlla se tutte le celle del buffer sono state inizializzate. In caso positivo, determina
se il numero di celle contententi un valore pari a +1 è maggiore di quelle con -1 e termina tutti e tre i
thread. Mentre un thread ha accesso al buffer, nessun altro thread deve accedervi. Una volta che un
thread ha acceduto in lettura o scrittura al buffer, deve attendere un numero di secondi random tra 0 e
3*/

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN_BUFFER 5
#define NUM_THREADS 3

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
pthread_cond_t cond;
int buffer[LEN_BUFFER] = {0};

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER; i++) {
        printf("%d", buffer[i]);
        if (i < LEN_BUFFER - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void *set_positive(void *args) {
    int pos = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        pos = rand() % LEN_BUFFER;
        buffer[pos] = 1;
        printf("Sono il thread 1 e sto inserendo un elemento un 1 in posizione %d\n", pos);
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *set_negative(void *args) {
    int pos = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        pos = rand() % LEN_BUFFER;
        buffer[pos] = -1;
        printf("Sono il thread 1 e sto inserendo un elemento un -1 in posizione %d\n", pos);
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int check_buffer() {
    for (int i = 0; i < LEN_BUFFER; i++) {
        if (buffer[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void *check(void *args) {
    int pos = 0, neg = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (check_buffer() == 0) {
            pthread_cond_wait(&cond, &mutex);
            sleep(1);
        }
        for (int i = 0; i < LEN_BUFFER; i++) {
            if (buffer[i] == 1) {
                pos++;
            } else if (buffer[i] == -1) {
                neg++;
            }
        }
        if (pos > neg) {
            printf("CI SONO PIU' 1, SONO %d\n", pos);
        } else {
            printf("CI SONO PIU' -1, SONO %d\n", neg);
        }
        pthread_kill(threads[0], SIGINT);
        pthread_kill(threads[1], SIGINT);
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
    }
}

int main() {
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&threads[0], NULL, set_positive, 0);
    pthread_create(&threads[1], NULL, set_negative, 0);
    pthread_create(&threads[2], NULL, check, 0);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], 0);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
