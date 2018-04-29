#include <stdio.h> 
#include “tokens.h”

int yylex ();	// scanner prototype
extern char* yytext;
	
main () 
{ 	int n; 
	while ( n = yylex() )                          // call scanner until it returns 0 for EOF 
		printf (" %d  %s\n", n, yytext);   // output the token code and lexeme string 
} 