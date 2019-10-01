/*
	2019.9.30
	점화식 구할려다가 보니깐 피보나치 수열이 나왔음
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 41

using namespace std;

int dp[SIZE] = { 0 };

void solve() {
	int sum = 1;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < SIZE; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int a, b, c;
	scanf("%d %d", &a, &b);
	int start = 0;
	for (int i = 0; i < b; i++) {
		scanf("%d", &c);
		int end = c;
		sum *= dp[end - start-1];
		start = end;
	}
	if (start != a) {
		sum *= dp[a - start];
	}
	printf("%d", sum);
}

int main(void) {
	solve();
}