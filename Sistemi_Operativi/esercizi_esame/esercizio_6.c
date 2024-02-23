#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t pid_p, pid_d;
    int p = 0, d = 0, s = 0;
    int numero = 0;
    int fd_p[2];
    int fd_d[2];
    srand(time(NULL));

    pipe(fd_p);
    pipe(fd_d);

    pid_p = fork();
    if (pid_p == 0) {
        close(fd_p[PIPE_RD]);
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
            while (1) {
                numero = rand() % 101;
                if (numero % 2 == 1) {
                    write(fd_d[PIPE_WR], &numero, sizeof(numero));
                }
            }
        } else if (pid_d > 0) {
            // close
            // close
            while (1) {
                read(fd_p[PIPE_RD], &p, sizeof(p));
                read(fd_d[PIPE_RD], &d, sizeof(d));
                s = p + d;
                printf("%d = %d + %d\n", s, p, d);
                if (s >= 190) {
                    kill(pid_p, SIGTERM);
                    kill(pid_d, SIGTERM);
                    break;
                }
            }
        }
    }

    return 0;
}
