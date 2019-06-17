/*
	2019.6.17
	�ܼ��� ��ȭ���� ������ Ǯ��ȴ�.
	���� ó���� ������� ��ȭ���̶� ���� ��ȭ���̶� ����ߴµ� ��ȭ���� ������ ������ �ʿ��� �� ����.

	1 <= digit <= 8 -> �� �Ʒ� ���ϱ�
	0 -> ���� 1 ��ŭ ��������
	9 -> ���� 8 ��ŭ �������� 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 100

using namespace std;

long long dp[SIZE][10] = { 0 };
int N;

void input() {
	scanf("%d", &N);
}

void print() {
	
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[N - 1][i];
	}
	printf("%lld", sum % 1000000000);
}

void solve() {
	dp[0][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i < N; i++) {
		for (int digit = 0; digit < 10; digit++) {
			if (digit == 0)
				dp[i][0] = dp[i - 1][1];
			else if (digit == 9)
				dp[i][9] = dp[i - 1][8];
			else
				dp[i][digit] = (dp[i-1][digit - 1] + dp[i-1][digit + 1]) % 1000000000;
		}
	}
	
	print();
}



int main(void) {
	input();
	solve();
}

