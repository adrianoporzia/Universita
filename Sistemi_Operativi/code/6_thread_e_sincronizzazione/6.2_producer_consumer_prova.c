#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10 /* numero di posti nel buffer */
#define TRUE 1

sem_t mutex;
sem_t empty;
sem_t full;

int buffer[N];
int in = 0;

/* Funzioni helper per utilizzare i semafori */
void down(sem_t *sem) {
    sem_wait(sem);
}

void up(sem_t *sem) {
    sem_post(sem);
}

void insert_item() {
    int item = rand() % 100;
    printf("\n Inserisco l'elemento %d in posizione %d", item, (in + 1));
    buffer[in] = item;
    in++;
}

void remove_item() {
    int item = buffer[in - 1];
    printf("\nRimuovo elemento %d in posizione %d", item, in);
    in--;
}

void print_buffer() {
    for (int i = 0; i <= in; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void *producer(void *arg) {
    while (TRUE) {
        down(&mutex);
        down(&empty);

        insert_item();
        print_buffer();

        up(&mutex);
        up(&full);
    }
}

void *consumer(int *arg) {
    while (TRUE) {
        down(&mutex);
        down(&empty);

        remove_item();
        print_buffer();

        up(&mutex);
        up(&full);
    }
}

int main() {
    pthread_t prod, cons;
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Distruzione dei semafori
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
