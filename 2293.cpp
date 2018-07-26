/*
	2018.7.20
	먼가 내 생각은 했는데 그것을 점화식으로 풀지는 못했다....
	계단이랑 비슷하게 풀면 되는데
	ex) 10원은 1,2,5원 이
	9 + 1
	8 + 2
	5 + 5 인 경우다.
	따라서 이 세 경우를 다 더하면 답이 나온다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int dp[10001];

int main(void) {
	int n;
	int k;
	scanf("%d", &n);
	scanf("%d", &k);
	
	int *coin = new int[n];
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		coin[i] = a;
	}
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if(j-coin[i] >= 0)
				dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[k]);

	return 0;
}