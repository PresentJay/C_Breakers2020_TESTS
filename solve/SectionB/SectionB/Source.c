#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  <work space> : Declare appropriate header.

/*

C Breakers TEST B.
SATISFY all of conditions (first, second)

*/

/*
		<first condition>
		Declare and Implement "init" function that receives 'strings'(string address) parameter, 'size'(integer) parameter.
		c.f)	init function initiates the string array for standard input(keyboard) with scanf.
				ignore pre-initiated values. you must re-initiate array,
				also concern the size of new string. (maximum size is a hundred)

		<second condition>
		Declare and Implement "prn" function that receives 'strings'(string address) parameter, 'size'(integer) parameter.
		c.f)	prn function shows all of string array.

		<< this program must be execute with functions!! >>

		*/

void init(char** strings, int size){
	char tmp[100];
	for (int i = 0; i < size; i++){
		scanf("%s", &tmp);
		strings[i] = (char*)malloc(sizeof(tmp));
		strcpy(strings[i], tmp);
	}
}

void prn(char** strings, int size){
	for (int i = 0; i < size; i++)
		printf("%s\n", strings[i]);
}

int main(){
	char* flower[5] = { "lily", "cosmos", "sunflower", "rose", "lavender" };

	// if you satisfy all of conditions, let below comment outed two line be in code.

	init(flower, 5);
	prn(flower, 5);

	return 0;
}