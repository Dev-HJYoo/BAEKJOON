/*
	2018.9.7
	그냥 생각하는 되로 풀었다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int dp[1001] = { 0 };
int bread[1001] = { 0 };
int main(void) {
	
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &bread[i]);

	dp[1] = bread[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = bread[i];
		for (int j = i; j >= i / 2; j--)
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
	}
	printf("%d", dp[N]);
}