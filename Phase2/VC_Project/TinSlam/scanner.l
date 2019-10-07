%{

#define YY_NO_UNISTD_H // Don't mind me (.,. )
//                                       /|\
//                                        |
//                                       / \

#include <stdio.h>

#define TOKEN_INT 1
#define TOKEN_REAL 2
#define TOKEN_ID 3
#define TOKEN_ERROR 4

void printToken(const char* string);
int isatty(int param);

%}

%%

Whitespace	;

Real	{
	printToken("Real found.");
	return TOKEN_REAL;
}

Integer	{
	printToken("Int found.");
	return TOKEN_INT;
}

Identifier	{
	printToken("ID found.");
	return TOKEN_ID;
}

Error	{
	printToken("Error found.");
	return TOKEN_ERROR;
}

%%

int main(){
	fopen_s(&yyin, "Inputs/input.txt", "r");

	while(yylex());
	
	return 0;
}

void printToken(const char* string){
	printf("%s\t%s\n", string, yytext);
}

int yywrap(){
	return 1;
}

int isatty(int param){
	return 1;
}