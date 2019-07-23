/*
	2019.7.23
	�׳� ���� ���̵� ���ö� Ǯ����. 
	�� ���� ���� ��� �׳� ���縦 �Գ� �ȸԳ� �̰����� �����ϴٰ� ���縦 �������� ������ �߿� �ڱ⺸�� �����鼭 ���̰� ū ���� ���� �ǰڴٴ� �����̵����.
	��, ���� �� > ���� �� & �̶������� ���� < ���� ���� ���� ����
	�̷� ��ȭ���� ����� Ǯ����.
	*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1001
using namespace std;

int n;
int dp[2][SIZE] = { 0 };

void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &dp[0][i]);
}

void solve() {
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		int num = dp[0][i];
		for (int j = 1; j < i; j++) {
			if (dp[0][j] < num && dp[1][j] > dp[1][i] ) {
				dp[1][i] = dp[1][j];
			}
		}
		dp[1][i]++;
	}
	
}

void print() {
	int max = dp[1][1];
	for (int i = 2; i <= n; i++)
		if (dp[1][i] > max)
			max = dp[1][i];
	printf("%d", max);
}

int main(void) {
	input();
	solve();
	print();
}