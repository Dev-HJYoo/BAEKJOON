/*
	2018.824
	���ͳݿ��� �� ���� �ٷ� Ǯ�����ѵ�.... % ���� �κ��� �־����� ������ �𸣰چ����������� ��Ʊ�...
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