#include <stdio.h>

void IntergerSort(int array[],int n, int k);
int max(int array[], int lunghezza);


int main(){
    int a[] = {7,2,4,5,3,1};
    int n = sizeof(a)/ sizeof (int);
    int k= max(a, n);
    IntergerSort(a, n, k);
    
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void IntergerSort(int A[],int n, int k){

    k++;
    int *X = calloc(k, sizeof(int));
    for(int i = 0; i < n; i++ ){
        X[A[i]]++;
    }
    int j = 0;
    for(int i = 0; i < k; i++){
        while (X[i] > 0){
            A[j] = i;
            j+=1;
            X[i]--;
        }
    }
    free (X);
  
}

int max(int a[], int lunghezza){
    int m=a[0];
    for(int i = 1; i < lunghezza ; i++){
        if (a[i] > m){
            m = a[i];
        }
    }
    return m;
}
