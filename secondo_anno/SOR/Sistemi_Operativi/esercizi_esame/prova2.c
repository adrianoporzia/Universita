#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define STDIN 0
#define STDOUT 1

int main() {
    pid_t pid_A, pid_B;
    char a = 'A', b = 'B';
    int fd_A[2];
    int fd_B[2];

    pipe(fd_A);
    pipe(fd_B);

    pid_A = fork();
    if (pid_A == 0) {
        close(STDIN);
        close(STDOUT);
        close(fd_A[PIPE_RD]);

        while (1) {
            write(fd_A[PIPE_WR], &a, sizeof(a));
        }
    } else if (pid_A > 0) {

        pid_B = fork();
        if (pid_B == 0) {
            close(STDIN);
            close(STDOUT);
            close(fd_B[PIPE_RD]);
            while (1) {
                write(fd_B[PIPE_WR], &b, sizeof(b));
            }
        } else if (pid_B > 0) {
            close(STDIN);
            while (1) {
                read(fd_A[PIPE_RD], &a, sizeof(a));
                read(fd_B[PIPE_RD], &b, sizeof(b));
                printf("\n");
                write(STDOUT, &a, sizeof(a));
                printf("--\n");
                write(STDOUT, &b, sizeof(b));
                printf("\n");
            }
        }
    }
}
