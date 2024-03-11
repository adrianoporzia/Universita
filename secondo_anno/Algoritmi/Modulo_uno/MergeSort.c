#include <stdio.h>

void Merge(A, i, f1, f2);

int main() {
}

void Merge(int A[], int i, int f1, int f2) {
    int X[f2 - i];
    int j = 0;
    int k1 = i;
    int k2 = f1 + 1;

    while (k1 <= f1 && k2 <= f2) {
        if (A[k1] <= A[k2]) {
            X[j] = A[k1];
            j++;
            k1++;
        } else {
            X[j] = A[k2];
            j++;
            k2++;
        }
        if (k1 <= f1) {
            for (int l = k1; l < f1; l++) {
                A[l] = X[0];
            }
        }

        else {
            for (int v = k2; v < f2; v--) {
                A[v] = X[0];
            }
            for (j; j < f2; j++) {
                A[j] = X[j];
            }
        }
    }
