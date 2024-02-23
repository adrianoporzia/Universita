#include <stdio.h>
#include <string.h>

int lunghezza_sovrapposizione(char s1[], char s2[]) {
    int lunghezza_s1 = strlen(s1);
    int lunghezza_s2 = strlen(s2);
    int maxSovrapposizione = 0;

    
    for (int i = 0; i < lunghezza_s1; i++) {
        int sovrapposizione = 0;
        int j = i;

        while (s1[j] != '\0' && s2[sovrapposizione] != '\0' && s1[j] == s2[sovrapposizione]) {
            sovrapposizione++;
            j++;
        }

        if (sovrapposizione > maxSovrapposizione) {
            maxSovrapposizione = sovrapposizione;
        }
    }

    return maxSovrapposizione;
}

void visualizza_intersezione(char s1[], char s2[], int sovrapposizione) {
    int lunghezza_s1 = strlen(s1);
    int lunghezza_s2 = strlen(s2);
    int inizio_intersezione = lunghezza_s1 - sovrapposizione;

    printf("%s\n", s1);

    for (int i = 0; i < inizio_intersezione; i++) {
        printf(" ");
    }

    printf("%s\n", s2);
}

int main() {
    char s1[101];
    char s2[101];

    printf("Inserisci la stringa s1: ");
    scanf("%s", s1);

    printf("Inserisci la stringa s2: ");
    scanf("%s", s2);

    int maxSovrapposizione = lunghezza_sovrapposizione(s1, s2);

    printf("La massima lunghezza di sovrapposizione è %d\n", maxSovrapposizione);

    printf("Intersezione:\n");
    visualizza_intersezione(s1, s2, maxSovrapposizione);

    return 0;
}
