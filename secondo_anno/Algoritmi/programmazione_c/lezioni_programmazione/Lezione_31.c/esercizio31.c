#include <stdio.h>
#include <stdlib.h>

struct array_int {
    int *a;
    int n;
    int c;
};
typedef struct array_int array_int;

array_int trovaspazi(char *a);
array_int append_array( array_int v, int e );
void printarray(array_int c);

void main(){
    char a[]= "programmazione dei calcolatori";
    char *p= a;
    array_int c;

    
    c=trovaspazi(p);
    printarray(c);
    
    
    }
void printarray(array_int c){
    int n;
    for (n=0; n<c.n; n++){
        printf("%d ", c.a[n]);
        }
        printf("\n");
    }

array_int append_array( array_int v, int e ){
    int i;
    int *a = malloc((v.n+1)*sizeof(int));
    
    if ( a != NULL) { // malloc e' andata a buon fine
        for(i = 0; i < v.n; i++){
            a[i] = v.a[i]; // ORRORE :-) significa a[i] = x[i]
        }
        a[v.n] = e;
        v.n++;
        free(v.a);
        v.a = a;
    }
    
    
    return v;
}


 
array_int trovaspazi(char *a){
    int n=0;
    array_int v={NULL, 0, 0 };

    while ( a[n] != '\0'){
        if (a[n]== ' '){
            v= append_array(v, n);
            
            }
        n++;
    }
    return v;
}

