%{
#include <string>
#include <stack>
#include <fstream>
#include <iostream>
#include <stdio.h>
#define INFILE_ERROR 1
#define OUTFILE_ERROR 2
using namespace std;
extern "C" int yylex();
extern "C" int yyerror(const char *msg, ...);
void writeToFIle(char * text);
void writeToFIlei(int text);
void triples(char * text);
void writeToFIlef(float text);
stack<string> myStack;
string result;
%}
%union 
{
	char *text;
	int	ival;
	float fval;
};
%token <text> ID
%token <ival> LC 
%token <fval> LR 
%token INT FLOAT STRING IF WHILE LR KOM
%%
wyr
	:skladnik '+' wyr	{printf(" + \n");triples(" + ");}
	|skladnik '-' wyr	{printf(" - \n");triples(" - ");}
	|skladnik 			{printf("wyr \n");}
	;
skladnik
	:skladnik '*' czynnik	{printf(" * \n");triples(" * ");}
	|skladnik '/' czynnik	{printf(" / \n");triples(" / ");}
	|czynnik		{printf("skladnik \n");}
	;
czynnik
	:ID			{printf("zmienna (%s)\n",$1);myStack.push(string($1)); } 
	|LC			{printf("b:liczba całkowita(%d)\n",$1); myStack.push(to_string($1));}
	|LR			{printf("b:liczba rzeczywista (%f)\n",$1); myStack.push(to_string($1));}
	|'(' wyr ')'		{printf("wyrazenie w nawiasach\n");}
	;
%%
void triples(char * text)
{
	string sec = myStack.top();
	myStack.pop();
	string first = myStack.top();
	myStack.pop();

	result = first + text + sec;
	myStack.push(result);
	
	ofstream outfile;

	outfile.open("file.txt", std::ios_base::app);
	outfile << result << endl; 
}
void writeToFIle(char * text)
{
	FILE *f = fopen("file.txt", "a");	
	fprintf(f, " %s", text);
	fclose(f);
}
void writeToFIlei(int text)
{
	FILE *f = fopen("file.txt", "a");	
	fprintf(f, " %d", text);
	fclose(f);
}
void writeToFIlef(float text)
{
	FILE *f = fopen("file.txt", "a");	
	fprintf(f, " %f", text);
	fclose(f);
}
int main(int argc, char *argv[])
{
	result ="";
	FILE *f = fopen("file.txt", "w");	
	fprintf(f, "");
	fclose(f);
	yyparse();
	return 0;
}
