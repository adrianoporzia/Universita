
#include <stdio.h>
#include <stdlib.h>

struct array_int {
	int *a;
	int n;
	int c;
};
typedef struct array_int array_int;


array_int array_int_init(void);
array_int array_int_append( array_int, int );
void array_int_print(array_int);
array_int array_int_pop(array_int);
array_int delete(array_int v, int i);

void main(){
	array_int v = array_int_init();
	int i, n = 24; 
	

	array_int_print(v);
	
	for(i = 0; i < n; i++){ // O(n^2)
		v = array_int_append(v, i);
			printf("n = %d; c = %d\n", v.n, v.c);

	}
	
	array_int_print(v);
	printf("--------------");
	
	v= delete(v, 3);
	
	array_int_print(v);

	
	while( v.n > 0 ){
		v = array_int_pop(v);
		array_int_print(v);
		printf("n = %d; c = %d\n", v.n, v.c);
	}

}


array_int delete(array_int v, int i){
    int j;
	
	for(j=i; j< v.n ; j++){
		v.a[j]= v.a[j+1];
		}
		if(v.n < v.c/4){
			v.a= realloc(v.a, (v.c/2+1)*sizeof(int));
			v.c= v.c/2+1;
		}
		v.n--;
		return v;
	}




array_int array_int_init(void){ // O(1)
	array_int v = {NULL, 0, 0};
	return v;
}




array_int array_int_append( array_int v, int e ){
		
	if (  v.n == v.c ){
		v.a = realloc(v.a, (2*v.c+1)*(sizeof(int)));
		v.c = v.c*2+1;
	}
	v.a[v.n] = e;
	v.n++;
	
	return v;
	
	/*
	 * Complessità temporale è O(1) nel caso medio (n append consecutive costano O(n))
	 * Complessità spaziale O(n) perché nel caso peggiore viene usata la metà della memoria allocata 
	 * 
	 * */
}

void array_int_print(array_int v){ // O(v.n)
	int i;
	
	printf("[");
	for( i = 0 ; i < v.n; i++){
		printf("%d,", v.a[i]);
	}
	printf("]\n");
}

array_int array_int_insert( array_int v, int pos, int e) {
	int old_c = v.c, old_n = v.n;
	int i;
	
	if (pos > v.n)
		return v;
	
	v = array_int_append(v, 0);
	
	if (old_c == old_n && old_c == v.c){ // malloc dentro append ritorna NULL
		return v;
	}
	
	for( i = v.n-1; i >= pos; i--){
		v.a[i+1] = v.a[i];
	}
	
	v.a[pos] = e;
	
	return v;
}

array_int array_int_pop(array_int v ){
	if (v.n > 0)
		v.n--;
	return v;
}
