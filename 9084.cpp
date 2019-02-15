#define _CRT_SECURE_NO_WARNINGS
/*
	2019.2.15
	���� �ߴ� �˰����� �Ųٷ� �غô��� �Ǵ���...
	��... 10000 * 20 �� 20 * 10000���� �ؼ� Ǯ����.
	�ٸ� ������ ���� ����� ������ ���߰ڴ�.
*/
#include <iostream>
#define SIZE 10001
#define SIZE2 20

using namespace std;


int coin[SIZE2] = { 0 };

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		long long dp[SIZE] = { 0 };
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		int limit;
		scanf("%d", &limit);


		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= limit; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}

		cout << dp[limit]<<"\n";
	}
}