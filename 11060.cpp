#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {
	int N;
	scanf("%d", &N);

	int dp[1001] = { 0 };
	int score[1001] = { 0 };
	

	score[0] = 0;
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);
		score[i] = n;
	}

	dp[0] = 0;
	if (score[1] == 0) {
		printf("-1");
		return 0;
	}
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = 1000;
		for (int j = 1; j < i; j++) {
			if (j + score[j] >= i) {
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	if (dp[N] == 1000)
		printf("-1");
	else 
		printf("%d", dp[N]);
	return 0;
}


