#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t pid_s, pid_e;
    const char pathfile[] = "data/input.txt";
    int fd;

    int fd_s[2];
    int fd_e[2];
    pipe(fd_s);
    pipe(fd_e);

    struct stat FileStat;
    stat(pathfile, &FileStat);
    int len_file = FileStat.st_size;
    int len_buffer = len_file / 2;
    int perm = FileStat.st_mode & S_IRUSR;

    char buffer[len_buffer];

    pid_s = fork();
    if (pid_s == 0) {
        close(fd_s[PIPE_RD]);
        if (!perm) {
            fprintf(stderr, "Non ci sono permessi\n");
            exit(-1);
        }
        fd = open(pathfile, O_RDONLY);
        read(fd, &buffer, len_buffer);
        write(fd_s[PIPE_WR], &buffer, len_buffer);
        close(fd);

    } else if (pid_s > 0) {
        pid_e = fork();
        if (pid_e == 0) {
            close(fd_e[PIPE_RD]);
            if (!perm) {
                fprintf(stderr, "Non ci sono permessi\n");
                exit(-1);
            }
            fd = open(pathfile, O_RDONLY);
            lseek(fd, len_buffer, SEEK_SET);
            read(fd, &buffer, len_buffer);
            write(fd_e[PIPE_WR], &buffer, len_buffer);
            close(fd);
        } else if (pid_e > 0) {
            close(fd_s[PIPE_WR]);
            close(fd_e[PIPE_WR]);
            read(fd_s[PIPE_RD], &buffer, len_buffer);
            waitpid(pid_s, NULL, 0);
            printf("[%d]--> %s\n", pid_s, buffer);
            printf("---------------------------------------\n");
            read(fd_e[PIPE_RD], &buffer, len_buffer);
            waitpid(pid_e, NULL, 0);
            printf("[%d]--> %s\n", pid_e, buffer);

            kill(pid_s, SIGTERM);
            kill(pid_e, SIGTERM);
        }
    }
    return 0;
}
