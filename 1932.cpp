/*
	2018.7.29
	������ ���� �߰� dp������ �����ߴ�.
	store �� ���� ���� ��
	first �� ���� ���ƴ� �� 
	last �� ���� ���� �� + ���� ���ƴ� �� 

	�̷��� �ؼ� Ǯ���� �ѵ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N;
	scanf("%d", &N);

	int store[502] = { 0 };
	int first[502] = { 0 };
	int last[502] = { 0 };
	int maxs = 0;
	int x;
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= i; j++) {
			int a;
			scanf("%d", &a);
			store[j] = a;
		}

		for (int j = 0; j < i; j++) 
			last[j + 1] = store[j + 1] + max(first[j], first[j + 1]);
		for (int j = 1; j <= i; j++) 
			first[j] = last[j];
	}

	for (int i = 1; i <= N; i++)
		maxs = max(last[i], maxs);
	printf("%d", maxs);
}
