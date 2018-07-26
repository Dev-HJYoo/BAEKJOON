/*
2018.7.15
dp 짜응 이제 느낌을 알아간다

*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		int *dp = new int[N+1];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= N; i++) 
			dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
		printf("%d\n", dp[N]);
		delete dp;
	}


	return 0;
}