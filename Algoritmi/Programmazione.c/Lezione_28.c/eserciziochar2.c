#include <stdio.h>

//ESERCIZIO LEZIONE 27
//char swirch_case( char c); se ci stava prima funzione main
//lista prototipi e vabene anche char switch_case(c);

char switch_case(char c);//PROTOTIPO

void main(){
	char c='1';
	printf("%c" ,switch_case(c));
	if (c==-1){
		printf("%c non è una lettera/n", c);
	}
	else{
		printf("%c" ,switch_case(c));
	
	
	}
}









	char switch_case(char c){
		if (c>='A' && c<='Z'){
			return c+'a'-'A';
			}
		if (c>='a' && c<='z'){
			return c+'A'-'a';
			}
		else{
			return c=-1;
			}		
		}
