/*
	2018.7.17
	결국에는 인터넷 보고 깨달았다...
	값이 파보나치의 수열로 나온다. 
	즉 d[i] = d[i-1] + d[i-2] 이렇게 나온다
	.... ㅂㄷㄷ
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int min(int a, int b) {
	return a > b ? b : a;
}

int min(int a, int b, int c) {
	return a > b ? (b > c ? c : b) : (a > c ? c : a);
}

int main(void) {

	int N;
	scanf("%d", &N);

	long long * dp = new long long[N + 1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld", dp[N]);
	return 0;
}

