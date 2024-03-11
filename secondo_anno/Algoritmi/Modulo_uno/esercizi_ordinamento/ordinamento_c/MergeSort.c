// da sistemare, non corretto

#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 11

void StampaArray(int array[], int len) {
    printf("[");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[len - 1]);
}

void Concatena(int array[], int X[], int i, int f) {
    for (int i = 0; i <= f; i++) {
        X[i] = array[i];
    }
}

void Merge(int array[], int sx, int cx, int dx) {
    int j = 0, k1 = sx, k2 = cx + 1;
    int *X = (int *)calloc((dx - sx), sizeof(int));
    while (k1 <= cx && k2 <= dx) {
        if (array[k1] < array[k2]) {
            X[j] = array[k1];
            j++;
            k1++;
        } else {
            X[j] = array[k2];
            j++;
            k2++;
        }
    }
    if (k1 <= cx) {
        Concatena(array, X, k1, cx);
    } else {
        Concatena(array, X, k2, dx);
    }
    Concatena(X, array, sx, dx);
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Trovare il punto medio dell'array
        int m = l + (r - l) / 2;

        // Ordinare la prima e la seconda metà
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        // Unire le due metà ordinate
        Merge(arr, l, m, r);
    }
}

int main() {
    int array[] = {7, 2, 4, 5, 3, 1, 5, 6};
    int len = sizeof(array) / sizeof(int);
    MergeSort(array, 0, len - 1);
    StampaArray(array, len);
    return 0;
}
