#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid) {
    int r = rand() % 5;

    sleep(r);

    printf("Hello World. Sono il thread %d\n", tid);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for (i = 0; i <= NUMBER_OF_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);

        printf("Process %d created with status %d\n", i, status);

        if (status != 0) {
            printf("Problems in process %d\n", i);
            exit(-1);
        }
    }

    for (i = 0; i <= NUMBER_OF_THREADS; i++) {
        status = pthread_join(threads[i], NULL);

        printf("Process %d terminated with status %d\n", i, status);

        if (status != 0) {
            printf("Problem with the end for the process %d\n", i);
            exit(-1);
        }
    }
    return 0;
}
