#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int dp[21][21][21] = { 0 };
int main(void) {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int t = 0; t <= 20; t++) {
				if (i <= 0 || j <= 0 || t <= 0) {
					dp[i][j][t] = 1;
					continue;
				}
				if (i < j && j < t)
					dp[i][j][t] = dp[i][j][t - 1] + dp[i][j - 1][t - 1] - dp[i][j - 1][t];
				else
					dp[i][j][t] = dp[i - 1][j][t] + dp[i - 1][j - 1][t] + dp[i - 1][j][t - 1] - dp[i - 1][j - 1][t - 1];
			}
		}
	}
	
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;
		if (a <= 0 || b <= 0 || c <= 0) 
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
		else if (a >20 || b>20 || c>20)
			printf("w(%d, %d, %d) = %d\n", a, b, c, dp[20][20][20]);
		else
			printf("w(%d, %d, %d) = %d\n", a, b, c, dp[a][b][c]);
	}
}