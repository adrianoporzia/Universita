#include <stdio.h>
#include <stdlib.h>


int str_cmp(char *a, char *b); //La funzione ritorna 0 se le due stringhe sono uguali; ritorna -1 se a precede b lessicograficamente e +1 altrimenti.

int main(){
    char a[]="ciao";
    char b[]="ciaone";
    int n;

	
	n=str_cmp(a, b);
	printf("%d\n", n);


}


int str_cmp(char *a, char *b){
	int i;
	i=0;

	
	if(a[i]>b[i]){
		return -1;
		}
	if(a[i]<b[i]){
		return 1;
		}
	else{
		return 0;
		}
	}

/*
int str_cmp(char *a, char *b){
	int n;
	int i;
    i=0;

		if(a[i]> b[i]){
			n=-1;
			}
		if(a[i] > b[i]){
			n=1;
		}
	return n;

}
*/
