%{

#include <stdio.h>

extern FILE* yyin;
extern char* tempString;

int yylex();
void yyerror(const char* error);

%}

%start entry
%token STRING
%token INT
%token SLASH

%%

entry :	entry newEntry
	| /* Lambda */

newEntry : STRING {printf("Course name : %s\n", tempString);} INT INT SLASH INT	
			
%%

int main(){
	yyin = fopen("input.txt", "r");
	yyparse();
	return 0;
}

void yyerror(const char* error){
	printf("Error : %s\n", error);
}