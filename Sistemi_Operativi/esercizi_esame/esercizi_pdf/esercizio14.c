/*
 9.Si richiede di implementare un programma in linguaggio C che utilizzi il metodo delle fork per la comunicazione tra processi.
 Il programma dovrà creare un file di testo e poi creare due processi figli. Uno dei processi figli dovrà scrivere una sequenza di
 N numeri interi pari nel file, mentre l'altro processo figlio dovrà scrivere una sequenza di N numeri interi dispari, attraverso
 la funzione seek va a scriverli subito dopo la sequenza degli N numeri pari nello stesso file.
 Il processo padre dovrà leggere i dati dal file e stamparli a video.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#define PIPE_RD 0
#define PIPE_WR 1

void print_buffer(char buffer[], int n) {
    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("%c, ", buffer[i]);
    }
    printf("%c]\n", buffer[n - 1]);
}

int main() {
    pid_t pid_p, pid_d;
    int p, d;
    int num = 0;
    int fd;
    int fd_p[2];
    int fd_d[2];
    const char *filename = "prova.txt";

    pipe(fd_p);
    pipe(fd_d);

    fd = creat("prova.txt", 0700);
    close(fd);

    pid_p = fork();
    if (pid_p == 0) {
        const int n = 10;
        close(fd_p[PIPE_RD]);
        fd = open(filename, O_RDWR);
        for (int i = 0; i < n; i++) {
            do {
                p = rand() % 21;
            } while (p % 2 == 1);
            char c = p + '0';
            write(fd, &c, sizeof(c));
        }
        write(fd_p[PIPE_WR], &n, sizeof(n));
        close(fd);

    } else if (pid_p > 0) {
        pid_d = fork();
        if (pid_d == 0) {
            waitpid(pid_p, NULL, 0);
            const int m = 5;
            read(fd_p[PIPE_RD], &num, sizeof(num));
            fd = open(filename, O_RDWR);
            lseek(fd, num, SEEK_SET);

            for (int i = 0; i < m; i++) {
                do {
                    d = rand() % 21;
                } while (d % 2 == 0);
                char c = d + '0';
                write(fd, &c, sizeof(c));
            }
            num += m;
            write(fd_d[PIPE_WR], &num, sizeof(num));
            close(fd);
        } else if (pid_d > 0) {
            waitpid(pid_d, NULL, 0);
            close(fd_p[PIPE_WR]);
            close(fd_p[PIPE_RD]);
            close(fd_d[PIPE_WR]);
            read(fd_d[PIPE_RD], &num, sizeof(num));
            char buffer[num];
            printf("[INFO] : il numero di elementi totale è %d\n", num);
            fd = open(filename, O_RDONLY);
            read(fd, &buffer, sizeof(num));
            print_buffer(buffer, num);
            close(fd);
            exit(0);
        }
    }
    close(fd_d[PIPE_RD]);
    return 0;
}
