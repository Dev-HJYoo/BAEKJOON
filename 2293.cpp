/*
	2018.7.20
	�հ� �� ������ �ߴµ� �װ��� ��ȭ������ Ǯ���� ���ߴ�....
	����̶� ����ϰ� Ǯ�� �Ǵµ�
	ex) 10���� 1,2,5�� ��
	9 + 1
	8 + 2
	5 + 5 �� ����.
	���� �� �� ��츦 �� ���ϸ� ���� ���´�.
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