#include <stdio.h>

void SelectionSort(int array[], int dimensione){
    int k=0;
    int m;
    int j = 0;
    int c= 0;

    for (k; k< dimensione - 1; k++){
        m = k;
        for (j=k+1; j < dimensione; j++){
            if (array[j] < array[m]){
                m = j;
                }
        }
        c= array[k];
        array[k]= array[m];
        array[m]= c;
        }
    }

int main(){
    int A[] = {2, 4, 7, 10, 15, 6, 8, 12, 9, 3};
    int dimensione= sizeof(A)/sizeof(int);
    int i=0;
    SelectionSort(A, dimensione);
    for (i; i< dimensione; i++){
        printf("%d ", A[i]);
    }
    return 0;
}
