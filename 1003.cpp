/*
	2018.7.17
	이거 옛날에 봤던 문제인데 zero 랑 one 이 피보나치 순서대로 움지이더라
	0 => 1 0
	1 => 0 1
	2 => 1 1
	3 => 1 2
	
	요렇게
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int T;
	scanf("%d", &T);
	
	int ** dp = new int*[41];
	for (int i = 0; i <= 40; i++)
		dp[i] = new int[2];

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;

	for (int i = 3; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", dp[n][0], dp[n][1]);
	}

	return 0;
}