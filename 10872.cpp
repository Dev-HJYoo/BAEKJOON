/*
	2018.7.27
	매우 쉽지
	그리고 0! = 1 인 것을 까먹지 말자!!

*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int N;
	scanf("%d", &N);
	long  total = 1;
	for (int i = 1; i <= N; i++) {
		if (N >= i) {
			total *= i;
			continue;
		}
		break;
	}

	printf("%ld", total);
	return 0;
}