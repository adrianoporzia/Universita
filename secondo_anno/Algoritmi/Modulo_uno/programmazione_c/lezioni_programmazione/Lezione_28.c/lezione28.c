#include <stdio.h>

void change_array(int x[], int n){
    for(i=0; i<n; i++){
        x[i]=10*i;
    }
    x[6]= 999;
    printf("***%d\n", sizeof(x));  //intero a 8 byte, indirizzo ddi memoria
}
void main(){
     int a[10];                      //array di 10 inter non definiti
     int b[]= {0, 10, 20, 30, 40};  //array non definisco numero di elementi ma li definisco
     int c[5]= {0, 10, 20, 30, 40};
     int d[15]= {0, 10, 20, 30, 40};// dal 6 in poi sono definiti come 0
     int e[100]= {0};               // tutti 0 
     int i, len_d;
     //indicizazzione predno elementi come python
     d[11]=21;
     printf("%d, %d, %d, %d, %d,%d\n", a[4], b [0], c[2], d[10], e[97]);
     len_d=sizeof(d)/sizeof(int);//stampa numero elementi
     printf("%d\n", len_d);
     printf("%d\n", sizeof (d)); //stampa numero di byte non di elementi
     
     for (i=0; i< len_d; i++){
          printf("%d\n", d[i]);
     }
     change_array(d,len_d);
     printf("%d\n", d[6]);
     // costo per accedere ad array è costante in lettura, perchè un array in memoria è un blocco consecutivo di memoria e tutti gli elementi di array sono uguali e occupano stesso spazio. Ma voglio leggere elemento in posizione k, quanto mi costa? Mi costa 2-3 operazioni perche so dove inizia array(p),p+k volte trovo poszione (somma e prodotto)
}


 //funzione che prende in input un array e lo modifica
 
 
