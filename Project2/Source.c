#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
//#include <malloc.h>
#include "y_tab.h"

//#include "y_tab.c"

FILE *yyin = NULL;

//int yyparse();
int yyerror(char *str)
{
	printf("Error\n");
	return 0;
}
int yylex()
{
	char c;
	c = fgetc(yyin);
	if (isdigit(c))
	{
		return (DIGIT);
	}
	if (c == '+' || c == '-')
	{
		return (SIGN);
	}
	return (c);
}

int main()
{
	yyin = fopen("input.txt", "r");
	yyparse();
	fclose(yyin);
	printf("Complete\n");
	while (1) {}
	return 0;
}