/*Generare due processi figli che comunicano con il padre.
• Uno dei processi genera numeri casuali [0-50] ed invia al padre solo i numeri multipli di 3.
• L’altro processo genera numeri casuali [51-100] ed invia al padre solo i numeri multipli di 2.
• Il padre stampa i numeri ricevuti ed esegue la loro somma quando la somma > 300*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    srand(time(NULL));
    pid_t pid_0, pid_1;
    int num_0 = 0, num_1 = 0, sum = 0, n = 0;
    int fd_0[2];
    int fd_1[2];

    pipe(fd_0);
    pipe(fd_1);

    pid_0 = fork();
    if (pid_0 == 0) {
        close(fd_0[PIPE_RD]);
        while (1) {
            n = rand() % 51;
            if (n % 3 == 0) {
                write(fd_0[PIPE_WR], &n, sizeof(n));
            }
        }
    } else if (pid_0 > 0) {
        pid_1 = fork();
        if (pid_1 == 0) {
            close(fd_1[PIPE_RD]);
            while (1) {
                n = rand() % 51;
                n += 50;
                if (n % 2 == 0) {
                    write(fd_1[PIPE_WR], &n, sizeof(n));
                }
            }
        } else if (pid_1 > 0) {
            close(fd_0[PIPE_WR]);
            close(fd_1[PIPE_WR]);
            while (1) {
                read(fd_0[PIPE_RD], &num_0, sizeof(num_0));
                sum += num_0;
                printf("Sono il processo %d e sto sommando il numero %d, [SUM] --> %d\n", pid_0, num_0, sum);

                read(fd_1[PIPE_RD], &num_1, sizeof(num_1));
                sum += num_1;
                printf("Sono il processo %d e sto sommando il numero %d, [SUM] -->%d\n", pid_1, num_1, sum);

                printf("%d = %d + %d\n", sum, num_0, num_1);
                if (sum > 300) {
                    kill(pid_0, SIGTERM);
                    kill(pid_1, SIGTERM);
                    break;
                }
            }
        }
    }
    close(fd_0[PIPE_RD]);
    close(fd_1[PIPE_RD]);
    return 0;
}
