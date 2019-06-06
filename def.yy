%{
#include <string>
#include <stack>
#include <vector>
#include <sstream>
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
		int type; // 1 zmienna , 2 int ,3 float
		string val;
		string fVal;

		Element()
		{
		}
		Element(int ty,string na)
		{
			type = ty;
			val = na;
			fVal = "0" ;
		}
		Element(int ty,string na, string fv)
		{
			type = ty;
			val = na;
			fVal = fv;
		}
};
void addSymbol(Element el);
stack<Element> myStack;
vector<Element> symbols;
vector<string> symbolsValues;
string result;
stack<string> labels;
stack<string> logOperators;
vector<string> toPrint;
void changeVariableValue(string variableName, int type);
void read(string variableName);
void printing();
void ifJump(string logOperator);
void stringPrintingData(int nl);
void addStringForPrint(string tmp);
void startIf();
static int labelNumber = 1 ;
static int printStringNum = 1;
static int counter = 1;
static int floatCounter = 1;
void endIF();
void startWhile();
void makeIntArray(string name,int lenght);
void makeFloatArray(string name,int lenght);
void changeArray(string name, int index);
void midWhile();
void addFloat(string id);
void addInt(string id);
void elseIf();
void elseIfend();
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
%token INT FLOAT STRING IF WHILE KOM PR RD EQ NEQ LEQ MEQ ELSE PRN
%%
wiel
	:wiel linia {printf(" wielolinia \n");}
	|linia		{printf(" linia \n");}
	;
linia
	:wyrp ';' {printf(" linia przypisujaca \n");}
	|funkcja ';' {printf(" linia z funkcja \n");}
	|if_wyr {}
	|if_else_wyr_end {}
	|while_wyr {}
	|tab_wyr ';' {}
	;

tab_wyr
	:INT '[' LC ']' ID  {makeIntArray($5,$3);}
	|FLOAT '[' LC ']' ID  {makeFloatArray($5,$3);}
	|ID '[' LC ']' '=' wyr {changeArray($1, $3);}
	;

if_else_wyr_end
	: if_else_wyr '{' wiel '}' { endIF(); }
	;
if_wyr
	: if_pocz '{' wiel '}' { endIF(); }	
	;
if_else_wyr
	: if_pocz '{' wiel '}' ELSE  { elseIf(); }
	;

if_pocz
	:IF '(' wyr operatorLog wyr ')' { startIf(); }
	;

while_wyr
	: while_pocz '{' wiel '}' { midWhile(); }	
	;
while_pocz
	: WHILE '(' wyr operatorLog wyr ')' { startWhile(); }	
	;	
	
funkcja
	:PR wyrWNawiasach  {printf(" wyswietlenie \n"); printing();}
	|PRN '(' str ')'   {printf(" wyswietlenie \n"); stringPrintingData(2);}
	|PRN '(' ')'   {printf(" wyswietlenie \n"); stringPrintingData(3);}
	|PR '(' str ')'  {printf(" wyswietlenie str \n"); stringPrintingData(1);}
	|RD '(' ID ')'   {printf(" czytanie \n"); read($3);}
	;
str 
	: '"' word '"' {}
	;
word 
	: ID {addStringForPrint($1);}
	| word ID {addStringForPrint($2);}
	;
wyrp
	:INT ID '=' wyr {printf(" nowa zmienna int \n"); addInt($2); }
	|FLOAT ID '=' wyr {printf(" nowa zmienna float \n");addFloat($2);  }
	|ID '=' wyr {printf(" przypisanie \n"); changeVariableValue($1,3); }
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
	|LR			{printf("b:liczba rzeczywista (%f)\n",$1); myStack.push(Element(3,to_string($1),to_string($1)));}
	|wyrWNawiasach		{printf("wyrazenie w nawiasach\n");}
	|ID '[' LC ']'      {stringstream tmp ;tmp<<$1<<"_"<<to_string($3) ;myStack.push(Element(1,tmp.str()));}
	;
wyrWNawiasach
	:'(' wyr ')'		{}
	;
%%
void addSymbol(Element el)
{
	symbols.push_back(el);
	//symbolsValues.push_back(myStack.top().val);
	//myStack.pop();
}
void addStringForPrint(string tmp)
{
	toPrint.push_back(tmp);
}
void addFloat (string id)
{
	if (myStack.top().type == 2) 
		yyerror("you can`t put int into float \n");
	else if (myStack.top().type == 1)
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if(myStack.top().val == symbols[i].val)
			{
				type2 = symbols[i].type;
				break;
			}
		}
		if(type2 == 2)
			yyerror("you can`t put int into float \n");
	}
	symbols.push_back(Element(3,id,myStack.top().fVal));
	myStack.pop();
}
void addInt(string id)
{
	if (myStack.top().type == 3) 
		yyerror("you can`t put float into int \n");
	else if (myStack.top().type == 1)
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if(myStack.top().val == symbols[i].val)
			{
				type2 = symbols[i].type;
				break;
			}
		}
		if(type2 == 3)
			yyerror("you can`t put float into int \n");
	}
	addSymbol(Element(2,id)); 
	changeVariableValue(id,1);
}
void makeIntArray(string name,int lenght)
{
	for (int i = 0 ; i < lenght ; i++)
	{
		stringstream  tmp;
		tmp << name << "_" << i;
		addSymbol(Element(2,tmp.str())); 
	}
}
void makeFloatArray(string name,int lenght)
{
	for (int i = 0 ; i < lenght ; i++)
	{
		stringstream  tmp;
		tmp << name << "_" << i;
		addSymbol(Element(3,tmp.str())); 
	}
}
void changeArray(string name, int index)
{
	stringstream  tmp;
	tmp << name << "_" << index;
	changeVariableValue(tmp.str(),3);
}
void startIf()
{	
	if (myStack.top().type == 2)
		outCode.push_back("li $t1 , "+myStack.top().val);
	else
		outCode.push_back("lw $t1 , "+myStack.top().val);	
	myStack.pop();

	if (myStack.top().type == 2)
		outCode.push_back("li $t0 , "+myStack.top().val);
	else
		outCode.push_back("lw $t0 , "+myStack.top().val);
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
	if (myStack.top().type == 2)
		outCode.push_back("li $t1 , "+myStack.top().val);
	else
		outCode.push_back("lw $t1 , "+myStack.top().val);
	myStack.pop();
	if (myStack.top().type == 2)
		outCode.push_back("li $t0 , "+myStack.top().val);
	else
		outCode.push_back("lw $t0 , "+myStack.top().val);
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
void endIF()
{
	outCode.push_back(labels.top() + ":");
	labels.pop();
}
void elseIf()
{	
	stringstream  tmp;
	tmp <<  "b	" << "label" << labelNumber+1;
	outCode.push_back(tmp.str());
	outCode.push_back(labels.top() + ":");
	labels.pop();
	labelNumber++;
	labels.push("label"+to_string(labelNumber));
}
void midWhile()
{
	outCode.push_back("b label"+to_string(labelNumber-2));
	outCode.push_back(labels.top() + ":");
	labels.pop();
}
void stringPrintingText()
{
	outCode.push_back("li $v0 , 4");
	outCode.push_back("la $a0 , str"+to_string(printStringNum));
	outCode.push_back("syscall");
	printStringNum = printStringNum + 1 ;
}
void stringPrintingData(int nl)
{
	stringstream  tmp;
	tmp <<  "str" << printStringNum << ": .asciiz	";

	tmp << "\"";

	if(nl != 3)
	{
		for (int i = 0 ; i < toPrint.size(); i++)
		{
			tmp << toPrint[i] << " ";
		}
	}
	if(nl == 2 || nl == 3)
		{tmp << "\\n";}

	tmp << "\"";

	toPrint.clear();
	symbols.push_back(Element(4,tmp.str()));

	stringPrintingText();
}
void printing()
{
	int type = myStack.top().type;  // 1 zmienna , 2 int ,3 float

	if(type == 2)
	{
		outCode.push_back("li $v0 , 1");
		outCode.push_back("li $a0 , "+myStack.top().val);
	}else if (type == 3) 
	{
		symbols.push_back(Element(3,"tmp"+to_string(floatCounter),myStack.top().fVal));
		outCode.push_back("li $v0 , 2");
		outCode.push_back("l.s $f12 , tmp"+to_string(floatCounter));
	}else if (type == 1) 
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if( myStack.top().val == symbols[i].val)
			{
				type2 = symbols[i].type;
			}
		}
		if(type2 == 2)
		{
			outCode.push_back("li $v0 , 1");
			outCode.push_back("lw $a0 , "+myStack.top().val);
		}else if (type2 == 3) 
		{
			outCode.push_back("li $v0 , 2");
			outCode.push_back("l.s $f12 , "+ myStack.top().val);
		}
	}

	//zmienna int
	//outCode.push_back("li $v0 , 1");
	//outCode.push_back("lw $a0 , "+myStack.top().val);

	outCode.push_back("syscall");
}
void triples(char * text)
{
	//outfile.open("yyout", std::ios_base::app);

	Element sec = myStack.top();
	myStack.pop();
	Element first = myStack.top();
	myStack.pop();
	int type1 = 0 ;
	int type2 = 0 ;

	result = first.val + text + sec.val;
	//symbols.push_back(Element(2,"result"+to_string(counter)));
	myStack.push(Element(1,"result"+to_string(counter)));
	//symbolsValues.push_back("0");

	outCode.push_back("# " + result );

	if(sec.type == 1 || first.type == 1)
	{
		if (first.type == 1)
		{
			for (int i = 0 ; i < symbols.size() ;i++ )
			{
				if(first.val == symbols[i].val)
				{
					type1 = symbols[i].type;
					break;
				}
			}
		}else
		{
			type1 = first.type;
		}
		if (sec.type == 1)
		{
			for (int i = 0 ; i < symbols.size() ;i++ )
			{
				if(first.val == symbols[i].val)
				{
					type2 = symbols[i].type;
					break;
				}
			}
		}else
		{
			type2 = sec.type;
		}
		if(type1 != type2)
		{
			yyerror("expression has both float and int, unacceptable 1 !!! \n");
		}
	}
	else if (sec.type != first.type )
	{
		yyerror("expression has both float and int, unacceptable 2 !!! \n");
	}

	if(first.type == 1)
	{
		outCode.push_back("lw $t0, " + first.val);
	}else if (first.type == 2)
	{
		outCode.push_back("li $t0, " + first.val);
	}else if (first.type == 3)
	{
		symbols.push_back(Element(3,"tmp"+to_string(floatCounter),first.fVal));
		stringstream  tmp;
		tmp <<  "l.s $f0 , " << "tmp";
		outCode.push_back(tmp.str()+to_string(floatCounter));
		floatCounter++;
	}

	if(sec.type == 1)
	{
		outCode.push_back("lw $t1, " + sec.val);
	}else if (sec.type == 2)
	{
		outCode.push_back("li $t1, " + sec.val);
	}else if (sec.type == 3)
	{
		symbols.push_back(Element(3,"tmp"+to_string(floatCounter),sec.fVal));
		stringstream  tmp;
		tmp <<  "l.s $f1 , " << "tmp";
		outCode.push_back(tmp.str()+to_string(floatCounter));
		floatCounter++;
	}

	if (first.type != 1)
		type1 = first.type ;
	if (sec.type != 1)
		type2 = sec.type ;

	if(type1 == 3 || type2 == 3)
	{
		symbols.push_back(Element(3,"result"+to_string(counter)));
		if(text =="-")
		{	
			outCode.push_back("sub.s $f0 , $f0 , $f1");
		}else if(text == "+")
		{	
			outCode.push_back("add.s $f0 , $f0 , $f1");
		}else if(text == "*")
		{	
			outCode.push_back("mul.s $f0 , $f0 , $f1");
		}else if(text == "/")
		{	
			outCode.push_back("div.s $f0 , $f0 , $f1");
		}
		outCode.push_back("s.s $f0  , result"+to_string(counter) + "\n");
	}else
	{
		symbols.push_back(Element(2,"result"+to_string(counter)));
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
	}

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
	outfile.open("yyout.asm", std::ios_base::app);

	outfile << ".data" << endl;

	for (int i = 0 ; i < symbols.size();i++)
	{
		symbolsFile << symbols[i].type << " " << symbols[i].val << endl;
		if(symbols[i].type == 4 )
			outfile << symbols[i].val << endl;
		else if (symbols[i].type == 3)
			outfile << symbols[i].val << ": .float	" << symbols[i].fVal << endl;
		else
			outfile << symbols[i].val << ":	.word	" << "0" << endl;
	} 
}
void changeVariableValue(string variableName, int type)
{	
	// 1 - int | 2 - float | 3- nieznana
	outCode.push_back("#"+variableName+"="+myStack.top().val);
	if(type == 1)
	{	
		if (myStack.top().type == 2)
			outCode.push_back("li $t0 , "+myStack.top().val);
		else
			outCode.push_back("lw $t0 , "+myStack.top().val);
		outCode.push_back("sw $t0, "+variableName);
	}else if (type == 2) 
	{
		if (myStack.top().type == 3 || myStack.top().type == 2)
			outCode.push_back("l.s $f0 , "+myStack.top().val);
		else
			outCode.push_back("s.s $f0 , "+myStack.top().val);
	}else if (type == 3)
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if(variableName == symbols[i].val)
			{
				type2 = symbols[i].type;
			}
		}
		if (type2 == 3)
		{
			if(myStack.top().type == 2)
			{
				yyerror("you can`t put int into float \n");
			}else if (myStack.top().type == 1)
			{
				for (int i = 0 ; i < symbols.size() ;i++ )
				{
					if(myStack.top().val == symbols[i].val)
					{
						type2 = symbols[i].type;
					}
				}
				if(type2 == 2)
					yyerror("you can`t put int into float \n");
			}
			symbols.push_back(Element(3,"tmp"+to_string(floatCounter),myStack.top().fVal));
			stringstream  tmp;
			tmp <<  "l.s $f0 , " << "tmp";
			outCode.push_back(tmp.str()+to_string(floatCounter));
			outCode.push_back("s.s $f0 , "+variableName);
			floatCounter++;
			
		}else
		{
			if(myStack.top().type == 3)
			{
				yyerror("you can`t put float into int \n");
			}else if (myStack.top().type == 1)
			{
				for (int i = 0 ; i < symbols.size() ;i++ )
				{
					if(myStack.top().val == symbols[i].val)
					{
						type2 = symbols[i].type;
					}
				}
				if(type2 == 3)
					yyerror("you can`t put float into int \n");
				else
					outCode.push_back("lw $t0 , "+myStack.top().val);
			}
			if (myStack.top().type == 2)
				outCode.push_back("li $t0 , "+myStack.top().val);
				
			outCode.push_back("sw $t0, "+variableName);
		}
	}	
	myStack.pop();	
	
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

	outfile.open("yyout.asm", std::ios_base::app);

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

	FILE *fil = fopen("yyout.asm", "w");
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
