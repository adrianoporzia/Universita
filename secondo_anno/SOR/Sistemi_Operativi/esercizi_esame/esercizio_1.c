#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t pid_pari, pid_dispari;
    int s = 0, p = 0, d = 0;
    int fd_pari[2];
    int fd_dispari[2];
    int numero;

    pipe(fd_pari);
    pipe(fd_dispari);

    pid_pari = fork();

    if (pid_pari == 0) {
        close(STDIN);
        close(STDOUT);
        close(fd_pari[PIPE_RD]);

        while (1) {
            numero = rand() % 101;
            if (numero % 2 == 0) {
                write(fd_pari[PIPE_WR], &numero, sizeof(numero));
            }
        }
    } else {
        pid_dispari = fork();

        if (pid_dispari == 0) {
            close(STDIN);
            close(STDOUT);
            close(fd_dispari[PIPE_RD]);

            while (1) {
                numero = rand() % 101;
                if (numero % 2 == 1) {
                    write(fd_dispari[PIPE_WR], &numero, sizeof(numero));
                }
            }
        }

        if (pid_dispari > 0) {

            while (1) {
                read(fd_dispari[PIPE_RD], &d, sizeof(d));
                read(fd_pari[PIPE_RD], &p, sizeof((p)));
                s = d + p;

                printf("%d + %d = %d\n", d, p, s);
                if (s <= 10) {
                    kill(pid_dispari, SIGTERM);
                    kill(pid_pari, SIGTERM);
                    break;
                }
            }
        }
    }

    close(fd_pari[PIPE_RD]);
    close(fd_dispari[PIPE_RD]);

    return 0;
}
