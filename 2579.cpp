/*
	2018.7.17
	인터넷의 도움으로 겨우 풀었다..... ㅂㄷㄷ...

*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


int max(int a, int b) {
	return a < b ? b : a;
}

int main(void) {
	int N;
	scanf("%d", &N);

	int *score = new int[N+1];
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);
		score[i] = n;
	}
	score[0] = 0;
	int *dp = new int[N + 1];
	for (int i = 1; i <= 3 && i <= N; i++)
		if (i != 3)
			dp[i] = dp[i - 1] + score[i];
		else
			dp[i] = max(score[i] + dp[i - 2], score[i] + score[i - 1]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
	}

	printf("%d",dp[N]);
	return 0;
}