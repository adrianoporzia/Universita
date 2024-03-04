#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define STDIN 0
#define STDOUT 1

int main() {
    pid_t pid_p, pid_d; // processo pari e processo dispari
    int p, d, s;        // numero pari, dispari e la somma
    int fd_p[2];        // pipe processo numero pari
    int fd_d[2];        // pipe processo numero dispari
    int numero = 0;

    pipe(fd_p);
    pipe(fd_d);

    pid_p = fork(); // clone generatore numeri pari
    if (pid_p == 0) {
        close(fd_p[PIPE_RD]);
        close(STDIN);
        close(STDOUT);
        while (1) {
            numero = rand() % 101;
            if (numero % 2 == 0) {
                write(fd_p[PIPE_WR], &numero, sizeof(numero));
            }
        }
    } else if (pid_p > 0) {
        pid_d = fork();
        if (pid_d == 0) {
            close(fd_d[PIPE_RD]);
            close(STDIN);
            close(STDOUT);
            while (1) {
                numero = rand() % 101;
                if (numero % 2 == 1) {
                    write(fd_d[PIPE_WR], &numero, sizeof(numero));
                }
            }
        } else if (pid_d > 0) {
            close(fd_p[PIPE_WR]);
            close(fd_d[PIPE_WR]);
            close(STDIN);
            while (1) {
                read(fd_p[PIPE_RD], &p, sizeof(p));
                read(fd_d[PIPE_RD], &d, sizeof(d));
                s = p + d;

                printf(" %d = %d + %d\n", s, p, d);

                if (s >= 190) {
                    kill(pid_p, SIGTERM);
                    kill(pid_d, SIGTERM);
                    break;
                }
            }
        }
    }
    close(fd_p[PIPE_RD]);
    close(fd_d[PIPE_RD]);
    return 0;
}
