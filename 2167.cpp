/*
	2018.8.12
	�յ��� �ٴ��Ѵٰ� �ϴ� ���̵��� ���Ҵ�
	�׸��� ��� Ʋ���ٰ� sum�κ��� long���� �ٲٴ� �ٷ� Ǯ����. ������ ���� ��������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}
int main(void) {
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	long dp[301][301] = { 0 };

	for (int i = 1; i <= N; i++) {
		long sum = 0;
		for (int j = 1; j <= M; j++) {
			long a;
			scanf("%ld", &a);
			sum += a;
			dp[i][j] = sum;
		}
	}
	int Q;
	scanf("%d", &Q);

	for (int _ = 0; _ < Q; _++) {
		int a, b, c, d;
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		scanf("%d", &d);
		
		int x_min = min(a, c);
		int x_max = max(a, c);
		int y_min = min(b, d);
		int y_max = max(b, d);

		long sum = 0;
		for (int i = x_min; i <= x_max; i++)
			sum += dp[i][y_max] - dp[i][y_min - 1];
		printf("%ld\n", sum);
	}
}