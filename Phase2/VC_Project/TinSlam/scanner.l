%{

#define YY_NO_UNISTD_H // Don't mind me (.,. )
//                                       /|\
//                                        |
//                                       / \

#include <string>

#include "parser.tab.h"

int isatty(int param);

std::string currentLexeme;

%}

%%

Whitespace	;

Real	{
	currentLexeme = std::string(yytext);
	return TOKEN_REAL;
}

Integer	{
	currentLexeme = std::string(yytext);
	return TOKEN_INT;
}

.*	{
	currentLexeme = std::string(yytext);
	return TOKEN_ID;
}

%%

int yywrap(){
	return 1;
}

int isatty(int param){
	return 1;
}