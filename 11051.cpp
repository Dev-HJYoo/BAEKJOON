/*
	2019.7.22
	일단... 그냥 풀려고하니깐 컴파일 에러가 발생했다. 그 이유는 long long으로 해도 값이 너무 커져서 감당을 못하기 때문이다.
	따라서... 파스칼의 삼각형을 이용해서 풀면 쉽게 풀 수 있는 문제였다.
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