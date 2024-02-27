#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 11

void print_array(int array[], int len) {
    printf("[");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[len - 1]);
}

void append(int array[], int X[], int i, int f) {
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
        append(array, X, k1, cx);
    } else {
        append(array, X, k1, cx);
    }
    append(X, array, sx, dx);
}
void MergeSort(int array[], int i, int f) {

    if (i < f) {
        int m = (i + f) / 2;
        MergeSort(array, i, m - 1);
        MergeSort(array, m, f);
        Merge(array, i, m, f);
    }
}
int main() {
    int array[] = {7, 2, 4, 5, 3, 1, 5, 6};
    int len = sizeof(array) / sizeof(int);
    MergeSort(array, 0, len - 1);
    print_array(array, len);
}
