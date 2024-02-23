/*Due thread, il produttore inserisce numeri pari da 0 a 100 in posizioni pari, e numeri dispari da 100 a 200 in posizioni dispari
 * all'interno di un buffer di N elementi, iniziliazzato a -1, il consumatore legge dal buffer un numero pari e un numero dispari,
 * li somma e stampa la loro somma. */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

pthread_t prod, cons;
sem_t(mutex);
sem_t(empty);
sem_t(full);
:
