/*3. Sei thread, un scrittore e 5 lettori. Lo scrittore scrive su un buffer numeri dispari da 0 a 50 nelle posizioni
pari e numeri pari da 50 a 100 nelle posizioni dispari. I lettori leggono coppie di numeri (paro, disparo), li
somma e li stampa*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN_BUFFER 10
#define R 5
#define N 10

sem_t mutex;
sem_t db;
pthread_t writer;
pthread_t readers[R];
int buffer[LEN_BUFFER];
int r_count = 0;

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}
/*
int gen_disp() {
    int pos = 0, n = 0;
    do {
        pos = rand() % LEN_BUFFER;
        n = rand() % 51;
    } while (pos % 2 == 1 && n % 2 == 0);
    buffer[pos] = n;
    return n;
}

int gen_pari() {
    int pos = 0, n = 0;
    do {
        pos = rand() % LEN_BUFFER;
        n = rand() % 51 + 50;
    } while (pos % 2 == 0 && n % 2 == 1);
    buffer[pos] = n;
    return n;
}*/

int gen(int range, int offset, int mod) {
    int num = 0;
    do {
        num = rand() % range + offset + 1;
    } while (num % 2 != mod);
    return num;
}

void *f_write() {
    int i = 0;
    while (i < N) {
        sem_wait(&db);

        int p = gen(51, 50, 1);
        int d = gen(51, 0, 0);
        int pos_pari = gen(LEN_BUFFER, 0, 1);
        int pos_dispari = gen(LEN_BUFFER, 0, 0);

        buffer[pos_pari] = d;
        buffer[pos_dispari] = p;

        printf("WRITER\n");
        print_buffer();

        sem_post(&db);
        sleep(1);
        i++;
    }
    pthread_exit(0);
}

void *f_read() {
    int i = 0, sum = 0;
    while (i < N) {
        sem_wait(&mutex);
        r_count++;
        if (r_count == 1) {
            sem_wait(&db);
        }
        sem_post(&mutex);

        int pos_pari = gen(LEN_BUFFER, 0, 0);
        int pos_dispari = gen(LEN_BUFFER, 0, 1);

        int p = buffer[pos_pari];
        int d = buffer[pos_dispari];
        sum = p + d;

        sem_wait(&mutex);
        r_count--;
        if (r_count == 0) {
            sem_post(&db);
        }
        sem_post(&mutex);
        printf("[INFO]: %d + %d = %d\n", p, d, sum);
        sleep(1);
        i++;
    }
    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);

    pthread_create(&writer, 0, f_write, NULL);
    for (int i = 0; i < R; i++) {
        pthread_create(&readers[i], 0, f_read(), NULL);
    }

    for (int i = 0; i < R; i++) {
        pthread_join(readers[i], 0);
    }
    pthread_join(writer, 0);

    sem_destroy(&mutex);
    sem_destroy(&db);
}
