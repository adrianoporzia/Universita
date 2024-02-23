/*2. Si scriva un programma con tre thread che risolvono il seguente problema: Un buffer di n elementi inizializzato
con a -1 viene riempito nel seguente modo:
• Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
• Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
• Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
buff[0] = buff[0]; buff[1] = buff[1] + buff[0]; buff[2] = buff[1] + buff[2]. Si proponga
una soluzione di mutua esclusione*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN_BUFFER 5

pthread_t threads[3];
pthread_mutex_t mutex;
pthread_cond_t cond;
int buffer[LEN_BUFFER];
int done = 0;

void set_pari(int n, int p) {
    do {
        n = rand() % 101;
        p = rand() % LEN_BUFFER;
    } while (p % 2 == 1);
    buffer[p] = n;
}
void set_dispari(int n, int p) {
    do {
        n = rand() % 101 + 100;
        p = rand() % LEN_BUFFER;
    } while (p % 2 == 0);
    buffer[p] = n;
}

void mod_buffer() {
    for (int i = 1; i < LEN_BUFFER; i++) {
        buffer[i] = buffer[i] + buffer[i - 1];
    }
}

int sum_element(int n) {
    for (int i = 0; i < LEN_BUFFER; i++) {
        n += buffer[i];
    }
    return n;
}

void print_buffer() {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}

int check() {
    for (int i = 0; i < LEN_BUFFER; i++) {
        if (buffer[i] == -1) {
            return 0;
        }
    }
    return 1;
}

void *in_pari() {
    int n = 0, pos = 0;
    while (done == 0) {
        pthread_mutex_lock(&mutex);
        int pos = rand() % LEN_BUFFER;
        set_pari(n, pos);
        printf("Sono il thread 1 e sto inserendo il numero %d in posizione %d\n", buffer[pos], pos);
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(0);
}

void *in_dispari() {
    int n = 0, pos = 0;
    while (done == 0) {
        pthread_mutex_lock(&mutex);
        int pos = rand() % LEN_BUFFER;
        set_dispari(n, pos);
        printf("Sono il thread 2 e sto inserendo il numero %d in posizione %d\n", buffer[pos], pos);
        print_buffer();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(0);
}

void *sum_buffer() {
    int sum = 0;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (check() == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        done = 1;

        mod_buffer();
        sum = sum_element(sum);
        printf("[%d]\n", sum);

        print_buffer();

        pthread_mutex_unlock(&mutex);
        sleep(1);
        pthread_exit(0);
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < LEN_BUFFER; i++) {
        buffer[i] = -1;
    }
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&threads[0], 0, in_pari, NULL);
    pthread_create(&threads[1], 0, in_dispari, NULL);
    pthread_create(&threads[2], 0, sum_buffer, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], 0);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}
