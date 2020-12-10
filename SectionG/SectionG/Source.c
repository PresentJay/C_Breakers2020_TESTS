#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_Dstr(int n);

/*
	get_Dstr()�� ���� ����
	1. n���� ������������� �������� �Ҵ�
	2. �ԷµǴ� ���ڸ� getch()�Լ��� �޾� �Ҵ�� ������������� ����.
	3. �ԷµǴ� ���ڰ� ���� Ȯ���� ������ ���ڶ�� ������ �߰� Ȯ��
		3-1. ���� Ȯ���� ����+a��ŭ ���ڿ� ���� ������ ���� �Ҵ��� ��
		3-2. ���� �Էµ� ���ڵ��� ���� �Ҵ��� ������ ����(������� �ʴ� ������ ������.)
		3-3. �Ҵ�� ������ �������� ���ڿ��� ��ǥ���� '\0'���ڸ� ������ �� ���� ������ 3-1, 3-2������ �ݺ���
	4. �Էµ� ���ڿ��� ���̸� ����Ͽ� ��Ȯ���� ������ ũ�Ⱑ '���ڿ� ����+1'���� ũ�� '���ڿ� ����+1'��ŭ�� ������ Ȯ���� �� ���� ���ڿ��� ���� Ȯ���� ������ ������.
	5. �ϼ��� ���ڿ��� ����� ������ �ּҸ� ��ȯ��.
*/

int main(){

	char *dstr = get_Dstr(3);
	printf("�Էµ� ���ڿ��� ���̴� %d�̸�, ���ڿ��� %s�Դϴ�. \n", strlen(dstr), dstr);

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