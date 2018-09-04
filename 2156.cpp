/*
	2018.8.28
	�Ƶ� ���� ó������ dp ���� �������� Ǭ�� ����..
	�׳� ��� ����� ������ ������ ���� ����鼭 ���ϱ� ������ ���Դ�
	4��°�� ������ �� �� �ִ� ��츦 �� �����ؼ� 3������ ��ȭ���� ���ͤӤ���.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int dp[10001] = { 0 };
int glass[10001] = { 0 };
int max(int a, int b) {
	return a < b ? b : a;
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &glass[i]);

	dp[1] = glass[1];
	
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 3] + glass[i - 1] + glass[i], dp[i - 2] + glass[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	
	printf("%d", dp[N]);
	return 0;
}