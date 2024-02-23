#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define PIPE_WR 1
#define PIPE_RD 0

int main() {

    pid_t s_pid, e_pid; // start pid e end pid
    int fd_s[2];
    int fd_e[2];
    int fd;
    const char pathfile[] = "data/input.txt";

    struct stat fileStat;
    stat(pathfile, &fileStat);
    int len_file = fileStat.st_size;
    int len_buffer = len_file / 2;
    int perm = fileStat.st_mode & S_IRUSR;
    pipe(fd_s);
    pipe(fd_e);

    char buffer[len_buffer];

    // fd = open(pathfile, O_RDONLY); // Apre il file di origine
    // if (fd < 0 )
    // perror("file non in sola lettura"); // Se non può aprirlo, esce

    s_pid = fork();
    if (s_pid == 0) {
        close(fd_s[PIPE_RD]);
        if (!perm) {
            fprintf(stderr, "non ci sono permessi\n");
            exit(-1);
        }
        fd = open(pathfile, O_RDONLY);
        read(fd, &buffer, len_buffer);
        write(fd_s[PIPE_WR], &buffer, len_buffer);
        close(fd);
    } else if (s_pid > 0) {
        e_pid = fork();
        if (e_pid == 0) {
            close(fd_e[PIPE_RD]);
            if (!perm) {
                fprintf(stderr, "non ci sono permessi\n");
                exit(-1);
            }
            fd = open(pathfile, O_RDONLY);
            lseek(fd, len_buffer, SEEK_SET);
            read(fd, &buffer, len_buffer);
            write(fd_e[PIPE_WR], &buffer, len_buffer);
            close(fd);
        } else if (e_pid > 0) {
            close(fd_e[PIPE_WR]);
            close(fd_s[PIPE_WR]);
            read(fd_s[PIPE_RD], &buffer, len_buffer);
            waitpid(s_pid, NULL, 0);
            printf("[%d] --> %s\n", s_pid, buffer);
            printf("----------------------------------------------\n");
            read(fd_e[PIPE_RD], &buffer, len_buffer);
            waitpid(e_pid, NULL, 0);
            printf("[%d] --> %s\n", e_pid, buffer);
        }
    }
    return 0;
}
