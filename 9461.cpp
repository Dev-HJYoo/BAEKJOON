/*
	2018.8.5
	점화식 dp[i] = dp[i-1] + dp[i-5]를 찾아서 풀었당
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int main(void) {

	long long dp[101];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	int T;
	scanf("%d", &T);
	
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}