#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 11

void MergeSort(int array[], int i, int f){
    if(i < f){
      int m = (i + f) / 2;
      MergeSort(array, i, m);
      MergeSort(array, m, f );
      Merge(array, i, m, f)
    }
}

void Merge(int array[], int sx, int cx, int dx){
    int j = 0, k_1 = sx, k_2 = cx;
    int X[];
    X = calloc((dx - sx + 1), sizeof(int));
    while(k_1 <= cx && k_2 <= dx - 1){

    }
}


int main(){


}
