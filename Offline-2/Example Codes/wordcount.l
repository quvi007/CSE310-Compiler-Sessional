%option noyywrap

%{
#include<iostream>
using namespace std;

int word_count=0;
int line_count=1;

void IncWc(){
	word_count++;
}
%}

Letter [a-zA-Z]

%%
[ \t\v]+ {}

if {cout << "<IF> ";}
for {cout << "<FOR> ";}
do {cout << "<DO> ";}
int {cout << "<INT> ";}
float {cout << "<FLOAT> ";}
void {cout << "<VOID> ";}
switch {cout << "<SWITCH> ";}
default {cout << "<DEFAULT> ";}
else {cout << "<ELSE> ";}
while {cout << "<WHILE> ";}
break {cout << "<BREAK> ";}
char {cout << "<CHAR> ";}
double {cout << "<DOUBLE> ";}
return {cout << "<RETURN> ";}
case {cout << "<CASE> ";}
continue {cout << "<CONTINUE> ";}

{Letter}+ {}
[\n] {line_count++;}
<<EOF>> {cout << "Total Line Number: " << line_count << " and word number: " << word_count << "\n"; return 0;}
. {}
%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	

	yyin= fin;
	yylex();
	fclose(yyin);
	return 0;
}
