/*
	2018.8.25
	또 결국엔 인터넷 보고 했네...
	근데 계속 보면 먼가 점화식 비슷한거는 만들어 내는데 정확하지가 않네... 
	정확도를 늘리는 스킬을 익혀야 겠다.
	그리고 아직 동적배열이 익숙하지가 않네... 공부하자
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int _ = 0; _ < T; _++) {
		int N;
		scanf("%d", &N);
		int sticker[2][100001];
		int dp[2][100001];
		
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &sticker[i][j]);
			
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];

		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(dp[1][i - 1] , dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1] , dp[0][i - 2]) + sticker[1][i];
		}
		printf("%d\n", max(dp[0][N], dp[1][N]));
	}
}