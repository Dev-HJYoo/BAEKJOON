/*
	2018.8.15
	�հ� ���ö� �غôµ� �ȵǼ� �ᱹ���� ���ͳ� ã�ƺô�....
	������ �� �����ؼ� Ǯ���
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	int score[100001];
	int dp[100001];
	score[0] = 0;
	dp[0] = 0;
	int max = -1000;
	for (int i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		score[i] = a;
		dp[i] = dp[i - 1] + score[i] > score[i] ? dp[i - 1] + score[i] : score[i];
		if (max < dp[i])
			max = dp[i];
	}
	printf("%d", max);
}