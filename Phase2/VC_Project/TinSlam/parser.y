%{

#include <stdio.h>
#include <string>

extern FILE* yyin;

extern std::string currentLexeme;

extern int yylex();
extern void yyerror(const char* error);

void print(std::string string);

%}

%start program
%token TOKEN_REAL
%token TOKEN_INT
%token TOKEN_ID

%%

program : program value
	| value
	
value : TOKEN_REAL { print("Real found: " + currentLexeme); }
	| TOKEN_INT { print("Integer found: " + currentLexeme); }
	| TOKEN_ID { print("Identifier found: " + currentLexeme); }

%%

int main(){
	fopen_s(&yyin, "Inputs/input.txt", "r");

	yyparse();
	
	fclose(yyin);
}

void print(std::string string){
	printf("%s\n", string.c_str());
}

void yyerror(const char* error){
	printf("Error: %s\n", error);
}