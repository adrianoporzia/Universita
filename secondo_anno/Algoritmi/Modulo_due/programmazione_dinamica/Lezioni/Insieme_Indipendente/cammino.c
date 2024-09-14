#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int *maxx(int *L, int n);
int *path(int *L, int *OPT, int n);

void print_array(int *L, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d, ", L[i]);
    }
    printf("%d]\n", L[n]);
}
int max(int a, int b) {
    if (a >= b) {
        return a;
    } else
        return b;
}

int *maxx(int *L, int n) {
    int *OPT;
    OPT = malloc(n * (sizeof(int)));
    OPT[0] = L[0];
    OPT[1] = max(L[0], L[1]);
    for (int j = 2; j < n; j++) {
        OPT[j] = max(OPT[j - 1], (OPT[j - 2] + L[j]));
    }
    return OPT;
}

int *path(int *L, int *OPT, int n) {
    int *S = malloc((n / 2) * (sizeof(int)));
    int j = n;
    int i = 0;
    while (j >= 3) {
        if (OPT[j - 1] >= (L[j] + OPT[j - 2])) {
            j--;
        } else {
            S[i] = L[j];
            i++;
            j -= 2;
        }
    }
    if ((j == 2) && L[0] < L[1]) {
        S[i] = L[1];
    } else {
        S[i] = L[0];
    }
    return S;
}

int main() {
    int list[] = {1, 4, 8, 4, 3, 10};
    int n = sizeof(list) / sizeof(int);
    int *opt = maxx(list, n);
    int *S = path(list, opt, n);
    int n_s = n / 2;

    print_array(S, n_s);
}
