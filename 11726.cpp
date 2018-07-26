#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	unsigned long long *dp = new unsigned long long[N + 1];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	printf("%d", dp[N]%10007);
	return 0;
}