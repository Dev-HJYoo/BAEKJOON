/*
	2018.10.7 
	그냥 생각나는대로 해서 풀었는데 잘나오네
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int dp[1001][1001] = { 0 };
int store[1001][1001] = { 0 };

int max(int a, int b, int c) {
	int max = (a < b) ? b : a;
	return ((max < c) ? c : max);
}
int main(void) {

	int n;
	int m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &store[i][j]);
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + store[i][j];
		}
	}
	printf("%d", dp[n][m]);
	return 0;
}