/*
	2018.8.15
	오랜만에 내 힘으로 문제 풀었네 ㅋㅋㅋㅋ
	핵심은 현재에서 제곱 되는 수를 뺀 거에서 최소값을 찾는 것이다
	ex)
	11 - 1 = 10(2) + 1 ==> 3
	11 - 4 = 7(4) + 1 ==> 5
	11 - 9 = 2(2) + 1 ==> 3
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int dp[100001] ;

int main(void) {
	int N;
	scanf("%d", &N);

	int check = 1;
	for (int i = 1; i <= N; i++) {
		dp[i] = 100000;
		if (i == check * check) {
			check++;
			dp[i] = 1;
			continue;
		}
		for (int temp = 1; temp < check; temp++) {
			dp[i] = dp[i] > dp[i - temp*temp] + 1 ? dp[i - temp*temp] + 1 : dp[i];
		}
	}
	printf("%d", dp[N]);
}