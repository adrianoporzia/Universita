#include <stdio.h>
#include <stdlib.h>

int str_cmp(char *, char *);
int str_cmp_n(char *, char *, int);
int str_cpy(char *, char *);
int str_len(char *);
void str_cat(char *, char *);

int str_cmp(char *s1, char *s2) {
    if (s1 > s2) {
        printf("La stringa 1 = [%s] ha un valore maggiore di 2 = [%s]\n", s1, s2);
        return 1;
    } else if (s2 > s1) {
        printf("La stringa 2 =[%s] ha un valore maggiore di 1 = [%s]\n", s2, s1);
        return -1;
    }
    int x = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    printf("Le stringhe [%s] e [%s] sono uguali\n", s1, s2);
    return 0;
}

int str_cmp_n(char *s1, char *s2, int n) {
    int i = 0;
    while (i <= n) {
        if (s1[i] > s2[i]) {
            printf("La stringa 1 = [%s] ha un valore maggiore di 2 = [%s]\n", s1, s2);
            return 1;
        } else if (s2[i] > s1[i]) {
            printf("La stringa 2 =[%s] ha un valore maggiore di 1 = [%s]\n", s2, s1);
            return -1;
        } else
            i++;
    }
    int x = 0;
    for (int i = 0; i <= n; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    printf("Le stringhe [%s] e [%s] sono uguali\n", s1, s2);
    return 0;
}
int str_cpy(char *s1, char *s2) {
    // s1 è la destinazione e s2 originale
    int i = 0;
    while (s2[i] != '\0' && s1[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    printf("%s e %s", s1, s2);
    return 0;
}

int str_len(char *s1) {
    int len = 0, i = 0;
    while (s1[i] != '\0') {
        len++;
        i++;
    }
    printf("La lunghezza della stringa [%s] è %d\n", s1, len);
    return 0;
}

void str_cat(char *s1, char *s2) {
    char *cat = malloc((str_len(s1) + str_len(s2)) * sizeof(char));
    int i = 0;
    while (s1[i] != '\0') {
        cat[i] = s1[i];
        i++;
    }
    while (s2[i] != '\0') {
        cat[i] = s2[i];
        i++;
    }
    printf("%s\n", cat);
}
int main() {
    char *s1 = "Cia";
    char *s2 = "mondo";
    char *s3 = "Ci  ao";
    str_cat(s1, s2);
    // int y = str_cmp_n(s1, s2, 4);
}
