/*
	2019.10.18
	Ǯ�� �ߴµ�..... 100�� �� 90 ���̴�. 
	�� ������ �ϴ� �丣���� �������� Ǯ�� log ���� Ǯ���µ� dp�� �ϸ� �ð� �ʰ��� ���� �����̶�µ�.... �丣���� �������� ���ذ� �Ȱ�..
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1000000
#include <vector>
using namespace std;

vector<vector<int> > dp;
int n,p;

void input() {
	scanf("%d %d", &n, &p);
	for (int i = 0; i <= n; i++) {
		vector<int> temp(i + 1,1);
		for (int j = 1; j <= i - 1; j++)
			temp[j] = (dp[i-1][j - 1] + dp[i-1][j]) % 1000000007;
		dp.push_back(temp);
	}
	cout << dp[n][p];
}

int main(void) {
	input();
}

