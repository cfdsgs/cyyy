#include <iostream>
#include <fstream>
#include <string.h>     
#include <ctype.h>      // provides isalpha and isdigit
#include <stdlib.h>
using namespace std;
#include<windows.h>
#include<winbase.h>
#define MaxSize 50
// declare the structure of the word
struct KeyWord
{
	char keyword[32];
	int  count;
};

KeyWord KeyWordTable[] =
{
	{"auto",0},{"break",0},{"case",0},{"char",0},{"const",0},{"continue",0},{"default",0},{"do",0},{"double",0},{"else",0},{"enum",0},{"extern",0},
	{"float", 0}, {"for", 0},{"foto",0},{"if", 0},{"int", 0},{"long",0},{"register",0},{"return",0},{"short",0},{"signed",0},{"sizeof",0},{"static",0},
	{"struct",0},{"switch",0},{"typedef",0},{"union",0},{"unsigned",0},{"void",0},{"volatile",0},{"while", 0}
};

// the sequential search algorithm on the array of keywords
int SeqSearch(KeyWord *tab, int n, char *word) 
{
	int i;
	for(i = 0;i < n;i++,tab++)
	{
		if(strcmp(tab->keyword,word)==0)
			return i;
	}
	return -1;
}

// extract a word beginning with a letter and possibly
// other letters/digits
int GetWord (ifstream& fin, char w[])
{
	char c;
	int  i = 0;

	// skip non-alphabetic input
	while ( fin.get(c) && !isalpha(c))
		;

	// return 0 (Failure) on end of file
	if (fin.eof())
		return 0;

	// record 1st letter of the word    
	w[i++] = c;

	// collect letters and digits and NULL terminate string
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w[i++] = c;
	w[i] = '\0';

	return  1;        // return 1 (Success)
}

