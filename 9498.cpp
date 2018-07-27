/*
	2018.7.27
	그냥 너무 쉬운 문제이다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int score;
	scanf("%d", &score);

	char name = 'A';
	for (int i = 90; i >= 60; i -= 10) {
		if (score >= i) {
			printf("%c", name);
			return 0;
		}
		else if (score < 60) {
			printf("F");
			return 0;
		}
		name++;
	}
}