#include <stdio.h>

void InsertionSort(int A[], int n);

int main(){
    int a[] = {7,2,4,5,3,1};
    int n = sizeof(a)/ sizeof (int);
    InsertionSort(a, n);

    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void InsertionSort(int A[], int n){
    int t = 0;
    int x = 1;
    for (int i = x; i < n; i++){
        while( i > 0 ){
            if(A[i]< A[i-1]){
                t = A[i];
                A[i] = A[i-1];
                A[i-1]= t;

            }
            i--;
        }
        x++;
    } 
}