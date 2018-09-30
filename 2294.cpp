#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

int dp[10001] = { 0 };


int main(void) {

	int n;
	int k;
	scanf("%d %d", &n, &k);

	int *store = new int[n+1];
	store[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &store[i]);

	std::sort(&store[0], &store[n]);
	
	dp[store[1]] = 1;
	for (int i = store[1] + 1; i <= k; i++) {
		dp[i] = 10000;
		for (int j = 1; j <= n; j++) {
			if (store[j] == i) {
				dp[i] = 1;
				break;
			}
			if (i - store[j] > 0) {
				if(dp[i-store[j]] != 0 && dp[i-store[j]] <10000)
					dp[i] = std::min(dp[i], dp[i - store[j]] + 1);
			}
		}
		printf("%d %d\n", i, dp[i]);
	}

	if (dp[k] == 10000)
		printf("-1");
	else
		printf("%d", dp[k]);
	return 0;
}