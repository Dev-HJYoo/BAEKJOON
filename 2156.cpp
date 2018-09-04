/*
	2018.8.28
	아따 거의 처음으로 dp 문제 내힘으로 푼것 같네..
	그냥 모든 경우의 수에서 가능한 수를 지우면서 가니깐 저런게 나왔다
	4번째를 기준을 올 수 있는 경우를 다 생각해서 3가지의 점화식이 나와ㅣㅆ다.
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