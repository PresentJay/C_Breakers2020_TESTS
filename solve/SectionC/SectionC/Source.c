#include <stdio.h>
//  <work space> : Declare appropriate header.
#include <malloc.h>
#include <string.h>

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
void PrintCities(struct student *Aclass, int size);

// <work spaceB> :	Declare "ArrangeByCity" function.
void ArrangeByCity(struct student *Aclass, int size);

int main(){

	// <work spaceC> :	Declare student Array "Aclass", and initiate each structure values from "students.txt" file at the same time.
	//					not file I/O, just Declare&Initiate at the same time. ("students.txt" file is just for reference. copy and paste each value)
	struct student Aclass[5] = {
		{ .StdNum = 2020101, .Name = "더대현", .Age = 20, .Address = "부산시" },
		{ .StdNum = 2019211, .Name = "김당균", .Age = 21, .Address = "부산시" },
		{ .StdNum = 2009002, .Name = "김대공", .Age = 31, .Address = "울산시" },
		{ .StdNum = 2014014, .Name = "도덩호", .Age = 26, .Address = "서울시" },
		{ .StdNum = 2016999, .Name = "김당대", .Age = 24, .Address = "창원시" },
	};

	// <work spaceD> :	Execute "PrintCities" function.
	PrintCities(Aclass, 5);

	// <work spaceE> :	Execute "ArrangeByCity" function.
	ArrangeByCity(Aclass, 5);

	return 0;
}

/*
	<work spaceF> :	Implement "PrintCities" function.
	this function makes a array including city names 'except duplication'.
	and print it.

	*/
void PrintCities(struct student *Aclass, int size){
	char **AArray;
	int count = 0;

	for (int i = 0; i < size; i++){
		// declare existChecker variable to find duplication.
		int existChecker = 0;

		// if loop is in first count, just put address in first item of AArray.
		if (!count){
			AArray = (char**)malloc(sizeof(char*) * ++count);
			AArray[0] = (char*)malloc(sizeof(char) * 10);
			strcpy(AArray[0], Aclass[i].Address);
		}
		else{
			// check all original city array. 
			for (int j = 0; j < count; j++){
				if (strcmp(AArray[j], Aclass[i].Address)==0)
					existChecker++;
			}
			// if this city do not exist in city array
			if (existChecker==0){

				// declare the paste of original city array for original size (dynamic allocation)
				char** tmpArr = (char**)malloc(sizeof(char*) * count);
				for (int k = 0; k < count; k++){
					tmpArr[k] = (char*)malloc(sizeof(char) * 10);
					strcpy(tmpArr[k], AArray[k]);
				}

				// declare the new city array for original+1 size (dynamic allocation)
				// and paste original to new
				AArray = (char**)malloc(sizeof(char*) * ++count);
				for (int j = 0; j < count; j++){
					AArray[j] = (char*)malloc(sizeof(char) * 10);
					if (j!=count-1)
						strcpy(AArray[j], tmpArr[j]);
				}
				// add new item
				strcpy(AArray[count - 1], Aclass[i].Address);
			}
		}
	}

	// print all city item
	printf("print list:\n");
	while (--count >= 0){
		printf("\t%s\n", AArray[count]);
	}
	printf("\n");
}

/*
	<work spaceG> :	Implement "ArrangeByCity".
	this function "classify" student array(exactly, "Aclass") by Address.
	and "print" it with size of array that sorted by Address.

	ex.		XX시 : N명
	<A학번> <A이름> <A나이> <A지역>
	<B학번> <B이름> <B나이> <B지역>

	YY시 : M명
	<C학번> <C이름> <C나이> <C지역>

	please make sure your algorithm cover the situation that some other data can include different address each other.
	*/
void ArrangeByCity(struct student *Aclass, int size){

	int count = 1;
	// declare "CityStudents" variable to include 2 dimentions of student array.
	struct student** CityStudents;

	// initiate CityStudents.
	CityStudents = (struct student**)malloc(sizeof(struct student*) * count);

	// check the duplication from second item.
	for (int AclassIndex = 0; AclassIndex < size; AclassIndex++){
		// first value is first item
		if (AclassIndex == 0){
			CityStudents[0] = (struct student*)malloc(sizeof(struct student));
			CityStudents[0][0].StdNum = Aclass[0].StdNum;
			strcpy(CityStudents[0][0].Address, Aclass[0].Address);
			CityStudents[0][0].Age = Aclass[0].Age;
			strcpy(CityStudents[0][0].Name, Aclass[0].Name);
		}
		else{
			// find the existing index (or -1)
			int existingIndex = -1;
			for (int CSIndex = 0; CSIndex < count; CSIndex++){
				if (!strcmp(Aclass[AclassIndex].Address, CityStudents[CSIndex][0].Address)){
					existingIndex = CSIndex;
					break;
				}
			}

			// if the item already exist : duplicate original item, expand original item, paste original item to expanded item, and add new student to original item.
			if (existingIndex>-1){
				int tmpCount = sizeof(CityStudents[existingIndex]) / sizeof(struct student*);

				// duplicate original item.
				struct student* tmpStudents = (struct student*)malloc(sizeof(struct student) * tmpCount);
				for (int tSIndex = 0; tSIndex < tmpCount; tSIndex++){
					tmpStudents[tSIndex].StdNum = CityStudents[existingIndex][tSIndex].StdNum;
					tmpStudents[tSIndex].Age = CityStudents[existingIndex][tSIndex].Age;
					strcpy(tmpStudents[tSIndex].Name, CityStudents[existingIndex][tSIndex].Name);
					strcpy(tmpStudents[tSIndex].Address, CityStudents[existingIndex][tSIndex].Address);
				}

				// expand original item and paste original item to new item.
				CityStudents[existingIndex] = (struct student*)malloc(sizeof(struct student)*(tmpCount + 1));
				for (int newIndex = 0; newIndex < tmpCount; newIndex++){
					CityStudents[existingIndex][newIndex].Age = tmpStudents[newIndex].Age;
					CityStudents[existingIndex][newIndex].StdNum = tmpStudents[newIndex].StdNum;
					strcpy(CityStudents[existingIndex][newIndex].Name, tmpStudents[newIndex].Name);
					strcpy(CityStudents[existingIndex][newIndex].Address, tmpStudents[newIndex].Address);
				}

				// add new student to original item
				CityStudents[existingIndex][tmpCount].Age = Aclass[AclassIndex].Age;
				CityStudents[existingIndex][tmpCount].StdNum = Aclass[AclassIndex].StdNum;
				strcpy(CityStudents[existingIndex][tmpCount].Name, Aclass[AclassIndex].Name);
				strcpy(CityStudents[existingIndex][tmpCount].Address, Aclass[AclassIndex].Address);
			}
			else // item not exist : duplicate original array including items, expand original array, paste original array including items to expanded array, and add new array to expanded array.
			{
				// duplicate original array including items
				struct student** tmpStudents = (struct student**)malloc(sizeof(struct student*) * count);
				for (int tSCount = 0; tSCount < count; tSCount++){
					int tmpCount = _msize(CityStudents[tSCount]) / sizeof(struct student);
					tmpStudents[tSCount] = (struct student*)malloc(sizeof(struct student) * tmpCount);
					for (int tSitemIndex = 0; tSitemIndex < tmpCount; tSitemIndex++){
						tmpStudents[tSCount][tSitemIndex].Age = CityStudents[tSCount][tSitemIndex].Age;
						tmpStudents[tSCount][tSitemIndex].StdNum = CityStudents[tSCount][tSitemIndex].StdNum;
						strcpy(tmpStudents[tSCount][tSitemIndex].Address, CityStudents[tSCount][tSitemIndex].Address);
						strcpy(tmpStudents[tSCount][tSitemIndex].Name, CityStudents[tSCount][tSitemIndex].Name);
					}
				}

				// expand original array and paste original array including items to expanded array.
				CityStudents = (struct student**)malloc(sizeof(struct student*) * (count + 1));
				for (int CSIndex = 0; CSIndex < count; CSIndex++){
					int tmpCount = _msize(tmpStudents[CSIndex]) / sizeof(struct student);
					CityStudents[CSIndex] = (struct Student*)malloc(sizeof(struct student) * tmpCount);
					for (int CSitemIndex = 0; CSitemIndex < tmpCount; CSitemIndex++){
						CityStudents[CSIndex][CSitemIndex].Age = tmpStudents[CSIndex][CSitemIndex].Age;
						CityStudents[CSIndex][CSitemIndex].StdNum = tmpStudents[CSIndex][CSitemIndex].StdNum;
						strcpy(CityStudents[CSIndex][CSitemIndex].Address, tmpStudents[CSIndex][CSitemIndex].Address);
						strcpy(CityStudents[CSIndex][CSitemIndex].Name, tmpStudents[CSIndex][CSitemIndex].Name);
					}
				}
				CityStudents[count] = (struct student*)malloc(sizeof(struct student));
				// add new array to expanded array.
				CityStudents[count][0].Age = Aclass[AclassIndex].Age;
				CityStudents[count][0].StdNum = Aclass[AclassIndex].StdNum;
				strcpy(CityStudents[count][0].Address, Aclass[AclassIndex].Address);
				strcpy(CityStudents[count++][0].Name, Aclass[AclassIndex].Name);
			}
		}
	}

	// print all students by address.
	for (int i = 0; i < count; i++){
		int size = _msize(CityStudents[i]) / sizeof(struct student);
		printf("%s : %d명\n", CityStudents[i][0].Address, size);
		for (int j = 0; j < size; j++){
			printf("%d %s %d %s\n", CityStudents[i][j].StdNum, CityStudents[i][j].Name, CityStudents[i][j].Age, CityStudents[i][j].Address);
		}
		printf("\n");
	}

	free(CityStudents);
}