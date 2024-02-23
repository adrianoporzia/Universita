/*
Un processo padre genera due processi figli.
• Il primo processo figlio invia al padre un numero casuale da 0 a 100.
• Il padre legge questo numero, lo moltiplica per un k causale e lo manda al secondo figlio.
• Il secondo figlio legge il numero inviato dal padre e lo stampa a video
 **/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    srand(time(NULL));
    pid_t pid_1, pid_2;
    int numero = 0, k = 0;
    int fd_1[2];
    int fd_2[2];

    pipe(fd_1);
    pipe(fd_2);

    pid_1 = fork();
    if (pid_1 == 0) {
        close(fd_1[PIPE_RD]);

        numero = rand() % 101;
        write(fd_1[PIPE_WR], &numero, sizeof(numero));
    }
    if (pid_1 > 0) {
        close(fd_1[PIPE_WR]);
        close(fd_2[PIPE_RD]);
        read(fd_1[PIPE_RD], &numero, sizeof(numero));
        k = rand();
        numero = numero * k;
        write(fd_2[PIPE_WR], &numero, sizeof(numero));
    }
    waitpid(pid_1, NULL, 0);
    pid_2 = fork();
    if (pid_2 == 0) {
        close(fd_2[PIPE_WR]);
        read(fd_2[PIPE_RD], &numero, sizeof(numero));
        printf("%d\n", numero);
    }
    if (pid_2 > 0) {
        waitpid(pid_2, NULL, 0);
        kill(pid_1, SIGTERM);
        kill(pid_2, SIGTERM);
    }
    return 0;
}
