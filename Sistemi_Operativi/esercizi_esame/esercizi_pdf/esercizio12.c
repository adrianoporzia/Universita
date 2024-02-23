/*8. Scrivere un programma C che svolge le seguenti richieste:
• Un processo padre genera due processi figli. Ciascun processo inizializza un proprio array di N interi con numeri randomici
 da 0 a 100.
• Il primo processo invia al processo padre solo i numeri in posizioni pari, e il secondo processo solo i
numeri in posizioni dispari.
• Il padre riceve questi numeri e li scrive in un array di N interi, mettendo il posizioni pari i numeri ricevuti
dal primo figlio, e in posizioni dispari i numeri ricevuti dal secondo filgio.*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

#define LEN_BUFFER 7
#define PIPE_RD 0
#define PIPE_WR 1

int check(int buffer[]) {
    for (int i = 0; i < LEN_BUFFER; i++) {
        if (buffer[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void create_buffer(int buffer[], int seed) {
    srand(seed);
    int n = 0;
    for (int i = 0; i < LEN_BUFFER; i++) {
        n = rand() % 101;
        buffer[i] = n;
    }
}

void print_buffer(int buffer[]) {
    printf("[");
    for (int i = 0; i < LEN_BUFFER - 1; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("%d]\n", buffer[LEN_BUFFER - 1]);
}

int main() {
    srand(time(NULL));
    pid_t pid_1, pid_2;
    int n = 0, i = 0;
    int fd_1[2];
    int fd_2[2];
    int buffer3[LEN_BUFFER] = {0};

    pipe(fd_1);
    pipe(fd_2);

    pid_1 = fork();
    if (pid_1 == 0) {
        close(fd_1[PIPE_RD]);
        int seed_1 = getpid();
        int buffer1[LEN_BUFFER];
        create_buffer(buffer1, seed_1);
        printf("Sono il figlio 1 e questo è il mio buffer\n");
        print_buffer(buffer1);
        for (int i = 0; i < LEN_BUFFER; i++) {
            if (i % 2 == 0) {
                write(fd_1[PIPE_WR], &buffer1[i], sizeof(int));
            } else {
                continue;
            }
        }
        sleep(1);
        exit(0);
    } else if (pid_1 > 0) {
        pid_2 = fork();
        if (pid_2 == 0) {
            close(fd_2[PIPE_RD]);
            int buffer2[LEN_BUFFER];
            int seed_2 = getpid();
            create_buffer(buffer2, seed_2);
            printf("Sono il figlio 2 e questo è il mio buffer\n");
            print_buffer(buffer2);
            for (int i = 0; i < LEN_BUFFER; i++) {
                if (i % 2 == 1) {
                    write(fd_2[PIPE_WR], &buffer2[i], sizeof(int));
                } else {
                    continue;
                }
            }
            exit(0);
        } else if (pid_2 > 0) {
            close(fd_1[PIPE_WR]);
            close(fd_2[PIPE_WR]);
            waitpid(pid_1, NULL, 0);
            waitpid(pid_2, NULL, 0);
            while (i < LEN_BUFFER) {
                if (i % 2 == 0) {
                    read(fd_1[PIPE_RD], &n, sizeof(int));
                    printf("Padre ha letto da Figlio 1: %d\n", n);
                } else {
                    read(fd_2[PIPE_RD], &n, sizeof(int));
                    printf("Padre ha letto da Figlio 2: %d\n", n);
                }
                buffer3[i] = n;
                printf("Sto inserendo l'elemento [%d] in posizione [%d]\n", n, i);
                print_buffer(buffer3);
                i++;
            }
            if (check(buffer3) == 1) {
                kill(pid_1, SIGTERM);
                kill(pid_2, SIGTERM);
                printf("--------BUFFER-------\n");
                print_buffer(buffer3);
            }
        }
    }
    close(fd_1[PIPE_RD]);
    close(fd_2[PIPE_RD]);
    return 0;
}
