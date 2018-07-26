#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int W, H, N;
		scanf("%d", &W);
		scanf("%d", &H);
		scanf("%d", &N);

		printf("%d\n", N%W*100 + N/W + 1);
	}
	return 0;
}