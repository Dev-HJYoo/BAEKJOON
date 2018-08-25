/*
	2018.8.25
	�� �ᱹ�� ���ͳ� ���� �߳�...
	�ٵ� ��� ���� �հ� ��ȭ�� ����ѰŴ� ����� ���µ� ��Ȯ������ �ʳ�... 
	��Ȯ���� �ø��� ��ų�� ������ �ڴ�.
	�׸��� ���� �����迭�� �ͼ������� �ʳ�... ��������
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