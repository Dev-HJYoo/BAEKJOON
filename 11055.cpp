/*
	2019.6.17
	�̰͵� ��ȭ���� ��¥�� �Ǵ� �ǵ�... ���ͼ��ϳ� ������ ��ȭ������ �ܴٴ°�

	���� ���� �ε��� 0���� �����ؼ� �ڱ⺸�� �����ſ� �� ���غ��� �Ǵµ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 1000
using namespace std;


int num[SIZE] = { 0 };
int N;
int dp[SIZE] = { 0 };
void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
}

void print(int max) {
	printf("%d", max);
}

void solve() {
	dp[0] = num[0];
	int max = dp[0];
	for (int i = 1; i < N; i++) {
		int sum = num[i];
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i] && sum < dp[j] + num[i])
				sum = dp[j] + num[i];
		}
		dp[i] = sum;
		if (max < sum)
			max = sum;
	}
	print(max);
}

int main(void) {
	input();
	solve();
}