#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t s_pid, e_pid;
    int fd;
    int fd_s[2];
    int fd_e[2];
    const char filepath[] = "data/input.txt";

    struct stat FileName;
    stat(filepath, &FileName);
    int len_file = FileName.st_size;
    int len_buffer = len_file / 2;
    int perm = FileName.st_mode & S_IRUSR;

    pipe(fd_s);
    pipe(fd_e);

    char buffer[len_buffer];

    s_pid = fork();
    if (s_pid == 0) {
        if (!perm) {
            fprintf(stderr, "Non ci sono permessi\n");
            exit(-1);
        }
        close(fd_s[PIPE_RD]);
        fd = open(filepath, O_RDONLY);
        read(fd, &buffer, len_buffer);
        write(fd_s[PIPE_WR], &buffer, len_buffer);
        close(fd);
    } else if (s_pid > 0) {
        e_pid = fork();
        if (e_pid == 0) {
            if (!perm) {
                fprintf(stderr, "Non ci sono i permessi\n");
                exit(-1);
            }
            close(fd_e[PIPE_RD]);
            fd = open(filepath, O_RDONLY);
            lseek(fd, len_buffer, SEEK_SET);
            read(fd, &buffer, len_buffer);
            write(fd_e[PIPE_WR], &buffer, len_buffer);
            close(fd);
        } else if (e_pid > 0) {
            close(fd_s[PIPE_WR]);
            close(fd_e[PIPE_WR]);

            read(fd_s[PIPE_RD], &buffer, len_buffer);
            waitpid(s_pid, NULL, 0);
            printf("[%d] --> %s", s_pid, buffer);
            printf("------------------------------------------");
            read(fd_e[PIPE_RD], &buffer, len_buffer);
            waitpid(e_pid, NULL, 0);
            printf("[%d] --> %s", e_pid, buffer);
        }
    }
    close(fd_s[PIPE_WR]);
    close(fd_e[PIPE_WR]);
    return 0;
}
