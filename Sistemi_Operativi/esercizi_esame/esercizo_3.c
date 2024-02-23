// tre processi figli, due generano numeri che si sommano e la somma deve essere uguale al numero generato
// dal terzo processo e il padre lo stampa
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t pid_1, pid_2, pid_3;
    int num_1, num_2, num_3, somma;

    int fd_1[2];
    int fd_2[2];
    int fd_3[2];

    pipe(fd_1);
    pipe(fd_2);
    pipe(fd_3);

    pid_1 = fork();
    if (pid_1 == 0) {
        close(fd_1[PIPE_RD]);
        srand(getpid());

        while (1) {
            num_1 = rand() % 10;
            write(fd_1[PIPE_WR], &num_1, sizeof(num_1));
        }
    } else if (pid_1 > 0) {
        pid_2 = fork();
        if (pid_2 == 0) {
            close(fd_2[PIPE_RD]);
            srand(getpid());

            while (1) {
                num_2 = rand() % 10;
                write(fd_2[PIPE_WR], &num_2, sizeof(num_2));
            }
        } else if (pid_2 > 0) {
            pid_3 = fork();
            if (pid_3 == 0) {
                close(fd_3[PIPE_RD]);
                srand(getpid());

                while (1) {
                    num_3 = rand() % 20;
                    write(fd_3[PIPE_WR], &num_3, sizeof(num_3));
                }
            } else if (pid_3 > 0) {
                close(fd_1[PIPE_WR]);
                close(fd_2[PIPE_WR]);
                close(fd_3[PIPE_WR]);
                while (1) {
                    read(fd_1[PIPE_RD], &num_1, sizeof(num_1));
                    read(fd_2[PIPE_RD], &num_2, sizeof(num_2));
                    read(fd_3[PIPE_RD], &num_3, sizeof(num_3));
                    int somma = num_1 + num_2;
                    printf("%d + %d = %d --- %d\n", num_1, num_2, somma, num_3);
                    if (somma == num_3) {
                        kill(pid_1, SIGTERM);
                        kill(pid_2, SIGTERM);
                        kill(pid_3, SIGTERM);
                        break;
                    }
                }
            }
        }
    }
    close(fd_1[PIPE_RD]);
    close(fd_2[PIPE_RD]);
    close(fd_3[PIPE_RD]);
    return 0;
}
