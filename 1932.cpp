/*
	2018.7.29
	생각은 내가 했고 dp적으로 생각했다.
	store 는 새로 받은 값
	first 는 전에 합쳤던 값 
	last 는 새로 받은 값 + 전에 합쳤던 값 

	이렇게 해서 풀었다 뿌듯
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
