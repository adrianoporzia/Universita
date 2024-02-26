#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 11

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
}
