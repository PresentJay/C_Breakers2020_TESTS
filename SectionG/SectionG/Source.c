#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_Dstr(int n);

/*
	get_Dstr()의 동작 설명
	1. n개의 문자저장공간을 동적으로 할당
	2. 입력되는 문자를 getch()함수로 받아 할당된 문자저장공간에 저장.
	3. 입력되는 문자가 많아 확보된 공간이 모자라면 공간을 추가 확보
		3-1. 기존 확보된 공간+a만큼 문자열 저장 공간을 새로 할당한 후
		3-2. 기존 입력된 문자들을 새로 할당한 공간에 복사(사용하지 않는 공간은 해제함.)
		3-3. 할당된 공간의 나머지에 문자열의 끝표시인 '\0'문자를 저장할 수 있을 때까지 3-1, 3-2과정을 반복함
	4. 입력된 문자열의 길이를 계산하여 기확보된 공간의 크기가 '문자열 길이+1'보다 크면 '문자열 길이+1'만큼의 공간을 확보한 후 기존 문자열을 새로 확보된 공간에 복사함.
	5. 완성된 문자열이 저장된 공간의 주소를 반환함.
*/

int main(){

	char *dstr = get_Dstr(3);
	printf("입력된 문자열의 길이는 %d이며, 문자열은 %s입니다. \n", strlen(dstr), dstr);

	return 0;
}

char* get_Dstr(int n){
	char *tmp = (char*)malloc(sizeof(char) * (n+1));
	int count = 0;

	for (char c = getch(); c != '\r'; c = getch()){
		if (n == count){
			char *tmpstr = (char*)malloc(sizeof(char) * ++n);
			for (int i = 0; i < count; i++)
				tmpstr[i] = tmp[i];
			tmp = (char*)malloc(sizeof(char) * (n + 1));
			for (int i = 0; i < count; i++)
				tmp[i] = tmpstr[i];
			free(tmpstr);
		}
		printf("%c", c);
		tmp[count++] = c;
	}
	tmp[n] = NULL;
	printf("\n");
	return tmp;
}