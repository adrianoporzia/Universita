#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define PIPE_RD 0
#define PIPE_WR 1

int str_comp(const char str_2[], char str_1[]) {
    if (strcmp(str_1, str_2) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    pid_t pid_s, pid_h; // pid_start e pid_half
    int n_1 = 0, n_2 = 0;
    int fd_s[2];
    int fd_h[2];
    int fd; // fd per file
    pipe(fd_s);
    pipe(fd_h);

    const char filepath[] = "data/input.txt";
    const char word[] = "Letraset";
    int len_word = strlen(word);

    struct stat FileStat;
    stat(filepath, &FileStat);
    int len_file = FileStat.st_size;
    int half = len_file / 2;

    char buffer[len_word + 1];

    pid_s = fork();
    if (pid_s == 0) {
        fd = open(filepath, O_RDONLY);
        close(fd_s[PIPE_RD]);
        int count = 0, i = 0;
        while (i <= half) {
            read(fd, &buffer, sizeof(buffer));
            buffer[len_word] = '\0';
            count += str_comp(word, buffer);
            i++;
            lseek(fd, i, SEEK_SET);
        }
        write(fd_s[PIPE_WR], &count, sizeof(count));
        close(fd);

    } else if (pid_s > 0) {
        pid_h = fork();
        if (pid_h == 0) {
            fd = open(filepath, O_RDONLY);
            close(fd_h[PIPE_RD]);
            int count = 0, i = half;
            while (i + len_word <= len_file) {
                lseek(fd, i, SEEK_SET);
                read(fd, &buffer, sizeof(buffer));
                buffer[len_word] = '\0';
                count += str_comp(word, buffer);
                i++;
            }
            write(fd_h[PIPE_WR], &count, sizeof(count));
            close(fd);

        } else if (pid_h > 0) {
            close(fd_s[PIPE_WR]);
            close(fd_h[PIPE_WR]);
            printf("[%s]\n", word);
            read(fd_s[PIPE_RD], &n_1, sizeof(n_1));
            printf("Nella prima metà ci sono %d occorrenze della parola\n", n_1);
            read(fd_h[PIPE_RD], &n_2, sizeof(n_2));
            printf("Nella seconda metà ci sono %d occorrenze della parola\n", n_2);

            kill(pid_s, SIGTERM);
            kill(pid_h, SIGTERM);
            exit(0);
        }
    }
    close(fd_s[PIPE_RD]);
    close(fd_h[PIPE_RD]);
    return 0;
}
