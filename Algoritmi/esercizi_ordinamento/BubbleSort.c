#include <stdio.h>


void BubbleSort(int A[] , int n );
void swap(int *, int*);



int main(){
    int a[]={7, 2, 4, 5, 3, 1};
    int n= sizeof(a)/sizeof(int);
    int i=0;
    BubbleSort(a, n);

    for(i; i< n ; i++){
        printf("%d ", a[i]);
    }


}

void BubbleSort(int A[], int n){
    int i=0;
    int k=0;
    int t=0;
    for (k; k < n ; k++){
        for(i=0; i < n -k- 1; i++){
            if(A[i] > A[i+1]){
                t = A[i];
                A[i]= A[i+1];
                A[i+1]= t;     
            }
        }


    }

}
/*
void swap( int *a, int *b){
    int t;
    t= *a;
    *a = *b;
    *b = t;
    return
}
*/