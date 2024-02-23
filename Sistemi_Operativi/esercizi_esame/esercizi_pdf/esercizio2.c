/*Due processi leggono dallo stesso file che si trova all’interno di una directory, (es. /data/file.txt). Controllare
che il file sia in modalità lettura, altrimenti restituire errore.
• Il primo processo legge dall’inizio del file fino a metà,
• Il secondo legge dalla metà in poi. I figli mandano il contenuto al padre
• Il padre lo stampa nel seguente formato: [PID_FIGLIO] -> TESTO*/
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
    int fd_s[2];
    int fd_e[2];
    int fd;
    const char pathfile[] = "data/input.txt";

    pipe(fd_s);
    pipe(fd_e);

    struct stat filestat;
    stat(pathfile, &filestat);
    int len_file = filestat.st_size;
    int len_buffer = len_file / 2;
    int perm = filestat.st_mode & S_IRUSR;

    char buffer[len_buffer];

    pid_s = fork();
    if (pid_s == 0) {
        if (!perm) {
            fprintf(stderr, "NON CI SONO I PERMESSI\n");
            exit(-1);
        }
        close(fd_s[PIPE_RD]);
        fd = open(pathfile, O_RDONLY);
        read(fd, &buffer, len_buffer);
        write(fd_s[PIPE_WR], &buffer, len_buffer);
        close(fd);
    }
    if (pid_s > 0) {
        pid_e = fork();
        if (pid_e == 0) {
            if (!perm) {
                fprintf(stderr, "NON CI SONO I PERMESSI\n");
                exit(-1);
            }
            close(fd_e[PIPE_RD]);
            fd = open(pathfile, O_RDONLY);
            lseek(fd, len_buffer, SEEK_SET);
            read(fd, &buffer, len_buffer);
            write(fd_e[PIPE_WR], &buffer, len_buffer);
            close(fd);
        }
    }
    if (pid_e > 0) {
        close(fd_s[PIPE_WR]);
        close(fd_e[PIPE_WR]);
        read(fd_s[PIPE_RD], &buffer, len_buffer);
        printf("[%d]--> %s \n", pid_s, buffer);
        printf("-----------------------------------\n");
        read(fd_e[PIPE_RD], &buffer, len_buffer);
        printf("[%d]--> %s \n", pid_e, buffer);
        kill(pid_s, SIGTERM);
        kill(pid_e, SIGTERM);
    }
    return 0;
}
