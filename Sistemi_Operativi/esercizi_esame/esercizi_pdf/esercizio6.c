/*Si scriva un programma con tre thread che risolvono il seguente problema: Un buffer di n elementi inizializzato
con a -1 viene riempito nel seguente modo:
• Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
• Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
• Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
buff[0] = buff[0]; buff[1] = buff[1] + buff[0]; buff[2] = buff[1] + buff[2]. Si proponga
una soluzione di mutua esclusione.*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN_BUFFER 11
#define NUM_THREADS 3

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
pthread_cond_t cond;
int buffer[LEN_BUFFER] = {-1};

int posizione_pari() {
    int n = 0;
    while (n % 2 == 0) {
        n = rand() % LEN_BUFFER;
    }
    return n;
}
void insert_pari() {
    while (1) {
        pthread_mutex_lock(&mutex);
        int pos = rand() % LEN_BUFFER;
        int num = rand() % 101;
        if (pos % 2 == 0) {
            buffer[pos] = num;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void insert_dispari() {
    while (1) {
        pthread_mutex_lock(&mutex);
        int pos = rand() % LEN_BUFFER;
        int num = rand() % 101 + 100;
        if (pos % 2 == 1) {
            buffer[pos] = num;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void sum() {
    while (1) {
    }
}
