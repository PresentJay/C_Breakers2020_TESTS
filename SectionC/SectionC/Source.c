#include <stdio.h>
//  <work space> : Declare appropriate header.

/*

C Breakers TEST C.
IMPLEMENT all of work spaces (A to G)

*/

struct student {
	int StdNum;
	char Name[10];
	int Age;
	char Address[10];
};

// <work spaceA> :	Declare "PrintCities" function.

// <work spaceB> :	Declare "ArrangeByCity" function.

int main(){

	// <work spaceC> :	Declare student Array "Aclass", and initiate each structure values from "students.txt" file at the same time.
	//					not file I/O, just Declare&Initiate at the same time. ("students.txt" file is just for reference. copy and paste each value)

	// <work spaceD> :	Execute "PrintCities" function.

	// <work spaceE> :	Execute "ArrangeByCity" function.

	return 0;
}

/*
	<work spaceF> :	Implement "PrintCities" function.
					this function makes a array including city names except duplication.
					and print it.
*/

/*
	<work spaceG> :	Implement "ArrangeByCity".
					this function "classify" student array(exactly, "Aclass") by Address.
					and "print" it with size of array that sorted by Address.
			
			ex.		XX�� : N��
					<A�й�> <A�̸�> <A����> <A����>
					<B�й�> <B�̸�> <B����> <B����>

					YY�� : M��
					<C�й�> <C�̸�> <C����> <C����>

					please make sure your algorithm cover the situation that some other data can include different address each other.
*/