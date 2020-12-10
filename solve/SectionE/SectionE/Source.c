#include <stdio.h>
#include <string.h>

void delete_a_char(char* s, char target);

void delete_chars(char* s, char target);

void main(void){
	char str[80];
	gets(str);
	delete_a_char(str, 'o');
	puts(str);
	delete_chars(str, 'g');
	puts(str);
}

void delete_a_char(char* s, char target){
	for (int i = 0; i < strlen(s); i++){
		if (s[i] == target){
			for (int j = i; j < strlen(s); j++)
				s[j] = s[j + 1];
			break;
		}
	}
}

void delete_chars(char* s, char target){
	for (int i = 0; i < strlen(s); i++){
		if (s[i] == target){
			for (int j = i; j < strlen(s); j++)
				s[j] = s[j + 1];
		}
	}
}