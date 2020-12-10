#include <stdio.h>
//  <work space> : Declare appropriate header.
#include <string.h>

/*

C Breakers TEST D.
IMPLEMENT all of work spaces (A to G)

*/

struct date{
	int year;
	int month;
	int day;
};

struct person{
	char name[10];
	int score[4];
	struct date birthday;
};

void output_info(struct person p){
	int total = 0;
	printf("%s\t%d-%d-%d\t", p.name, p.birthday.year, p.birthday.month, p.birthday.day);
	for (int i = 0; i < 4; i++){
		printf("%d\t", p.score[i]);
		total += p.score[i];
	}
	printf("%d\t%.2f\n", total, (double)total / 4);
}

void change_name(struct person* p, char* target, int size){
	int flag = 0;
	for (int i = 0; i < size; i++){
		if (strcmp(p[i].name, target) == 0){
			flag = 1;
			printf("»õ·Î¿î ÀÌ¸§ ÀÔ·Â >> ");
			scanf("%s", p[i].name);
		}
	}
	if (!flag)
		printf("ÇØ´ç ÀÌ¸§ %sÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n", target);
}

int main(){

	struct person persons[5] = {
		{ .name = "±è±æµ¿", .birthday = { .year = 1990, .month = 7, .day = 5 }, .score[0] = 80, .score[1] = 60, .score[2] = 75, .score[3] = 40 },
		{ .name = "±è¼¼¿µ", .birthday = { .year = 1994, .month = 6, .day = 20 }, .score[0] = 60, .score[1] = 75, .score[2] = 60, .score[3] = 55 },
		{ .name = "ÀåÈ«¼ö", .birthday = { .year = 1990, .month = 10, .day = 3 }, .score[0] = 55, .score[1] = 60, .score[2] = 75, .score[3] = 85 },
		{ .name = "±è¿µÈñ", .birthday = { .year = 1995, .month = 4, .day = 30 }, .score[0] = 50, .score[1] = 80, .score[2] = 90, .score[3] = 85 },
		{ .name = "¹ÚÁ¾¼ö", .birthday = { .year = 1991, .month = 4, .day = 5 }, .score[0] = 90, .score[1] = 80, .score[2] = 85, .score[3] = 90 }
	};

	for (int i = 0; i < 5; i++)
		output_info(persons[i]);

	change_name(persons, "±è¿µÈñ", 5);
	change_name(persons, "±è¿µÈñ", 5);

	return 0;
}