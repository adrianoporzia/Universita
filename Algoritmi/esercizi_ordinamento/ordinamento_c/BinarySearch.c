#include <stdio.h>

int Binarysearch(int array[], int sx , int dx, int x);

int main(){

    int a[] = {1, 3, 5, 7, 8, 9};
    int n = sizeof(a) / sizeof(int);
    int x = 8;
    int p = BinarySearch(a, 0, n, x);
    printf("%d", p);
    

}

int BinarySearch(int array[], int sx, int dx, int x){

    if(sx <= dx){

        int m = (sx + dx) / 2;

        if (array[m] == x){
            return m;
        }

        else if(array[m] < x){
            BinarySearch(array, m + 1, dx, x);
        }

        else{
            BinarySearch(array, sx, m-1, x);
        }
    }
    else{
        return -1;
    }
        
}