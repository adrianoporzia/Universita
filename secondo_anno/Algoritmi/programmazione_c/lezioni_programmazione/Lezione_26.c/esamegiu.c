#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrice[20][20];
    int sommaL, sommaR;
    int asse = -1;
    int i, j, k;

    
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            int valore = rand() % 41 - 20;

            
            for (k = 0; k < i; k++) {
                if (matrice[k][j] == valore) {
                    valore = rand() % 41 - 20;
                    k = -1; 
                }
            }

            matrice[i][j] = valore;
        }
    }

    
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%3d ", matrice[i][j]);
        }
        printf("\n");
    }

    
    k = 0;
    while (k < 20 && asse == -1) {
        sommaL = 0;

        
        for (j = 0; j < k; j++) {
            for (i = 0; i < 20; i++) {
                sommaL += matrice[i][j];
            }
        }

        sommaR = 0;

        
        for (j = k + 1; j < 20; j++) {
            for (i = 0; i < 20; i++) {
                sommaR += matrice[i][j];
            }
        }

        
        if (abs(sommaL - sommaR) <= 10) {
            asse = k;
        }

        k++;
    }

    
    if (asse != -1) {
        printf("\nAsse verticale trovato nella colonna %d\n", asse);
        printf("Somma a sinistra: %d\n", sommaL);
        printf("Somma a destra: %d\n", sommaR);
    } else {
        printf("\nNessun asse verticale trovato.\n");
    }

    return 0;
}
