/*
	2018.8.6 
	��� ������ ã�ٺ��ϱ� �̱��� �Դ�.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	long N;

	scanf("%ld", &N);

	long sum = 0;
	long i = 1;
	long j = 0;
	for (; N >= i; i *= 10, j++) {
		sum += (i- i/10)*j;
	}

	sum += (N - i / 10 + 1 ) * j;
	if (N < 10)
		printf("%d", N);
	
	else
		printf("%ld", sum);

}