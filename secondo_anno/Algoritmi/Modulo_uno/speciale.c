#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int special(int arr[], int N) {
    int SP, SF = 0;
    for (int i = 0; i < N; i++) {
        SP += arr[i];
    }
    for (int i = 0; i < N; i++) {
        SF += arr[i];
        SP -= arr[i];
        if (SF > SP) {
            return i;
        }
    }
}

int main() {
    int array[] = {3, 4, 7, 10, 3, 2, 1};
    int len = sizeof(array) / sizeof(int);
    int i = special(array, len);
    printf("%d\n", i);
}
