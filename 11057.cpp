/*
	2018.824
	인터넷에서 모델 보고 바로 풀었긴한데.... % 쓰는 부분은 왜쓰는지 아직도 모르겠넼ㅋㅋㅋㅋㅋ 어렵긔...
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main(void) {

	int N;
	scanf("%d", &N);

	int **dp = new int *[N+1];
	for (int i = 0; i <= N; i++)
		dp[i] = new int[10];
	
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) 
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] ) % 10007;
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[N][i];
	printf("%d", sum % 10007 );
}