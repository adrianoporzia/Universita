/*Sei thread, un scrittore e 5 lettori. Lo scrittore scrive su un buffer numeri dispari da 0 a 50 nelle posizioni pari e
 * numeri pari da 50 a 100 nelle posizioni dispari. I lettori leggono coppie di numeri (paro, disparo), li somma e li stampa*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN_BUFFER 5

pthread_t readers[5];
pthread_t writer;
int r_count = 0;
sem_t mutex;
sem_t db;
int buffer[LEN_BUFFER] = {0};

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}

int gen_pos(int offset) {
    int num = 0;
    do {
        num = rand() % LEN_BUFFER;
    } while (num % 2 == 0);
    return num;
}

void gen(int offset, int p, int n) {
    int pos = 0, num = 0;
    do {
        pos = rand() % LEN_BUFFER;
        num = rand() % 51 + offset;
    } while (pos % 2 == p && num % 2 == n);
    buffer[pos] = num;
}

void *writes() {
    while (1) {
        sem_wait(&db);

        gen(0, 1, 0);
        gen(100, 0, 1);

        print_buffer();

        sem_post(&db);
        sleep(1);
    }
}

void *reads() {
    int p = 0, d = 0;
    while (1) {
        sem_wait(&mutex);

        r_count++;

        if (r_count == 1) {
            sem_wait(&db);
        }
        sem_post(&mutex);

        p = gen_pos(1);
        d = gen_pos(0);
        p = buffer[p];
        d = buffer[d];

        sem_wait(&mutex);

        r_count--;
        if (r_count == 0) {
            sem_post(&db);
        }
        sem_post(&mutex);
        printf("%d e %d\n", p, d);
        sleep(1);
    }
}

int main() {
    srand(time(NULL));

    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);

    pthread_create(&writer, 0, writes, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], 0, reads, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], 0);
    }
    pthread_join(writer, 0);

    sem_destroy(&mutex);
    sem_destroy(&db);
}
