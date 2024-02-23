/*
 Si scriva un programma con tre thread che risolvono il seguente problema:
Un buffer di n elementi inizializzato con a -1 viene riempito nel seguente modo:
    - Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
    - Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
    - Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
        buff[0] = buff[0], buff[1] = buff[1] + buff[0], buff[2] = buff[1] + buff[2]
Si proponga una soluzione di mutua esclusione.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 3
#define LEN_BUFFER 10

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
pthread_cond_t cond;
int buffer[LEN_BUFFER];

void print_buffer() {
    for (int i = 0; i < LEN_BUFFER; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("\n");
}
void *add_even(void *args) {
    int pos = 0;
    int n = 0;
    n = rand() % 101;
    while (1) {
        pthread_mutex_lock(&mutex);
        do {
            pos = rand() % LEN_BUFFER;
        } while (pos % 2 != 0);
        buffer[pos] = n;
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *add_odd(void *args) {
    int pos = 0;
    int n = 0;
    n = rand() % 101 + 100;

    while (1) {
        pthread_mutex_lock(&mutex);
        do {
            pos = rand() % LEN_BUFFER;
        } while (pos % 2 != 1);

        buffer[pos] = n;
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int check() {
    for (int i = 0; i < LEN_BUFFER; i++) {
        if (buffer[i] == -1) {
            return 0;
        }
    }
    return 1;
}

void *sum(void *args) {
    pthread_mutex_lock(&mutex);
    while (check() == 0) {
        pthread_cond_wait(&cond, &mutex);
    }
    for (int i = 1; i < LEN_BUFFER; i++) {
        buffer[i] += buffer[i - 1];
    }
    print_buffer();
    pthread_cancel(threads[0]);
    pthread_cancel(threads[1]);
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < LEN_BUFFER; i++) {
        buffer[i] = -1;
    }

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&threads[0], NULL, add_even, 0);
    pthread_create(&threads[1], NULL, add_odd, 0);
    pthread_create(&threads[2], NULL, sum, 0);
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], 0);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}
