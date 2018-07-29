/*
	2018.7.29
	점화식을 찾아서 풀었다.
	dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
	그림을 그리다 보니 이러한 점화식이 도출되었다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int main(void) {
	int T;
	scanf("%d", &T);
	int dp[31][31] = { 0 };

	for (int i = 1; i <= 30; i++) 
		dp[1][i] = i;

	for (int i = 2; i <= 30; i++)
		for (int j = i; j <= 30; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
	for (int _ = 0; _ < T; _++) {
		int a;
		int b;
		scanf("%d", &a);
		scanf("%d", &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}