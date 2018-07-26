/*
2018.7.2
浆款 巩力具 浆款巩力
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int M,N;
	scanf("%d", &M);
	scanf("%d", &N);
	int total = 0;
	int min;
	for (int n = M; n <= N; n++) {
		int i;
		for (i = 2; i < n; i++)
			if (n%i == 0)
				break;
		if (i == n) {
			if (!total)
				min = n;
			total += n;
		}
	}
	if (total == 0)
		printf("-1");
	else {
		printf("%d\n%d\n", total, min);
	}
	return 0;
}