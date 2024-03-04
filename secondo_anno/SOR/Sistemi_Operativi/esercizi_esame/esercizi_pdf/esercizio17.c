/*


Due processi leggono dallo stesso file che si trova all'interno di una directory, (es. /data/file.txt).

Alternativa - Usare dirent e readdir per leggere all'interno della directory e controllare se il file esiste o meno.

Controllare che il file sia in modalità lettura, altrimenti restituire errore.

Alternativa - invece di restituire un errore, cambiare i permessi al file con chmod.

    Il primo processo legge dall'inizio del file fino a metà,
    Il secondo legge dalla metà in poi. I figli mandano il contenuto al padre
    Il padre lo stampa nel seguente formato: [PID_FIGLIO] -> TESTO

 * */

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

#define PIPE_RD 0
#define PIPE_WR 1

int main() {
    pid_t pid_s, pid_e;
    int fd_s[2];
    int fd_e[2];
    pipe(fd_s);
    pipe(fd_e);
    const char *filename = "data/input.txt";

    struct stat filestat;
    stat(filename, &filestat);
    int len_file = filestat.st_size;
    int len_buffer = len_file / 2;
    int perm = filestat.st_mode & S_IRUSR;
    int fd;

    char buffer[len_buffer];

    pid_s = fork();
    if (pid_s == 0) {
        if (!perm) {
            fprintf(stderr, "NON CI SONO PERMESSI\n");
            exit(-1);
        }
        close(fd_s[PIPE_RD]);
        fd = open(filename, O_RDONLY);
        read(fd, &buffer, len_buffer);
        write(fd_s[PIPE_WR], &buffer, len_buffer);
        close(fd);
    } else if (pid_s > 0) {
        pid_e = fork();
        if (pid_e == 0) {
            if (!perm) {
                fprintf(stderr, "NON CI SONO PERMESSI\n");
                exit(-1);
            }
            close(fd_e[PIPE_RD]);
            fd = open(filename, O_RDONLY);
            lseek(fd, len_buffer, SEEK_SET);
            read(fd, &buffer, len_buffer);
            write(fd_e[PIPE_WR], &buffer, len_buffer);
            close(fd);

        } else if (pid_e > 0) {
            close(fd_s[PIPE_WR]);
            close(fd_e[PIPE_WR]);
            read(fd_s[PIPE_RD], &buffer, len_buffer);
            printf("[%d] --> %s\n", pid_s, buffer);
            printf("------------------------\n");
            read(fd_e[PIPE_RD], &buffer, len_buffer);
            printf("[%d] --> %s", pid_e, buffer);
            pthread_kill(pid_s, SIGTERM);
            pthread_kill(pid_e, SIGTERM);
        }
    }

    close(fd_s[PIPE_RD]);
    close(fd_e[PIPE_RD]);
    return 0;
}
