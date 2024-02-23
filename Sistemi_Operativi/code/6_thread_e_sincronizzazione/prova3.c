#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DIM_BUFFER 5

pthread_t threads[3];
int buffer[DIM_BUFFER] = {0};
pthread_cond_t cond;
pthread_mutex_t mutex;

void print_buffer() {
    for (int i = 0; i < DIM_BUFFER; i++) {
        printf("%d ", buffer[i]);
    }
}

void *set_positive(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex);
        srand(time(NULL));
        int pos = rand() % DIM_BUFFER;
        buffer[pos] = 1;
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}

void *set_negative(void *args) {
    while (1) {
        pthread_mutex_lock(&mutex);
        srand(time(NULL));
        int pos = rand() % DIM_BUFFER;
        buffer[pos] = 1;
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 4);
    }
}

int check() {
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
        while (check() == 0) {
            pthread_cond_wait(&cond, &mutex);
            sleep(rand() % 4);
        }
        int num_pos = 0, num_neg = 0;
        for (int i = 0; i < DIM_BUFFER; i++) {
            if (buffer[i] == 1) {
                num_pos++;
            }
            if (buffer[i] == -1) {
                num_neg++;
            }
        }
        if (num_neg < num_pos) {
            printf("ci sono piu positivi\n");
        } else {
            printf("ci sono piu negativi\n");
        }
    }
}

int main() {
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
}
