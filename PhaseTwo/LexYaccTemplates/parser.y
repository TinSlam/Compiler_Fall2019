%{

#include <stdio.h>

extern char* currentLexeme;

extern FILE* yyin;
extern int yylex();

void print(const char* string);
void yyerror(const char* error);

%}

// Defining tokens. TASK 2. ------------------------------------------------------------------------------------------
%start program
%token ID

%%

// Entering grammar rules. TASK 4. -----------------------------------------------------------------------------------
// Printing out matched rules. TASK 8. -------------------------------------------------------------------------------
program : program ID { print(currentLexeme); }
	| ID { print(currentLexeme); print("File parsed successfully! It's a stack thoooough..."); }

%%

// Setting an entry point. TASK 5. -----------------------------------------------------------------------------------
int main(){
	yyin = fopen("input.txt", "r");

	yyparse();
	
	fclose(yyin);
}

void print(const char* string){
	printf("%s\n", string);
}

void yyerror(const char* error){
	printf("Error: %s\n", error);
}