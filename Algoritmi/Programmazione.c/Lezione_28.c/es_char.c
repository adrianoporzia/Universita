#include <stdio.h>

//ESERCIZIO LEZIONE 27
//char swirch_case( char c); se ci stava prima funzione main
//lista prototipi e vabene anche char switch_case(c);

char switch_case(char c);//PROTOTIPO



void main (){
      char c= 'd' , c_out;
      printf("%c - %c\n" , c, switch_case(c));
      
      c='E';
      printf("%c - %c\n" , c, switch_case(c));
      
      c='0';
      c_out=switch_case(c);
      if ( c_out==-1)
         printf("%c non è una letterna\n", c);
      else
         printf("%c - %c\n" , c, c_out);
  }
  
  
  
 
	char switch_case(char c){
		 if ( c >= 'A' &&  c <= 'Z'){ //test se c è maiuscolo
			return 'a' + c - 'A';
		 } else if ( c >= 'a' &&  c <= 'z'){
			 return 'A' + c - 'a';
		 } else {
			  return -1;
		 }
	}
// ARRAY= si possono fare sequenze di lunghezza fissata con elementi tutti dello stesso tipo.

  
