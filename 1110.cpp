#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int main(void) {
	int set[2];
	int N;
	scanf("%d", &N);
	int real = N;
	int temp = -1;
	int i = 0;

	while (temp != real) {
		set[0] = N / 10;
		set[1] = N % 10;
		temp = set[1] * 10 + (set[0] + set[1]) % 10;
		i++;
		N = temp;
	}
	printf("%d\n", i);
	return 0;
}