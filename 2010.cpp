#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int total = 0;

	for (int _ = 0; _ < N; _++) {
		int a;
		scanf("%d", &a);
		total += a;
	}
	printf("%d", total - N + 1);
	return 0;
}