/*
	2019.6.17
	단순히 점화식을 세워서 풀면된다.
	내가 처음에 만들었던 점화식이랑 정답 점화식이랑 비슷했는데 점화식을 만들어보는 연습도 필요한 것 같다.

	1 <= digit <= 8 -> 위 아래 더하기
	0 -> 전의 1 만큼 가져오기
	9 -> 전의 8 만큼 가져오기 
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

