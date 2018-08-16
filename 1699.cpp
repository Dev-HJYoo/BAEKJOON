/*
	2018.8.15
	�������� �� ������ ���� Ǯ���� ��������
	�ٽ��� ���翡�� ���� �Ǵ� ���� �� �ſ��� �ּҰ��� ã�� ���̴�
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