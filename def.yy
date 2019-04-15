%{
#include <string>
#include <stack>
#include <vector>
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
vector<string> outCode;
class Element
{
	public:
		int type;
		string val;

		Element()
		{
		}
		Element(int ty,string na)
		{
			type = ty;
			val = na;
		}
};
void addSymbol(Element el);
stack<Element> myStack;
vector<Element> symbols;
vector<string> symbolsValues;
string result;
stack<string> labels;
stack<string> logOperators;
void changeVariableValue(string variableName);
void read(string variableName);
void printing(int val);
void ifJump(string logOperator);
void stringPrinting(string val);
void startIf();
static int labelNumber = 1 ;
void midIf();
void startWhile();
void midWhile();
void elseIf();
%}
%union 
{
	char *text;
	int	ival;
	float fval;
};
%token <text> ID STR
%token <ival> LC 
%token <fval> LR 
%token INT FLOAT STRING IF WHILE KOM PR RD EQ NEQ LEQ MEQ ELSE 
%%
wiel
	:wiel linia {printf(" wielolinia \n");}
	|linia		{printf(" linia \n");}
	;
linia
	:wyrp ';' {printf(" linia przypisujaca \n");}
	|funkcja ';' {printf(" linia z funkcja \n");}
	|if_wyr {}
	|ob_else {}
	|while_wyr {}
	;
if_wyr
	: if_pocz '{' wiel '}' { midIf(); }	
	;
if_pocz
	:IF '(' wyr operatorLog wyr ')' { startIf(); }
	;
ob_else
	:if_wyr ELSE '{' wiel '}' { elseIf(); }
	;
while_wyr
	: while_pocz '{' wiel '}' { midWhile(); }	
	;
while_pocz
	: WHILE '(' wyr operatorLog wyr ')' { startWhile(); }	
	;	
funkcja
	:PR wyrWNawiasach  {printf(" wyswietlenie \n"); printing(1);}
	|PR '(' STR ')'  {printf(" wyswietlenie str \n"); stringPrinting($3);}
	|RD '(' ID ')'   {printf(" czytanie \n"); read($3);}
	;
wyrp
	:INT ID '=' wyr {printf(" nowa zmienna int \n"); addSymbol(Element(1,$2)); changeVariableValue($2); }
	|FLOAT ID '=' wyr {printf(" nowa zmienna float \n"); addSymbol(Element(2,$2)); changeVariableValue($2); }
	|ID '=' wyr {printf(" przypisanie \n"); changeVariableValue($1); }
	;
wyr
	:skladnik '+' wyr	{printf("+\n");triples("+");}
	|skladnik '-' wyr	{printf("-\n");triples("-");}
	|skladnik 			{printf("wyr\n");}
	;
skladnik
	:skladnik '*' czynnik	{printf("*\n");triples("*");}
	|skladnik '/' czynnik	{printf("/\n");triples("/");}
	|czynnik		{printf("skladnik\n");}
	;
operatorLog
	: EQ { logOperators.push("==");}
	| NEQ {logOperators.push("!=");}
	| MEQ {logOperators.push(">=");}
	| LEQ {logOperators.push("<=");}
	| '>' {logOperators.push(">");}
	| '<' {logOperators.push("<");}
	;
czynnik
	:ID			{printf("zmienna (%s)\n",$1);myStack.push(Element(1,string($1)));} 
	|LC			{printf("b:liczba całkowita(%d)\n",$1); myStack.push(Element(2,to_string($1)));}
	|LR			{printf("b:liczba rzeczywista (%f)\n",$1); myStack.push(Element(3,to_string($1)));}
	|wyrWNawiasach		{printf("wyrazenie w nawiasach\n");}
	;
wyrWNawiasach
	:'(' wyr ')'		{}
	;
%%
void addSymbol(Element el)
{
	symbols.push_back(el);
	symbolsValues.push_back(myStack.top().val);
	//myStack.pop();
}
void startIf()
{	
	outCode.push_back("li $t1 , "+myStack.top().val);
	myStack.pop();
	outCode.push_back("li $t0 , "+myStack.top().val);
	myStack.pop();

	string logOperator = logOperators.top();
	logOperators.pop();

	ifJump(logOperator);

	labels.push("label"+to_string(labelNumber));
	labelNumber++;
}
void startWhile()
{	
	outCode.push_back("label"+to_string(labelNumber)+":");
	labelNumber++;
	outCode.push_back("li $t1 , "+myStack.top().val);
	myStack.pop();
	outCode.push_back("li $t0 , "+myStack.top().val);
	myStack.pop();

	string logOperator = logOperators.top();
	logOperators.pop();

	ifJump(logOperator);

	labels.push("label"+to_string(labelNumber));
	labelNumber++;
}
void ifJump(string logOperator)
{
	if(logOperator == "==")
	{
		outCode.push_back("bne $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == "!=")
	{
		outCode.push_back("beq $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == "<")
	{
		outCode.push_back("bge $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == "<=")
	{
		outCode.push_back("bgt $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == ">")
	{
		outCode.push_back("ble $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == ">=")
	{
		outCode.push_back("blt $t0, $t1 ,label"+to_string(labelNumber));
	}
}
void midIf()
{
//	outCode.push_back("b label"+to_string(labelNumber+1));// dodac if label istnieje jak kolwiek mialo by to byc
	outCode.push_back(labels.top() + ":");
	labels.pop();

//	labelNumber++;
}
void midWhile()
{
	outCode.push_back("b label"+to_string(labelNumber-2));
	outCode.push_back(labels.top() + ":");
	labels.pop();
}
void elseIf()
{
//	outCode.push_back(labels.top() + ":");
//	labels.pop();
}
void stringPrinting(string val)
{
	//symbols.push_back(symbols)
	/*
	. data
	str : . asciiz " Tekst do wypisania ."
	. text
	li $v0 , 4
	la $a0 , str
	syscall
	*/
}
void printing(int type)
{
	outCode.push_back("li $v0 , 1");
	if(type == 1)
		outCode.push_back("lw $a0 , $t0");
	else if(type == 2)
		outCode.push_back("li $a0 , "+myStack.top().val);
	outCode.push_back("syscall");
}
void triples(char * text)
{
	static int counter = 1;
	Element sec = myStack.top();
	myStack.pop();
	Element first = myStack.top();
	myStack.pop();

	result = first.val + text + sec.val;
	symbols.push_back(Element(2,"result"+to_string(counter)));
	myStack.push(Element(1,"result"+to_string(counter)));
	symbolsValues.push_back("0");

	outCode.push_back("# " + result );

	if(first.type == 1)
	{
		outCode.push_back("lw $t0, " + first.val);
	}else if (first.type == 2)
	{
		outCode.push_back("li $t0, " + first.val);
	}

	if(sec.type == 1)
	{
		outCode.push_back("lw $t1, " + sec.val);
	}else if (sec.type == 2)
	{
		outCode.push_back("li $t1, " + sec.val);
	}

	if(text =="-")
	{	
		outCode.push_back("sub $t0 , $t0 , $t1");
	}else if(text == "+")
	{	
		outCode.push_back("add $t0 , $t0 , $t1");
	}else if(text == "*")
	{	
		outCode.push_back("mul $t0 , $t0 , $t1");
	}else if(text == "/")
	{	
		outCode.push_back("div $t0 , $t0 , $t1");
	}

	outCode.push_back("sw $t0 , result"+to_string(counter) + "\n");

	ofstream outfile;
	counter++;

	outfile.open("file.txt", std::ios_base::app);
	outfile << result << endl; 
}
void symbolsToFile()
{	
	ofstream outfile;
	ofstream symbolsFile;

	symbolsFile.open("symbols.txt", std::ios_base::app);
	outfile.open("yyout", std::ios_base::app);

	outfile << ".data" << endl;

	for (int i = 0 ; i < symbols.size();i++)
	{
		symbolsFile << symbols[i].type << " " << symbols[i].val << endl;
		//outfile << symbols[i].val << ":	.word	" << symbolsValues[i] << endl;
		outfile << symbols[i].val << ":	.word	" << "0" << endl;
	} 
}
void changeVariableValue(string variableName)
{
	cout << "test1" << endl;	
	outCode.push_back("#"+variableName+"="+myStack.top().val);
	cout << "test2" << endl;	
	outCode.push_back("l1 $t0, "+myStack.top().val);
	cout << "test3" << endl;	
	myStack.pop();
	cout << "test4" << endl;	
	outCode.push_back("sw $t0, "+variableName);
	cout << "test5" << endl;	
}
void read(string variableName)
{
	outCode.push_back("li $v0 , 5");
	outCode.push_back("syscall");
	outCode.push_back("sw $v0, "+variableName);
}
void saveOutput()
{	
	ofstream outfile;

	outfile.open("yyout", std::ios_base::app);

	outfile << ".text" << endl;

	for (int i = 0 ; i < outCode.size();i++)
	{
		outfile << outCode[i] << endl;
	} 
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
void clearFiles()
{
	result ="";
	FILE *f = fopen("file.txt", "w");	
	fprintf(f, "");
	fclose(f);

	FILE *fi = fopen("symbols.txt", "w");
	fprintf(fi, "");
	fclose(fi);

	FILE *fil = fopen("yyout", "w");
	fprintf(fil, "");
	fclose(fil);

}
int main(int argc, char *argv[])
{
	clearFiles();

	yyparse();

	symbolsToFile();
	saveOutput();
	
	return 0;
}
