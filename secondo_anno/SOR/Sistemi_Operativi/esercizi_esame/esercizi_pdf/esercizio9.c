/*Sei thread, un scrittore e 3 lettori. Lo scrittore scrive su un buffer numeri dispari da 0 a 50 nelle posizioni
pari e numeri pari da 50 a 100 nelle posizioni dispari. I lettori leggono coppie di numeri (paro, disparo), li
somma e li stampa*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LEN_BUFFER 11

pthread_t writer;
pthread_t reader[3];
sem_t mutex;
sem_t db;
int rc = 0;
int buffer[LEN_BUFFER];

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}

void insert_pari() {
    int pos = 0, num = 0;
    do {
        pos = rand() % LEN_BUFFER;
        num = rand() % 51;
    } while (pos % 2 == 1 || num % 2 == 0);
    buffer[pos] = num;
}

void insert_dispari() {
    int pos = 0, num = 0;
    do {
        pos = rand() % LEN_BUFFER;
        num = rand() % 51 + 50;
    } while (pos % 2 == 0 || num % 2 == 1);
    buffer[pos] = num;
}

int del_pari() {
    int n;
    do {
        n = rand() % LEN_BUFFER;
    } while (n % 2 == 1);
    return n;
}

int del_dispari() {
    int n;
    do {
        n = rand() % LEN_BUFFER;
    } while (n % 2 == 0);
    return n;
}

void *write_num() {
    while (1) {
        sem_wait(&db);
        insert_pari();
        insert_dispari();
        printf("Sono lo scrittore e sto inserendo due elementi\n");
        print_buffer();
        printf("\n");
        sem_post(&db);
        sleep(2);
    }
}

void *read_num(void *args) {
    int *i = (int *)args;
    int sum = 0, p = 0, d = 0;
    while (1) {
        sem_wait(&mutex);
        rc++;
        if (rc == 1)
            sem_wait(&db);
        sem_post(&mutex);
        p = del_pari();
        d = del_dispari();
        printf("Sono il lettore %d\n", *i);
        printf("Sto rimuovendo due elementi in posizione %d e %d\n", p, d);
        sum = buffer[p] + buffer[d];
        printf("La somma tra %d e %d è %d\n", buffer[p], buffer[d], sum);
        print_buffer();
        printf("\n");
        sem_wait(&mutex);
        rc--;
        if (rc == 0)
            sem_post(&db);
        sem_post(&mutex);
        sleep(2);
    }
}

int main() {
    srand(time(NULL));
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);

    pthread_create(&writer, NULL, write_num, 0);
    for (int i = 0; i < 3; i++) {
        int j = i;
        pthread_create(&reader[i], NULL, read_num, (void *)&j);
    }

    pthread_join(writer, 0);
    for (int j = 0; j < 3; j++) {
        pthread_join(reader[j], 0);
    }

    sem_destroy(&mutex);
    sem_destroy(&db);
}
