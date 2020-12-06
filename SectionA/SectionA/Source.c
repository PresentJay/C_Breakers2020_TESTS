#include <stdio.h>
//  <work space> : Declare appropriate header.

/*
C Breakers TEST A.
SATISFY all of conditions (basic, first, second)

write your codes in <work space> lines. (do not write other space. no using)
*/

struct student {
	char name[10];	// "name" variable is consist of 3 letters of korean.
	int score[4];	// "score" variable is consist of A to D scores.
	int total;		// "total" variable have uncalculated integer value.
};					// calculating must be execute in "compute" function"

void compute(struct student *Aclass, int size);
void list(struct student *Aclass, int size);
void change_name(struct student *Aclass, char *fname, char *nname, int size);

/*

		<basic condition>

please refer "students.txt" file on your project directory.
let your program reads 5 lines of string(just copy and paste from "students.txt" file)
and then, initiate the structure values from readed information.

		<first condition>

A. implement the "compute" function that calculates all total score of each students.
B. implement the "list" function that show structure value of each student including "total" value.
c.f of B) showing format is be like this below.

(name)NAME, (scoreA)SCOREA, (scoreB)SCOREB, (scoreC)SCOREC, (scoreD)SCORED, (total)TOTAL

		<second condition>

A. implement the "change_name" function.
c.f of A)	this function has 4 parameters. second parameter is original name,
			and third parameter is new name.
c.f of B)	if the original name exists in structure list, change name,
			but not exists, print like this.
			"original name XXX is not exist."
*/


int main(){
	struct student Aclass[5];

	// <work space> : for basic condition

	// execute the first condition's functions.
	compute(Aclass, sizeof(Aclass) / sizeof(struct student));
	list(Aclass, sizeof(Aclass) / sizeof(struct student));

	// execute the second condition's functions.
	change_name(Aclass, "±è¿µÈñ", "±è¿µÈ¸", sizeof(Aclass) / sizeof(struct student));
	list(Aclass, sizeof(Aclass) / sizeof(struct student));
	change_name(Aclass, "±è¿µÈñ", "±è¿µÈÖ", sizeof(Aclass) / sizeof(struct student));
	list(Aclass, sizeof(Aclass) / sizeof(struct student));

	return 0;
}

void compute(struct student *Aclass, int size){

	// implement the "compute" function below.
	// <work space> : for first condition

}

void list(struct student *Aclass, int size){

	// implement the "list" function below.
	// <work space> : for first condition

}

void change_name(struct student *Aclass, char *fanme, char*nname, int size){

	// implement the "change_name" function below.
	// <work space> : for second condition

}