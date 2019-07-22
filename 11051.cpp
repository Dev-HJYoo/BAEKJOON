/*
	2019.7.22
	�ϴ�... �׳� Ǯ�����ϴϱ� ������ ������ �߻��ߴ�. �� ������ long long���� �ص� ���� �ʹ� Ŀ���� ������ ���ϱ� �����̴�.
	����... �Ľ�Į�� �ﰢ���� �̿��ؼ� Ǯ�� ���� Ǯ �� �ִ� ��������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1001
using namespace std;

int n, k;
int dp[SIZE][SIZE] = { 0 };

void input() {
	scanf("%d %d", &n, &k);
}

void solve() {
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < SIZE; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		dp[i][i] = 1;
	}
}

void print() {
	printf("%d", dp[n][k]);
}
int main(void) {
	input();
	solve();
	print();
}