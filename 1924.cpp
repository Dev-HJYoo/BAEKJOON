/*
	2018.7.27
	음.. 보면 이해될꺼야
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>

int main(void) {
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);
	
	char result[3];
	std::string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int total = -1;
	for (int i = 1; i <= 7; i += 2) 
		if (x > i)
			total += 31;
	for (int i = 8; i <= 12; i += 2)
		if (x > i)
			total += 31;
	for (int i = 4; i <= 6; i += 2)
		if (x > i)
			total += 30;
	for (int i = 9; i <= 11; i += 2)
		if (x > i)
			total += 30;
	if (x > 2)
		total += 28;
	total += y;
	total %= 7;
	printf("%s", day[total].c_str());
	return 0;
	
}