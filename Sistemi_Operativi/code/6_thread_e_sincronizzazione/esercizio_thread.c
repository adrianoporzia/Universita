// Scrivere un programma C che segue le seguenti specifiche.
// Il processo eseguito, inizialmente crea un buffer come array di 11 numeri interi, inizializzati a zero.
// In seguito genera tre thread utilizzando le librerie POSIX secondo le seguenti specifiche:
// •  Il primo thread in un ciclo infinito sceglie casualmente una cella del buffer e vi scrive il numero +1, qualsiasi sia il valore presente nella cella.
// •  Il secondo thread in un ciclo infinito sceglie casualmente una cella del buffer e vi scrive il numero -1, qualsiasi sia il valore presente nella cella.
// •  Il terzo thread in un ciclo infinito controlla se tutte le celle del buffer sono state inizializzate ad un valore diverso da 0. In caso positivo, determina se il numero di celle contenenti un valore pari a +1 è maggiore di quelle con -1 e termina tutti e tre i thread.
// •  Mentre un thread ha accesso al buffer, nessun altro thread deve accedervi.
// •  Una volta che un thread ha acceduto in lettura o scrittura al buffer, deve attendere un numero di secondi random tra 0 e 3
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DIM_BUFFER 5

pthread_mutex_t mutex;
pthread_cond_t cond;
pthread_t threads[3];
int buffer[DIM_BUFFER] = {0};
int done = 0;

void print_buffer() {
    for (int i = 0; i < DIM_BUFFER; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void *set_positive(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int pos = rand() % DIM_BUFFER;
        buffer[pos] = 1;
        print_buffer();
        printf("\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}

void *set_negative(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int pos = rand() % DIM_BUFFER;
        buffer[pos] = -1;
        print_buffer();
        printf("\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}

int check_array() {
    for (int i = 0; i < DIM_BUFFER; i++) {
        if (buffer[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void *check_buffer(void *args) {

    while (1) {
        pthread_mutex_lock(&mutex);

        while (check_array() == 0) {

            sleep(rand() % 4);
            pthread_cond_wait(&cond, &mutex);
        }
        int num_pos = 0;
        int num_neg = 0;
        for (int i = 0; i < DIM_BUFFER; i++) {
            if (buffer[i] == 1) {
                num_pos++;
            } else {
                num_neg++;
            }
        }
        if (num_pos > num_neg) {
            printf("ha vinto thread 1\n");
        } else {
            printf("ha vinto thread 2\n");
        }
        pthread_kill(threads[0], SIGINT);
        pthread_kill(threads[1], SIGINT);
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
    }
}
int main() {
    srand(time(NULL));

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&threads[0], NULL, set_positive, NULL);
    pthread_create(&threads[1], NULL, set_negative, NULL);
    pthread_create(&threads[2], NULL, check_buffer, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
