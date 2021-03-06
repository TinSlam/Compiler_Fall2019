%{

// Let Lex know the token values generated by the Yacc file. TASK 2. --------------------------------
#include "parser.tab.h"

#include <stdlib.h>
#include <string.h>

void updateCurrentLexeme(const char* str);
char* createString(const char* str);

char* currentLexeme = NULL;

%}

%%

[ \t\n]+	;

[a-zA-Z_0-9]+		{
	updateCurrentLexeme(yytext);
	// Return token values to the parser. TASK 3. ---------------------------------------------------
	return ID; // Is defined in "parser.tab.h".
}

%%

// Remove the main function. TASK 5. ----------------------------------------------------------------
/*
int main(){
	yyin = fopen("input.txt", "r");

	while(yylex());
	
	fclose(yyin);
}
*/

void updateCurrentLexeme(const char* str){
	if(currentLexeme != NULL){
		free(currentLexeme);
		currentLexeme = NULL;
	}
	currentLexeme = createString(str);
}

char* createString(const char* str){
	int pointerSize = strlen(str) + 1;
	char* string = (char*) malloc(sizeof(char) * pointerSize);
	
	strcpy(string, str);
	string[pointerSize - 1] = 0;
	
	return string;
}

int yywrap(){
	return 1;
}