/*
 Semafori
1. Due thread, il produttore inserisce numeri pari da 0 a 100 in posizioni pari, e numeri dispari da 100 a 200 in
posizioni dispari all’interno di un buffer di N elementi, iniziliazzato a -1, il consumatore legge dal buffer un
numero pari e un numero dispari, li somma e stampa la loro somma.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN_BUFFER 10

sem_t mutex;
sem_t full;
sem_t empty;
pthread_t prod, cons;
int buffer[LEN_BUFFER] = {0};

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d ]\n", buffer[LEN_BUFFER - 1]);
}

void *producer(void *args) {
    int n = 0, pos = 0, k = 0;

    while (k < 10) {
        sem_wait(&empty);
        sem_wait(&mutex);
        do {
            pos = rand() % LEN_BUFFER;
        } while (pos % 2 == 1);
        do {
            n = rand() % 101;
        } while (n % 2 == 1);
        buffer[pos] = n;

        do {
            pos = rand() % LEN_BUFFER;
        } while (pos % 2 == 0);
        do {
            n = rand() % 101;
        } while (n % 2 == 0);
        buffer[pos] = n;

        print_buffer();
        sem_post(&mutex);
        sem_post(&full);
        k++;
        sleep(1);
    }
    pthread_exit(0);
}

void *consumer(void *args) {
    int pos = 0, k = 0, p = 0, d = 0, s = 0;
    while (k < 10) {
        sem_wait(&full);
        sem_wait(&mutex);

        do {
            pos = rand() % LEN_BUFFER;
        } while (pos % 2 == 1);
        p = buffer[pos];
        do {
            pos = rand() % LEN_BUFFER;
        } while (pos % 2 == 0);
        d = buffer[pos];

        s = p + d;
        printf("%d = %d + %d\n", s, p, d);

        sem_post(&mutex);
        sem_post(&empty);
        k++;
        sleep(1);
    }
    pthread_exit(0);
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, LEN_BUFFER);

    pthread_create(&prod, NULL, producer, 0);
    pthread_create(&cons, NULL, consumer, 0);

    pthread_join(prod, 0);
    pthread_join(cons, 0);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}
