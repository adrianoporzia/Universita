#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    srand(time(NULL));
    pid_t pid_p, pid_d;
    int fd_p[2];
    int fd_d[2];
    int p, d, s;

    pipe(fd_p);
    pipe(fd_d);

    pid_p = fork();
    if (pid_p == 0) {
        close(fd_p[PIPE_RD]);
        while (1) {
            p = rand() % 101;
            if (p % 2 == 0) {
                write(fd_p[PIPE_WR], &p, sizeof(p));
            }
        }
    } else if (pid_p > 0) {
        pid_d = fork();
        if (pid_d == 0) {
            close(fd_d[PIPE_RD]);
            while (1) {
                d = rand() % 101;
                if (d % 2 == 1) {
                    write(fd_d[PIPE_WR], &d, sizeof(d));
                }
            }
        } else if (pid_d > 0) {
            close(fd_p[PIPE_WR]);
            close(fd_d[PIPE_WR]);
            while (1) {
                read(fd_p[PIPE_RD], &p, sizeof(p));
                read(fd_d[PIPE_RD], &d, sizeof(d));
                s = p + d;
                printf("%d + %d = %d\n", p, d, s);
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
