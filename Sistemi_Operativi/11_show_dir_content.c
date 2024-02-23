#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void printFileInfo(const char *dirName, const char *fileName) {
    struct stat fileInfo;
    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s/%s", dirName, fileName);
    ;
    if (stat(filePath, &fileInfo) < 0) {
        perror("Errore nel recupero delle informazioni del file");
        return;
    }

    printf("%llu ", fileInfo.st_size); // Dimensione del file

    // Permessi del file
    printf((S_ISDIR(fileInfo.st_mode)) ? "d" : "-");
    printf((fileInfo.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileInfo.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileInfo.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileInfo.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileInfo.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileInfo.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileInfo.st_mode & S_IROTH) ? "r" : "-");
    printf((fileInfo.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileInfo.st_mode & S_IXOTH) ? "x" : "-");

    // Proprietario e gruppo
    struct passwd *pw = getpwuid(fileInfo.st_uid);

    struct group *gr = getgrgid(fileInfo.st_gid);
    printf(" %s %s", pw->pw_name, gr->gr_name);

    // Data di ultima modifica
    char dateStr[128];
    strftime(dateStr, sizeof(dateStr), "%b %d %H:%M",
             localtime(&fileInfo.st_mtime));
    printf(" %s", dateStr);

    // Nome del file
    printf(" %s\n", fileName);
}

int main(int argc, char *argv[]) {
    DIR *dirp;             // puntatore alla dirextory che deve essere aperta
    struct dirent *dirent; // puntatore al singolo elemento della dirextory

    if (argc != 2) {
        fprintf(stderr, "Errore: manca inputfile. Uso: %s <directory>\n",
                argv[0]);
        return 1;
    }

    dirp = opendir(argv[1]);
    if (dirp == NULL) {
        perror("Errore nell'apertura della directory");
        return 1;
    }
    dirent = readdir(dirp);
    while (dirent != NULL) {
        printFileInfo(argv[1], dirent->d_name);
        dirent = readdir(dirp);
    }

    closedir(dirp);
    return 0;
}
