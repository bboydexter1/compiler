%{
#include <stdlib.h>
#include <string.h>
#include "def.tab.hh"
#define INFILE_ERROR 1
#define OUTFILE_ERROR 2
int yyerror(const char *,...);
extern int yylineno;
%}
%%
"int"		{fprintf(yyout, "int\n");return INT;} 
"float"		{fprintf(yyout, "float\n");return FLOAT;} 
"string"	{fprintf(yyout, "string\n");return STRING;} 
"if"		{fprintf(yyout, "if\n");return IF;} 
"else"		{fprintf(yyout, "else\n");return ELSE;} 
"while"		{fprintf(yyout, "while\n");return WHILE;} 
"print"		{fprintf(yyout, "print\n");return PR;}
"println"	{fprintf(yyout, "println\n");return PRN;} 
"read"		{fprintf(yyout, "read\n");return RD;} 
\+			{fprintf(yyout, "+\n");return '+';} 
\*			{fprintf(yyout, "*\n");return '*';}
\(			{fprintf(yyout, "(\n");return '(';}
\)			{fprintf(yyout, ")\n");return ')';}
\[			{fprintf(yyout, "[\n");return '[';}
\{			{fprintf(yyout, "{\n");return '{';}
\}			{fprintf(yyout, "}\n");return '}';}
\"			{fprintf(yyout, "\n");return '"';}
\]			{fprintf(yyout, "]\n");return ']';}
\/			{fprintf(yyout, "/\n");return '/';}
\-			{fprintf(yyout, "-\n");return '-';}
\=\=		{fprintf(yyout, "==\n");return EQ;}
\>			{fprintf(yyout, ">\n");return '>';}
\>\=		{fprintf(yyout, ">=\n");return MEQ;}
\<			{fprintf(yyout, "<\n");return '<';}
\<\=		{fprintf(yyout, "<=\n");return LEQ;}
\!\=		{fprintf(yyout, "!=\n");return NEQ;}
\=			{
				fprintf(yyout, "=\n");
				return '=';
			}
\/\/		{fprintf(yyout, "KOM\n");return KOM;}
[1-9][0-9]*|0	{
				fprintf(yyout, "liczba całkowita\n");
				yylval.ival = atoi(yytext);
				return LC;
			}
([1-9][0-9]*|0)\.[0-9]+ {
				fprintf(yyout, "liczba rzeczywista\n");
				yylval.fval = atof(yytext);
				return LR;
			}			
[A-Za-z][A-Za-z0-9]*	{
				fprintf(yyout, "nazwa\n");
				yylval.text = strdup(yytext);
				return ID;
			}
\ |\t|\n	{;}
\;			{yylineno++;return ';';}
.			{yyerror("Blad leksykalny\n");}
%%
int yyerror(const char *msg,...)
{
	printf("%d: %s", yylineno, msg);
	exit(1);
}

