/*1. Due thread, il produttore inserisce numeri pari da 0 a 100 in posizioni pari, e numeri dispari da 100 a 200 in
posizioni dispari all’interno di un buffer di N elementi, iniziliazzato a -1, il consumatore legge dal buffer un
numero pari e un numero dispari, li somma e stampa la loro somma.*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LEN_BUFFER 5

pthread_t prod, cons;
sem_t mutex;
sem_t empty;
sem_t full;
int buffer[LEN_BUFFER];

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}

void in_pari() {
    srand(time(NULL));
    int pos = 0, n = 0;
    do {
        pos = rand() % LEN_BUFFER;
        n = rand() % 101;
    } while (pos % 2 == 1 && n % 2 == 1);
    buffer[pos] = n;
}

void in_dispari() {
    srand(time(NULL));
    int pos = 0, n = 0;
    do {
        pos = rand() % LEN_BUFFER;
        n = rand() % 101 + 100;
    } while (pos % 2 == 0 && n % 2 == 0);
    buffer[pos] = n;
}

void del_pari() {
    int pos = 0;
    do {
        pos = rand() % LEN_BUFFER;
    } while (buffer[pos] % 2 == 1);
    buffer[pos] = -1;
}

void del_dispari() {
    int pos = 0;
    do {
        pos = rand() % LEN_BUFFER;
    } while (buffer[pos] % 2 == 0);
    buffer[pos] = -1;
}

void *producer() {
    int k = 0;
    while (k < 5) {
        sem_wait(&empty);
        sem_wait(&mutex);

        in_pari();
        in_dispari();
        printf("Sono il produttore e sto inserendo\n");
        print_buffer();

        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
        k++;
    }
    pthread_exit(0);
}

void *consumer() {
    int p = 0, d = 0, k = 0;
    while (k < 5) {
        sem_wait(&full);
        sem_wait(&mutex);

        del_pari();
        del_dispari();

        printf("Sono il consumer e sto rimuovendo\n");
        print_buffer();
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
        k++;
    }
    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < LEN_BUFFER; i++) {
        buffer[i] = -1;
    }

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, LEN_BUFFER);
    sem_init(&full, 0, 0);

    pthread_create(&prod, NULL, producer, 0);
    pthread_create(&cons, NULL, consumer, 0);

    pthread_join(prod, 0);
    pthread_join(cons, 0);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}
