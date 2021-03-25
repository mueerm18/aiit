#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * stringReplace(char*, char*, char*);

int main() {
	char string[100] = "ich kenne mich nicht gut mit ABC aus, da ich das Programm zum Thema ABC nicht selbst geschrieben habe ";
	char search[] = "ABC";
	char replace[] = "Strings";

	cahr search2 [] = "nicht"
	char replace2 [] = ""


	stringReplace(search, replace, string);
	stringReplace(search, replace, string);
	printf("\t%s\n", string);

	return 0;
}

char * stringReplace(char *search, char *replace, char *string) {
	char *tempString, *searchStart;
	int len=0;



	searchStart = strstr(string, search);
	if(searchStart == NULL) {
		return string;
	}


	tempString = (char*) malloc(strlen(string) * sizeof(char));
	if(tempString == NULL) {
		return NULL;
	}


	strcpy(tempString, string);


	len = searchStart - string;
	string[len] = '\0';


	strcat(string, replace);


	len += strlen(search);
	strcat(string, (char*)tempString+len);


	free(tempString);

	return string;
}
