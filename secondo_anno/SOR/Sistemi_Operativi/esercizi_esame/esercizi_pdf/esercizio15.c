/*Scrivere un programma in C con tre thread che operano su due array di dimensione N inizialmente a 0.

Il primo thread scrive in un array A numeri casuali tra 1 e 150, scrivendo un numero per volta in posizioni randomiche.
Il secondo thread scrive in un array B numeri cassuali tra 150 e 300, scrivendo un numero per volta in posizioni randomiche.
Il terzo thread controlla se entrambi gli array sono stati inizializzati, in caso affermativo calcola il massimo in A e in B,
calcola il minimo in A e in B. Infine determina il max{max(A), max(B)} e il min{min(A), min(B)}.*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LEN_BUFFER 5

pthread_t th_1, th_2, th_3;
int max_1 = 0, max_2 = 0, max = 0;
int min_1 = 0, min_2 = 0, min = 0;
int buffer_1[LEN_BUFFER];
int buffer_2[LEN_BUFFER];
pthread_mutex_t mutex;
pthread_cond_t cond;

void print_buffer(int buffer[]) {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}

int f__max(int buffer[], int m) {
    m = buffer[0];
    for (int i = 1; i < LEN_BUFFER; i++) {
        if (buffer[i] >= m) {
            m = buffer[i];
        }
    }
    return m;
}

int f_min(int buffer[], int m) {
    m = buffer[0];
    for (int i = 1; i < LEN_BUFFER; i++) {
        if (buffer[i] <= m) {
            m = buffer[i];
        }
    }
    return m;
}

int gen(int n, int offset) {
    n = rand() % 150 + offset + 1;
    return n;
}

void *insert_150() {
    int pos = 0, num = 0;
    while (1) {
        pthread_mutex_lock(&mutex);

        pos = rand() % LEN_BUFFER;
        num = gen(num, 0);
        buffer_1[pos] = num;
        printf("[INFO] : thread 1 inserisce %d in posizione %d\n", num, pos);
        print_buffer(buffer_1);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(0);
}

void *insert_300() {
    int pos = 0, num = 0;
    while (1) {
        pthread_mutex_lock(&mutex);

        pos = rand() % LEN_BUFFER;
        num = gen(num, 150);
        buffer_2[pos] = num;
        printf("[INFO] : thread 2 inserisce %d in posizione %d\n", num, pos);
        print_buffer(buffer_2);

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(0);
}

int check() {
    for (int i = 0; i < LEN_BUFFER; i++) {
        if (buffer_1[i] == 0 & buffer_2[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void *check_buffer() {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (!check()) {
            pthread_cond_wait(&cond, &mutex);
        }
        max_1 = f__max(buffer_1, max_1);
        min_1 = f_min(buffer_1, min_1);

        max_2 = f__max(buffer_2, max_2);
        min_2 = f_min(buffer_2, min_2);

        if (max_1 >= max_2) {
            printf("Max in buffer_1 == %d\n", max_1);
        } else {
            printf("Max in buffer_2 == %d\n", max_2);
        }

        if (min_1 <= min_2) {
            printf("Mix in buffer_1 == %d\n", min_1);
        } else {
            printf("Min in buffer_2 == %d\n", min_2);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

int main() {
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&th_1, 0, insert_150, NULL);
    pthread_create(&th_2, 0, insert_300, NULL);
    pthread_create(&th_3, 0, check_buffer, NULL);

    pthread_join(th_1, 0);
    pthread_join(th_2, 0);
    pthread_join(th_3, 0);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}
